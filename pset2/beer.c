#include <stdio.h>

// Função para retornar a string correspondente ao número de garrafas na parede
char* garrafas_na_parede(int num) {
    // Arrays de strings para os casos específicos
    char* singular[] = {"uma garrafa", "uma"};
    char* plural[] = {" garrafas", ""};

    // Retornar a string correspondente baseada no número de garrafas
    if (num == 1)
        return singular[0];
    else
        return plural[0];
}

// Função para imprimir uma linha da canção
void imprimir_linha(int num) {
    printf("%d %s de cerveja no muro, ", num, garrafas_na_parede(num));
    printf("bebo uma, jogo no lixo, ");
    printf("%d %s de cerveja no muro...\n", num - 1, garrafas_na_parede(num - 1));
}

int main(void) {
    // Loop de 10 a 1 para imprimir as linhas da canção
    for (int i = 10; i >= 1; i--) {
        imprimir_linha(i);
    }
    // Linha final da canção
    printf("Nenhuma garrafa de cerveja no muro...\n");

    return 0;
}
