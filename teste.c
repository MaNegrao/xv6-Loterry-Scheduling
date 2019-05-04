#include "types.h"      //necessaria para as variaveis
#include "user.h"       //função para print e chamada do sistema

#define STDOUT 1
#define FILHOS 30
#define TIMER 123456

int main(){
    int pid, i, x = 0;

    for (i = 0; i < FILHOS; i++){
        if(i <10)
            pid = fork(1);
        else if(i < 20)
            pid = fork(1);
        else
            pid = fork(1);

        if(pid == 0){
            for(i = TIMER; i > 0; i--){ // FOR PARA GASTAR TEMPO
                if(i % 100 == 0) printf(STDOUT,"");
            }
            exit();
        }
    }

    while(1){
        pid = wait();
        if(pid < 0)break;
        x++;
    }

    exit();
}
