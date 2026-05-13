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
// Plansza
void Rysowanie() {
    system("cls");


    for (int i = 0; i < szerokosc + 2; i++) printf("#");
    printf("\n");

    for (int i = 0; i < wysokosc; i++) {
        for (int j = 0; j < szerokosc; j++) {
            if (j == 0) printf("#");

            if (i == y && j == x) {
                printf("O");
            }
            else if (i == owocY && j == owocX) {
                printf("*");
            }
            else {
                // Ogon
                int czyWydrukowanoOgon = 0;
                for (int k = 0; k < dlugoscOgona; k++) {
                    if (ogonX[k] == j && ogonY[k] == i) {
                        printf("o");
                        czyWydrukowanoOgon = 1;
                    }
                }
                if (!czyWydrukowanoOgon) printf(" ");
            }

            if (j == szerokosc - 1) printf("#");
        }
        printf("\n");
    }


    for (int i = 0; i < szerokosc + 2; i++) printf("#");
    printf("\n");
    printf("WYNIK: %d\n", wynik);
}