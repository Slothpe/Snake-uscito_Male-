//
//  Mylib.c
//  Snake
//
//  Created by Perrulli Antonio on 13/01/25.
//
#include <stdio.h>
#include "Mylib.h"
#include <time.h>
#include <stdlib.h>


void setPlayGround(char* pt_min, char* pt_max)
{
    
    for (char* i = pt_min; i <= pt_max; i++)
    {
        *i = ' ';
    }
}

void printGround(char playGround[][MAX], int max)
{
    for (int i = 0; i < MAX; i++)
    {
        printf("-");
    }
    puts("");
    
    for (int i = 0; i< max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            if (j == 0)
            {
                printf("|");
            }
            printf("%c",playGround[i][j]);
            if (j == max-1)
            {
                printf("|");
            }
            
        }
        puts(" ");
    }
    for (int i = 0; i < MAX; i++)
    {
        printf("-");
    }
}
void UpDateGround(BODY snake[], char ground[][MAX], int dimensione,char valore)
{
    int x;
    int y;
    //in base alla lunghezza del serpente seganata dalla variabile powerUp del main, associo ogni cordinata un valore che indica il serpente che si muove
    for (int i = 0; i < dimensione; i++)
    {
        x = snake[i].x;
        y = snake[i].y;
        ground[y][x] = valore;
    }
}

void randomPowerUp(char ground[][MAX], int* pt_x, int* pt_y)
{
    srand(time(NULL));
    *pt_x = rand()%MAX-1;
    *pt_y = rand()%MAX-1;
    
    ground[*pt_y][*pt_x] = '@';
}

void UpdateBody(BODY snake[], int dimensione)
{
    
    for (int i = dimensione; i > 0; i--)
    {
        snake[i] = snake[i-1];
    }
    
}
