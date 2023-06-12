//Pile 

#include <stdio.h>
#include <stdlib.h>

#define taille 7

int Pile[taille];
int sommet = -1;

void initPile() {
    sommet = -1;
}

int PileVide() {
    if (sommet == -1)
        return 1;
    return 0;
}

int PileRemplie() {
    if (sommet == taille - 1)
        return 1;
    return 0;
}

void pushPile(int valeur) {
    if (!PileRemplie()) {
        sommet++;
        Pile[sommet] = valeur;
    }
}

int popPile() {
    int valeur = -1; // Default value if the stack is empty
    if (!PileVide()) {
        valeur = Pile[sommet];
        sommet--;
    }
    return valeur;
}

int main() {
    initPile();
    pushPile(10);
    pushPile(20);
    pushPile(30);
    
    int value = popPile();
    printf("%d\n", value); // Output: 30
    
    value = popPile();
    printf("%d\n", value); // Output: 20
    
    return 0;
}
