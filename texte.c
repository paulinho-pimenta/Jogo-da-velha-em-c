#include <stdio.h>
#include <stdlib.h>

void limpar_tela(){
    system("cls");
}

void esvaziar_matriz(char matriz[3][3]){
    int i, j;

    for (i = 0; i <= 2; i++)
    {
        for (j = 0; j <= 2; j++)
        {
            matriz[i][j] = ' ';
        }
    }
}

int verifica_matriz(char matriz[3][3], char vencedor, int *p_k){
    int i, j;
    for(i = 0; i <= 2; i++){
        if(matriz[i][0] != ' ' || matriz[i][1] != ' ' || matriz[i][2] != ' '){
            if(matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]){
                printf("O vencedor eh %c\n",vencedor); 
                *p_k = 1;     
            }else if(matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i]){
                printf("O vencedor eh %c\n",vencedor); 
                *p_k = 1;  
            }
        }
    }
    
    return 0;
}

void preenche_matriz(char matriz[3][3]){
    int i, j, k = 0;
    char simbolo;

    printf("Escolha o seu simbolo: X ou O\n");
    scanf("%c", &simbolo);

    while(k != 1){
        limpar_tela();
        printf("Jogada atual: %c\n", simbolo);
        mostrar_matriz(matriz);
        
        printf("De as coordenadas de onde vai jogar:\n");
        scanf("%d %d", &i, &j);

        limpar_tela();
        
        if(simbolo == 'X' || simbolo == 'x'){
            matriz[i][j] = 'X';  
        }else if(simbolo == 'o' || simbolo == 'O'){
            matriz[i][j] = 'O';
        }else{
            printf("ERRO: jogada invalida ou execucao inesperada\n");
        }

        verifica_matriz(matriz,simbolo,&k);
        if(simbolo == 'X' || simbolo == 'x'){
            simbolo = 'O';
        }else if(simbolo == 'o' || simbolo == 'O'){
            simbolo = 'X';
        }
        
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
    mostrar_matriz(matriz);

    return 0;
}
