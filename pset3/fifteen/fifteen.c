#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DIMENSION 4

int board[DIMENSION][DIMENSION];

// Função para inicializar o tabuleiro
void init(void)
{
    int count = DIMENSION * DIMENSION;

    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 0; j < DIMENSION; j++)
        {
            board[i][j] = --count;
        }
    }

    if (DIMENSION % 2 == 0)
    {
        int temp = board[DIMENSION - 1][DIMENSION - 3];
        board[DIMENSION - 1][DIMENSION - 3] = board[DIMENSION - 1][DIMENSION - 2];
        board[DIMENSION - 1][DIMENSION - 2] = temp;
    }
}

// Função para imprimir o tabuleiro
void draw(void)
{
    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 0; j < DIMENSION; j++)
        {
            if (board[i][j] == 0)
            {
                printf(" _ ");
            }
            else
            {
                printf("%2d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

// Função para encontrar a posição da peça no tabuleiro
void findPiece(int tile, int *row, int *col)
{
    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 0; j < DIMENSION; j++)
        {
            if (board[i][j] == tile)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Função para mover uma peça no tabuleiro
int move(int tile)
{
    // Verifica se a peça está no tabuleiro
    if (tile < 1 || tile > DIMENSION * DIMENSION - 1)
    {
        return 0;
    }

    // Encontra a posição da peça no tabuleiro
    int row, col;
    findPiece(tile, &row, &col);

    // Verifica se a peça pode ser movida para o espaço vazio
    if ((row > 0 && board[row - 1][col] == 0) || (row < DIMENSION - 1 && board[row + 1][col] == 0) ||
        (col > 0 && board[row][col - 1] == 0) || (col < DIMENSION - 1 && board[row][col + 1] == 0))
    {
        // Troca a peça com o espaço vazio
        board[row][col] = 0;
        if (row > 0 && board[row - 1][col] == 0) {
            board[row - 1][col] = tile;
        } else if (row < DIMENSION - 1 && board[row + 1][col] == 0) {
            board[row + 1][col] = tile;
        } else if (col > 0 && board[row][col - 1] == 0) {
            board[row][col - 1] = tile;
        } else if (col < DIMENSION - 1 && board[row][col + 1] == 0) {
            board[row][col + 1] = tile;
        }
        return 1;
    }

    return 0;
}

// Função para verificar se o jogador venceu
int won(void)
{
    int count = 1;

    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 0; j < DIMENSION; j++)
        {
            if (count != DIMENSION * DIMENSION && board[i][j] != count)
            {
                return 0;
            }
            count++;
        }
    }

    return 1;
}

// Função principal
int main(void)
{
    init();

    while (!won())
    {
        system("clear");

        draw();

        int tile;
        printf("Digite o número da peça que deseja mover (0 para sair): ");
        scanf("%d", &tile);

        if (tile == 0)
        {
            break;
        }

        if (!move(tile))
        {
            printf("Movimento inválido!\n");
            usleep(1000000); 
        }
    }

    if (won())
    {
        system("clear");

        draw();

        printf("Parabéns, você ganhou!\n");
    }

    return 0;
}
