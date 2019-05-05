#include "types.h"      //necessaria para as variaveis
#include "user.h"       //função para print e chamada do sistema

#define STDOUT 1
#define FILHOS 10
#define TIMER 9999999

int main(){
    int pid, i, x = 0, fim[FILHOS];

    for (i = 0; i < FILHOS; i++){
        if(i <5)
            pid = fork(1);
        else if(i < 7)
            pid = fork(10);
        else
            pid = fork(50);

        if(pid == 0){
            for(i = TIMER; i > 0; i--){ // FOR PARA GASTAR TEMPO
                if(i % 100 == 0) printf(STDOUT,"J");
            }
            exit();
        }
    }

    while(1){
        pid = wait();
        if(pid < 0)break;
        fim[x] = pid;
        x++;
    }

    for(i = 0; i < FILHOS; i++){
        printf(STDOUT,"Filho %d Acabou\n", fim[i] );
    }

    exit();
}