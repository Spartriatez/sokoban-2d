#include "glowa.h"
#include <dirent.h>

DIR *folder2;
FILE *plik4;
char *nazw4;
char *nazwa;
//struct zawartosc **tab;
struct zawartosc2 tab2[32];
char calosc3[100];
char d2[100];
char ostat2[100];
void polacz2(char *a)
{
    int i;
    char *b="./zapis/";
    char *c=".txt";
    int il1=strlen(a);
int qs=0;
    for(i=0;i<il1;i++)
    {
        if(a[i]=='.')
        {
            break;
        }else{d2[i]=a[i];qs++;}

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
            calosc3[i]=b[i];
        }else if(i<il2+qs)
        {
          calosc3[i]=d2[i-il2];
        }else if(i<dodaj)
        {
            calosc3[i]=c[i-il2-qs];
        }

    }
    int kasuj=strlen(calosc3);
for(i=0;i<kasuj;i++)
    {
        if(i<dodaj){
    ostat2[i]=calosc3[i];}
    else
    {
        ostat2[i]=0;
    }
    }



    printf("nazwx %s calosc %s, okr %s\n",ostat2,calosc3,okr);

}

int stala2=0,wa2;
void dodaj2(char *z)
{
     wa2=strlen(z);
      int l;
   if(stala2<32){
    for(l=0;l<wa2;l++)
    {
       if(stala2>1 && z[l]!='.' ){
        tab2[stala2-2].nazwa[l]=z[l];
      //  printf("%c",tab[stala].nazwa);
       }
    }
    stala2++;
    }else{ set_gfx_mode(GFX_TEXT,0,0,0,0);
    allegro_message("Przekroczono limit");allegro_exit();}
     printf("%s\n",z);
    }
void katalogi2()
{
   DIR* katalog = opendir( "./zapis" );

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
dodaj2(n);
printf("%s\n",n);

    //tab[stala].nazwa=pozycja->d_name;
//stala++;
        }

  closedir(katalog); // zamkniêcie katalogu
  int i;
  for(i=0;i<stala2;i++)
  {
      printf("%s\n", tab2[i].nazwa);
  }
printf("ilosc kat %d ",stala2);
}
int ile2=0;
char *wczytywanie2()
{
    int potab=0;
    int i;
    int cof=0;

 katalogi2();
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
    for(i=0;i<stala2;i++)

{
      textprintf_ex(lista,font,10,i*10+2,makecol(255,255,255),"%s",tab2[i].nazwa);
      tab2[i].i=i;
}
    if(key[KEY_UP]){potab--;}
    if(key[KEY_DOWN]){potab++;}
    if(potab<0){potab=0;}else if(potab>=stala2)
    {
        potab=stala2-1;
    }
    for(i=0;i<stala2;i++)
{
     if(potab==tab2[i].i)
      {
          textprintf_ex(lista,font,10,i*10+2,makecol(255,217,77),"%s",tab2[i].nazwa);
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
    nazwa=tab2[potab].nazwa;polacz2(nazwa),obiekt=0; z=ostat2;printf("\n\n%s\n",z);
}
stala2=0;
int j;
for(i=0;i<100;i++)
{
    for(j=0;j<20;j++){
    //tab[i].nazwa[j]=0;
    }
    d2[i]=0;
}
return z;
}


