#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

struct segment{                                                         //pojedynczy segment listy
    char znak;
    struct segment *nastepny;
    struct segment *poprzedni;
};

segment *dodaj_segment(struct segment *actual) {                            //dodanie wezla
    segment *nowy = new segment;
    segment *tmp;
    nowy->znak='.';
    tmp=actual->poprzedni;
    tmp->nastepny=nowy;
    actual->poprzedni=nowy;
    nowy->nastepny=actual;
    nowy->poprzedni=tmp;
    actual=nowy;
    return actual;
}

segment *usun_segment (struct segment *actual) {                        //argumentem jest wskaznik i zwracany tez jest wskaznik
    if(actual==actual->nastepny){
        delete actual;
        cout<<"Zegnaj okrutny swiecie";
    }
    else {
        segment *tmp;
        segment *prev;

        tmp=actual;
        actual=actual->nastepny;
        prev=tmp->poprzedni;
        actual->poprzedni=prev;
        prev->nastepny=actual;
        delete tmp;
    }
    return actual;
}

void mapa(char znak, char **pole, int *wsk,int wiersze, int kolumny) {

    int stop= *wsk;                                         //wsk[0]=stop;
    int i,j;
    wsk++;
    i = *wsk;
    wsk++;                                                         //wsk[1]=i;
    j= *wsk;                                                        //wsk[2]=j;
    wsk++;                          // wsk ustawiony na last
    switch (znak) {                                               //--aktualizacja pozycji na mapie
    case 'g':
        if (i>0){
            if(pole[i-1][j]!='T'){
                i--;
                stop=0;
                *wsk=1;
            }
        }
        break;
    case 'd':
        if ((i+1)<wiersze){
            if(pole[i+1][j]!='T'){
                i++;
                stop=0;
                *wsk=0;
            }
        }
        break;
    case 'l':
        if (j>0){
            if(pole[i][j-1]!='T'){
                j--;
                stop=0;
                *wsk=3;
            }
        }
        break;
    case 'p':
        if ((j+1)<kolumny){
            if(pole[i][j+1]!='T'){
                j++;
                stop=0;
                *wsk=2;

            }
        }
        break;
    }
    wsk--;
    *wsk=j;
    wsk--;
    *wsk=i;
    wsk--;
    *wsk=stop;

}

segment *edek(segment *aktualny, char **znak1, int i, int j,int last){
                                                                        //last 0 = i+ , 1=i-, 2=j+, 3=j-;
    aktualny=aktualny->nastepny;
    switch(znak1[i][j]){
    case '.':
        if(aktualny->znak!='.'){
            znak1[i][j]=aktualny->znak;
        }
        break;
    case 'G':
        znak1[i][j]='.';
        aktualny=dodaj_segment(aktualny);
        break;
    case 'K':
        if (aktualny==aktualny->nastepny){
            cout<<"Zegnaj okrutny swiecie!"<<endl;
            delete aktualny;
            aktualny=NULL;
            if (last==0) i--;
            if (last==1) i++;
            if (last==2) j--;
            if (last==3) j++;
            cout<<j<<" "<<i<<endl;
        }
        else aktualny=usun_segment(aktualny);
        break;
    default:        //a-z
        aktualny->znak=znak1[i][j];
        break;
    }
return aktualny;
}


int main()
{
    int kolumny, wiersze, segmenty;
    char bufor[7], znak;
    cin>>kolumny>>wiersze>>segmenty;

    //-----------------------------------------------------------utworzenie Edka
    segment *aktualny = new segment;                            //tworzenie 1-wszego segmentu
    aktualny->znak='.';
    aktualny->nastepny=aktualny;
    aktualny->poprzedni=aktualny;
    for (int a=0; a<segmenty-1; a++) aktualny=dodaj_segment(aktualny);

    //-----------------------------------------------------------odczyt mapy
    int status=0;                                               // status >0 oznacza aby nie czytaæ kolejnych znakow tylko wypelnic mape char znak
    char **tab2;
    tab2 =new char *[wiersze];
    for(int i = 0; i<wiersze; i++) {
        tab2[i] =new char[kolumny];
        for (int j=0; j<kolumny; j++) {
            if (status==0) {
                cin>>bufor;
                    if ((bufor[0]>'0')&&(bufor[0]<':')){        // jesli 1 znak jest cyfra 1-9 (po 9 w ASCII jest :) tzn ze to liczba
                        cin>>znak;                              // wg schematu po liczbie bedzie znak
                        status = atoi(bufor)-1;
                        tab2[i][j]=znak;
                    }
                    else   tab2[i][j]=bufor[0];
            }
            else {                  //status busy...
                tab2[i][j]=znak;
                status--;
            }
        }
    }


                                                            //-odczyt zapisanej mapy------------/
    for(int i = 0; i<wiersze; i++) {
        for (int j=0; j<kolumny; j++)
            cout<< tab2[i][j]<<" ";
        cout<<endl;
    }
    //cout<<"status: "<<status<<endl;                           //status=0;


    int i=0;                                                    //pozycja startowa
    int j=0;
    int stop=1;
    int tablica[4];
    int *wsk_tabl;

    tablica[0]=stop;
    tablica[1]=i;
    tablica[2]=j;
    int last;                                                            //tablica[3] last;
    wsk_tabl=tablica;

    while ((cin>>bufor)&&(aktualny!=NULL)) {
                if ((bufor[0]>'0')&&(bufor[0]<':')){            // jesli 1 znak jest cyfra 1-9 (po 9 w ASCII jest :) tzn ze to liczba
                    cin>>znak;                                  // wg schematu po liczbie bedzie znak
                    status = atoi(bufor);                       //ilosc powtorzen znaku
                    while ((status>0)&&(aktualny!=NULL)) {
                        tablica[0]=1;
                        mapa(znak,tab2,wsk_tabl,wiersze,kolumny);
                        stop= tablica[0];
                        i= tablica[1];
                        j=tablica[2];
                        last = tablica[3];
                        if (stop==0){                           //czyli wykonany zosta³ ruch
                            aktualny=edek(aktualny,tab2,i,j,last);
                        }
                    status--;
                    }
                }
                else  {                                         // w buforze jest znak - wykonanie ruchu

                    mapa(bufor[0], tab2,wsk_tabl,wiersze,kolumny);
                    stop= tablica[0];
                    i= tablica[1];
                    j=tablica[2];
                    last = tablica[3];
                    if (stop==0){                               //czyli wykonany zosta³ ruch
                        aktualny=edek(aktualny,tab2,i,j,last);
                    }
                }

    }


    if (aktualny!=NULL) cout<<j<<" "<<i<<endl;
                                                                //-odczyt zapisanej mapy------------/
    for(int i = 0; i<wiersze; i++) {
        for (int j=0; j<kolumny; j++)
            cout<< tab2[i][j];
        cout<<endl;
    }
                                                                //---------------------------------/
    return 0;
}
