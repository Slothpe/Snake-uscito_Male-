//
//  Mylib.h
//  Snake
//
//  Created by Perrulli Antonio on 13/01/25.
//
#define MAX 20
#include <stdio.h>

typedef struct{
    
    int x; //Colonne
    int y; //Righe
    
} BODY;

//aggiorno il campo di gioco in base al corpo del serpente
void UpDateGround(BODY [], char[][MAX], int, char);

//imposto il campo di gioco di partenza
void setPlayGround(char*, char*);

//stampo il campo di gioco
void printGround(char[][MAX], int);

void randomPowerUp(char[][MAX], int*, int*);

void UpdateBody(BODY [], int);
