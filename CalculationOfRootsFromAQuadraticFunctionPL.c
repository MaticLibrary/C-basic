#include <stdio.h>
#include <math.h>

int ObliczPierwiastki(int a, int b, int c, double *miejsceZerowe1, double *miejsceZerowe2) {
    double delta = b * b - 4 * a * c;
    if (delta < 0){
        return 0;
    }else if (delta == 0) {
        *miejsceZerowe1 = -b / (2.0 * a);
        return 1;
    }else{
        *miejsceZerowe1 = (-b - sqrt(delta)) / (2.0 * a);
        *miejsceZerowe2 = (-b + sqrt(delta)) / (2.0 * a);
        return 2;
    }
}
int main(void) {
    int a, b, c;
    double x1, x2;
    printf("\n ax^2 + bx + c = 0\n---------------------\n");
    printf("\nWprowadz wartosc dla a: ");
    scanf("%d", &a);
    printf("\nWprowadz wartosc dla b: ");
    scanf("%d", &b);
    printf("\nWprowadz wartosc dla c: ");
    scanf("%d", &c);

    int LiczbaPierwiastkow = ObliczPierwiastki(a, b, c, &x1, &x2);

    switch (LiczbaPierwiastkow) {
        case 0:
            printf("Brak miejsc zerowych.\n");
        break;
        case 1:
            printf("Jedno miejsce zerowe: x = %.2f\n", x1);
        break;
        case 2:
            printf("Dwa miejsca zerowe: x1 = %.2f, x2 = %.2f\n", x1, x2);
        break;
    }
    return 0;
}
