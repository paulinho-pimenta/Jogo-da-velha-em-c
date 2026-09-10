#include <stdio.h>
#include <stdlib.h>

void limpar_tela();
void esvaziar_matriz(char matriz[3][3]);
int tabuleiro_cheio(char matriz[3][3]);
char verifica_matriz(char matriz[3][3]);
void preenche_matriz(char matriz[3][3]);
void mostrar_matriz(char matriz[3][3]);
void pausar();

void limpar_tela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void esvaziar_matriz(char matriz[3][3]){
    int i, j;

    for (i = 0; i <= 2; i++){
        for (j = 0; j <= 2; j++){
            matriz[i][j] = ' ';
        }
    }
}

void pausar(){
    while(getchar() != '\n');
    printf("Pressione ENTER para continuar...\n");
    getchar();
}

int tabuleiro_cheio(char matriz[3][3]){
    int i, j;
    for(i = 0; i <= 2; i++)
        for(j = 0; j <= 2; j++)
            if(matriz[i][j] == ' ') return 0;
    return 1;
}

char verifica_matriz(char matriz[3][3]){
    int i;
    for(i = 0; i <= 2; i++){
        //horizontal
        if(matriz[i][0] != ' ' && matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]){
            return matriz[i][0];
        }
        //vertical
        if(matriz[0][i] != ' ' && matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i]){
            return matriz[0][i];
        }
    }
    
    //diagonal secundaria
    if(matriz[0][0] != ' ' && matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]){
        return matriz[0][0];
    }
    //diagonal
    if(matriz[0][2] != ' ' && matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]){
        return matriz[0][2];
    }
    
    return ' ';
}

void preenche_matriz(char matriz[3][3]){
    int i, j, k = 0;
    char simbolo;

    printf("Escolha o seu simbolo: X ou O\n");
    scanf("%c", &simbolo);
    while(simbolo != 'X' && simbolo != 'x' && simbolo != 'O' && simbolo != 'o'){
        printf("Simbolo invalido! Escolha X ou O:\n");
        while(getchar() != '\n'); // limpa o buffer
        scanf("%c", &simbolo);
    }

    while(k != 1){
        limpar_tela();
        printf("Jogada atual: %c\n", simbolo);
        mostrar_matriz(matriz);
        
        //---jogadas---
        printf("De as coordenadas de onde vai jogar:\n");

        //---tratando erros de entrada---
        if(scanf("%d %d", &i, &j) != 2){
            printf("Entrada invalida!\n");
            pausar();
            continue;
        } 
        if(i < 0 || i > 2 || j < 0 || j > 2){
            printf("Coordenadas invalidas! Use valores de 0 a 2.\n");
            pausar();
            continue;
        }
        if(matriz[i][j] != ' '){
            printf("Essa posicao ja esta ocupada!\n");
            pausar();
            continue;
        }     

        limpar_tela();
        
        if(simbolo == 'X' || simbolo == 'x'){
            matriz[i][j] = 'X';  
        }else{
            matriz[i][j] = 'O';
        }       

        //---empate---
        char vencedor = verifica_matriz(matriz);
        if(vencedor != ' '){
            limpar_tela();
            mostrar_matriz(matriz);
            printf("O VENCEDOR EH: %c\n", vencedor);
            k = 1;
        }

        if(k != 1 && tabuleiro_cheio(matriz)){
            limpar_tela();
            mostrar_matriz(matriz);
            printf("EMPATE!\n");
            k = 1;
        }

        //---troca de turno---
        simbolo = (simbolo == 'X' || simbolo == 'x') ? 'O' : 'X';
    }
}

void mostrar_matriz(char matriz[3][3]){
    int i, j;
    for (i = 0; i <= 2; i++){
        for (j = 0; j <= 2; j++){
            printf("%c", matriz[i][j]);
            if (j < 2){
                printf(" | ");
            }
        }
        printf("\n");
    }
}

int main(){
    char matriz[3][3];

    esvaziar_matriz(matriz);
    preenche_matriz(matriz);

    return 0;
}
