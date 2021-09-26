# **Rozdział 6 - Struktury**

# 6.2. Struktury i funkcje

## Deklaracja struktury

Struktury deklarowane są przez użycie słowa kluczowego `struct`, po słowie kluczowym może znajdowac się opcjonalna nazwa
struktury. W nawiasach klamrowych deklarowane są parametry struktury. Po zamknięciu nawiasów klamrowych można zadeklarować
instancje struktury.

Przykładowa deklaracja struktury oraz trzech jej instancji; `x`, `y`, `z`:

```c
struct point {
    int x;
    int y;
} x, y, z;
```

```c
struct point x, y, z;
```

Powyższe deklaracje są równoważne.

## Inicjalizacja struktury

Struktury można inicjalizować poprzez użycie nawiasów klamrowych, podając następnie wartości jej kolejnych parametrów.

Przykładowa deklaracja struktury typu `point` o nazwie `screen` i elementach `x` i `y` równych odpowiednio `1920` i `1080`

```c

struct point pt = {1920, 1080};

```

Możemy również zainicjalizować strukturę poprzez przypisanie jej wartości z funkcji zwracającej typ `struct point`.

Przykładowa funkcja oraz inicjalizacja struktury przez przypisanie:

```c
struct point makepoint(int x, int y) {
    struct point temp;

    temp.x = x;
    temp.y = y;

    return temp;
}

struct point pt = makepoint(1920, 1080);
```

## Przekazywanie struktur do funkcji

Przy większych strukturach wydajniejsze jest przekazanie adresu na strukturę do funkcji w celu uniknięcia kopiowania.

Mając wskaźnik na strukturę możemy odwołać się do niego poprzez operator strzałki `->` (minus i znak większości). Operator ten dokonuje dereferencji wskaźnika i uzyskuje wartość danego parametru struktury. Poniższe zapisy są równoważne

```c
struct point origin;
struct point *ptr = &origin;

printf("copying: x - %d; y - %d\n", (*ptr).x, (*ptr).y);
printf("pointer: x - %d; y - %d\n",   ptr->x,  ptr->.y);
```

Nawiasy okrągłe w wyrażeniu `(*ptr).x` są konieczne, ponieważ operator kropki `.` ma wyższy priorytet niż operator gwiazdki `*`. Operator strzałki ma wyższy priorytet niż operatory inkrementacj (`++`) i dekrementacji (`--`), więc wyrażenie

```c
++p->len
```

zwiększa parametr `len`, a nie wskaźnik `p`, jest to równoważne z zapisem

```c
++(p->len)
```

# 6.3. Tablice struktur

## Inicjalizacja tablicy struktur

Tablicę struktur możemy zainicjalizować podobnie do pojedynczej struktury, poprzez podanie kolejnych jej elementów. Po podaniu elementów pierwszej struktury, wartości po przecinku będą przypisane do elementów drugiej struktury etc..

Tablice struktur, podobnie jak same struktury można zainicjalizować zaraz po ich deklaracji w kodzie.

```c
struct key {
    char* keyword;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    
}