#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Função para criptografar uma única letra
char cifra_de_cesar(char letra, int chave) {
    if (isalpha(letra)) {
        char base = isupper(letra) ? 'A' : 'a';
        return (letra - base + chave) % 26 + base;
    } else {
        return letra; // Caracteres não alfabéticos permanecem inalterados
    }
}

// Função para criptografar uma string inteira
void criptografar_texto(char *texto, int chave) {
    int tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        texto[i] = cifra_de_cesar(texto[i], chave);
    }
}

int main(int argc, char *argv[]) {
    // Verificar se foi fornecido exatamente um argumento de linha de comando
    if (argc != 2) {
        printf("Uso: %s chave\n", argv[0]);
        return 1;
    }

    int chave = atoi(argv[1]);

    // Solicitar ao usuário um texto para criptografar
    printf("Digite um texto para criptografar: ");
    char texto[1000];
    fgets(texto, sizeof(texto), stdin);

    // Remover a quebra de linha adicionada por fgets, se houver
    int tamanho = strlen(texto);
    if (texto[tamanho - 1] == '\n') {
        texto[tamanho - 1] = '\0';
    }

    // Criptografar o texto
    criptografar_texto(texto, chave);

    // Imprimir o texto criptografado
    printf("Texto criptografado: %s\n", texto);

    return 0;
}
