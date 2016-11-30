#include <iostream>
#include <stdio.h>

using namespace std;

struct Edge {
    int fromNode;
    int toNode;
    int distance;
    Edge *next;
};

int main()
{
    int nodesNo;  // iloœæ wierzcho³ków
    cin>>nodesNo;
    int startNode; // nr pocz¹tkowego wierzcho³ka
    cin>>startNode;
    Edge *edgesHead;// lista krawêdzi
    Edge *edgesActual;
    edgesHead=NULL;
    edgesActual=NULL;
    const int MAX_INT = 2147483647;
    int *distanceToNodes = new int[nodesNo];

    for (int i=0; i<nodesNo; i++) {                 //i - fromNode; odczyt danych i wypelnienie listy
            if (i== startNode) distanceToNodes[i]=0;
                else
                     distanceToNodes[i] = MAX_INT;
            int outgoingEdgesNo;
            cin>>outgoingEdgesNo;
            for (int j=0; j<outgoingEdgesNo; j++) {

                Edge *newEdge = new Edge;
                cin>>newEdge->toNode;
                cin>>newEdge->distance;
                newEdge->fromNode=i;
                newEdge->next=NULL;

                if (edgesHead==NULL) {
                        edgesHead=newEdge;
                        edgesActual=newEdge;
                }
                else {
                        edgesActual->next=newEdge;
                        edgesActual=newEdge;
                }

            }
    }


    //-------------------------------uaktualnienie tabeli dystansów
    for (int n=0; n<nodesNo-1; n++){
        edgesActual=edgesHead;
        while (edgesActual!=NULL){
            if (distanceToNodes[edgesActual->fromNode]!=MAX_INT) {
                int distanceUsingEdge = distanceToNodes[edgesActual->fromNode] - edgesActual->distance;
                if (distanceUsingEdge < distanceToNodes[edgesActual->toNode]) {
                    distanceToNodes[edgesActual->toNode]=distanceUsingEdge;
                }
            }
            edgesActual=edgesActual->next;
        }
    }

    //------------------------------wyszukanie najmniejszej wartosci (wart bezwzglegna bedzie najwieszka)
    int shortestDistance = 0;
    for (int n=0; n<nodesNo; n++){
        if(distanceToNodes[n]<shortestDistance) shortestDistance=distanceToNodes[n];
    }

    shortestDistance*=-1;

    cout<<shortestDistance;

/*/test - wyswietlenie liczby wierzcholkow i listy krawêdzi
    cout<<"nodes: "<<nodesNo<<endl;
    edgesActual=edgesHead;
    while(edgesActual!=NULL){
        cout<<edgesActual->fromNode<<"-"<<edgesActual->toNode<<"->"<<edgesActual->distance<<endl;
        edgesActual=edgesActual->next;
    }

    //test wyœwietlenie tabeli dystansow
    cout<<endl;
    cout<<"nodesNo: "<<nodesNo<<endl;
    for (int n=0; n<nodesNo; n++) {
        cout<<distanceToNodes[n]<<endl;
    }
*/

    //-------------------------------kasowanie listy krawedzi
    while (edgesHead!=NULL) {
        edgesActual=edgesHead->next;
        delete edgesHead;
        edgesHead=edgesActual;
    }
    delete[] distanceToNodes;
    return 0;
}
