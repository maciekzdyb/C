#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include "ListaProcesora.h"
#include "StosProcesora.h"

using namespace std;

void wykonajOperacje(Stos * stos, char * rozkazy, unsigned int * wskaznikInstrukcji, unsigned int * rozmiarProgramu) {
	if(*wskaznikInstrukcji >= *rozmiarProgramu) return;
	//cout<<"Operator "<< rozkazy[*wskaznikInstrukcji]<<endl;
	switch(rozkazy[*wskaznikInstrukcji]) {
		case '\'' :
			dodaj(stos, new Lista());
		break;
		case ',' :
			usun(stos);
		break;
		case ':' :
			dodaj(stos, new Lista(pobierz(stos->top,0)));
		break;
		case ';' :
			zamienDwaGorneElementy(stos);
		break;
		case '@' :
			operacjaMalpa(stos);
		break;
		case '&' :
			if(stos->rozmiar>0)
				wypiszStos(stos, stos->rozmiar-1);
		break;
		case '.' :
			dodajNaPoczatek(pobierz(stos->top,0), getchar());
		break;
		case '-' :
			negacja(stos);
		break;
		case '^' :
			bezwzgledna(stos);
		break;
		case '>' :
			cout<<pobierz(stos->top,0)->poczatek->znak;
			usun(stos);
		break;
		case '$' :
			operatorDolar(stos);
		break;
		case ']' :
			nawiasZamk(stos);
		break;
		default:
			dodajNaPoczatek(pobierz(stos->top,0), rozkazy[*wskaznikInstrukcji]);
		break;
		
	}
	if(rozkazy[*wskaznikInstrukcji] != '?') {
		(*wskaznikInstrukcji)++;
	}
	wykonajOperacje(stos,rozkazy,wskaznikInstrukcji, rozmiarProgramu);
}

int main(int argc, char** argv)
{
	Stos * stos = new Stos();
	char * rozkazy = new char[2001]();
	unsigned int * wskaznikInstrukcji = new unsigned int();
	unsigned int * rozmiarProgramu = new unsigned int();
	* wskaznikInstrukcji = 0;
	std::cin.getline(rozkazy, 2001);
	*rozmiarProgramu = strlen(rozkazy);
	wykonajOperacje(stos, rozkazy, wskaznikInstrukcji, rozmiarProgramu);
	
	
	return 0;
}
