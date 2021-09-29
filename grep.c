#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
    char* word;
    char* option;
    int statementLength = 100;
    char currentStatement[statementLength];
    char tempWord[statementLength];

    if(argc == 2){
        option = "\0";
        word = argv[1];
    }else
    if(argc == 3){
        option = argv[1];
        word = argv[2];
    }else{
        printf("try again\n");
        return 1;
    }

    while(!feof(stdin)){
        fgets(currentStatement,statementLength,stdin);
        int length = strlen(currentStatement)-strlen(word);
        for(int i = 0; i <= length; ++i){
            int r = 1;
            memcpy(tempWord,currentStatement+i,strlen(word)*sizeof(char));
            if(strcmp(option,"-i")==0){
                r = strcasecmp(tempWord,word);
            }else{
                r = strcmp(tempWord,word);
            }

            if(r==0){
               printf("%s",currentStatement);
               break;
            } 
        }   
    }
    return 0;
}