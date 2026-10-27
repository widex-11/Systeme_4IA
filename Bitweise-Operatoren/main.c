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
    printf("3 A = A + B \n");
    printf("4 A = A UND B \n");
    printf("5 A = A ODER B \n");
    printf("6 A = A XOR B \n");
    printf("7 A = NICHT A \n");
    printf("8 A um B Stellen nach links schieben \n");
    printf("9 A um B Stellen nach rechts schieben \n");
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

            case 3:
                a = bit_plus(a, b);
                zeige_wert("Addition:", a);
                break;

            case 4:
                a = bit_und(a, b);
                zeige_wert("UND:", a);
                break;


            case 5:
                a = bit_oder(a, b);
                zeige_wert("ODER:", a);
                break;

            case 6:
                a = bit_xor(a, b);
                zeige_wert("XOR:", a);
                break;

            case 7:
                a = bit_nicht(a);
                zeige_wert("NICHT:", a);
                break;

            case 8:
                if (im_bereich(b)) {
                    a = bit_links(a, b);
                    zeige_wert("LINKS:", a);
                } else {
                    printf("B muss zwischen 0 und F liegen; A bleibt gleich\n");
                }
                break;


            case 9:
                if (im_bereich(b)) {
                    a = bit_rechts(a, b);
                    zeige_wert("RECHTS:", a);
                } else {
                    printf("B muss zwischen 0 und F liegen; A bleibt gleich\n");
                }
                break;

            case 0:
                printf("Programm beendet. \n");
                break;

            default:
                printf("ungueltige Wahl \n");
                break;

        }
    }while (wahl != 0);

    return 0;









}