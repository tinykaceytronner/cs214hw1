#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n){
    int i,j,min_idx;
    for(i=0;i < n-1;i++){

        min_idx = i;
        for(j = i + 1; j < n; j++)
            if(arr[j] < arr[min_idx])
                min_idx = j;
                swap(&arr[min_idx],&arr[i]);
    }
}

int main(int argc, char** argv){
    char* option;

    if(argc == 1){
        option = "-l";
    }else
    if(argc == 2){
        option = argv[1];
        if(strcmp(option,"-n") != 0){
            printf("%s is not a valid sort option.\n",option);
            return 1;
        }
    }else{
        printf("try again\n");
        return 1;
    }

    int arrayIndex = 0;

    char tempWord[100];
    char wordArray[100][100];
    
    int intArray[100];

    for(int i = 0; i < 100; i++){
        intArray[i] = 99999999;
    }

    while(!feof(stdin)){
        // reading lexicographical sorting 
        if(strcmp(option,"-l")==0){
            fgets(tempWord,sizeof(tempWord),stdin);
            strcpy(wordArray[arrayIndex],tempWord);
            arrayIndex++;

        }// reading numerical sorting
        else if(strcmp(option,"-n")==0){
            scanf("%d",&intArray[arrayIndex]);
            arrayIndex++;
        }
    }
    arrayIndex--;
    // lexicographical sorting
    if(strcmp(option,"-l")==0){
        //copying to new array of correct size
        char newWordArray[arrayIndex][100];
        for(int i = 0;i < arrayIndex;i++){
            strcpy(newWordArray[i],wordArray[i]);
        }

        //sorting

        char temp[100];

        for (int i = 0; i < (arrayIndex); ++i) {
            for (int j = i + 1; j < (arrayIndex); ++j) {

         // swapping strings if they are not in the lexicographical order
                if (strcasecmp(newWordArray[i], newWordArray[j]) > 0) {
                    strcpy(temp, newWordArray[i]);
                    strcpy(newWordArray[i], newWordArray[j]);
                    strcpy(newWordArray[j], temp);
                }
             }
         }

        //printing
        for(int i = 0;i < arrayIndex;i++){
            printf("%s",newWordArray[i]);
        }

    }// numerical sorting
    else if(strcmp(option,"-n")==0){

        //copying to new array of correct size
        int newIntArray[arrayIndex];
        for(int i=0;i<(arrayIndex);i++){
            newIntArray[i] = intArray[i];
        }

        // sorting
        selectionSort(newIntArray,arrayIndex);

        // printing
        for(int i = 0;i < arrayIndex;i++){
            printf("%d\n",newIntArray[i]);
        }
    }

    return 0;
}