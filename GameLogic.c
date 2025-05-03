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

    int igual = 0;

    int repetidosB[5];
    for (int i = 0; i < 5; i++){
        while(1){
        int valorTemporario = (rand()% 15)+1;    //COLUNA B
        igual = 0;
        for (int j=0; j < 5; j++){
            if(valorTemporario == repetidosB[j]){
                igual = 1;
                break;
            }
        }

            if (igual == 0){
                matriz[i][0] = valorTemporario;
                repetidosB[i] = valorTemporario;
                break;

            }
        }
    }

    int repetidosI[5];
    for (int i = 0; i < 5; i++){
        while(1){
        int valorTemporario = (rand()% 15)+16;    //COLUNA I
        igual = 0;
        for (int j=0; j < 5; j++){
            if(valorTemporario == repetidosI[j]){
                igual = 1;
                break;
            }
        }
        
            if (igual == 0){
                matriz[i][1] = valorTemporario;
                repetidosI[i] = valorTemporario;
                break;

            }
        }
    }

    int repetidosN[5];
    for (int i = 0; i < 5; i++){
        if(i == 2){
            matriz[2][2] = 0;
            continue;
        }
        while(1){
            int valorTemporario = (rand()% 15)+31;      //COLUNA N
            igual = 0;
      
        for (int j=0; j < 5; j++){
            if(valorTemporario == repetidosN[j]){
                igual = 1;
                break;
            }
        }
        
            if (igual == 0){
                matriz[i][2] = valorTemporario;
                repetidosN[i] = valorTemporario;
                break;

            }
        }
    }

    int repetidosG[5];
    for (int i = 0; i < 5; i++){
        while(1){
        int valorTemporario = (rand()% 15)+46;    //COLUNA G
        igual = 0;
        for (int j=0; j < 5; j++){
            if(valorTemporario == repetidosG[j]){
                igual = 1;
                break;
            }
        }
        
            if (igual == 0){
                matriz[i][3] = valorTemporario;
                repetidosG[i] = valorTemporario;
                break;

            }
        }
    }

    int repetidosO[5];
    for (int i = 0; i < 5; i++){
        while(1){
        int valorTemporario = (rand()% 15)+61;    //COLUNA O
        igual = 0;
        for (int j=0; j < 5; j++){
            if(valorTemporario == repetidosO[j]){
                igual = 1;
                break;
            }
        }
        
            if (igual == 0){
                matriz[i][4] = valorTemporario;
                repetidosO[i] = valorTemporario;
                break;

            }
        }
    }
}


void printaCartela(int matriz[5][5]){
    printf("\n------------------------------------\n");
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

int condicaoVitoria(int matriz[5][5]){
    
    for(int i=0; i< 5; i++){
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

    
    for(int j=0; j< 5; j++){
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

    int igual = 0;
    int repetidos[75];

    for (int i = 0; i < 75; i++) {
        repetidos[i] = -1;       //evitando lixo de memoria
    }

    int totalSorteada = 0;
    
    while(!condicaoVitoria(matriz)){
        int pedraTemporaria = (rand() % 75) + 1;
        igual = 0;

        for(int k = 0; k < totalSorteada; k++){
            if (pedraTemporaria == repetidos[k]){
                igual = 1;
                break;
            }
        }
            if (igual == 0){
                int pedraSorteada = pedraTemporaria;
                repetidos[totalSorteada] = pedraTemporaria;
                totalSorteada++;
                printf("Pedra sorteada: %d", pedraSorteada); 
            

          for(int i = 0; i < 5; i++){
              for(int j = 0; j < 5; j++){
                  if (matriz[i][j] == pedraSorteada){
                      matriz [i][j] = 0;       
                  }
              }
          }
          printaCartela(matriz); 
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
sorteiaPedra(cartela);

if(condicaoVitoria(cartela)){
    printf("Voce venceu, completou uma quina!!!");
}

return 0;
}

