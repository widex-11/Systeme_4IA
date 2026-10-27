#include <stdio.h>
#include <stdint.h>
#include "regelkreis.h"

#define DT 0.5
#define ANZAHL 720
#define SOLLWERT 21.0
#define EPSILON 0.5
#define STARTTEMPERATUR 15.0


int main(void)
{
    int ret = 0;
    messpunkt_t feld[ANZAHL];
    double temperatur = STARTTEMPERATUR;
    double heizung = 0;
    double fehler = 0;
    int64_t i = 0;

    setvbuf(stdout, NULL, _IONBF, 0);

    for (i = 0; i < ANZAHL; i = i + 1) {
        fehler = SOLLWERT - temperatur;
        heizung = zweipunkt_regler(fehler, EPSILON, heizung);

        feld[i].zeit = i * DT;
        feld[i].sollwert = SOLLWERT;
        feld[i].istwert = temperatur;
        feld[i].heizung = heizung;

        temperatur = strecke(temperatur, heizung, DT);
    }

    printf("Minute  Istwert  Heizung\n");

    for (i = 0; i < ANZAHL; i = i + 1) {
        if (i == 0 || feld[i].heizung != feld[i - 1].heizung)
            printf("%6.1f  %7.2f  %7.0f\n", feld[i].zeit, feld[i].istwert, feld[i].heizung);
    }

    return ret;
}