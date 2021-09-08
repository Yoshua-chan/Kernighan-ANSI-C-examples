# 5.7. Tabice wielorymiarowe

## Talblica dwuwymiarowa

Tablica dwuwymiarowa jest tak naprawdę ciągłą w pamięci tablicą jednowymiarową w którym każdy element jest tablicą. 
Jest ona tablicą w którym każdy wiersz jest mniejszą tablicą należącą do całości.

Przykładowa inicjalizacja tablicy dwuwymiarowej.

```c

int tab[3][5] = { //gdzie 3 to liczba wierszy, a 5 - liczba kolumn
    {1, 2, 3, 4, 5}, //wiersz 1
    {6, 7, 8, 9, 10}, //wiersz 2
    {11, 12, 13, 14, 15} //wiersz 3
};
```
## Przekazywanie do funkcji

Jeśli dwuwymiarowa tablica ma być przekazana do funkcji, deklaracja argumentów funkcji musi zawierać liczbę kolumn. 
Przykładowo funkcja przyjmująca tablicę `daytab` o wymiarach `2x13`
```c
func(int daytab[2][13]) { ... }
```
nie trzeba przekazywać liczby wierszy, więc dopuszczalny jest też zapis
```c
func(int daytab[][13])  { ... }
```
można również zapisać jako **wskaźnik do tablicy 13-elementowej**
```c
func(int (*daytab)[13]) { ... }
```
nawiasy wokół `*daytab` są potrzebne, ponieważ operator nawiasów klamrowych ma pierwszeństwo przed operatorem `*`
poniższy zapis oznaczałby **tablicę 13 wskaźników na int**
```c
int *daytab[13]
```
W przypadku tablic o większych wymiarach pierwszy wymiar może być pominięty, następne muszą zostać określone.
