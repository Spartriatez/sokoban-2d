#include "gra.h"

int gl;
void glos2(int a)
{
    gl=a;
    printf("%d\n",gl);

}
char *lancuch;
int poziom2;
int poz;
void parametr(char *z,int k)
{
    lancuch=z;
    poziom2=k;
}
int aa,bb,cc;
int xxx[300],yyy[300];
void parametr2(char *k,int n)
{
    poziom2=n;
    int a,b,c;
    FILE *plik;
   printf("\n%s\n",k) ;
   plik=fopen(k,"r");
char s[100];
   if(plik==NULL)
    {
        printf("\n nie zaladowano pliku");
        return 0;
    }

int q;
fscanf(plik,"%d %d %d %d",&q,&a,&b,&c);
int x[c];
int y[c];
int i;
for(i=0;i<c;i++)
{
    fscanf(plik,"%d",&x[i]);

}
for(i=0;i<c;i++)
{
    fscanf(plik,"%d",&y[i]);

}
         fclose(plik);
         printf("\n%s\n %d %d %d\n\n",s,a,b,c) ;
         for(i=0;i<c;i++)
         {
             printf("x %d \n y %d\n",x[i],y[i]);
         }
         aa=a;bb=b;cc=c;
         lancuch=s;
         poz=q;
         printf("poz %d aa %d bb %d cc %d\n",poz,aa,bb,cc);
         for(i=0;i<cc;i++)
         {
             xxx[i]=x[i];
             yyy[i]=y[i];
         }
          for(i=0;i<cc;i++)
         {
             xxx[i]=x[i];
             yyy[i]=y[i];
         }
          for(i=0;i<cc;i++)
         {
            printf("xx %d yy %d",xxx[i],yyy[i]);
         }
}

int sprawdz(int x,int y,int ilosc)
{
    int i;
    //printf("tx %d,ty %d \n",t[0].a,t[0].b);
    for(i=0;i<ilosc;i++)
    {
        if((skrzynka[i]->a==x) && (skrzynka[i]->b==y))
        {
            return i;
        }
    }
    return -1;
}
int poziom=0;


