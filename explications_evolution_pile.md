
```
## Expliquer `ifndef` en langage C

En langage C, `ifndef` est une directive de préprocesseur. Elle vérifie si un certain identificateur n'est pas déjà défini. Par exemple :

```c
#ifndef IDENTIFIANT
   // code à exécuter si l'identifiant n'est pas défini
#endif
```

Cette structure est souvent utilisée pour éviter les inclusions multiples d'un fichier d'en-tête dans le même fichier de code source.

## À quoi sert une énumération (enum) ?

Une énumération (`enum`) est un type de données en C qui consiste en un ensemble d'identifiants nommés. Un exemple serait :

```c
enum jour {lundi, mardi, mercredi, jeudi, vendredi, samedi, dimanche};
```

Ici, `jour` est un nouveau type de données qui peut prendre l'une des valeurs énumérées. 

## Comment déclarer une variable de type `pile*` ?

En C, `pile*` est un pointeur vers une instance de la structure `pile`. Vous pouvez le déclarer comme suit :

```c
pile* p;
```

## Exemple de code en utilisant `pile*` :

```c
#include <stdlib.h>

typedef struct {
    int valeur;
} pile;

pile* creer_pile(int valeur) {
    pile* nouvelle_pile = malloc(sizeof(pile));
    nouvelle_pile->valeur = valeur;
    return nouvelle_pile;
}
```

Notez que dans un véritable programme, vous devriez vérifier si `malloc` renvoie `NULL`, ce qui indiquerait qu'il n'a pas pu allouer de mémoire. De plus, une pile dans un véritable programme serait une structure de données plus complexe, généralement une liste chaînée, avec des opérations pour empiler (push) et dépiler (pop).

## Exemple complet de programme utilisant `pile*` :

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct pile {
    int valeur;
    struct pile* suivant;
} pile;

pile* creer_pile(int valeur) {
    pile* nouvelle_pile = (pile*) malloc(sizeof(pile));
    if (nouvelle_pile == NULL) {
        printf("Erreur : impossible d'allouer de la mémoire pour une nouvelle pile.\n");
        exit(1);
    }
    nouvelle_pile->valeur = valeur;
    nouvelle_pile->suivant = NULL;
    return nouvelle_pile;
}

void empiler(pile** sommet, int valeur) {
    pile* nouvel_element = creer_pile(valeur);
    if (nouvel_element == NULL) {
        printf("Erreur : impossible d'empiler une nouvelle valeur.\n");
        exit(1);
    }
    nouvel_element->suivant = *sommet;
    *sommet = nouvel_element;
}

int depiler(pile** sommet) {
    if (*sommet == NULL) {
        printf("Erreur : impossible de dépiler, la pile est vide.\n");
        exit(1);
    }
    int valeur = (*sommet)->valeur;
    pile* a_supprimer = *sommet;
    *sommet = (*sommet)->suivant;
    free(a_supprimer);
    return valeur;
}

int main() {
    pile* ma_pile =

 creer_pile(5);
    empiler(&ma_pile, 10);
    empiler(&ma_pile, 15);
    printf("Valeur déposée : %d\n", depiler(&ma_pile));
    printf("Valeur déposée : %d\n", depiler(&ma_pile));
    printf("Valeur déposée : %d\n", depiler(&ma_pile));
    return 0;
}
```

## Qu'est-ce que l'opérateur `->` en C ?

L'opérateur `->` est utilisé en C pour accéder aux membres d'une structure pointée par un pointeur. Considérons l'exemple suivant :

```c
typedef struct {
    int valeur;
} MaStructure;

MaStructure* ptr = malloc(sizeof(MaStructure));
ptr->valeur = 10;
```

Ici, `ptr` est un pointeur vers une instance de `MaStructure`. Pour accéder au membre `valeur` de cette structure, nous utilisons `ptr->valeur`. En fait, `ptr->valeur` est un raccourci pour `(*ptr).valeur`. Les deux sont équivalents, mais `ptr->valeur` est plus couramment utilisé car il est plus facile à lire et à écrire.
```
