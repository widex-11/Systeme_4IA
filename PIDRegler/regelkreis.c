//
// Created by Maxi on 28.10.2026.
//

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