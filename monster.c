#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printBoard(int boardX,int boardY,int plrX,int plrY,int goalX,int goalY,int monX,int monY){
    for(int i = boardY-1; i > -1; i--){
        for(int j = 0; j < boardX; j++){
            if(plrX == j && plrY == i){
                printf("P ");
            }else if(goalX == j && goalY == i){
                printf("G ");
            }else if(monX == j && monY == i){
                printf("M ");
            }else{
                //printf("(%d, %d) ",j,i);
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char** argv){
    if(argc!=9) {
        printf("You have to enter 8 numbers.");
        return 1;
    }
    int boardX = 0;
    int boardY = 0;
    int plrX = 0;
    int plrY = 0;
    int goalX = 0;
    int goalY = 0;
    int monX = 0;
    int monY = 0;
    int playerMoved = 0;
    char direction[2];
    boardX = atoi(argv[1]);
    boardY = atoi(argv[2]);
    plrX = atoi(argv[3]);
    plrY = atoi(argv[4]);
    goalX = atoi(argv[5]);
    goalY = atoi(argv[6]);
    monX = atoi(argv[7]);
    monY = atoi(argv[8]);

    printBoard(boardX,boardY,plrX,plrY,goalX,goalY,monX,monY);

    while(!feof(stdin)){
        playerMoved = 0;
        strcpy(direction,"A");
        scanf("%s",direction);
        if(!strcmp(direction,"N")){
            if(boardY == plrY+1){
            printf("invalid move\n");
            continue;
            }
            plrY++;
            playerMoved = 1;
        }else if(!strcmp(direction,"E")){
            if(boardX == plrX+1){
            printf("invalid move\n");
            continue;
            }
            plrX++;
            playerMoved = 1;
        }else if(!strcmp(direction,"S")){
            if(0 == plrY){
            printf("invalid move\n");
            continue;
            }
            plrY--;
            playerMoved = 1;
        }else if(!strcmp(direction,"W")){
            if(0 == plrX){
            printf("invalid move\n");
            continue;
            }
            plrX--;
            playerMoved = 1;
        }else{
            printf("invalid move\n");
        }

        if((plrX == goalX) && (plrY == goalY)){
            printf("player wins!");
            break;
        }

        if(playerMoved){
            int diffX = abs(plrX - monX);
            int diffY = abs(plrY - monY);
            if(diffX > diffY){
                if(monX > plrX){
                    printf("monster moves W\n");
                    monX--;
                }else if(monX < plrX){
                    printf("monster moves E\n");
                    monX++;
                }
            }else if(diffX < diffY){
                if(monY > plrY){
                    printf("monster moves S\n");
                    monY--;
                }else if(monY < plrY){
                    printf("monster moves N\n");
                    monY++;
                }
            }else if(diffX == diffY){
                if(monY > plrY){
                    printf("monster moves S\n");
                    monY--;
                }else if(monY < plrY){
                    printf("monster moves N\n");
                    monY++;
                }
            }
        }

        if((monX == plrX) && (monY == plrY)){
            printf("monster wins!");
            break;
        }

        printBoard(boardX,boardY,plrX,plrY,goalX,goalY,monX,monY);

    }

}