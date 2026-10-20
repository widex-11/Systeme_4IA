#include <stdio.h>
#include <stdint.h>
#include "bitweise.h"



void zeile_leeren(void)
{
    int64_t zeichen = getchar();

    while (zeichen != '\n' && zeichen != EOF)
        zeichen = getchar();
}

void zeige_menue(uint16_t a, uint16_t b) {
    printf("\n");
    zeige_wert("A", a);
    zeige_wert("B", b);
    printf("\n");

    printf("1 A eingeben (HEX) \n");
    printf("2 B eingeben (HEX) \n");
    printf("0 ENDE \n");
    printf("Wahl:");

}
int main(void) {
    zeige_wert("Test", 0x35AF);

    uint16_t a = 0;
    uint16_t b = 0;
    int wahl = -1;

    setvbuf(stdout, NULL, _IONBF, 0);

    do {
        zeige_menue(a, b);
        if (scanf("%d", &wahl) != 1)
            wahl = -1;
        zeile_leeren();

        switch (wahl) {
            case 1:
                printf("A (HEX): ");
                if (scanf("%hx", &a) != 1) {
                    printf("Keine gueltige Hexzahl. \n");
                }
                zeile_leeren();
                break;

            case 2:
                printf("B (HEX): ");
                if (scanf("%hx", &b) != 1) {
                    printf("Keine gueltige Hexzahl. \n");
                }
                zeile_leeren();
                break;

            case 0:
                printf("Programm beendet. \n");
                break;

            default:
                printf("ungültige Wahl \n");
                break;

        }
    }while (wahl != 0);

    return 0;









}