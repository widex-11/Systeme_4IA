//
// Created by Maxi on 20.10.2026.
//

#ifndef BITWEISE_H
#define BITWEISE_H

#include <stdint.h>

void zeige_bits(uint16_t wert);
void zeige_wert(const char *name, uint16_t wert);
uint16_t bit_plus(uint16_t a, uint16_t b);
uint16_t bit_und(uint16_t a, uint16_t b);
uint16_t bit_oder(uint16_t a, uint16_t b);

#endif