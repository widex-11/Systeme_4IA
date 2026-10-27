#ifndef REGELKREIS_H
#define REGELKREIS_H

#include <stdint.h>
#define HEIZRATE 0.5
#define VERLUST 0.02
#define AUSSENTEMPERATUR 5.0

typedef struct messpunkt_s {
    double zeit;
    double sollwert;
    double istwert;
    double heizung;
} messpunkt_t;

double strecke(double temperatur, double heizung, double dt);
double zweipunkt_regler(double fehler, double epsilon, double heizung_alt);
int64_t csv_schreiben(const char *dateiname, messpunkt_t feld[], int64_t anzahl);

#endif