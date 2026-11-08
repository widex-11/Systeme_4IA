#include <stdio.h>
#include <stdint.h>
#include "regelkreis.h"

#define DT 0.25


int main(void){

    int ret = 0;
    double fehler[4] = {1.0, 0.5, 0.5, -0.2};
    double integral = 0;
    double fehler_alt = 1.0;
    double heizung = 0;
    int64_t i = 0;

    setvbuf(stdout, NULL, _IONBF, 0);

    printf("Fehler e  Heizung  Integral\n");



    for (i = 0; i < 4; i = i + 1) {
        heizung = pid_regler(fehler[i], &integral, &fehler_alt, DT);
        printf("%8.2f  %7.3f  %8.3f\n", fehler[i], heizung, integral);

    }

    return ret;
}