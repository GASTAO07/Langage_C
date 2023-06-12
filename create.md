
# Analyse de la fonction de tri par pile

Le code ci-dessous est une implémentation d'une fonction qui trie un tableau en utilisant deux piles.

```c
void fonction(int* tab, int tab_size){
 pile* p = creer_pile();
 pile* p2 = creer_pile();
 empiler(p, tab[0]);
 for (int i = 1; i < tab_size; i++){
 int value; 
 do{
 value = depiler(p);
 if (value > tab[i]){
 empiler(p2, value); 
 } else {
 empiler(p, value);
 break;
 }
 } while(!est_vide(p));
 empiler(p, tab[i]);
 while(!est_vide(p2)){
 empiler(p, depiler(p2));
 }
 }
 for(int i = 0; i < tab_size; i++){
 tab[i] = depiler(p);
 }
}
```

## Question

1. Si t est un tableau contenant les éléments 7, 4, 6 et 5, que contiendra le tableau après avoir appelé `fonction(t, 4)`?
2. Que fait la fonction `fonction`?

## Réponses

1. Le tableau `t` contiendra les éléments [7, 6, 5, 4] après avoir appelé `fonction(t, 4)`.
2. La fonction `fonction` est une implémentation d'une sorte de tri par pile, qui trie les éléments du tableau dans l'ordre décroissant.

## Explication détaillée

La fonction commence par initialiser deux piles vides, `p` et `p2`, puis empile le premier élément du tableau sur `p`. Elle parcourt ensuite le reste du tableau.

Pour chaque élément :
- Elle dépile des éléments de `p` tant qu'ils sont plus grands que l'élément actuel et les empile sur `p2`.
- Une fois qu'elle trouve un élément dans `p` qui n'est pas plus grand que l'élément actuel, elle l'empile de nouveau dans `p` et interrompt la boucle.
- Elle empile ensuite l'élément actuel sur `p`.
- Enfin, elle dépile tous les éléments de `p2` et les empile sur `p`.

À la fin de ce processus, tous les éléments du tableau ont été déplacés vers `p` et sont maintenant triés dans l'ordre décroissant.

La fonction dépile ensuite les éléments de `p` un par un et les place dans le tableau, de sorte que le tableau est maintenant trié dans l'ordre décroissant.

C'est une variante du tri par insertion où deux piles sont utilisées au lieu d'une seule liste.
