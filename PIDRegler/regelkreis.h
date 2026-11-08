//
// Created by Maxi on 28.10.2026.
//


#ifndef REGELKREIS_H
#define REGELKREIS_H

#define HEIZRATE 0.5
#define VERLUST 0.02
#define AUSSENTEMPERATUR 5.0


//kp -> fehler ( je weiter weg vom sollwert desto mehr heizen
//ki -> summe aller fehler; das am ende keine abweichung übrig ist
//kd -> änderung des fehlers; bremsen befor zu warm wird

#define KP 0.5
#define KI 0.02
#define KD 1.0

double strecke(double temperatur, double heizung, double dt);

double pid_regler(double fehler, double *integral, double *fehler_alt, double dt);

#endif
