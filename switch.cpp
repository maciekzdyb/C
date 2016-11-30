/*#############################################################
  #######  switch by Maciej Zdyb 2015 September   #############
  #######             index No 67011              #############
  #############################################################
*/
#include <iostream>
#include <cstdlib> // atoi

using namespace std;

//---------------------------------------------------------------node---------------------------------------------------------

struct node {
    int port;           //-2 is not last,
    int octet_value;
    struct node *next;         //prawy brat
    struct node *firstborn;    //pierwszy z dzieci
};

//-----------------------------------------------------------get ip octets----------------------------------------------------

void get_ip_octets(int *int_table) {
    char ip[16]; // nie 15 bo jeszcze jest \0;
    cin>>ip;
    int bit_no=0;
    for (int i=0;i<4; i++){
        char octet[4];
        int a=0;
        while (ip[bit_no]!='.' && ip[bit_no]!='\0'){
            octet[a]=ip[bit_no];
            a++;
            bit_no++;
        }
        octet[a]='\0';
        bit_no++;

        *int_table=atoi(octet);
        int_table++;

        /*if (i==0) {
                *int_table=atoi(octet);
                int_table++;
        }
        if (i==1) {
                *int_table=atoi(octet);
                int_table++;
        }
        if (i==2) {
                *int_table=atoi(octet);
                int_table++;
        }
        if (i==3) {
                *int_table=atoi(octet);
        }*/
    }
}

//-------------------------------------------------------------------------sort----------------------------------

int partition(int *tablica, int p, int r)       // dzielimy tablice na dwie czesci, w pierwszej wszystkie liczby sa mniejsze badz rowne x, w drugiej wieksze lub rowne od x
{
    int x = tablica[p]; // obieramy x
    int i = p, j = r, w; // i, j - indeksy w tabeli
    while (true){ // petla nieskonczona - wychodzimy z niej tylko przez return j
        while (tablica[j] > x) // dopoki elementy sa wieksze od x
            j--;
        while (tablica[i] < x) // dopoki elementy sa mniejsze od x
            i++;
        if (i < j) {// zamieniamy miejscami gdy i < j
            w = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = w;
            i++;
            j--;
        }
        else // gdy i >= j zwracamy j jako punkt podzialu tablicy
            return j;
    }
}

void quicksort(int *tablica, int p, int r) // sortowanie szybkie
{
    int q;
    if (p < r){
        q = partition(tablica,p,r); // dzielimy tablice na dwie czesci; q oznacza punkt podzialu
        quicksort(tablica, p, q); // wywolujemy rekurencyjnie quicksort dla pierwszej czesci tablicy
        quicksort(tablica, q+1, r); // wywolujemy rekurencyjnie quicksort dla drugiej czesci tablicy
    }
}


//-------------------------------------------------------------------------make Trie_node---------------------------------------------------------------------

node *make_node(node *actual1,int octet, int port_No){                            //tworzenie nowego node'a lub zwracanie istniejacej wartoœci

    if(actual1->firstborn!=NULL) {
            actual1=actual1->firstborn;
            while(actual1->octet_value!=octet && actual1->next!=NULL){
                actual1=actual1->next;                                //tym przesuwam wskaznik po liscie az znajde taki sam wezel lub dojde na koniec listy
            }
            if (actual1->octet_value!=octet) {                       //jak jest rozne to znaczy ze jestesmy na koncu listy
                actual1->next=new node;                              // dolaczenie nowego do konca listy
                actual1=actual1->next;
                actual1->next=NULL;
                actual1->octet_value=octet;
                actual1->firstborn=NULL;
                actual1->port=port_No;

            }
            else{
                actual1->port=port_No;
            }
    }
    else {                                                          //lista jest pusta wiêc tworzymy nowego noda

        actual1->firstborn = new node;
        actual1=actual1->firstborn;
        actual1->next=NULL;
        actual1->octet_value=octet;
        actual1->firstborn=NULL;
        actual1->port=port_No;
    }
return actual1;
}

//-------------------------------------------------------------------------walk------------------------------------------------------------------

node *walk_node(node *actual2, int octet){                           //wskaznik na rodzica, zwracamy wskaŸnik na istniejacy element z listy firstborne'a (równy wart octet)lub NULL jeœli takiego nie ma

            while(actual2->octet_value!=octet && actual2->next!=NULL){ //przesuwamy siê po liœcie tak d³ugo jak nie znajdziemy odpowiedniego oktetu lub dojedziemy do koñca listy
                actual2=actual2->next;
            }
            if (actual2->octet_value!=octet) {                       //jak jest rozne to znaczy ze jestesmy na koncu)
                return(NULL);
            }
            else return (actual2);
}

