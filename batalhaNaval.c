#include <stdio.h>

#define TAMANHO 10   // Tamanho do tabuleiro (10x10)
#define NAVIO 3      // Tamanho fixo dos navios (3 posições)

int main() {
    // Inicializa o tabuleiro com 0 (representa água)
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // ------------------ NAVIO HORIZONTAL ------------------
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    // Verifica se o navio cabe no tabuleiro horizontalmente
    if (coluna_horizontal + NAVIO <= TAMANHO) {
        // Posiciona o navio (valor 3) na horizontal
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
        }
    } else {
        printf("Erro: navio horizontal fora dos limites.\n");
        return 1;
    }

    // ------------------ NAVIO VERTICAL ------------------
    int linha_vertical = 5;
    int coluna_vertical = 1;

    // Verifica se o navio cabe no tabuleiro verticalmente
    if (linha_vertical + NAVIO <= TAMANHO) {
        // Verifica se há sobreposição com outro navio
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] == 3) {
                printf("Erro: sobreposição de navios.\n");
                return 1;
            }
        }
        // Posiciona o navio na vertical
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha_vertical + i][coluna_vertical] = 3;
        }
    } else {
        printf("Erro: navio vertical fora dos limites.\n");
        return 1;
    }

    // ------------------ NAVIO DIAGONAL PRINCIPAL ↘ ------------------
    int linha_diag1 = 0;
    int coluna_diag1 = 0;

    // Verifica se o navio diagonal ↘ cabe no tabuleiro
    if (linha_diag1 + NAVIO <= TAMANHO && coluna_diag1 + NAVIO <= TAMANHO) {
        // Verifica sobreposição
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linha_diag1 + i][coluna_diag1 + i] == 3) {
                printf("Erro: sobreposição de navios na diagonal ↘.\n");
                return 1;
            }
        }
        // Posiciona o navio na diagonal principal (↘)
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha_diag1 + i][coluna_diag1 + i] = 3;
        }
    } else {
        printf("Erro: navio diagonal ↘ fora dos limites.\n");
        return 1;
    }

    // ------------------ NAVIO DIAGONAL SECUNDÁRIA ↙ ------------------
    int linha_diag2 = 0;
    int coluna_diag2 = 9;

    // Verifica se o navio diagonal ↙ cabe no tabuleiro
    if (linha_diag2 + NAVIO <= TAMANHO && coluna_diag2 - (NAVIO - 1) >= 0) {
        // Verifica sobreposição
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linha_diag2 + i][coluna_diag2 - i] == 3) {
                printf("Erro: sobreposição de navios na diagonal ↙.\n");
                return 1;
            }
        }
        // Posiciona o navio na diagonal secundária (↙)
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha_diag2 + i][coluna_diag2 - i] = 3;
        }
    } else {
        printf("Erro: navio diagonal ↙ fora dos limites.\n");
        return 1;
    }

    // ------------------ IMPRIMIR TABULEIRO ------------------

    // Exibe o tabuleiro com 0 (água) e 3 (navio)
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
