//Autorzy Projektu Snake: Łukasz Dudzik i Tomasz Undas

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

// Klawisze
void Klawiatura() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            if (kier != PRAWO) kier = LEWO;
            break;
        case 'd':
            if (kier != LEWO) kier = PRAWO;
            break;
        case 'w':
            if (kier != DOL) kier = GORA;
            break;
        case 's':
            if (kier != GORA) kier = DOL;
            break;
        case 'x':
            koniecGry = 1;
            break;
        }
    }
}

void Logika() {

    int poprzednieX = ogonX[0];
    int poprzednieY = ogonY[0];
    int poprz2X, poprz2Y;
    ogonX[0] = x;
    ogonY[0] = y;

    for (int i = 1; i < dlugoscOgona; i++) {
        poprz2X = ogonX[i];
        poprz2Y = ogonY[i];
        ogonX[i] = poprzednieX;
        ogonY[i] = poprzednieY;
        poprzednieX = poprz2X;
        poprzednieY = poprz2Y;
    }


    switch (kier) {
    case LEWO:  x--; break;
    case PRAWO: x++; break;
    case GORA:  y--; break;
    case DOL:   y++; break;
    default: break;
    }


    if (x >= szerokosc || x < 0 || y >= wysokosc || y < 0) {
        koniecGry = 1;
    }


    for (int i = 0; i < dlugoscOgona; i++) {
        if (ogonX[i] == x && ogonY[i] == y) {
            koniecGry = 1;
        }
    }


    if (x == owocX && y == owocY) {
        wynik += 10;
        owocX = rand() % szerokosc;
        owocY = rand() % wysokosc;
        dlugoscOgona++; // Wąż rośnie
    }
}

int main() {
    Start();

    while (!koniecGry) {
        Rysowanie();
        Klawiatura();
        Logika();
        Sleep(100); // Prędkość gry
    }

    printf("\n KONIEC GRY! Twoj wynik to: %d\n", wynik);
    system("pause"); // Okno konsoli
    return 0;
}