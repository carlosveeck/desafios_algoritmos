#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int mov_linha[] = {2, 2, -2, -2, 1, 1, -1, -1};
int mov_coluna[] = {1, -1, 1, -1, 2, -2, 2, -2};


int movimento_valido(int linha, int coluna, bool matriz[10][10]){
    return (linha >= 0 && coluna >= 0) && (linha < 10 && coluna < 10) && (matriz[linha][coluna] == true);
}

int backtracking(int linha_atual, int coluna_atual, bool matriz[10][10], int & casas, int & max_casas){
    int linha_target, coluna_target;
    for (int i = 0; i < 8; ++i) {
        linha_target = linha_atual + mov_linha[i];
        coluna_target = coluna_atual + mov_coluna[i];
        if(movimento_valido(linha_target, coluna_target, matriz)){
            matriz[linha_target][coluna_target] = false;
            casas++;
            if (casas > max_casas){
                max_casas = casas;
            }
            backtracking(linha_target, coluna_target, matriz, casas, max_casas);
            casas--;
            matriz[linha_target][coluna_target] = true;


        }
    }
    return max_casas;
}

int main() {

    bool matriz_tabuleiro[10][10];

    int numero_linhas = -1;
    int test_case = 0;


    while (numero_linhas != 0) {
        int posicoes_totais = 0;
        cin >> numero_linhas;

        if (numero_linhas != 0) {
            int skipped, posicoes;

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    matriz_tabuleiro[i][j] = false;
                }
            }
            for (int i = 0; i < numero_linhas; ++i) {
                cin >> skipped >> posicoes;
                posicoes_totais += posicoes;
                for (int j = skipped; j < skipped + posicoes; ++j) {
                    matriz_tabuleiro[i][j] = true;
                }
            }

            matriz_tabuleiro[0][0] = false;
            int resultado_pre = 0;
            int maximo = 0;
            resultado_pre = backtracking(0, 0, matriz_tabuleiro, resultado_pre, maximo);
            test_case++;

            int res = posicoes_totais - resultado_pre - 1;
            if(res == 1){
                printf("Case %d, 1 square can not be reached.", test_case);
            }else{
                printf("Case %d, %d squares can not be reached.", test_case, res);
            }

            cout << "\n";
        }
    }
}



