#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define HABILIDADE 5
#define MATRIZ_HAB 5 // Tamanho fixo das matrizes de habilidade

// Função para imprimir o tabuleiro com legenda
void imprimir_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\nLegenda: 0=Água | 3=Navio | 5=Habilidade\n");
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para sobrepor a matriz de habilidade no tabuleiro
void aplicar_habilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[MATRIZ_HAB][MATRIZ_HAB], int origem_linha, int origem_coluna) {
    int meio = MATRIZ_HAB / 2;

    for (int i = 0; i < MATRIZ_HAB; i++) {
        for (int j = 0; j < MATRIZ_HAB; j++) {
            // Verifica se a posição está dentro dos limites do tabuleiro
            int linha_tabuleiro = origem_linha + i - meio;
            int coluna_tabuleiro = origem_coluna + j - meio;

            if (linha_tabuleiro >= 0 && linha_tabuleiro < TAMANHO &&
                coluna_tabuleiro >= 0 && coluna_tabuleiro < TAMANHO) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[linha_tabuleiro][coluna_tabuleiro] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // ------------------ POSICIONAR NAVIOS ------------------
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[2][4 + i] = 3;             // Horizontal
        tabuleiro[5 + i][1] = 3;             // Vertical
        tabuleiro[i][i] = 3;                 // Diagonal ↘
        tabuleiro[i][9 - i] = 3;             // Diagonal ↙
    }

    // ------------------ MATRIZES DE HABILIDADES ------------------

    // Cone (em formato de pirâmide para baixo)
    int cone[MATRIZ_HAB][MATRIZ_HAB] = {0};
    for (int i = 0; i < MATRIZ_HAB; i++) {
        for (int j = 0; j < MATRIZ_HAB; j++) {
            // Cone cresce horizontalmente conforme desce (↘ e ↙)
            if (j >= (MATRIZ_HAB / 2) - i && j <= (MATRIZ_HAB / 2) + i) {
                cone[i][j] = 1;
            }
        }
    }

    // Cruz (linha e coluna central cheias)
    int cruz[MATRIZ_HAB][MATRIZ_HAB] = {0};
    for (int i = 0; i < MATRIZ_HAB; i++) {
        cruz[MATRIZ_HAB / 2][i] = 1;  // Linha do meio
        cruz[i][MATRIZ_HAB / 2] = 1;  // Coluna do meio
    }

    // Octaedro (losango)
    int octaedro[MATRIZ_HAB][MATRIZ_HAB] = {0};
    for (int i = 0; i < MATRIZ_HAB; i++) {
        for (int j = 0; j < MATRIZ_HAB; j++) {
            // Fórmula de losango |i - meio| + |j - meio| <= meio
            if (abs(i - MATRIZ_HAB / 2) + abs(j - MATRIZ_HAB / 2) <= MATRIZ_HAB / 2) {
                octaedro[i][j] = 1;
            }
        }
    }

    // ------------------ APLICAR HABILIDADES NO TABULEIRO ------------------

    aplicar_habilidade(tabuleiro, cone, 1, 2);       // Cone com origem próxima do topo
    aplicar_habilidade(tabuleiro, cruz, 5, 5);       // Cruz no centro
    aplicar_habilidade(tabuleiro, octaedro, 8, 8);   // Octaedro no canto inferior

    // ------------------ EXIBIR TABULEIRO ------------------

    imprimir_tabuleiro(tabuleiro);

    return 0;
}
