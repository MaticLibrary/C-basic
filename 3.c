#include <stdio.h>

int main(void) {
    float kelvinTemperature = 0, fahrenheitTemperature = 0, rankineTemperature = 0, celsiusTemperature = 0;
    int option, option1;

    printf("Select an input unit:\n1. Kelvin\n2. Fahrenheit\n3. Rankine\n4. Celsius\nYour choice: ");
    scanf("%d", &option);

    if (option == 1) {
        printf("\nEnter temperature in Kelvin: ");
        scanf("%f", &kelvinTemperature);
    } else if (option == 2) {
        printf("\nEnter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheitTemperature);
    } else if (option == 3) {
        printf("\nEnter temperature in Rankine: ");
        scanf("%f", &rankineTemperature);
    } else if (option == 4) {
        printf("\nEnter temperature in Celsius: ");
        scanf("%f", &celsiusTemperature);
    } else {
        printf("\nInvalid option, please try again.\n");
        return 1;
    }

    printf("\nSelect a target unit:\n1. Kelvin\n2. Fahrenheit\n3. Rankine\n4. Celsius\nYour choice: ");
    scanf("%d", &option1);

    if (option == 1) {
        if (option1 == 2) {
            fahrenheitTemperature = (kelvinTemperature - 273.15) * 9 / 5 + 32;
            printf("\nTemperature in Fahrenheit: %.2f°F\n", fahrenheitTemperature);
        } else if (option1 == 3) {
            rankineTemperature = kelvinTemperature * 9 / 5;
            printf("\nTemperature in Rankine: %.2f°R\n", rankineTemperature);
        } else if (option1 == 4) {
            celsiusTemperature = kelvinTemperature - 273.15;
            printf("\nTemperature in Celsius: %.2f°C\n", celsiusTemperature);
        }
    } else if (option == 2) {
        if (option1 == 1) {
            kelvinTemperature = (fahrenheitTemperature - 32) * 5 / 9 + 273.15;
            printf("\nTemperature in Kelvin: %.2fK\n", kelvinTemperature);
        } else if (option1 == 3) {
            rankineTemperature = fahrenheitTemperature + 459.67;
            printf("\nTemperature in Rankine: %.2f°R\n", rankineTemperature);
        } else if (option1 == 4) {
            celsiusTemperature = (fahrenheitTemperature - 32) * 5 / 9;
            printf("\nTemperature in Celsius: %.2f°C\n", celsiusTemperature);
        }
    } else if (option == 3) {
        if (option1 == 1) {
            kelvinTemperature = rankineTemperature * 5 / 9;
            printf("\nTemperature in Kelvin: %.2fK\n", kelvinTemperature);
        } else if (option1 == 2) {
            fahrenheitTemperature = rankineTemperature - 459.67;
            printf("\nTemperature in Fahrenheit: %.2f°F\n", fahrenheitTemperature);
        } else if (option1 == 4) {
            celsiusTemperature = (rankineTemperature - 491.67) * 5 / 9;
            printf("\nTemperature in Celsius: %.2f°C\n", celsiusTemperature);
        }
    } else if (option == 4) {
        if (option1 == 1) {
            kelvinTemperature = celsiusTemperature + 273.15;
            printf("\nTemperature in Kelvin: %.2fK\n", kelvinTemperature);
        } else if (option1 == 2) {
            fahrenheitTemperature = (celsiusTemperature * 9 / 5) + 32;
            printf("\nTemperature in Fahrenheit: %.2f°F\n", fahrenheitTemperature);
        } else if (option1 == 3) {
            rankineTemperature = (celsiusTemperature + 273.15) * 9 / 5;
            printf("\nTemperature in Rankine: %.2f°R\n", rankineTemperature);
        }
    } else {
        printf("\nInvalid option.\n");
    }
    return 0;
}
