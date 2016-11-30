#ifndef STOSPROCESORA_H
#define	STOSPROCESORA_H

#include "ListaProcesora.h"

struct ElementStosu {
	ElementStosu * nastepny;
	Lista * wartosc;
	ElementStosu(Lista * lista);
};

struct Stos {
	ElementStosu * top;
	unsigned int rozmiar;
	Stos();
};

void dodaj(Stos * stos, Lista * lista);
void usun(Stos * stos);
Lista * zdejmij(Stos * stos);
Lista * pobierz(ElementStosu * el, unsigned int numer);
void zamienDwaGorneElementy(Stos * stos);
void operacjaMalpa(Stos * stos);
void wypiszStos(Stos * stos, int idElementu);
void negacja(Stos * stos);
void bezwzgledna(Stos * stos);
void operatorDolar(Stos * stos);
void nawiasZamk(Stos * stos);
#endif	/* STOSPROCESORA_H */

