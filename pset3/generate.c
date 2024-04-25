#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar números pseudoaleatórios
void generate(int n, int s)
{
    // Se s for fornecido, use-o como semente
    if (s != 0)
    {
        srand(s);
    }
    else
    {
        // Caso contrário, use o tempo atual como semente
        srand(time(NULL));
    }

    // Gere e imprima n números pseudoaleatórios
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", rand());
    }
}

int main(int argc, char *argv[])
{
    // Verifique se o número correto de argumentos foi fornecido
    if (argc != 2 && argc != 3)
    {
        printf("Utilização: generate n [s]\n");
        return 1;
    }

    // Converta o primeiro argumento para um inteiro
    int n = atoi(argv[1]);

    // Se o segundo argumento (seed) for fornecido, converta-o para um inteiro
    int s = argc == 3 ? atoi(argv[2]) : 0;

    // Chame a função generate com os argumentos fornecidos
    generate(n, s);

    return 0;
}
