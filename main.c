//
//  main.c
//  Snake1.1
//
//  Created by Perrulli Antonio on 14/01/25.
//
/*
    ISTRUZIONI D'USO:
    Premi il pulsante n per chiudere il gioco;
    I comandi sono w a s d;
    Pian piano che mi vengono in mente li scrivo (Forse);
 
 
 
 */

#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include "Mylib.h"

int main(void)
{
    CORDINATE snake[RIGHE*COLONNE]; /* corpo del serpente, ogni parte del serpente ha delle cordinate x y
                                     che servono per orientare sul array bidimensionale y = riga x = colonna*/
    int powerUp = 1; // ci indica la dimensione attuale del serpente
    char mossa; // mossa inserita dal utente
    char buffer = 's'; //il serpente inzia a muoversi andando verso il basso
    char ground[RIGHE][COLONNE];
    initscr(); //serve per inizializzare il prompt in modalita ncurses
    noecho();//srve per non avere in usscita il buffer di input da parte del utente
    nodelay(stdscr, TRUE);//disattivo il tempo di attesa del input da parte del utente;
    
    int x = 0;
    int y = 0;
    int x_apple = 0;
    int y_apple = 0;
    
    
    RandomPowerUp(&y_apple, &x_apple, ground);
    SetPlayGround(ground, RIGHE, COLONNE);
    snake[0].x = 0;
    snake[0].y = 0;
   
    do {

        mossa = getch();
        if (mossa != ERR)//ERR sarebe che non è stato inserito alcun valore da parte del utente.
        {
            buffer = mossa;
        }
        
        switch (buffer)
        {
            case 'w': // mossa su
    
                x = snake[powerUp].x;
                y = snake[powerUp].y;
                ground[y][x] = ' ';
                snake[0].y = ( snake[0].y <= 0? RIGHE-1 :  snake[0].y-1);
                UpdateBody(snake, powerUp);
                ground[y][x] = ' ';
                if (ground[snake[0].y][snake[0].x] == 'o')
                {
                    mossa = 'n';
                }
               
                break;
                
            case 's':
               
                x = snake[powerUp].x;
                y = snake[powerUp].y;
                snake[0].y = (snake[0].y >= RIGHE-1? 0 :  snake[0].y+1);
                UpdateBody(snake, powerUp);
                ground[y][x] = ' ';
                if (ground[snake[0].y][snake[0].x] == 'o')
                {
                    mossa = 'n';
                }
                
               
                break;
                
            case 'd':
                
                x = snake[powerUp].x;
                y = snake[powerUp].y;
                snake[0].x = ( snake[0].x >= COLONNE-1 ? 0 :  snake[0].x + 1);
                UpdateBody(snake, powerUp);
                ground[y][x] = ' ';
                if (ground[snake[0].y][snake[0].x] == 'o')
                {
                    mossa = 'n';
                }
               
                
                break;
                
            case 'a':
                
                x = snake[powerUp].x;
                y = snake[powerUp].y;
                snake[0].x = (snake[0].x <= 0 ? COLONNE-1 :  snake[0].x - 1);
                UpdateBody(snake, powerUp);
                ground[y][x] = ' ';
                if (ground[snake[0].y][snake[0].x] == 'o')
                {
                    mossa = 'n';
                }
               
                
                break;
                
            default:
                break;
        }
        
        UpgradeGround(ground, snake, powerUp);
        PrintPlayGround(ground, RIGHE, COLONNE);
        if (ground[y_apple][x_apple] == ' ') {
            RandomPowerUp(&y_apple, &x_apple, ground);
            powerUp = powerUp + 1;
        }
        refresh();
        napms(100);
        
    } while (mossa != 'n');
    
    
    getch();
    
    
    endwin();//chiusura del prompt in modalita ncurses
}

