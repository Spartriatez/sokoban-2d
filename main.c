#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "glowa.h"
#include "gra.h"
#include "edycja.h"
#include "wczytanie.h"
int ScreenWidth=800,ScreenHeigth=600,pole1=0,pole2=0;
 SAMPLE *menu=NULL;
SAMPLE *plansza=NULL;
SAMPLE *winner=NULL;
BITMAP *kursor=NULL;
BITMAP *tlo=NULL;
BITMAP *bufor=NULL;
FONT *czcionka=NULL;
FILE *plik=NULL;
BITMAP *sciana=NULL;
 BITMAP *podloga=NULL;
 BITMAP *xx=NULL;
BITMAP *tlo2=NULL;
 BITMAP *ludek=NULL;
 BITMAP *skrzynia=NULL;
BITMAP *ok=NULL;
BITMAP *lista=NULL;
BITMAP *strzalki=NULL;
FONT *czcionka2=NULL;
BITMAP *wygrana=NULL;
//DIR *dirptr=NULL;
int mx=0,my=0,mb=0;
//volatile long speed=0;
END_OF_FUNCTION(incement_speed);
LOCK_VARIABLE(speed);
LOCK_FUNCTION(increment_speed);
int glos=1;
int poziom23;
void wlacz(int d)
{
    if(d==1)
    {
        play_sample(menu,255,127,1000,1);
    }else
    {
        stop_sample(menu);
    }
}
int main()
{
    char *lancuch;
    char *lancuch2;
    int obiekt;

      allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,ScreenWidth,ScreenHeigth,0,0);
    install_timer();
    install_int_ex(incement_speed, BPS_TO_TIMER(50));
    install_mouse();
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"");
    set_volume(255,255);

    tlo=load_bmp("d3.bmp",default_palette);
     if(!tlo)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("nie zaladowano tla");
        allegro_exit();
        return 0;
    }
    tlo2=load_bmp("d.bmp",default_palette);
     if(!tlo2)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("nie zaladowano tla");
        allegro_exit();
        return 0;
    }
    czcionka = load_font("czcionka.pcx", NULL, NULL);
     if(!czcionka)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("nie zaladowano czcionki");
        allegro_exit();
        return 0;
    }
     bufor=create_bitmap(SCREEN_W,SCREEN_H);
    if(!bufor)
    {
       set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("nie zaladowano bufora");
        allegro_exit();
        return 0;
    }
    kursor=load_bitmap("kursor.bmp",NULL);
    if(!kursor)
    {
       set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("nie zaladowano kursora");
        allegro_exit();
        return 0;
    }
     lista=create_bitmap(200,600);
    if(!lista)
    {
       set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("nie zaladowano listy");
        allegro_exit();
        return 0;
    }
    sciana=load_bmp("mur.bmp",default_palette);
    if(!sciana)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("nie zaladowano sciany");
        allegro_exit();
        return 0;
    }
    wygrana=load_bmp("winner.bmp",default_palette);
    if(!wygrana)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("nie zaladowano sciany");
        allegro_exit();
        return 0;
    }
    xx=load_bmp("X2.bmp",default_palette);
    if(!xx)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("nie zaladowano x");
        allegro_exit();
        return 0;
    }
     podloga=load_bmp("podloga.bmp",default_palette);
    if(!podloga)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("nie zaladowano podlogi");
        allegro_exit();
        return 0;
    }
    ludek=load_bmp("circle.bmp",default_palette);
     if(!ludek)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("nie zaladowano obiektu");
        allegro_exit();
        return 0;
    }
     strzalki=load_bmp("strzalki.bmp",default_palette);
     if(!strzalki)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("nie zaladowano obiektu");
        allegro_exit();
        return 0;
    }
 skrzynia=load_bmp("skrzynka.bmp",default_palette);
     if(!skrzynia)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("nie zaladowano skrzynki");
        allegro_exit();
        return 0;
    }
ok=load_bmp("OK.bmp",default_palette);
     if(!ok)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("nie zaladowano ok");
        allegro_exit();
        return 0;
    }
     czcionka2 = load_font("czcionka2.pcx", NULL, NULL);
     if(!czcionka2)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("nie zaladowano czcionki");
        allegro_exit();
        return 0;
    }
     menu = load_sample("menu.wav");
     if(!menu)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("nie zaladowano dz_menu");
        allegro_exit();
        return 0;
    }
        plansza= load_sample("plansza.wav");
     if(!plansza)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("nie zaladowano dz_plansza");
        allegro_exit();
        return 0;
    }
    winner= load_sample("winner.wav");
     if(!winner)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("nie zaladowano dz_winner");
        allegro_exit();
        return 0;
    }
