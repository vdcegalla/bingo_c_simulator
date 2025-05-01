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

int condicaoVitora(int matriz[5][5]){
    
    for(int i; i< 5; i++){
    int contador = 0;

    for (int j = 0; j < 5; j++){
        if (matriz[i][j] == 0){            // testa linha 
            contador++;
            }   
        }
        if (contador == 5 ){
            return 1;
        }
    }

    
    for(int j; j< 5; j++){
        int contador = 0;
    
        for (int i = 0; i< 5; i++){
            if (matriz[i][j] == 0){            // testa coluna 
                contador++;
                }   
            }
            if (contador == 5 ){
                return 1;
            }
        }

    if (matriz[0][0] == 0 && matriz[1][1] == 0 && matriz[2][2] == 0 && matriz[3][3] == 0 && matriz[4][4] == 0){
        return 1;                                                           // testa uma digonal
    }

    if (matriz[0][4] == 0 && matriz[1][3] == 0 && matriz[2][2] == 0 && matriz[3][1] == 0 && matriz[4][0] == 0){     
        return 1;                                                          // testa a outra digonal
    }

    return 0;
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

if(condicaoVitora(cartela)){
    printf("Voce venceu, completou uma quina!!!");
}

return 0;
}

