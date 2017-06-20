#ifndef gra_h
#define gra_h

#include <allegro.h>
#include <stdio.h>
#define pole 25
extern BITMAP *sciana;
extern BITMAP *bufor;
extern  BITMAP *podloga;
extern  BITMAP *xx;
extern  BITMAP *tlo2;
extern  BITMAP *ludek;
 extern BITMAP *skrzynia;
extern BITMAP *ok;
extern BITMAP *lista;
extern BITMAP *strzalki;
extern FONT *czcionka2;
extern BITMAP *wygrana;
extern FILE *plik;
 extern SAMPLE *menu;
extern SAMPLE *plansza;
extern SAMPLE *winner;
extern int ScreenWidth,ScreenHeigth,pole1,pole2;
struct gracz_st
{
int x,y;
}gracz;
void glos2(int a);
struct skrz_st{
    int a,b;

};
 struct skrz_st **skrzynka;
int sprawdz(int x,int y,int ilosc);
void parametr(char *z,int k);
void gra();
void parametr2(char *k,int n);
//void plikix2(char *poz, int graczx, int graczy, int *tabx,int *taby,int ilosc2,char *m);
//void lacz2(char *poz, int graczx, int graczy, int *tabx,int *taby,int ilosc2);
//void zapis2(char *poz,int graczx,int graczy,int *tabx,int *taby,int ilosc2);
#endif // gra_h
