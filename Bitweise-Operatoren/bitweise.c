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