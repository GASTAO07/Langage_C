#include <stdio.h>
#include <stdlib.h>

#define taille 7

int File[taille];
int debut = 0;  // Index of the front element
int fin = -1;   // Index of the rear element
int nbElements = 0;  // Number of elements in the queue

void initFile() {
    debut = 0;
    fin = -1;
    nbElements = 0;
}

int FileVide() {
    return nbElements == 0;
}

int FilePleine() {
    return nbElements == taille;
}

void enfiler(int valeur) {
    if (!FilePleine()) {
        fin = (fin + 1) % taille;  // Wrap around the array if the end is reached
        File[fin] = valeur;
        nbElements++;
    }
}

int defiler() {
    int valeur = -1;  // Default value if the queue is empty
    if (!FileVide()) {
        valeur = File[debut];
        debut = (debut + 1) % taille;  // Wrap around the array if the end is reached
        nbElements--;
    }
    return valeur;
}

int main() {
    initFile();
    enfiler(10);
    enfiler(20);
    enfiler(30);
    
    int value = defiler();
    printf("%d\n", value);  // Output: 10
    
    value = defiler();
    printf("%d\n", value);  // Output: 20
    
    return 0;
}
