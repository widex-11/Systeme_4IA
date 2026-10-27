//
// Created by Maxi on 20.10.2026.
//

#include "bitweise.h"
#include <stdio.h>

void zeige_bits(uint16_t wert)
{
    for (int i = 15; i >= 0; i = i - 1) {
        printf("%d", (wert >> i) & 1);

        if (i == 8)
            printf(" ");
    }
}

void zeige_wert(const char *name, uint16_t wert) {
    printf("%s  Hex: %04X\n", name, wert);
    printf("   Bits: ");
    zeige_bits(wert);
    printf("\n");
}


uint16_t bit_plus(uint16_t a, uint16_t b)
{
    return a + b;
}



uint16_t bit_und(uint16_t a, uint16_t b)
{

    return a & b;
}


uint16_t bit_oder(uint16_t a, uint16_t b)
{
    return a | b;
}



uint16_t bit_xor(uint16_t a, uint16_t b)
{
    return a ^ b;
}



uint16_t bit_nicht(uint16_t a)
{
    return ~a;
}


int64_t im_bereich(int64_t n)
{
    return n >= 0 && n <= 15;
}



uint16_t bit_links(uint16_t a, uint16_t b)
{
    return a << b;
}



uint16_t bit_rechts(uint16_t a, uint16_t b)
{
    return a >> b;
}

uint16_t bit_setzen(uint16_t a, int64_t n)
{
    return a | (1u << n);
}



uint16_t bit_loeschen(uint16_t a, int64_t n)
{
    return a & ~(1u << n);
}



uint16_t bit_umschalten(uint16_t a, int64_t n)
{
    return a ^ (1u << n);
}



int64_t bit_pruefen(uint16_t a, int64_t n)
{
    return (a >> n) & 1u;
}