void gra()
{
if(gl==1){
    stop_sample(menu);
    play_sample(plansza,255,127,1000,1);}
//printf("\n%s\n",lancuch);
    char *nazw4;
    int restart=1;
    int q=0;

    int i,j;
 FILE *plik;
if(poziom2==1)
{
    poziom=10;
}

if(poziom2==2)
{
   // printf("poz %d",poz);
    poziom=poz;
}
    switch(poziom)
    {
        case 0: nazw4="./plansza/test2.txt";break;
        case 1: nazw4="./plansza/poziom1.txt";break;
        case 2: nazw4="./plansza/poziom2.txt";break;
        case 3: nazw4="./plansza/poziom3.txt";break;
        case 4: nazw4="./plansza/poziom4.txt";break;
        case 5: nazw4="./plansza/poziom5.txt";break;
        case 6: nazw4="./plansza/poziom6.txt";break;
        case 7: nazw4="./plansza/poziom7.txt";break;
        case 8: nazw4="./plansza/poziom8.txt";break;
        case 10: nazw4=lancuch;break;
    }
   plik=fopen(nazw4,"r");

   if(plik==NULL)
    {
        printf("\n nie zaladowano pliku");
        return 0;
    }
while(fgetc(plik)!='9')
{
    q++;
}
q=q/2;
      //  printf("%d\n",q);
// tworzenie tablicy
            int **p;
            p=(int**)malloc(q*sizeof(int*));
            for(i=0;i<q;i++)
            {
                p[i]=(int*)malloc(q*sizeof(int));
            }
// ³adowanie zawartosci z pliku do tablic
    for(i=0;i<q;i++)
    {
            for(j=0;j<q;j++)
            {
                fscanf(plik,"%d",&p[i][j]);
                }
       }
    for(i=0;i<q;i++)
    {
            for(j=0;j<q;j++)
            {
                printf("%d ",p[i][j]);
                }
                printf("\n");
       }
         fclose(plik);
        free(lancuch);
    int obiekt=9;
    int a,b;
    int pom_x;
int pom_y;
int skrzynka_id;
int s_id;
int skx;
int sky;

    int x=0,y=0;
// Tworzenie gry
        int tmpa,tmpb;
        int tmpskx,tmpsky;
        int suma=0;
        int *ilzal;

        int pauza=1;

//while(restart!=0)
//{

        int ilosc=0;
// Wstawianie ruchomych obiektow
 for(i=0;i<q;i++)
        {
            for(j=0;j<q;j++)
            {
                switch(p[i][j]){
              case 3: ilosc++;

                }
            }
        }

skrzynka=(struct skrz_st**)malloc(ilosc*sizeof (struct skrz_st*));

for(i=0;i<ilosc;i++)
{
    skrzynka[i]=(struct skrz_st*)malloc(sizeof (struct skrz_st));

}
int *tabx,*taby;
tabx=(int)malloc(ilosc*sizeof(int));
taby=(int)malloc(ilosc*sizeof(int));
 ilzal=(int*)malloc(ilosc*sizeof(int));
    for(i=0;i<ilosc;i++)
        {
            ilzal[i]=0;
        }
int tmp=0;

if(poziom2==2)
{
    a=aa;
    b=bb;
    for(i=0;i<cc;i++)
    {
        skrzynka[i]->a=xxx[i];
               skrzynka[i]->b=yyy[i];
    }
}else{
       for(i=0;i<q;i++){
        for(j=0;j<q;j++)
        {
            if(p[i][j]==4)
            {
                a=i;
                b=j;
            }
            if(p[i][j]==3)
            {
               skrzynka[tmp]->a=j;
               skrzynka[tmp]->b=i;
               tmp++;
            }

        }
        }
}
       /* for(i=0;i<ilosc;i++)
        {
          printf("skx %d sky %d",skrzynka[i]->a,skrzynka[i]->b);
        }*/
int czypoziom=0;
// Tworzenie gry
   while(obiekt!=0){
        stretch_blit(tlo2,bufor,0,0,tlo2->w,tlo2->h,0,0,SCREEN_W,SCREEN_H);

    tmpa=a;
    tmpb=b;
    tmpskx=skx;
    tmpsky=sky;
    y=0;
    x=0;
     if(key[KEY_ESC]){obiekt=0;poziom=0;}
      if(key[KEY_P]){pauza=0;}
      if(key[KEY_U]){pauza=1;}
      if(key[KEY_R]){obiekt=0;restart=2;}
    if(pauza!=0){
    //while(speed>0){
    if(key[KEY_UP]){y=-1;}
    else if(key[KEY_DOWN]){y=1;}
    else if(key[KEY_LEFT]){x=-1;}
    else if(key[KEY_RIGHT]){x=1;}
    else if(key[KEY_Z]){
            for(i=0;i<ilosc;i++)
            {
               tabx[i]=skrzynka[i]->a;
                taby[i]=skrzynka[i]->b;
            }
            zapis2(nazw4,a,b,tabx,taby,ilosc);
            }
/*speed--;
    }*/

//blit(lista,screen,0,0,600,0,lista->w,lista->h);

     textprintf_ex(bufor,czcionka2,650 +pole1,20+pole2,makecol(255,255,255),-1,"Poziom");
    textprintf_ex(bufor,czcionka2,690+pole1,60+pole2,makecol(255,255,255),-1,"%d",poziom);
    textprintf_ex(bufor,czcionka2,640+pole1,150+pole2,makecol(255,255,255),-1,"Skrzynki:");
    textprintf_ex(bufor,font,650+pole1,300+pole2,makecol(255,255,255),-1,"P-pauza");
    textprintf_ex(bufor,font,650+pole1,310+pole2,makecol(255,255,255),-1,"U-kontynuacja");
    textprintf_ex(bufor,font,650+pole1,320+pole2,makecol(255,255,255),-1,"R-restart");
    textprintf_ex(bufor,font,650+pole1,330+pole2,makecol(255,255,255),-1,"S-zapisz");
    textprintf_ex(bufor,font,650+pole1,340+pole2,makecol(255,255,255),-1,"ESC-wyjscie");
    textprintf_ex(bufor,czcionka2,660+pole1,180+pole2,makecol(255,255,255),-1,"%d / %d",suma,ilosc);
     textprintf_ex(bufor,font,650+pole1,380+pole2,makecol(255,255,255),-1,"STEROWANIE");
    masked_blit(strzalki,bufor,0,0,650+pole1,400+pole2,strzalki->w,strzalki->h);
    for(i=0;i<q;i++){
    for(j=0;j<q;j++)
            {
                switch(p[i][j]){
                case 5: masked_blit(podloga,bufor,0,0,j*pole+25+pole1,i*pole+25+pole2,podloga->w,podloga->h);break;
                case 1: masked_blit(sciana,bufor,0,0,j*pole+25+pole1,i*pole+25+pole2,podloga->w,podloga->h);break;
                case 2: masked_blit(xx,bufor,0,0,j*pole+25+pole1,i*pole+25+pole2,xx->w,xx->h);break;
                case 3: masked_blit(podloga,bufor,0,0,j*pole+25+pole1,i*pole+25+pole2,podloga->w,podloga->h);break;
                case 4: masked_blit(podloga,bufor,0,0,j*pole+25+pole1,i*pole+25+pole2,podloga->w,podloga->h);break;}
            }
        }
    a=a+y;
    b=b+x;

   if(p[a][b]==1 || p[a][b]==0)
    {
        a=tmpa;
        b=tmpb;
    }else{

skrzynka_id=sprawdz(b,a,ilosc);
skx=b+x;
   sky=a+y;
  // printf("skx: %d, sky: %d\n",skx,sky);/*
if(skrzynka_id!=-1)
{
if(p[sky][skx]==1 || p[sky][skx]==0)
{
   skx=tmpskx;
   sky=tmpsky;
    a=tmpa;
    b=tmpb;
}else if(sprawdz(skx,sky,ilosc)!=-1){
    s_id=sprawdz(skx,sky,ilosc);
   skx=tmpskx;
   sky=tmpsky;
    a=tmpa;
    b=tmpb;
    }
    else{
   skrzynka[skrzynka_id]->a=skx;
    skrzynka[skrzynka_id]->b=sky;
     pom_x=skrzynka[skrzynka_id]->a;
        pom_y=skrzynka[skrzynka_id]->b;
   }
}


for(i=0;i<ilosc;i++)
    {
//printf("skx %d sky %d",skrzynka[i]->a,skrzynka[i]->b);
       if(p[skrzynka[i]->b][skrzynka[i]->a]==2)
        {

           masked_blit(ok,bufor,0,0,skrzynka[i]->a*pole+25+pole1,skrzynka[i]->b*pole+25+pole2,ok->w,ok->h);
            ilzal[i]=1;
        }
       else{
        masked_blit(skrzynia,bufor,0,0,skrzynka[i]->a*pole+25+pole1,skrzynka[i]->b*pole+25+pole2,skrzynia->w,skrzynia->h);
            ilzal[i]=0;
        }
    }
//printf("zzzzzzzzzzzz");
    suma=0;
for(i=0;i<ilosc;i++)
{
    suma=suma+ilzal[i];
}
gracz.x=b*pole+25+pole1;
gracz.y=a*pole+25+pole2;

   masked_blit(ludek,bufor,0,0,gracz.x,gracz.y,ludek->w,ludek->h);

if(suma==ilosc)
{
    poziom++;
      if(poziom==9 || poziom==11)
   {
       czypoziom=1;
    obiekt=0;
       poziom2=0;
   }else{
       obiekt=0;
     restart=2;}
}

    rest(100);
    blit(bufor,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    clear_keybuf();
    }
    }
}
if(gl==1){
stop_sample(plansza);
}
if(czypoziom==1)
{
   //stop_sample(plansza);
   if(gl==1){
play_sample(winner,255,127,1000,1);}
while(czypoziom==1){
          stretch_blit(wygrana,bufor,0,0,wygrana->w,wygrana->h,0,0,SCREEN_W,SCREEN_H);

    if(key[KEY_ENTER]){stop_sample(winner);czypoziom=0;}
    blit(bufor,screen,0,0,0,0,SCREEN_W,SCREEN_H);
}
}
if(gl==1){
play_sample(menu,255,127,1000,1);}

for(i=0;i<ilosc;i++){
free(skrzynka[i]);

}
free(skrzynka);

for(i=0;i<q;i++)
{
     free(p[i]);
}
    free(p);

 if(restart==2){
gra();}
aa=0;
bb=0;
cc=0;
poziom=0;
 for(i=0;i<cc;i++)
         {
             xxx[i]=0;
             yyy[i]=0;
         }

}

