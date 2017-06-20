#ifndef glowa_h
#define gLowa_h
#include <allegro.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
extern BITMAP *kursor;
extern BITMAP *tlo;
extern BITMAP *bufor;
extern FONT *czcionka;
extern int czywl;
struct zawartosc2{
char nazwa[20];
int i;
};
extern BITMAP *sciana;
 extern BITMAP *podloga;
 extern BITMAP *xx;
extern BITMAP *tlo2;
extern  BITMAP *ludek;
 extern BITMAP *skrzynia;
extern BITMAP *ok;
extern BITMAP *lista;
extern BITMAP *strzalki;
extern FONT *czcionka2;
extern int ScreenWidth,ScreenHeigth,pole1,pole2;
extern volatile long speed;
extern int mx,my,mb;
void incement_speed();
void ustawienia();
void edytor();
void polacz2(char *a);
void dodaj2(char *z);
void katalogi2();
char *wczytywanie2();
int glosnosnosc();
#endif // glowa_h
