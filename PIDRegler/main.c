#include <stdio.h>
#include <stdint.h>
#include "regelkreis.h"

#define DT 0.25
#define ANZAHL 2400
#define SOLLWERT 23.0
#define STARTTEMPERATUR 12.0



int main(void){
    int ret = 0;
    static messpunkt_t feld[ANZAHL];
    double temperatur = STARTTEMPERATUR;


    double heizung = 0;
    double fehler = 0;
    double integral = 0;
    double fehler_alt = SOLLWERT - STARTTEMPERATUR;
    int64_t i = 0;


    setvbuf(stdout, NULL, _IONBF, 0);

    for (i = 0; i < ANZAHL; i = i + 1) {
        fehler = SOLLWERT - temperatur;
        heizung = pid_regler(fehler,&integral,&fehler_alt, DT);

        feld[i].zeit = i * DT;
        feld[i].sollwert = SOLLWERT;
        feld[i].istwert = temperatur;
        feld[i].heizung = heizung;

        temperatur = strecke(temperatur, heizung, DT);
    }

    printf("Minute  Istwert  Heizung\n");

    for (i = 0; i < ANZAHL; i = i + 120)
        printf("%6.1f  %7.2f  %7.2f\n", feld[i].zeit,feld[i].istwert, feld[i].heizung);


    return ret;
}