#ifndef LISTAPROCESORA_H
#define	LISTAPROCESORA_H

#include <stdlib.h>
#include <iostream>

struct ElementListy {
	ElementListy * nastepny;
	ElementListy * poprzedni;
	char znak;
	ElementListy(char);
};

struct Lista {
	ElementListy * poczatek, * koniec;
	unsigned int rozmiar;
	Lista();
	Lista(Lista* orig);
	~Lista();
};

void dodajNaKoniec(Lista * lista, char wartosc);
void dodajNaPoczatek(Lista * lista, char wartosc);
void usunKoniec(Lista * lista);
void usunPoczatek(Lista * lista);
void drukuj(Lista * lista);
char pobierzWartosc(Lista * lista, int numer);
void drukujZnak(ElementListy * el);
char pobierzWartosc(ElementListy * el, int numer);
void usunListe(Lista * lista);
void kopiuj(Lista * nowa, Lista * stara, int numer);
int numerZListy(ElementListy * el, int pozycja);

#endif	/* LISTAPROCESORA_H */

