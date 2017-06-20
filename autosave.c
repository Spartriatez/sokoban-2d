#include "gra.h"


FILE *plik3;

char nazwx2[100];
char znak2;
char calosc3[100];
void plikix2(int poz, int graczx, int graczy, int *tabx,int *taby,int ilosc2,char *m)
 {
    plik3=fopen(m,"w");
int i,j;
fprintf(plik3,"%d %d %d %d",poz,graczx,graczy,ilosc2);
fprintf(plik3,"\n");
for(i=0;i<ilosc2;i++)
{
    fprintf(plik3,"%d ",tabx[i]);
}
fprintf(plik3,"\n");
for(i=0;i<ilosc2;i++)
{
    fprintf(plik3,"%d ",taby[i]);
}
fclose(plik3);
free(calosc3);
 }

void lacz2(char *poz, int graczx, int graczy, int *tabx,int *taby,int ilosc2)
{
    int i;
  char *b="./zapis/";
    char *c=".txt";

   int il1=strlen(nazwx2);
    int il3=strlen(c);


    int il2=strlen(b);
   int dodaj=il1+il2+il3;
printf("%s",nazwx2);
      char okr[dodaj];
// calosc=(char*)malloc(dodaj*sizeof(char));
    printf("il %d ilo2 %d",il1,il2);
for(i=0;i<dodaj;i++)
    {
        if(i<il2)
        {
            calosc3[i]=b[i];
        }else if(i<il2+il1)
        {
          calosc3[i]=nazwx2[i-il2];
        }else
        {
            calosc3[i]=c[i-il2-il1];
        }
    }
for(i=0;i<dodaj;i++)
    {
        okr[i]=calosc3[i];
    }
//printf("\n\n %s \n\n",nazwx2);

  printf("nazwx %s calosc %s, okr %s",nazwx2,calosc3,okr);
plikix2(poz,graczx,graczy,tabx,taby,ilosc2,calosc3);
}


void zapis2(char *poz, int graczx, int graczy, int *tabx,int *taby,int ilosc2)
{
 int rozm2=-1;
int i;
    //nazw=(char*)malloc(max*sizeof(char));
       int ilosc=0;
int czy=0;
   int obiekt=9;
while(obiekt!=0)
{
    //clear_to_color(bufor,makecol(0,0,0));
    rectfill(bufor,190,260,410,325,makecol(100,100,100));
if(rozm2<0)
{
    rozm2=-1;
}
textprintf_ex(bufor,font,200,275,makecol(255,255,255),-1,"zapisz gre");
hline(bufor,200,295,400,makecol(255,255,255));
hline(bufor,200,315,400,makecol(255,255,255));
vline(bufor,200,295,315,makecol(255,255,255));
vline(bufor,400,295,315,makecol(255,255,255));
textprintf_ex(bufor,font,220,300,makecol(255,255,255),-1,"%s",nazwx2);

if(ilosc==1 && znak2!=0)
        {
            rozm2++;
           nazwx2[rozm2]=znak2;
           printf("%c\n",nazwx2[rozm2]);
           ilosc=0;
          // czy=1;
        }else if(ilosc==1 && znak2==0)
        {
            nazwx2[rozm2]=znak2;
            rozm2--;
            printf("\n%c\n",nazwx2[rozm2]);
            ilosc=0;
        }

        if(key[KEY_A]){znak2=97;ilosc=1;}
        if(key[KEY_B]){znak2=98;ilosc=1;}
        if(key[KEY_C]){znak2=99;ilosc=1;}
        if(key[KEY_D]){znak2=100;ilosc=1;}
        if(key[KEY_E]){znak2=101;ilosc=1;}
        if(key[KEY_F]){znak2=102;ilosc=1;}
        if(key[KEY_G]){znak2=103;ilosc=1;}
        if(key[KEY_H]){znak2=104;ilosc=1;}
        if(key[KEY_I]){znak2=105;ilosc=1;}
        if(key[KEY_J]){znak2=106;ilosc=1;}
        if(key[KEY_K]){znak2=107;ilosc=1;}
        if(key[KEY_L]){znak2=108;ilosc=1;}
        if(key[KEY_M]){znak2=109;ilosc=1;}
        if(key[KEY_N]){znak2=110;ilosc=1;}
        if(key[KEY_O]){znak2=111;ilosc=1;}
        if(key[KEY_P]){znak2=112;ilosc=1;}
        if(key[KEY_Q]){znak2=113;ilosc=1;}
        if(key[KEY_R]){znak2=114;ilosc=1;}
        if(key[KEY_S]){znak2=115;ilosc=1;}
        if(key[KEY_T]){znak2=116;ilosc=1;}
        if(key[KEY_U]){znak2=117;ilosc=1;}
        if(key[KEY_V]){znak2=118;ilosc=1;}
        if(key[KEY_W]){znak2=119;ilosc=1;}
        if(key[KEY_X]){znak2=120;ilosc=1;}
        if(key[KEY_Y]){znak2=121;ilosc=1;}
        if(key[KEY_Z]){znak2=122;ilosc=1;}
        if(key[KEY_0]){znak2=48;ilosc=1;}
        if(key[KEY_1]){znak2=49;ilosc=1;}
        if(key[KEY_2]){znak2=50;ilosc=1;}
        if(key[KEY_3]){znak2=51;ilosc=1;}
        if(key[KEY_4]){znak2=52;ilosc=1;}
        if(key[KEY_5]){znak2=53;ilosc=1;}
        if(key[KEY_6]){znak2=54;ilosc=1;}
        if(key[KEY_7]){znak2=55;ilosc=1;}
        if(key[KEY_8]){znak2=56;ilosc=1;}
        if(key[KEY_9]){znak2=57;ilosc=1;}
                if(key[KEY_STOP]){znak2=46;ilosc=1;}
        if(key[KEY_BACKSPACE]){znak2=0;ilosc=1;}
   if(key[KEY_ENTER]){czy=1;obiekt=0;}
       printf("%d \n",rozm2);
        printf("%c \n",znak2);
       if(key[KEY_ESC]){obiekt=0;}
        rest(100);
    blit(bufor,screen,0,0,0,0,bufor->w,bufor->h);
    clear_keybuf();
}
printf("\n\n%s \n\n",nazwx2);
if(czy==1){lacz2(poz,graczx,graczy,tabx,taby,ilosc2);

    printf("%s %d %d",poz,graczx,graczy);
    for(i=0;i<ilosc2;i++)
    {
        printf("\n%d %d\n",tabx[i],taby[i]);
    }
}
for(i=0;i<100;i++)
{
    calosc3[i]=0;
    //nazwx2[i]=0;
}
//printf("\n\n%s\n",nazw);
//free(nazwx);


}

