#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void inicializaCartela (int matriz[5][5]){

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (i == 2 && j == 2){
                matriz[i][j] = 0;
            }else{
                matriz[i][j] = -1;
            }
        }
    }
}

void preencheCartela(int matriz [5][5]){

    for (int i = 0; i < 5; i++){ 
        matriz[i][0] = (rand()% 15)+1;    //COLUNA B
    }

    for (int i = 0; i < 5; i++){
        matriz[i][1] = (rand()% 15)+ 16;    //COLUNA I
    }

    for (int i = 0; i < 5; i++){
          if(i == 2){
            matriz[2][2] = 0;
        }else{
        matriz[i][2] = (rand()% 15)+ 31;    //COLUNA N
        }
    }

    for (int i = 0; i < 5; i++){
        matriz[i][3] = (rand()% 15)+ 46;    //COLUNA G
    }

    for (int i = 0; i < 5; i++){
        matriz[i][4] = (rand()% 15)+ 61;    //COLUNA O
    }
}

void printaCartela(int matriz[5][5]){
    printf("------------------------------------\n");
    printf(" B\t I\t N\t G\t O\n");
    printf("------------------------------------\n");
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf( " %d\t", matriz[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------------\n");
    printf("\n");
}


void sorteiaPedra(int matriz[5][5]){

    while(!venceu){
      int pedraSorteada = (rand() % 75) + 1;

        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if (matriz[i][j] == pedraSorteada){
                    matriz [i][j] = 0;          
                }
            }
        }
    }
}

int main(){

int cartela[5][5];

srand(time(NULL)); // pra que toda vez que o codigo for rodado, nao faca a criacao dos mesmo numeros aleatórios.

inicializaCartela(cartela);
printaCartela(cartela);
preencheCartela(cartela);
printaCartela(cartela);


return 0;
}

