#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Função para criptografar um único caractere usando a cifra de Vigenère
char cifra_de_vigenere(char letra, char chave) {
    char base = isupper(letra) ? 'A' : 'a';
    int deslocamento = toupper(chave) - 'A';
    return ((letra - base + deslocamento) % 26) + base;
}

int main(int argc, char *argv[]) {
    // Verificar se foi fornecida exatamente uma palavra-chave como argumento de linha de comando
    if (argc != 2) {
        printf("Uso: %s palavra_chave\n", argv[0]);
        return 1;
    }

    // Verificar se a palavra-chave contém apenas caracteres alfabéticos
    char *palavra_chave = argv[1];
    for (int i = 0; palavra_chave[i] != '\0'; i++) {
        if (!isalpha(palavra_chave[i])) {
            printf("A palavra-chave deve conter apenas caracteres alfabéticos.\n");
            return 1;
        }
    }

    // Solicitar ao usuário uma sequência de texto para criptografar
    char texto[1000];
    printf("Digite um texto para criptografar: ");
    fgets(texto, sizeof(texto), stdin);

    // Criptografar o texto usando a cifra de Vigenère
    int tamanho_palavra_chave = strlen(palavra_chave);
    int j = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) {
            texto[i] = cifra_de_vigenere(texto[i], palavra_chave[j]);
            j = (j + 1) % tamanho_palavra_chave;
        }
    }

    // Imprimir o texto criptografado
    printf("Texto criptografado: %s\n", texto);

    return 0;
}