show_mouse(NULL);
set_mouse_speed(200,200);
unscare_mouse();
/*if(glos==1){
;}*/
/*else
{
    stop_sample(menu);
}*/

wlacz(1);
int poprzednik;
while(!key[KEY_ESC]){
   stretch_blit(tlo,bufor,0,0,tlo->w,tlo->h,0,0,SCREEN_W,SCREEN_H);
    myszka();
    textprintf_ex(bufor,font,20,20,makecol(255,255,255),-1,"mx %d,my %d",mx,my);
     textprintf_ex(bufor,czcionka,250+pole1,220+pole2,makecol(255,255,255),-1,"NOWA GRA");
     textprintf_ex(bufor,czcionka,170+pole1,270+pole2,makecol(255,255,255),-1,"WCZYTANIE GRY");
      textprintf_ex(bufor,czcionka,50+pole1,320+pole2,makecol(255,255,255),-1,"OTWORZ ZAPISANA GRE");
       textprintf_ex(bufor,czcionka,150+pole1,370+pole2,makecol(255,255,255),-1,"EDYTOR PLANSZY");
    textprintf_ex(bufor,czcionka,220+pole1,420+pole2,makecol(255,255,255),-1,"USTAWIENIA");
    textprintf_ex(bufor,czcionka,300+pole1,470+pole2,makecol(255,255,255),-1,"KONIEC");

    while(speed>0){
    obiekt=0;
    if(mb==1){
     if(mx>250+pole1 && mx<570+pole1 && my>220+pole2 && my<265+pole2)
    {
        textprintf_ex(bufor,czcionka,250+pole1,220+pole2,makecol(255,217,77),-1,"NOWA GRA");
        obiekt=1;
    }else  if(mx>170+pole1 && mx<650+pole1 && my>270+pole2 && my<320+pole2)
    {
        textprintf_ex(bufor,czcionka,170+pole1,270+pole2,makecol(255,217,77),-1,"WCZYTANIE GRY");
      obiekt=2;
    }else  if(mx>50+pole1 && mx<750+pole1 && my>320+pole2 && my<370+pole2)
    {
        textprintf_ex(bufor,czcionka,50+pole1,320+pole2,makecol(255,217,77),-1,"OTWORZ ZAPISANA GRE");
        obiekt=3;
    }else  if(mx>150+pole1 && mx<650+pole1 && my>370+pole2 && my<420+pole2)
    {
       textprintf_ex(bufor,czcionka,150+pole1,370+pole2,makecol(255,217,77),-1,"EDYTOR PLANSZY");
       obiekt=4;
    }else  if(mx>220+pole1 && mx<560+pole1 && my>420+pole2 && my<470+pole2)
    {
      textprintf_ex(bufor,czcionka,220+pole1,420+pole2,makecol(255,217,77),-1,"USTAWIENIA");
      obiekt=5;
    }else  if(mx>300+pole1 && mx<510+pole1 && my>470+pole2 && my<540+pole2)
    {
      textprintf_ex(bufor,czcionka,300+pole1,470+pole2,makecol(255,217,77),-1,"KONIEC");
      obiekt=6;
    }
}
speed--;
}

poprzednik=glos;
//glos=glosnosnosc();printf("glos %d\n",glos);
    switch(obiekt)
    {
      case 1: glos2(glos);parametr(lancuch,0);gra();break;

      case 2:glos2(glos); lancuch=wczytywanie();printf("\nlancuch %s",lancuch);parametr(lancuch,1);gra();
      break;
      // ;parametr(lancuch,1) ;gra();break;
    case 3: glos2(glos);lancuch2=wczytywanie2();printf("\nlancuch2 %s",lancuch2);parametr2(lancuch2,2); gra();
    break;
        case 4: edytor();break;
       case 5:ustawienia();glos=glosnosnosc();printf("%d",glos);
       if(glos!=poprzednik){stop_sample(menu);wlacz(glos);
       }
                break;
        case 6:  destroy_bitmap(tlo);
                 destroy_bitmap(bufor);
                allegro_exit();return 0;break;
    }
rest(100);
  masked_blit(kursor,bufor,0,0,mx,my,kursor->w,kursor->h);
   blit(bufor,screen,0,0,0,0,SCREEN_W,SCREEN_H);

}
 remove_int(incement_speed);
    readkey();
stop_sample(menu);

destroy_bitmap(sciana);
destroy_bitmap(skrzynia);
destroy_bitmap(podloga);
destroy_bitmap(xx);
destroy_bitmap(ok);
destroy_bitmap(ludek);
destroy_bitmap(lista);
destroy_bitmap(wygrana);
    destroy_bitmap(tlo);
    destroy_bitmap(bufor);
    allegro_exit();
return 0;

}END_OF_MAIN();
