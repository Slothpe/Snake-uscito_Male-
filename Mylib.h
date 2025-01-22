//
//  Mylib.h
//  Snake1.1
//
//  Created by Perrulli Antonio on 15/01/25.
//


#define RIGHE 20
#define COLONNE 30
typedef struct{
    
    int x;
    int y;
    
}CORDINATE;


//[y][x] array bidimensionale
//[RIGHE][COLONNE]

//Funzione che serve per settare il campo di gioco la prima volta
void SetPlayGround(char [][COLONNE], int, int);

//funzione per stampare il campo di gioco
void PrintPlayGround(char [][COLONNE], int, int);

// Verifichiamo se stiamo colpendo il corpo del serpente
char CheckCollisione(char [][COLONNE], CORDINATE, char);

//Spawn casuale della mela;
void RandomPowerUp(int* , int* , char[][COLONNE]);

void UpgradeGround(char [][COLONNE], CORDINATE[], int);

void UpdateBody(CORDINATE[], int);
