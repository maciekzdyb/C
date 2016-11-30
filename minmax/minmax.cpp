#include <iostream>
#include <stdio.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    int liczlicz;
    cin>>liczlicz;
    short *liczby;
    liczby= new short[liczlicz];
    for (int a=0; a<liczlicz; a++){
        cin>> liczby[a];
    }
    int m,l,p;
    short minimum, maximum;
    cin>>m;
    for (int a=0; a<m; a++) {
        minimum=0;
        maximum=0;
        cin>>l>>p;
        for(int b=l;b<p+1;b++){
            if(b==l){
                minimum=liczby[b];
                maximum=liczby[b];
            }
            if (liczby[b]<minimum) minimum=liczby[b];
            if (liczby[b]>maximum) maximum=liczby[b];
        }
        cout<<minimum<<" "<<maximum<<endl;
    }
    delete[] liczby;
    return 0;
}
