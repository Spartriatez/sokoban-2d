#include "edycja.h"

FILE *plik;

char nazwx[100];
char znak;
char calosc[100];
void plikix(int **p,int k,char *m)
 {
    plik=fopen(m,"w");
int i,j;

for(i=0;i<=2*k;i++)
        {
           if(i==2*k)
           {
               fprintf(plik,"9");
           }else
           {
               fprintf(plik," ");
           }
       }


    fprintf(plik,"\n");
for(i=0;i<k;i++)
        {
            for(j=0;j<k;j++)
            {
                fprintf(plik,"%d ",p[i][j]);
           }
           fprintf(plik,"\n");
       }
fclose(plik);
free(calosc);
 }

void lacz(int **p,int k)
{
    int i;
    char *b="./mapa/";
    char *c=".txt";

    int il1=strlen(nazwx);
    int il3=strlen(c);
   // printf("%d",)

    int il2=strlen(b);
   int dodaj=il1+il2+il3;
       char okr[dodaj];
// calosc=(char*)malloc(dodaj*sizeof(char));
    printf("il %d ilo2 %d",il1,il2);
for(i=0;i<dodaj;i++)
    {
        if(i<il2)
        {
            calosc[i]=b[i];
        }else if(i<il2+il1)
        {
          calosc[i]=nazwx[i-il2];
        }else
        {
            calosc[i]=c[i-il2-il1];
        }
    }
for(i=0;i<dodaj;i++)
    {
        okr[i]=calosc[i];
    }


    printf("nazwx %s calosc %s, okr %s",nazwx,calosc,okr);
    plikix(p,k,calosc);
}


int rozm=100;
void zapis(int **p,int k){
 int rozm=-1;

    //nazw=(char*)malloc(max*sizeof(char));
       int ilosc=0;
int czy=0;
   int obiekt=9;
while(obiekt!=0)
{
    //clear_to_color(bufor,makecol(0,0,0));
    rectfill(bufor,190,260,410,325,makecol(100,100,100));
if(rozm<-1)
{
    rozm=-1;
}
textprintf_ex(bufor,font,200,275,makecol(255,255,255),-1,"zapisz gre");
hline(bufor,200,295,400,makecol(255,255,255));
hline(bufor,200,315,400,makecol(255,255,255));
vline(bufor,200,295,315,makecol(255,255,255));
vline(bufor,400,295,315,makecol(255,255,255));
textprintf_ex(bufor,font,220,300,makecol(255,255,255),-1,"%s",nazwx);

if(ilosc==1 && znak!=0)
        {
            rozm++;
           nazwx[rozm]=znak;
           printf("%c\n",nazwx[rozm]);
           ilosc=0;
          // czy=1;
        }else if(ilosc==1 && znak==0)
        {
            nazwx[rozm]=znak;
            rozm--;
            printf("\n%c\n",nazwx[rozm]);
            ilosc=0;
        }

        if(key[KEY_A]){znak=97;ilosc=1;}
        if(key[KEY_B]){znak=98;ilosc=1;}
        if(key[KEY_C]){znak=99;ilosc=1;}
        if(key[KEY_D]){znak=100;ilosc=1;}
        if(key[KEY_E]){znak=101;ilosc=1;}
        if(key[KEY_F]){znak=102;ilosc=1;}
        if(key[KEY_G]){znak=103;ilosc=1;}
        if(key[KEY_H]){znak=104;ilosc=1;}
        if(key[KEY_I]){znak=105;ilosc=1;}
        if(key[KEY_J]){znak=106;ilosc=1;}
        if(key[KEY_K]){znak=107;ilosc=1;}
        if(key[KEY_L]){znak=108;ilosc=1;}
        if(key[KEY_M]){znak=109;ilosc=1;}
        if(key[KEY_N]){znak=110;ilosc=1;}
        if(key[KEY_O]){znak=111;ilosc=1;}
        if(key[KEY_P]){znak=112;ilosc=1;}
        if(key[KEY_Q]){znak=113;ilosc=1;}
        if(key[KEY_R]){znak=114;ilosc=1;}
        if(key[KEY_S]){znak=115;ilosc=1;}
        if(key[KEY_T]){znak=116;ilosc=1;}
        if(key[KEY_U]){znak=117;ilosc=1;}
        if(key[KEY_V]){znak=118;ilosc=1;}
        if(key[KEY_W]){znak=119;ilosc=1;}
        if(key[KEY_X]){znak=120;ilosc=1;}
        if(key[KEY_Y]){znak=121;ilosc=1;}
        if(key[KEY_Z]){znak=122;ilosc=1;}
        if(key[KEY_0]){znak=48;ilosc=1;}
        if(key[KEY_1]){znak=49;ilosc=1;}
        if(key[KEY_2]){znak=50;ilosc=1;}
        if(key[KEY_3]){znak=51;ilosc=1;}
        if(key[KEY_4]){znak=52;ilosc=1;}
        if(key[KEY_5]){znak=53;ilosc=1;}
        if(key[KEY_6]){znak=54;ilosc=1;}
        if(key[KEY_7]){znak=55;ilosc=1;}
        if(key[KEY_8]){znak=56;ilosc=1;}
        if(key[KEY_9]){znak=57;ilosc=1;}
                if(key[KEY_STOP]){znak=46;ilosc=1;}
        if(key[KEY_BACKSPACE]){znak=0;ilosc=1;}
   if(key[KEY_ENTER]){czy=1;obiekt=0;}
       printf("%d \n",rozm);
        printf("%c \n",znak);
       if(key[KEY_ESC]){obiekt=0;}
        rest(100);
    blit(bufor,screen,0,0,0,0,bufor->w,bufor->h);
    clear_keybuf();
}
if(czy==1){lacz(p,k);}
int i;
for(i=0;i<100;i++)
{
    calosc[i]=0;
    nazwx[i]=0;
}
//printf("\n\n%s\n",nazw);
//free(nazwx);


}
