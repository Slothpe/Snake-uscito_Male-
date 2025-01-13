
#include <stdio.h>
#include "Mylib.h"


int main(void)
{

    char ground [MAX][MAX];
    BODY snake[10];
    int powerUp = 0;
    char mossa;
    
    setPlayGround(&ground[0][0], &ground[MAX-1][MAX-1]);
    
    
    do {
        printGround(ground,MAX);
        scanf("%c",&mossa);
       
        switch (mossa)
        {
            case 's':
              
               
                UpDateGround(snake, ground, powerUp,' ');
                snake[0].y =(snake[0].y > MAX-1? 0: snake[0].y+1);
                
                
                
                break;
                
            case 'w':
                
                UpDateGround(snake, ground, powerUp,' ');
                snake[0].y = (snake[0].y < 0? MAX-1 : snake[0].y-1);
                
                break;
                
            case 'd':
                
                UpDateGround(snake, ground, powerUp,' ');
                snake[0].x = (snake[0].x > MAX-1 ? 0 :  snake[0].x+1);
                
                break;
                
            case 'a':
                
                UpDateGround(snake, ground, powerUp,' ');
                snake[0].x = (snake[0].x < 0 ? MAX-1 :  snake[0].x-1);
                
                break;
            default:
                
                puts("");
                break;
        }
                
        UpDateGround(snake, ground, powerUp,'x');
    } while (mossa != 'n');
    
    return 0;
}
