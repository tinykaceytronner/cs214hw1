#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
    int tempCount = 1;
    char currentWord[100];
    char tempWord[100];
    int counts[100];
    for(int i = 0; i<100; i++){
        counts[i]=0;
    }
    char words[100][100];
    int countOfCounts = -1;
    

    while(!feof(stdin)){
        fgets(currentWord,sizeof(currentWord),stdin);

        if(strcmp(tempWord,currentWord)==0){
            tempCount++;
        }else{
            if(countOfCounts>=0){
            strcpy(words[countOfCounts],tempWord);
            counts[countOfCounts]=tempCount;
            }
            strcpy(tempWord,currentWord);
            countOfCounts++;
            tempCount = 1;
        }
    }
    for(int i = 0;i < countOfCounts;i++){
        printf("%d %s",counts[i],words[i]);
    }
    printf("%d %s",tempCount-1,tempWord);

    return 0;
}