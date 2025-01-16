
#include <stdio.h>
#include "Mylib.h"
#include <ncurses.h>
/*
 #include<unistd.h> Includi questa libreria se vuoi rendere il gioco in loop in modo automatico
 sleep(10); // per inserire un delay, essendo che quando va in loop è troppo veloce
 */



int main(void)
{

    initscr();
    char ground [MAX][MAX];
    BODY snake[MAX*MAX];
    int powerUp = 0;
    char mossa;
    int x_body = 0;
    int y_body = 0;
    int x;
    int y;
    
    randomPowerUp(ground, &x, &y);
    
    setPlayGround(&ground[0][0], &ground[MAX-1][MAX-1]);
    
    
    do {
        printGround(ground,MAX);
        scanf("%c",&mossa);
        noecho();
        
        
       
        switch (mossa)
        {
            case 's':
               
                x_body = snake[powerUp].x;
                y_body = snake[powerUp].y;
                UpdateBody(snake, powerUp);
                ground[y_body][x_body] = ' ';
                snake[0].y =(snake[0].y > MAX-1? 0: snake[0].y+1);
                if (ground[snake[0].y][snake[0].x] == 'o')
                {
                    mossa = 'n';
                }
                
                
                break;
                
            case 'w':
               
                x_body = snake[powerUp].x;
                y_body = snake[powerUp].y;
                UpdateBody(snake, powerUp);
                ground[y_body][x_body] = ' ';
                snake[0].y = (snake[0].y < 0? MAX-1 : snake[0].y-1);
                if (ground[snake[0].y][snake[0].x] == 'o')
                {
                    mossa = 'n';
                }
                break;
                
            case 'd':
                
                x_body = snake[powerUp].x;
                y_body = snake[powerUp].y;
                UpdateBody(snake, powerUp);
                ground[y_body][x_body] = ' ';
                snake[0].x = (snake[0].x > MAX-1 ? 0 :  snake[0].x+1);
                if (ground[snake[0].y][snake[0].x] == 'o')
                {
                    mossa = 'n';
                }
                break;
                
            case 'a':
                
                
                x_body = snake[powerUp].x;
                y_body = snake[powerUp].y;
                UpdateBody(snake, powerUp);
                ground[y_body][x_body] = ' ';
                snake[0].x = (snake[0].x < 0 ? MAX-1 :  snake[0].x-1);
                if (ground[snake[0].y][snake[0].x] == 'o')
                {
                    mossa = 'n';
                }
                break;
            default:
                
                puts("");
                break;
        }
        
        if (ground[y][x] == ' ')
        {
            randomPowerUp(ground, &x, &y);
            powerUp = powerUp + 1;
        }
        
        if (powerUp == MAX*MAX-1)
        {
            printf("HAI VINTO\n");
            mossa = 'n';
        }
       // printf("Punti: %d\n",powerUp);
        UpDateGround(snake, ground, powerUp,'o');
       clear();
       refresh();
    } while (mossa != 'n');
    
    endwin();
    return 0;
}
