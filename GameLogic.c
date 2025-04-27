
#include <stdio.h>
#include <stdlib.h>

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



int main(){

int cartela [5][5];

inicializaCartela(cartela);


return 0;
}

