#include "ListaProcesora.h"
#include <math.h>

Lista::Lista(): poczatek(NULL), koniec(NULL), rozmiar(0) {
}

Lista::~Lista()
{
	usunListe(this);
}

Lista::Lista(Lista* orig)
{
	this->rozmiar=0;
	this->koniec = this->poczatek = NULL;
	if(orig->rozmiar > 0)
		kopiuj(this, orig, orig->rozmiar-1);
	
}


ElementListy::ElementListy(char z) : nastepny(NULL), poprzedni(NULL), znak(z)
{
	
}

void dodajNaKoniec(Lista * lista, char wartosc) {
	if(lista->rozmiar > 0) {
		lista->koniec->nastepny = new ElementListy(wartosc);
		lista->koniec->nastepny->poprzedni = lista->koniec;
		lista->koniec = lista->koniec->nastepny;
	}
	else {
		ElementListy * el = new ElementListy(wartosc);
		lista->koniec = lista->poczatek = el;
	}
	lista->rozmiar++;
}

void dodajNaPoczatek(Lista * lista, char wartosc) {
	if(lista->rozmiar > 0) {
		lista->poczatek->poprzedni = new ElementListy(wartosc);
		lista->poczatek->poprzedni->nastepny = lista->poczatek;
		lista->poczatek = lista->poczatek->poprzedni;
	}
	else {
		ElementListy * el = new ElementListy(wartosc);
		lista->poczatek = lista->koniec = el;
	}
	lista->rozmiar++;
}

void drukuj(Lista * lista) {
	drukujZnak(lista->poczatek);
}

void drukujZnak(ElementListy * el) {
	if(el == NULL) {
		std::cout<<"\n";
	}
	else {
		std::cout<<el->znak;
		drukujZnak(el->nastepny);
	}
}

void usunKoniec(Lista * lista) {
	if(lista->rozmiar > 1) {
		ElementListy * el = lista->koniec;
		lista->koniec->poprzedni->nastepny = NULL;
		lista->koniec = lista->koniec->poprzedni;
		delete el;
		lista->rozmiar--;
	}
	else if(lista->rozmiar == 1) {
		ElementListy * el = lista->koniec;
		lista->koniec = lista->poczatek = NULL;
		delete el;
		lista->rozmiar--;
	}
	else {
		// nie można usunąć
		return;
	}
}

void usunPoczatek(Lista * lista) {
	if(lista->rozmiar > 1) {
		ElementListy * el = lista->poczatek;
		lista->poczatek->nastepny->poprzedni = NULL;
		lista->poczatek = lista->poczatek->nastepny;
		delete el;
		lista->rozmiar--;
	}
	else if(lista->rozmiar == 1) {
		ElementListy * el = lista->poczatek;
		lista->koniec = lista->poczatek = NULL;
		delete el;
		lista->rozmiar--;
	}
	else {
		// nie można usunąć
		return;
	}
}

char pobierzWartosc(Lista * lista, int numer) {
	if(numer >= lista->rozmiar) 
		return '\0';
	else {
		return pobierzWartosc(lista->poczatek, numer);
	}
}

char pobierzWartosc(ElementListy * el, int numer) {
	if(numer==0) {
		return el->znak;
	}
	else {
		return pobierzWartosc(el->nastepny,--numer);
	}
}

void usunListe(Lista * lista) {
	if(lista->rozmiar > 0) {
		usunPoczatek(lista);
		usunListe(lista);
	}
	else { return; }
}

void kopiuj(Lista * nowa, Lista * stara, int numer) 
{
	if(numer >= 0) {
		dodajNaPoczatek(nowa, pobierzWartosc(stara, numer));
		kopiuj(nowa, stara, --numer);
	}
}

int numerZListy(ElementListy * el, int pozycja) {
	if(pozycja >= 0) {
		if(el->znak == '-') {
			return -1 * numerZListy(el->poprzedni, --pozycja);
		}
		else {
			return ((el->znak-'0') * pow(10,(double)pozycja)) + numerZListy(el->poprzedni, --pozycja);
		}
	}
	else {
		return 0;
	}
}