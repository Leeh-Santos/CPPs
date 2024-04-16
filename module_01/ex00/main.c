#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(){
    char *teste = strdup("leandrooo");

    int pid = fork();

    if (!pid){
        teste[0] = 'P';
    }
    printf("%p ||||| %s\n", teste, teste);
}