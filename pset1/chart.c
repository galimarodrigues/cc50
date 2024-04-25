#include <stdio.h>

int main(void) {
    // Solicitar ao usuário quatro inteiros não negativos
    printf("M procurando F: ");
    int m_f;
    scanf("%d", &m_f);

    printf("F procurando M: ");
    int f_m;
    scanf("%d", &f_m);

    printf("F procurando F: ");
    int f_f;
    scanf("%d", &f_f);

    printf("M procurando M: ");
    int m_m;
    scanf("%d", &m_m);

    // Calcular a soma dos quatro valores
    int total = m_f + f_m + f_f + m_m;

    // Calcular o comprimento máximo da barra (80 caracteres)
    int comprimento_maximo = 80;

    // Calcular o comprimento de cada barra
    int comprimento_m_f = (m_f * comprimento_maximo + total / 2) / total;
    int comprimento_f_m = (f_m * comprimento_maximo + total / 2) / total;
    int comprimento_f_f = (f_f * comprimento_maximo + total / 2) / total;
    int comprimento_m_m = (m_m * comprimento_maximo + total / 2) / total;

    // Imprimir as barras
    printf("Quem procura quem?\n");
    printf("M procurando F\n");
    for (int i = 0; i < comprimento_m_f; i++) {
        printf("#");
    }
    printf("\n");

    printf("F procurando M\n");
    for (int i = 0; i < comprimento_f_m; i++) {
        printf("#");
    }
    printf("\n");

    printf("F procurando F\n");
    for (int i = 0; i < comprimento_f_f; i++) {
        printf("#");
    }
    printf("\n");

    printf("M procurando M\n");
    for (int i = 0; i < comprimento_m_m; i++) {
        printf("#");
    }
    printf("\n");

    return 0;
}