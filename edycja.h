#ifndef edycja_h
#define edycja_h
#include <allegro.h>
#include <stdio.h>
#define pole 25+25
extern BITMAP *sciana;
extern BITMAP *bufor;
extern  BITMAP *podloga;
extern  BITMAP *xx;
extern  BITMAP *tlo2;
extern  BITMAP *ludek;
 extern BITMAP *skrzynia;
extern BITMAP *ok;
extern BITMAP *lista;
extern BITMAP *kursor;
extern FONT *czcionka2;
extern FILE *plik;
extern int ScreenWidth,ScreenHeigth,pole1,pole2;
extern int mx,my,mb;
void qw(char *x,int g);
void plikix(int **p,int k,char *m);
void lacz(int **p,int k);
void zapis(int **p,int k);
void edycja();
#endif // edycja_h
