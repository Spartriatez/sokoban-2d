#ifndef wczytanie_h
#define wczytanie_h
#include <allegro.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
extern int ScreenWidth,ScreenHeigth,pole1,pole2;
extern int mx,my,mb;
extern BITMAP *bufor;
extern BITMAP *lista;
extern BITMAP *kursor;
extern BITMAP *tlo;
extern FONT *czcionka;
extern FILE *plik;
struct zawartosc{
char nazwa[100];
int i;
};
void katalogi();
void polacz(char *a);
char *wczytywanie();
 char *sprawdz2();
#endif // wczytanie_h
