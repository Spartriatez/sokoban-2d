
#include "glowa.h"
volatile long speed=0;
void incement_speed()
{
    speed++;
}int czywl=1;

int glosnosnosc()
{
    return czywl;
}
void myszka()
{
    if(mx!=mouse_x || my!=mouse_y || mb!=mouse_b)
    {
        mx=mouse_x;
        my=mouse_y;
        mb=mouse_b;
    }
}

void ustawienia()
{
    int ilosc_x;
 int ilosc=0;
int obiekt=9;
while(obiekt!=0)
{
    switch (ilosc)
        {
            case 1:ScreenWidth=800;ScreenHeigth=600;pole1=0;pole2=0;ilosc=0;
              set_gfx_mode(GFX_AUTODETECT_WINDOWED,ScreenWidth,ScreenHeigth,0,0);
              bufor=create_bitmap(ScreenWidth,ScreenHeigth);break;//textprintf_ex(bufor,czcionka,30+pole1,270+pole2,makecol(255,217,77),-1,"800x600");break;
            case 2: ScreenWidth=1024;ScreenHeigth=768;pole1=100;pole2=100;

             set_gfx_mode(GFX_AUTODETECT_FULLSCREEN,ScreenWidth,ScreenHeigth,0,0);
             bufor=create_bitmap(ScreenWidth,ScreenHeigth);
             ilosc=0;break;//textprintf_ex(bufor,czcionka,265+pole1,270+pole2,makecol(255,217,77),-1,"1024x768");break;
            case 3: ScreenWidth=1366;ScreenHeigth=768;pole1=275;pole2=100;
            set_gfx_mode(GFX_AUTODETECT_FULLSCREEN,ScreenWidth,ScreenHeigth,0,0);
            bufor=create_bitmap(ScreenWidth,ScreenHeigth);
           ilosc=0;break;
            //textprintf_ex(bufor,czcionka,530+pole1,270+pole2,makecol(255,217,77),-1,"1366x768");break;
        }
    stretch_blit(tlo,bufor,0,0,tlo->w,tlo->h,0,0,SCREEN_W,SCREEN_H);
    set_mouse_speed(200,200);
    textprintf_ex(bufor,czcionka,50+pole1,220+pole2,makecol(255,255,255),-1,"ROZDZIELCZOSC EKRANU");
    textprintf_ex(bufor,czcionka,30+pole1,270+pole2,makecol(255,255,255),-1,"800x600");
    textprintf_ex(bufor,czcionka,265+pole1,270+pole2,makecol(255,255,255),-1,"1024x768");
     textprintf_ex(bufor,czcionka,530+pole1,270+pole2,makecol(255,255,255),-1,"1366x768");
     textprintf_ex(bufor,czcionka,30+pole1,320+pole2,makecol(255,255,255),-1,"MUZYKA:");
     textprintf_ex(bufor,czcionka,350+pole1,320+pole2,makecol(255,255,255),-1,"WL");
     textprintf_ex(bufor,czcionka,500+pole1,320+pole2,makecol(255,255,255),-1,"WYL");
        textprintf_ex(bufor,czcionka,270+pole1,370+pole2,makecol(255,255,255),-1,"COFNIJ");
        myszka();
        if(mb==1){

      if(mx>30+pole1 && mx<260+pole1 && my>270+pole2 && my<330+pole2)
      {
          ilosc=1;
      }else if(mx>525+pole1 && mx<750+pole1 && my>270+pole2 && my<330+pole2)
      {
          ilosc=3;
      }else if(mx>265+pole1 && mx<525+pole1 && my>270+pole2 && my<330+pole2)
      {
          ilosc=2;
      }

 if(mx>350+pole1 && mx<450+pole1 && my>320+pole2 && my<365+pole2)
      {
          czywl=1;
      }else
    if(mx>500+pole1 && mx<650+pole1 && my>320+pole2 && my<365+pole2)
    {
      czywl=0;
    }
    if(mx>270+pole1 && mx<500+pole1 && my>370+pole2 && my<420+pole2)
    {
      textprintf_ex(bufor,czcionka,270+pole1,370+pole2,makecol(255,217,77),-1,"COFNIJ");
      obiekt=0;
    }
        }
        if(czywl==1)
    {
        textprintf_ex(bufor,czcionka,350+pole1,320+pole2,makecol(255,217,77),-1,"WL");

    }
    else{
        textprintf_ex(bufor,czcionka,500+pole1,320+pole2,makecol(255,217,77),-1,"WYL");
    }
      ilosc_x=SCREEN_W;
      if(ilosc_x==1366)
      {
       textprintf_ex(bufor,czcionka,530+pole1,270+pole2,makecol(255,217,77),-1,"1366x768");
      }else if(ilosc_x==1024)
      {
       textprintf_ex(bufor,czcionka,265+pole1,270+pole2,makecol(255,217,77),-1,"1024x768");
      }else
      {
           textprintf_ex(bufor,czcionka,30+pole1,270+pole2,makecol(255,217,77),-1,"800x600");
      }
      if(key[KEY_ESC]){obiekt=0;}
//printf("%d",ilosc_x);
    draw_sprite(bufor,kursor,mx,my);
blit( bufor, screen, 0, 0, 0, 0,SCREEN_W,SCREEN_H );
rest(100);
        clear_keybuf();
}
}
char *lan;
void edytor()
{
int gdy;
    int obiekt=9;
    while(obiekt!=0){
     stretch_blit(tlo,bufor,0,0,tlo->w,tlo->h,0,0,SCREEN_W,SCREEN_H);
    set_mouse_speed(200,200);
    textprintf_ex(bufor,czcionka,150+pole1,220+pole2,makecol(255,255,255),-1,"TWORZENIE MAPY");
    textprintf_ex(bufor,czcionka,100+pole1,270+pole2,makecol(255,255,255),-1,"WCZYTYWANIE MAPY");
    textprintf_ex(bufor,czcionka,270+pole1,320+pole2,makecol(255,255,255),-1,"COFNIJ");
     myszka();
      if(mb==1){

    if(mx>140+pole1 && mx<670+pole1 && my>220+pole2 && my<270+pole2)
    {
        textprintf_ex(bufor,czcionka,150+pole1,220+pole2,makecol(255,217,77),-1,"TWORZENIE MAPY");
        edycja();
    }else if(mx>90+pole1 && mx<700+pole1 && my>260+pole2 && my<320+pole2)
    {
      textprintf_ex(bufor,czcionka,100+pole1,270+pole2,makecol(255,217,77),-1,"WCZYTYWANIE MAPY");

    lan=wczytywanie();
    printf("\nlan %s\n",lan);
    qw(lan,1);
    edycja();
    }else if(mx>270+pole1 && mx<500+pole1 && my>320+pole2 && my<370+pole2)
    {
      //textprintf_ex(bufor,czcionka,270+pole1,320+pole2,makecol(255,217,77),-1,"COFNIJ");
obiekt=0;
    }
      }
      if(key[KEY_ESC]){ //textprintf_ex(bufor,czcionka,270+pole1,370+pole2,makecol(255,217,77),-1,"COFNIJ");
          obiekt=0;}
draw_sprite(bufor,kursor,mx,my);
blit( bufor, screen, 0, 0, 0, 0,SCREEN_W,SCREEN_H );
rest(100);
        clear_keybuf();
    }
}
