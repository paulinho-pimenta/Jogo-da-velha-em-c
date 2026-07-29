#include <stdio.h>
#include <stdlib.h>

void limpar_tela(){
    system("cls");
}

void esvaziar_matriz(char matriz[3][3]){
    int i,j;

    for(i = 0; i <= 2; i++){
        for(j = 0; j <= 2; j++){
            matriz[i][j] = ' ';
        }    
    }
}

void preenche_matriz(char matriz[3][3]){
    int i,j,k = 0,verificar = 0;
    char simbolo;

    printf("Escolha o seu simbolo: X ou O\n");
    scanf("%c",&simbolo);

    while(verificar){
        verificar = verifica_matriz;
        limpar_tela();
        printf("Jogada atual: %c\n",simbolo);
        mostrar_matriz(matriz);
        printf("De as coordenadas de onde ira jogar:\n");
        scanf("%d %d",&i,&j);

        if(simbolo == 'X' || simbolo == 'x'){
           matriz[i][j] = simbolo;
           simbolo = 'O';
        }else if(simbolo == 'o' || simbolo == 'O'){
            matriz[i][j] = simbolo;
            simbolo = 'X';
        }else{
            printf("ERRO: jogada invalida ou execucao inesperada\n");
        }
        k++;
    }

}

void mostrar_matriz(char matriz[3][3]){
    int i,j;
    for(i = 0; i <= 2; i++){
        for(j = 0; j <= 2; j++){
            printf(" %c | ",matriz[i][j]);
        }    
        printf("\n");
    }
}

int verifica_matriz(char matriz[3][3]){
    int i,j;

    for(i = 0; i <= 2; i++){
        //horizontal
        if(matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]){
            return 1;
        }

        for(j = 0; j <= 2; j++){
            
        }    
    }
    return 0;
}

int main(){
    char matriz[3][3];

    esvaziar_matriz(matriz);
    preenche_matriz(matriz);
    mostrar_matriz(matriz);
    //verifica_matriz(matriz);

    return 0;
}