//
// Created by Maxi on 28.10.2026.
//
#include <stdio.h>
#include "regelkreis.h"


double strecke(double temperatur, double heizung, double dt){

    double ret = 0;

    double erwaermung = HEIZRATE * heizung;
    double abkuehlung = VERLUST * (temperatur - AUSSENTEMPERATUR);


    ret = temperatur + dt * (erwaermung - abkuehlung);

    return ret;


}


double pid_regler(double fehler, double *integral, double *fehler_alt, double dt){

    double ret = 0;
    double integral_neu = *integral + fehler * dt;

    double ableitung = (fehler - *fehler_alt) / dt;

    ret = KP * fehler + KI * integral_neu + KD * ableitung;


    if (ret > 1.0)
        ret = 1.0;

    else if (ret < 0.0)
        ret = 0.0;

    else
        *integral = integral_neu;

    *fehler_alt = fehler;

    return ret;
}







void zahl_schreiben(FILE *datei, double zahl)
{
    char text[32];
    int64_t i = 0;

    snprintf(text, sizeof(text), "%.2f", zahl);

    while (text[i] != '\0') {
        if (text[i] == '.')
            text[i] = ',';
        i = i + 1;
    }

    fputs(text, datei);
}


int64_t csv_schreiben(const char *dateiname, messpunkt_t feld[], int64_t anzahl)
{
    int64_t ret = 0;

    int64_t i = 0;
    FILE *datei = fopen(dateiname, "w");

    if (datei != NULL) {
        fprintf(datei, "Zeit;Sollwert;Istwert;Heizung\n");

        for (i = 0; i < anzahl; i = i + 1) {

            zahl_schreiben(datei, feld[i].zeit);

            fprintf(datei, ";");
            zahl_schreiben(datei, feld[i].sollwert);
            fprintf(datei, ";");

            zahl_schreiben(datei, feld[i].istwert);
            fprintf(datei, ";");
            zahl_schreiben(datei, feld[i].heizung);
            fprintf(datei, "\n");

        }

        fclose(datei);
        ret = 1;
        
    }

    return ret;
}