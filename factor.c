#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char** argv){

    if(argc != 2) 
    {
        printf("Run program again with one number\n");
        return 1;
    }
    int n = atoi(argv[1]);

    bool running = true;
    while(running){
        running = false;
        for(int i = 2; i < n + 1 / 2; ++i){
            if(n % i == 0){
                printf("%d ",i);
                n /= i;
                running = true;
                break;
            }
        }
        if(running == false){
            printf("%d \n", n);
        }
    }

    return 0;

}