//---------------------------------------------------------------------return PortNo---------------------------------------------------------

int return_portNo(node *actual, int octet) {                         //zwracamy nr portu dla podanego octetu lub -2 je¿eli takiego oktetu nie ma
            actual=actual->firstborn;
            while(actual->octet_value!=octet && actual->next!=NULL){ //przesuwamy siê po liœcie tak d³ugo jak nie znajdziemy odpowiedniego oktetu lub dojedziemy do koñca listy
                actual=actual->next;
            }
            if (actual->octet_value!=octet) {                       //jak jest rozne to znaczy ze jestesmy na koncu)
                return(-2);                                         //nie znaleziono oktetu
            }
            else {
                    return (actual->port);                          //zwracany nr prtu dla podanego oktetu
            }
}

//------------------------------------------------------------------print all ports---------------------------------------------------------

node *print_all_ports(node *actual,int *table,int *elements) {
        if (actual->port==-2){
                if (actual->firstborn!=NULL) print_all_ports(actual->firstborn,table,elements);
                if (actual->next!=NULL) print_all_ports(actual->next,table,elements);
        }
        else {
                table[*elements] = actual->port;
                *elements=*elements + 1;
                if (actual->next!=NULL) print_all_ports(actual->next,table,elements);
        }
return NULL;
}

void delete_node(node *tmp){
    if (tmp->firstborn!=NULL) delete_node(tmp->firstborn);
    if (tmp->next!=NULL) delete_node(tmp->next);
    if (tmp->next==NULL && tmp->firstborn==NULL) delete tmp;
}

//##############################################################  main  #####################################################################

int main()
{
    node *root = new node;
    root->port=-3;          //-2 - not last;
    root->next=NULL;
    root->firstborn=NULL;
    root->octet_value= 300;



    int port_No;
    while (cin>>port_No) {

        int *port_table = new int[100005];
        int *number_of_elements = new int;
        *number_of_elements=0;

        int octet_table[4];
        get_ip_octets(octet_table);
        node *actual;
        actual = root;
        for (int a=0; a<4; a++){
            if(a<3) {
                actual=make_node(actual,octet_table[a],-2);
                //actual=actual->firstborn;
            }
            else {
                actual=make_node(actual,octet_table[a],port_No);
            }
        }
        //cout<<actual->port<<endl;
//--------------------------------------------------
        get_ip_octets(octet_table);
        actual=root;
        bool broadcast = false;

        if (octet_table[0]==255){
                actual=print_all_ports(actual->firstborn,port_table,number_of_elements);
                broadcast=true;
        }
        else {
                actual=walk_node(actual->firstborn,octet_table[0]);
                port_No=-2;
        }

        if(actual!=NULL) {
            if (octet_table[1]==255) {
                    actual=print_all_ports(actual->firstborn,port_table,number_of_elements);
                    broadcast=true;
            }
            else {
                    actual=walk_node(actual->firstborn,octet_table[1]);
                    port_No=-2;
            }
        }


        if(actual!=NULL) {
            if (octet_table[2]==255) {
                    actual=print_all_ports(actual->firstborn,port_table,number_of_elements);
                    broadcast=true;
            }
            else {
                    actual=walk_node(actual->firstborn,octet_table[2]);
                    port_No=-2;
            }
        }
        if(actual!=NULL) {
            if (octet_table[3]==255) {
                    actual=print_all_ports(actual->firstborn,port_table,number_of_elements);
                    broadcast=true;
            }
            else port_No=return_portNo(actual,octet_table[3]);
        }

        int data;
        cin>>data;

      // cout<<"elements: "<<*number_of_elements<<endl;

        if(broadcast==false) {
            if (port_No==-2) {
                cout<<"drop"<<endl;
            }
            else cout<<port_No<<" "<<data<<endl;
        }
        else {
                quicksort(port_table,0,*number_of_elements-1);
                for(int a=0; a<*number_of_elements; a++) {
                    cout<<port_table[a]<<" ";
                }
                cout<<data<<endl;
        }

        delete number_of_elements;
        delete[] port_table;
    } // while end

    delete_node(root);
return 0;
}
