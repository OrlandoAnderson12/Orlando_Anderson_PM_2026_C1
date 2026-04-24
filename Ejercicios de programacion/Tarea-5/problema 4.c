/* PS7_4_validado.c */
#include <stdio.h>
#include <string.h>

static int dias_en_mes(int m, int year_abs) {
    int bisiesto = (year_abs % 4 == 0 && year_abs % 100 != 0) || (year_abs % 400 == 0);
    switch (m) {
        case 1:  case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4:  case 6: case 9: case 11: return 30;
        case 2:  return bisiesto ? 29 : 28;
        default: return 0;
    }
}

int main(void) {
    char cad[16];
    if (!fgets(cad, sizeof(cad), stdin)) return 0;

    size_t n = strcspn(cad, "\r\n");
    cad[n] = '\0';

    int d, m, aa;
    if (sscanf(cad, "%d/%d/%d", &d, &m, &aa) != 3) {
        // Formato inválido: no imprime nada (ajusta si el profe quiere mensaje)
        return 0;
    }

    const char *mes[] = {
        "", "enero","febrero","marzo","abril","mayo","junio",
        "julio","agosto","septiembre","octubre","noviembre","diciembre"
    };

    if (m < 1 || m > 12) return 0;

    // Interpreta 'aa' como 2000..2099; cambia a 1900+aa si tu curso lo pide así.
    int year_abs = 2000 + aa;
    int dm = dias_en_mes(m, year_abs);
    if (d < 1 || d > dm) return 0;

    printf("%d de %s de %02d\n", d, mes[m], aa);
    return 0;
}