Wejœcie

Na wejœciu podane bêd¹, rozdzielone bia³ymi znakami, kolejno:
szerokoœæ mapy,
wysokoœæ mapy,
pocz¹tkowa liczba segmentów Edka,
zawartoœæ mapy; bêdzie to ci¹g znaków i liczb o nastêpuj¹cych w³asnoœciach:
kropka oznacza puste pole,
T oznacza drzewo,
K oznacza kolec,
G oznacza grzyb,
a–z oznacza ka³u¿ê o odpowiednim kolorze,
znak pola mo¿e poprzedzaæ liczba (np. 10 T); liczba ta mówi w ilu kolejnych kolumnach znajduje siê pole okreœlonego typu; np. 10 T jest równowa¿ne dziesiêciu kolejnym literom T,
pola opisane s¹ w kolejnoœci najpierw kolumnami, nastêpnie wierszami.
ruchy Edka: znaki l, p, g, d oznaczaj¹ce kolejno ruch o jedno pole w lewo, prawo, górê i dó³; podobnie jak w przypadku mapy, ruch mo¿e byæ poprzedzony liczb¹ oznaczaj¹c¹ iloœæ danych ruchów (np. 5 p oznacza piêæ ruchów w prawo)
Edek rozpoczyna podró¿ czysty, w lewym górnym polu mapy. 
Wysokoœæ i szerokoœæ mapy bêd¹ dodatnie i nie przekrocz¹ 4000 (szerokoœæ) i 1000 (wysokoœæ). Krotnoœæ ¿adnego ruchu nie bêdzie wiêksza ni¿ 5000.
Wyjœcie

Na wyjœciu nale¿y wypisaæ kolejno:
w osobnej linii napis Zegnaj, okrutny swiecie! je¿eli Edek zakoñczy³ swój ¿ywot,
w osobnej linii wspó³rzêdne (najpierw numer kolumny nastêpnie numer wiersza, licz¹c od zera) miejsca w którym Edek zakoñczy³ podró¿ lub ostatniego miejsca, w którym by³ ¿ywy,
zawartoœæ mapy po zakoñczeniu podró¿y; kolejne wiersze mapy nale¿y wypisywaæ w osobnych liniach; pól w wierszu nie nale¿y rozdzielaæ bia³ymi znakami; dla ka¿dego pola nale¿y wypisaæ:
kropkê je¿eli pole jest puste,
T je¿eli pole zawiera drzewo,
K je¿eli pole zawiera kolec,
G je¿eli pole zawiera grzyb,
a–z je¿eli pole zawiera ka³u¿ê odpowiedniego koloru.
Przyk³ad

Wejœcie
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

Wyjœcie
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