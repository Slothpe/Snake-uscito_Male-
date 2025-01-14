
#include <stdio.h>
#include "Mylib.h"


int main(void)
{

    char ground [MAX][MAX];
    BODY snake[10];
    int powerUp = 0;
    char mossa;
    char buffer = 'z';
    int x;
    int y;
    
    randomPowerUp(ground, &x, &y);
    
    setPlayGround(&ground[0][0], &ground[MAX-1][MAX-1]);
    
    
    do {
        printGround(ground,MAX);
        scanf("%c",&mossa);
        
       
        switch (mossa)
        {
            case 's':
              
                UpdateBody(snake, powerUp);
                
                if (buffer == 'd')
                {
                    ground[snake[powerUp].y][snake[powerUp].x-1] = ' ';
                }else if (buffer == 'a')
                {
                    ground[snake[powerUp].y][snake[powerUp].x+1] = ' ';
                }
                
                ground[snake[powerUp].y-1][snake[powerUp].x] = ' ';
                snake[0].y =(snake[0].y > MAX-1? 0: snake[0].y+1);
                
                
                
                break;
                
            case 'w':
                
                UpdateBody(snake, powerUp);
                
                
                ground[snake[powerUp].y+1][snake[powerUp].x] = ' ';
                snake[0].y = (snake[0].y < 0? MAX-1 : snake[0].y-1);
                
                break;
                
            case 'd':
                
                UpdateBody(snake, powerUp);
                
                if (buffer == 'w')
                {
                    ground[snake[powerUp].y+1][snake[powerUp].x] = ' ';
                }else if (buffer == 's')
                {
                    ground[snake[powerUp].y-1][snake[powerUp].x] = ' ';
                }
                
                ground[snake[powerUp].y][snake[powerUp].x-1] = ' ';
                snake[0].x = (snake[0].x > MAX-1 ? 0 :  snake[0].x+1);
                
                break;
                
            case 'a':
                
                UpdateBody(snake, powerUp);
                ground[snake[powerUp].y][snake[powerUp].x+1] = ' ';
                snake[0].x = (snake[0].x < 0 ? MAX-1 :  snake[0].x-1);
                
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
                
        UpDateGround(snake, ground, powerUp,'x');
        buffer = mossa;
    } while (mossa != 'n');
    
   
    return 0;
}
