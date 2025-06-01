#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // Coordenadas fixas dos navios
    int linha_horizontal = 2;
    int coluna_horizontal = 4;
    int linha_vertical = 5;
    int coluna_vertical = 1;

    // Posiciona navio horizontal (tamanho 3)
    if (coluna_horizontal + NAVIO <= TAMANHO) {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
        }
    } else {
        printf("Erro: navio horizontal fora dos limites.\n");
        return 1;
    }

    // Verifica e posiciona navio vertical (tamanho 3)
    if (linha_vertical + NAVIO <= TAMANHO) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] == 3) {
                printf("Erro: sobreposição de navios.\n");
                return 1;
            }
        }
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha_vertical + i][coluna_vertical] = 3;
        }
    } else {
        printf("Erro: navio vertical fora dos limites.\n");
        return 1;
    }

    // Imprime o tabuleiro
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
