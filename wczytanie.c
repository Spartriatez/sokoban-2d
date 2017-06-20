#include "wczytanie.h"
#include <dirent.h>

DIR *folder;
FILE *plik3;
char *nazw3;
char *nazw;
//struct zawartosc **tab;
struct zawartosc tab[32];
char calosc2[100];
char d[100];
char ostat[100];
void polacz(char *a)
{
    int i;
    char *b="./mapa/";
    char *c=".txt";
    int il1=strlen(a);
int qs=0;
    for(i=0;i<il1;i++)
    {
        if(a[i]=='.')
        {
            break;
        }else{d[i]=a[i];qs++;}

            }
    int il3=strlen(c);
   // printf("%d",)
    int il2=strlen(b);
   int dodaj=qs+il2+il3;
       char okr[dodaj];
// calosc=(char*)malloc(dodaj*sizeof(char));
    printf("il %d ilo2 %d",il1,il2);
for(i=0;i<dodaj;i++)
    {
        if(i<il2)
        {
            calosc2[i]=b[i];
        }else if(i<il2+qs)
        {
          calosc2[i]=d[i-il2];
        }else if(i<dodaj)
        {
            calosc2[i]=c[i-il2-qs];
        }

    }
    int kasuj=strlen(calosc2);
for(i=0;i<kasuj;i++)
    {
        if(i<dodaj){
    ostat[i]=calosc2[i];}
    else
    {
        ostat[i]=0;
    }
    }



    printf("nazwx %s calosc %s, okr %s\n",ostat,calosc2,okr);

}

int stala=0,wa;
void dodaj(char *z)
{
     wa=strlen(z);
      int l;
   if(stala<32){
    for(l=0;l<wa;l++)
    {
       if(stala>1 && z[l]!='.' ){
        tab[stala-2].nazwa[l]=z[l];
      //  printf("%c",tab[stala].nazwa);
       }
    }
    stala++;
    }else{ set_gfx_mode(GFX_TEXT,0,0,0,0);
    allegro_message("Przekroczono limit");allegro_exit();}
     printf("%s\n",z);
    }
void katalogi()
{
   DIR* katalog = opendir( "./mapa" );

  if (katalog == NULL) {

    int kod_bledu=errno;
    perror( "próba otwarcia katalogu" );
    fprintf(stderr, "b³¹d (kod %d): \"%s\" (%s : %d)\n", kod_bledu, strerror(kod_bledu), __FILE__, __LINE__);
    exit (1);
  } char *n;

  //printf("typ\tnazwa\n");
  struct dirent* pozycja = 0; // tworzymy strukturê odpowiedzialn¹ za przechowywanie informacji o pozycji katalogu
  while (pozycja = readdir(katalog)) {
//printf("%s\n", pozycja->d_name);
n=pozycja->d_name;
dodaj(n);
printf("%s\n",n);

    //tab[stala].nazwa=pozycja->d_name;
//stala++;
        }

  closedir(katalog); // zamkniêcie katalogu
  int i;
  for(i=0;i<stala;i++)
  {
      printf("%s\n", tab[i].nazwa);
  }
printf("ilosc kat %d ",stala);
}
int ile=0;
char *wczytywanie()
{
    int potab=0;
    int i;
    int cof=0;

 katalogi();
   //ile++; }

    BITMAP *lista;
    lista=create_bitmap(500,302);
    if(!lista)
    {
       set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("nie zaladowano bufora");
        allegro_exit();
        return 0;
    }
     int obiekt=9;
    while(obiekt!=0){
        clear_to_color(lista,makecol(0,0,0));
     stretch_blit(tlo,bufor,0,0,tlo->w,tlo->h,0,0,SCREEN_W,SCREEN_H);
    set_mouse_speed(200,200);
    myszka();


    textprintf_ex(bufor,czcionka,300+pole1,520+pole2,makecol(255,255,255),-1,"COFNIJ");
    textprintf_ex(bufor,font,50+pole1,190+pole2,makecol(255,217,77),-1,"UWAGA!!!MOZESZ ODCZYTAC MAKSYMWALNIE DO 30 PLIKOW. KOLEJNE PLIKI NIE BEDA UWZGLEDNIONE");
    textprintf_ex(bufor,font,130+pole1,200+pole2,makecol(255,217,77),-1,"STRZALKA W GORE- O 1 PLIK DO GORY, STRZALKA W DOL- O 1 PLIK W DOL, ");
    textprintf_ex(bufor,font,200+pole1,210+pole2,makecol(255,217,77),-1,"KLAWISZ ESC-POWROT DO MENU, KLAWISZ ENTER-LADOWANIE ZAWARTOSCI");
    for(i=0;i<stala;i++)

{
      textprintf_ex(lista,font,10,i*10+2,makecol(255,255,255),"%s",tab[i].nazwa);
      tab[i].i=i;
}
    if(key[KEY_UP]){potab--;}
    if(key[KEY_DOWN]){potab++;}
    if(potab<0){potab=0;}else if(potab>=stala)
    {
        potab=stala-1;
    }
    for(i=0;i<stala;i++)
{
     if(potab==tab[i].i)
      {
          textprintf_ex(lista,font,10,i*10+2,makecol(255,217,77),"%s",tab[i].nazwa);
      }
}

if(key[KEY_ENTER]){obiekt=0;cof=1;}
    if(mb==1){
    if(mx>300+pole1 && mx<510+pole1 && my>520+pole2 && my<570+pole2)
    {
      textprintf_ex(bufor,czcionka,300+pole1,520+pole2,makecol(255,217,77),-1,"COFNIJ");
      obiekt=0;
    }
       }
     if(key[KEY_ESC]){
         obiekt=0;
     }

 masked_blit(lista,bufor,0,0,150+pole1,230+pole2,lista->w,lista->h);

//pliki(nazw);
draw_sprite(bufor,kursor,mx,my);
blit( bufor, screen, 0, 0, 0, 0,SCREEN_W,SCREEN_H );
rest(100);
        clear_keybuf();
}
char *z;
if(cof==1)
{
    nazw=tab[potab].nazwa;polacz(nazw),obiekt=0; z=ostat;printf("\n\n%s\n",z);
}
stala=0;
int j;
for(i=0;i<100;i++)
{
    for(j=0;j<20;j++){
    //tab[i].nazwa[j]=0;
    }
    d[i]=0;
}
return z;
}

