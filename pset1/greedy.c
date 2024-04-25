#include <stdio.h>
#include <math.h>

int main(void) {
    printf("Oi. Quanto troco você deve?\n");
    float troco;
    do {
        scanf("%f", &troco);
        if (troco <= 0) {
            printf("Desculpe? Quanto você disse?\n");
            char buffer[100];
            fgets(buffer, sizeof(buffer), stdin);
        }
    } while (troco <= 0);

    // Converter para centavos e arredondar
    int centavos = round(troco * 100);

    // Contar o número mínimo de moedas necessário
    int moedas = 0;

    // Determinar o número de moedas de 25 centavos
    moedas += centavos / 25;
    centavos %= 25;

    // Determinar o número de moedas de 10 centavos
    moedas += centavos / 10;
    centavos %= 10;

    // Determinar o número de moedas de 5 centavos
    moedas += centavos / 5;
    centavos %= 5;

    // O restante será dado em moedas de 1 centavo
    moedas += centavos;

    // Imprimir o número mínimo de moedas
    printf("%d\n", moedas);

    return 0;
}

//Algoritmo Guloso / Ganancioso
