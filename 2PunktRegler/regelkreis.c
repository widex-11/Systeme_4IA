#include "regelkreis.h"


double strecke(double temperatur, double heizung, double dt)
{
    double ret = 0;
    double erwaermung = HEIZRATE * heizung;
    double abkuehlung = VERLUST * (temperatur - AUSSENTEMPERATUR);

    ret = temperatur + dt * (erwaermung - abkuehlung);

    return ret;
}


double zweipunkt_regler(double fehler, double epsilon, double heizung_alt)
{
    double ret = heizung_alt;

    if (fehler > epsilon)
        ret = 1.0;
    else if (fehler < -epsilon)
        ret = 0.0;

    return ret;
}