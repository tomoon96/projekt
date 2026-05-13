#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h> // Pauza

// Plansza
int szerokosc = 20, wysokosc = 20;

// Pozycje
int x, y, owocX, owocY, wynik;

// Tablice
int ogonX[100], ogonY[100];
int dlugoscOgona;

// Kierunki
enum Kierunek { STOP = 0, LEWO, PRAWO, GORA, DOL };
enum Kierunek kier;

int koniecGry;

// Ustawia od poczatku
void Start() {
    koniecGry = 0;
    kier = STOP;
    x = szerokosc / 2;
    y = wysokosc / 2;

    srand(time(NULL));
    owocX = rand() % szerokosc;
    owocY = rand() % wysokosc;
    wynik = 0;
    dlugoscOgona = 0;
}
