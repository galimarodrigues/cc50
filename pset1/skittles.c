#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    // seed do PRNG
    srand(time(NULL));
    // escolhe número pseudo-aleatório entre [0, 1023]
    int skittles = rand() % 1024;

    int guess;

    printf("Olá! Eu sou uma máquina de balas falante! Adivinhe quantos Skittles têm dentro de mim. Dica: Estou pensando em um número entre 0 e 1023. Qual é ele?\n");

    do {
            scanf("%d", &guess); // Ler a suposição do usuário

            if (guess < 0 || guess > 1023) {
                printf("Não tente ser difícil... Adivinhe novamente.\n");
            } else if (guess > skittles) {
                printf("Ok, eles não são tantos assim. Tente novamente.\n");
            } else if (guess < skittles) {
                printf("Haha! Tenho muito mais Skittles do que isso. Tente novamente.\n");
            } else {
                printf("Você está certo! Nom nom nom nom.\n");
            }
        } while (guess != skittles);

        return 0;
}

//Dica: Usar Algoritmo de Ordenação Pesquisa Binária