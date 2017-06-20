#include "edycja.h"
char *dl;
int wart;
void qw(char *x,int g)
{
   dl=x;
   wart=g;
   printf("\ndl %s g %d\n",dl,wart) ;
}

void edycja()
{

   int i,j,ii=0,jj=0,m=22;
    int **tab2;
    tab2=(int**)malloc(m*sizeof(int*));
    for(i=0;i<m;i++)
    {
        tab2[i]=(int*)malloc(m*sizeof(int));
    }
    if(wart==0){
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            tab2[i][j]=0;
        }
    }
    }
    int ppp=0;
    if(wart==1)
    {
      FILE *plikkk;
      plikkk=fopen(dl,"r");
      if(!plikkk)
    {
        printf("\n nie zaladowano pliku");
        return 0;
    }
    while(getc(plikkk)!='9')
    {
        ppp++;
    }
    printf("%d\n",ppp);
      for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++){
               fscanf(plikkk,"%d",&tab2[i][j]);
           }
            }
            for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++){
               printf("%d",tab2[i][j]);
           }
           printf("\n");
            }
            fclose(plikkk);
            free(dl);
    }



    int obiekt=9;
    int x=0,y=0,xxx=0,yyy=0;
    int iloscskrzynek=0,iloscxx=0,ilosckulek=0;
   while(obiekt!=0)
    {
       stretch_blit(tlo2,bufor,0,0,tlo2->w,tlo2->h,0,0,SCREEN_W,SCREEN_H);
        myszka();


        masked_blit(sciana,bufor,0,0,660+pole1,100+pole2,sciana->w,sciana->h);
        textprintf_ex(bufor,font,690+pole1,110+pole2,makecol(255,255,255),-1,"sciana");
        masked_blit(podloga,bufor,0,0,660+pole1,150+pole2,podloga->w,podloga->h);
        textprintf_ex(bufor,font,690+pole1,160+pole2,makecol(255,255,255),-1,"podloga");
        masked_blit(ludek,bufor,0,0,660+pole1,200+pole2,ludek->w,ludek->h);
        textprintf_ex(bufor,font,690+pole1,210+pole2,makecol(255,255,255),-1,"ludek");
        masked_blit(xx,bufor,0,0,660+pole1,250+pole2,xx->w,xx->h);
        textprintf_ex(bufor,font,690+pole1,260+pole2,makecol(255,255,255),-1,"xx");
        masked_blit(skrzynia,bufor,0,0,660+pole1,300+pole2,skrzynia->w,skrzynia->h);
        textprintf_ex(bufor,font,690+pole1,310+pole2,makecol(255,255,255),-1,"skrzynia");
        textprintf_ex(bufor,font,660+pole1,340+pole2,makecol(255,255,255),-1,"myszka x =%d",mx);
        textprintf_ex(bufor,font,660+pole1,360+pole2,makecol(255,255,255),-1,"myszka y= %d",my);
        textprintf_ex(bufor,font,660+pole1,380+pole2,makecol(255,255,255),-1,"myszka b= %d",mb);
        for(i=0;i<=m;i++)
        {
        hline(bufor,25+pole1,i*pole+pole2,575+pole1,makecol(255,255,255));
        vline(bufor,i*pole+pole1,25+pole2,575+pole2,makecol(255,255,255));
        }
        if(mb==2){
        if(mx>650+pole1 && mx<770+pole1 && my>100+pole2 && my<125+pole2)
            {
                obiekt=1;

            }else if(mx>650+pole1 && mx<770+pole1 && my>145+pole2&& my<180+pole2)
            {
                obiekt=5;
            }else if(mx>650+pole2 && mx<770+pole2 && my>295+pole2&& my<330+pole2)
            {
                obiekt=3;
            }else if(mx>650+pole1 && mx<770+pole1 && my>245+pole2&& my<280+pole2)
            {
                obiekt=2;
            }else if(mx>650+pole1 && mx<770+pole1 && my>195+pole2&& my<230+pole2)
            {
                obiekt=4;
            }//else{obiekt=0;}
            }
        switch(obiekt)        {
          case 1:  line(bufor,650+pole1,95+pole2,770+pole1,95+pole2,makecol(255,255,255));
            line(bufor,650+pole1,95+pole2,650+pole1,130+pole2,makecol(255,255,255));
            line(bufor,650+pole1,130+pole2,770+pole1,130+pole2,makecol(255,255,255));
            line(bufor,770+pole1,95+pole2,770+pole1,130+pole2,makecol(255,255,255));
            break;
            case 2:  line(bufor,650+pole1,245+pole2,770+pole1,245+pole2,makecol(255,255,255));
            line(bufor,650+pole1,245+pole2,650+pole1,280+pole2,makecol(255,255,255));
            line(bufor,650+pole1,280+pole2,770+pole1,280+pole2,makecol(255,255,255));
            line(bufor,770+pole1,245+pole2,770+pole1,280+pole2,makecol(255,255,255));
            break;
            case 3:  line(bufor,650+pole1,295+pole2,770+pole1,295+pole2,makecol(255,255,255));
            line(bufor,650+pole1,295+pole2,650+pole1,330+pole2,makecol(255,255,255));
            line(bufor,650+pole1,330+pole2,770+pole1,330+pole2,makecol(255,255,255));
            line(bufor,770+pole1,295+pole2,770+pole1,330+pole2,makecol(255,255,255));
            break;
            case 4:  line(bufor,650+pole1,195+pole2,770+pole1,195+pole2,makecol(255,255,255));
            line(bufor,650+pole1,195+pole2,650+pole1,230+pole2,makecol(255,255,255));
            line(bufor,650+pole1,230+pole2,770+pole1,230+pole2,makecol(255,255,255));
            line(bufor,770+pole1,195+pole2,770+pole1,230+pole2,makecol(255,255,255));
            break;
            case 5:  line(bufor,650+pole1,145+pole2,770+pole1,145+pole2,makecol(255,255,255));
            line(bufor,650+pole1,145+pole2,650+pole1,180+pole2,makecol(255,255,255));
            line(bufor,650+pole1,180+pole2,770+pole1,180+pole2,makecol(255,255,255));
            line(bufor,770+pole1,145+pole2,770+pole1,180+pole2,makecol(255,255,255));
            break;
        }
        if(mb==1){

        if(mx>=25+pole1 && mx<575+pole1)
        {
                 x=mx;
                 if(my>=25+pole2 && my<575+pole2)
        {
                 y=my;
                 xxx=x-x%25;
            yyy=y-y%25;
            ii=(xxx-25-pole1)/25;
            jj=(yyy-25-pole2)/25;
 tab2[jj][ii]=obiekt;
        }
        }
        }
 //tab[jj][ii]=obiekt;
        ilosckulek=0;
        iloscskrzynek=0;
        iloscxx=0;
                for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                switch(tab2[i][j])
                {
                    case 1:masked_blit(sciana,bufor,0,0,j*pole+pole1,i*pole+pole2,sciana->w,sciana->h);break;
                    case 2:masked_blit(xx,bufor,0,0,j*pole+pole1,i*pole+pole2,xx->w,xx->h);iloscxx++;;break;
                    case 3:masked_blit(skrzynia,bufor,0,0,j*pole+pole1,i*pole+pole2,skrzynia->w,skrzynia->h);iloscskrzynek++;break;
                    case 4:masked_blit(ludek,bufor,0,0,j*pole+pole1,i*pole+pole2,ludek->w,ludek->h);ilosckulek++;break;
                    case 5:masked_blit(podloga,bufor,0,0,j*pole+pole1,i*pole+pole2,podloga->w,podloga->h);break;
                }

            }
        }
