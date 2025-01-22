//
//  Mylib.c
//  Snake1.1
//
//  Created by Perrulli Antonio on 15/01/25.
//

#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "Mylib.h"


void SetPlayGround(char ground[][COLONNE], int righe, int colonne)
{
    
    for (int i = 0; i< righe; i++)
    {
        for (int j = 0; j < colonne; j++) {
            
            ground[i][j] = ' ';
        }
    }
}

void PrintPlayGround(char ground[][COLONNE], int righe, int colonne)
{
    /*
     Siccome stiamo stampando sul prompt dobbiamop ragionare in base alla posizione del cursore.
     Prima di tutto posiziono il curosre alla posziozione x = 0, y = 0;
     successivamente ogni riga del array bidimensionale devo andare a capo e quindi mi basta passare come argomento
     della funzione move x = i e y = 0
     */
    move(0, 0); //funzione che ci permette di modificare la posizone del cursore (ncurses.h)
    
    for (int i = 0; i< righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            addch(ground[i][j]);
        }
        move(i, 0);
    }
}

char CheckCollisione(char ground [][COLONNE], CORDINATE snake, char mossa)
{
    //se non e stato colpito nulla allora non chiudo il programma
    return (ground[snake.y][snake.x] == 'o' ? 'n' : mossa);
    
}

void RandomPowerUp(int* pt_y , int* pt_x , char ground[][COLONNE])
{
    srand(time(NULL));
    
    *pt_x = rand()%COLONNE;
    *pt_y = rand()%RIGHE;
    
    ground[*pt_y][*pt_x] = '@';
}

void UpgradeGround(char ground[][COLONNE], CORDINATE snake[], int powerUp)
{
    int x;
    int y;
    for (int i = 0; i <= powerUp; i++) {
        x = snake[i].x;
        y = snake[i].y;
        
        ground[y][x] = 'o';
    }
}

void UpdateBody(CORDINATE snake[], int dimensione)
{
    
    for (int i = dimensione; i > 0; i--)
    {
        snake[i] = snake[i-1];
    }
    
}
