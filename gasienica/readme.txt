Wej�cie

Na wej�ciu podane b�d�, rozdzielone bia�ymi znakami, kolejno:
szeroko�� mapy,
wysoko�� mapy,
pocz�tkowa liczba segment�w Edka,
zawarto�� mapy; b�dzie to ci�g znak�w i liczb o nast�puj�cych w�asno�ciach:
kropka oznacza puste pole,
T oznacza drzewo,
K oznacza kolec,
G oznacza grzyb,
a�z oznacza ka�u�� o odpowiednim kolorze,
znak pola mo�e poprzedza� liczba (np. 10 T); liczba ta m�wi w ilu kolejnych kolumnach znajduje si� pole okre�lonego typu; np. 10 T jest r�wnowa�ne dziesi�ciu kolejnym literom T,
pola opisane s� w kolejno�ci najpierw kolumnami, nast�pnie wierszami.
ruchy Edka: znaki l, p, g, d oznaczaj�ce kolejno ruch o jedno pole w lewo, prawo, g�r� i d�; podobnie jak w przypadku mapy, ruch mo�e by� poprzedzony liczb� oznaczaj�c� ilo�� danych ruch�w (np. 5 p oznacza pi�� ruch�w w prawo)
Edek rozpoczyna podr� czysty, w lewym g�rnym polu mapy. 
Wysoko�� i szeroko�� mapy b�d� dodatnie i nie przekrocz� 4000 (szeroko��) i 1000 (wysoko��). Krotno�� �adnego ruchu nie b�dzie wi�ksza ni� 5000.
Wyj�cie

Na wyj�ciu nale�y wypisa� kolejno:
w osobnej linii napis Zegnaj, okrutny swiecie! je�eli Edek zako�czy� sw�j �ywot,
w osobnej linii wsp�rz�dne (najpierw numer kolumny nast�pnie numer wiersza, licz�c od zera) miejsca w kt�rym Edek zako�czy� podr� lub ostatniego miejsca, w kt�rym by� �ywy,
zawarto�� mapy po zako�czeniu podr�y; kolejne wiersze mapy nale�y wypisywa� w osobnych liniach; p�l w wierszu nie nale�y rozdziela� bia�ymi znakami; dla ka�dego pola nale�y wypisa�:
kropk� je�eli pole jest puste,
T je�eli pole zawiera drzewo,
K je�eli pole zawiera kolec,
G je�eli pole zawiera grzyb,
a�z je�eli pole zawiera ka�u�� odpowiedniego koloru.
Przyk�ad

Wej�cie
10 10 3
. . T . . . . . . .
. . . . . . . . . .
. c . . . . . . a b
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .
. G G . . . . . . .
. . . . . . . . . .
. . . K K K K K K .
. . . . . . . . . .
5 p d d 100 p d d 10 l d d p p p p g l l d d d 10 p

Wyj�cie
Zegnaj, okrutny swiecie!
6 8
..T.......
..........
.c..c..cab
.........c
acbacbacba
b...c.....
c.aab.....
..b.......
..cKKKKKK.
..........