if(key[KEY_Z]){if(ilosckulek==1 && &iloscskrzynek>0 && iloscxx>0 && iloscskrzynek==iloscxx){zapis(tab2,m);obiekt=0;}}
if(key[KEY_ESC]){obiekt=0;}
if(ilosckulek==1)
        {
            textprintf_ex(bufor,font,640+pole1,530+pole2,makecol(50,255,100),-1,"Ilosc kulek: %d",ilosckulek);
        }else
        {
            textprintf_ex(bufor,font,640+pole1,530+pole2,makecol(255,0,50),-1,"Ilosc kulek: %d.",ilosckulek);
        }
if(iloscskrzynek==iloscxx && iloscskrzynek>0 && iloscxx>0)
{
    textprintf_ex(bufor,font,640+pole1,550+pole2,makecol(50,255,100),-1,"Ilosc skrzynek: %d",iloscskrzynek);
    textprintf_ex(bufor,font,640+pole1,560+pole2,makecol(50,255,100),-1,"=");
    textprintf_ex(bufor,font,640+pole1,570+pole2,makecol(50,255,100),-1,"Ilosc pola 'X': %d",iloscxx);
}else{
    textprintf_ex(bufor,font,640+pole1,550+pole2,makecol(255,0,50),-1,"Ilosc skrzynek: %d",iloscskrzynek);
    textprintf_ex(bufor,font,640+pole1,560+pole2,makecol(255,0,50),-1,"=");
    textprintf_ex(bufor,font,640+pole1,570+pole2,makecol(255,0,50),-1,"Ilosc pola 'X': %d",iloscxx);
}
          textprintf_ex(bufor,font,635+pole1,25+pole2,makecol(255,255,255),-1,"prawy przycisk myszy");
          textprintf_ex(bufor,font,635+pole1,35+pole2,makecol(255,255,255),-1,"- wybor obiektu");
          textprintf_ex(bufor,font,635+pole1,50+pole2,makecol(255,255,255),-1,"lewy przycisk myszy");
          textprintf_ex(bufor,font,635+pole1,60+pole2,makecol(255,255,255),-1,"- wybor pola ");
        //textprintf_ex(bufor,font,660,360,makecol(255,255,255),-1,"myszka y= %d");

        textprintf_ex(bufor,font,660+pole1,400+pole2,makecol(255,255,255),-1,"x =%d",x);
        textprintf_ex(bufor,font,660+pole1,420+pole2,makecol(255,255,255),-1,"y= %d",y);
        textprintf_ex(bufor,font,660+pole1,440+pole2,makecol(255,255,255),-1,"x2 =%d",xxx);
        textprintf_ex(bufor,font,660+pole1,460+pole2,makecol(255,255,255),-1,"y2= %d",yyy);
        textprintf_ex(bufor,font,660+pole1,480+pole2,makecol(255,255,255),-1,"i = %d",ii);
        textprintf_ex(bufor,font,660+pole1,500+pole2,makecol(255,255,255),-1,"j= %d",jj);
        draw_sprite(bufor,kursor,mx,my);
        blit(bufor,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        clear_keybuf();
    }
 for(i=0;i<m;i++)
    {
        free(tab2[i]);
    }
    free(tab2);
}
