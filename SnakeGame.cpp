#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


int main() {
    int sizeR = 20, sizeC = 40;
    int xPos = 10, yPos = 10;
    int xFruit, yFruit;
    char map[sizeR][sizeC];
    int length = 1;
    int snakeX[100], snakeY[100];



    xFruit = rand() % (sizeC - 2) + 1;
    yFruit = rand() % (sizeR - 2) + 1;

    srand(time(NULL));
    for (int i = 0; i < sizeR; i++) {
        for (int j = 0; j < sizeC; j++) {
            if (i == 0 || j == 0 || i == sizeR - 1 || j == sizeC - 1) {
                map[i][j] = '*';
            } else {
                map[i][j] = ' ';
            }
        }
    }

    map[yPos][xPos] = 'O';
    snakeX[0] = xPos;
    snakeY[0] = yPos;

    char command;
    while(true){
        system("cls");
        for(int i=0;i<sizeR;i++){
            for(int j=0;j<sizeC;j++){
                printf("%c", map[i][j]);
            }
            printf("\n");
        }

        if(_kbhit()){
            command = _getch();
        }


        switch(command){
            case 'w': yPos--; break;
            case 'a': xPos--; break;
            case 's': yPos++; break;
            case 'd': xPos++; break;
        }

        if (xPos <= 0 || xPos >= sizeC - 1 || yPos <= 0 || yPos >= sizeR - 1) {
            printf("Game Over!\n");
            break;
        }







        if(xPos == xFruit && yPos == yFruit){
            length++;
            xFruit=rand()%(sizeC -2)+1;
            yFruit=rand()%(sizeR -2)+1;
        }
		
		else{
            map[snakeY[length-1]][snakeX[length-1]]=' ';
        }

        for(int i=length;i>0;i--){
            snakeX[i]=snakeX[i-1];
		            snakeY[i]=snakeY[i-1];


        }
       snakeX[0]=xPos;
        snakeY[0]=yPos;

        map[yPos][xPos]='O';
        for(int i =1;i<length;i++) {
            map[snakeY[i]][snakeX[i]]='o';
        }

        map[yFruit][xFruit]='X';
    }

    return 0;
}

