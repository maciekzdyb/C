#include "StosProcesora.h"

ElementStosu::ElementStosu(Lista* lista) : nastepny(NULL), wartosc(lista) {}

Stos::Stos() : top(NULL), rozmiar(0) {}

void dodaj(Stos * stos, Lista * lista) {
	ElementStosu * el = new ElementStosu(lista);
	el->nastepny = stos->top;
	stos->top = el;
	stos->rozmiar++;
}

void usun(Stos * stos) {
	if(stos->rozmiar > 0) {
		ElementStosu * el = stos->top;
		stos->top = stos->top->nastepny;
		stos->rozmiar--;
		delete el->wartosc;
		delete el;
	}
}

Lista * zdejmij(Stos * stos) {
	if(stos->rozmiar > 0) {
		ElementStosu * el = stos->top;
		Lista * lista = el->wartosc;
		stos->top = stos->top->nastepny;
		stos->rozmiar--;
		delete el;
		return lista;
	}
	else {return NULL; }
}

Lista * pobierz(ElementStosu * el, unsigned int numer) {
	if(el != NULL) {
		if(numer==0) return el->wartosc;
		else {
			return pobierz(el->nastepny, --numer);
		}
	}
	else { return NULL; }
}

void zamienDwaGorneElementy(Stos * stos) {
	Lista * el1 = zdejmij(stos);
	Lista * el2 = zdejmij(stos);
	dodaj(stos, el1);
	dodaj(stos, el2);
}

void operacjaMalpa(Stos * stos) {
	Lista * listaZeSzczytu = zdejmij(stos);
	if(listaZeSzczytu->rozmiar == 0) return ;
	int numer =  numerZListy(listaZeSzczytu->koniec, listaZeSzczytu->rozmiar-1);
	Lista * listaDoSkopiowania = pobierz(stos->top, numer);
	dodaj(stos, new Lista(listaDoSkopiowania));
}

void wypiszStos(Stos * stos, int idElementu) {
	if(idElementu >= 0) {
		std::cout<<idElementu<<": ";
		Lista * l = pobierz(stos->top, idElementu);
		drukuj(l);
		wypiszStos(stos, --idElementu);
	}
}

void negacja(Stos * stos) {
	Lista * l = pobierz(stos->top, 0);
	char znak = pobierzWartosc(l,l->rozmiar-1);
	if(znak == '-') {
		usunKoniec(l);
	}
	else {
		dodajNaKoniec(l, '-');
	}
}

void bezwzgledna(Stos * stos) {
	Lista * l = pobierz(stos->top, 0);
	char znak = pobierzWartosc(l,l->rozmiar-1);
	if(znak == '-') {
		usunKoniec(l);
	}
}

void operatorDolar(Stos * stos) {
	Lista * l = pobierz(stos->top,0);
	char znak = pobierzWartosc(l,0);
	usunPoczatek(l);
	Lista * nowa = new Lista();
	dodajNaPoczatek(nowa, znak);
	dodaj(stos,nowa);
}

void nawiasZamk(Stos * stos) {
	Lista * listaZeSzczytu = zdejmij(stos);
	int numer =  numerZListy(listaZeSzczytu->koniec, listaZeSzczytu->rozmiar-1);
	Lista * nowa = new Lista();
	dodajNaPoczatek(nowa, (char)numer);
	dodaj(stos, nowa);
}