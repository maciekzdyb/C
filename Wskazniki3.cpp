#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    const int max_n=10001;

    char napis[max_n], separator[max_n], *wsk_n, *wsk_s;
    char akt_znak, ost_znak;                //aktualny zank i osatnio znaleziony

    ost_znak='s';
    while (cin>>napis>>separator) {
        wsk_n=napis;
        akt_znak='s';                       //nie znaleeziono spacji

        while(*wsk_n!='\0') {               //przeglada tablice napis
            wsk_s=separator;
            while(*wsk_s!='\0') {           //przeglada tablice separator
                if ((*wsk_s) == (*wsk_n)) {
                        akt_znak ='s';
                        wsk_s++;
                        break;              //znaleziono separator wiec nie trzeba dalej czytac
                }
                wsk_s++;
                akt_znak ='z';
            }
            if ((akt_znak=='s')&&(ost_znak=='z')) {
                    ost_znak='s';
                    cout<<" ";              //drukuje spacje jesli jest znaleziony separator i ostatni drukowany znak to nie byl separator
            }
            if (akt_znak=='z') {
                    ost_znak ='z';          //ostatni napisany znak to nie spacja
                    cout<<*wsk_n;
            }
            wsk_n++;
        }
    cout<<endl;
    }
    return 0;
}
