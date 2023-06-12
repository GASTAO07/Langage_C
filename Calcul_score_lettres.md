
## Programme de calcul de somme des positions des caractères dans l'alphabet

### Code en langage C

```c
#include <stdio.h>
#include <ctype.h>

int main() {
    char tableau_text[20];
    char special_letter;
    int sum = 0;

    printf("Veuillez saisir un texte de taille maximale de 19 caractères : ");
    scanf("%19s", tableau_text);

    printf("Veuillez choisir une lettre spéciale : ");
    scanf(" %c", &special_letter);

    for (int i = 0; i < 20; i++) {
        char current_char = tableau_text[i];

        if (current_char == '\0') {
            break;  // Sortir de la boucle si on atteint la fin de la chaîne
        }

        if (isalpha(current_char)) {
            int position;

            if (toupper(current_char) == toupper(special_letter)) {
                sum += 4;
            } else if (isupper(current_char)) {
                sum += (current_char - 'A' + 1) * 2;
            } else {
                sum += current_char - 'a' + 1;
            }
        } else {
            sum -= 1;
        }
    }

    printf("La somme des positions des caractères dans l'alphabet est : %d\n", sum);

    return 0;
}
```

### Explications

Ce programme en langage C permet de calculer la somme des positions des caractères dans l'alphabet pour un texte saisi par l'utilisateur. Voici comment il fonctionne :

1. On déclare un tableau de caractères `tableau_text` avec une taille de 20 pour stocker le texte saisi.
2. On demande à l'utilisateur de saisir un texte de taille maximale de 19 caractères à l'aide de la fonction `scanf`.
3. On demande également à l'utilisateur de choisir une lettre spéciale qui aura un poids multiplicatif de 4 dans le calcul de la somme.
4. On initialise la variable `sum` à 0, qui va contenir la somme des positions des caractères.
5. On itère sur chaque caractère du tableau `tableau_text` en utilisant une boucle `for`.
6. À chaque itération, on récupère le caractère courant dans la variable `current_char`.
7. Si le caractère est une lettre de l'alphabet, on détermine sa position dans l'alphabet en utilisant les fonctions `toupper` et `isupper` de la bibliothèque `<ctype.h>`.
8. Si le caractère est égal à la lettre spéciale choisie, on ajoute 4 à la somme. Sinon, si c'est une majuscule, on ajoute deux fois sa position à la somme. Sinon, c'est une minuscule et on ajoute simplement sa position à la somme.
9. Si le caractère n'est pas une lettre de l'alphabet, on soustrait 1 à la somme.
10. Une fois la boucle terminée, on affiche la somme calculée à l'utilisateur.

Ce programme permet ainsi de calculer la somme des positions des caractères dans l'alphabet en suivant les règles spécifiées dans l'énoncé.

## Programme de génération de mots de passe et recherche de configuration

### Code en langage C

```c
#include <stdio.h>
#include <stdlib

.h>
#include <string.h>

typedef struct {
    int letter_value;
    int uppercase_multiplier;
    char special_letter;
} Configuration;

int hash(const char* text, const Configuration* config) {
    int sum = 0;

    for (int i = 0; i < 20; i++) {
        char current_char = text[i];

        if (current_char == '\0') {
            break;  // Sortir de la boucle si on atteint la fin de la chaîne
        }

        if (isalpha(current_char)) {
            if (toupper(current_char) == config->special_letter) {
                sum += config->letter_value;
            } else if (isupper(current_char)) {
                sum += (current_char - 'A' + 1) * config->uppercase_multiplier;
            } else {
                sum += current_char - 'a' + 1;
            }
        }
    }

    return sum;
}

void generatePasswords(int knownHashes[], int unknownHash) {
    char passwords[100][3];
    int count = 0;

    for (int c1 = 32; c1 <= 122; c1++) {
        for (int c2 = 32; c2 <= 122; c2++) {
            char password[3];
            password[0] = (char)c1;
            password[1] = (char)c2;
            password[2] = '\0';

            int hash = hash(password, &config);

            for (int i = 0; i < 3; i++) {
                if (knownHashes[i] == unknownHash) {
                    strcpy(passwords[count], password);
                    count++;
                    break;
                }
            }
        }
    }

    printf("Liste des mots de passe possibles :\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", passwords[i]);
    }
}

int main() {
    Configuration config;

    config.letter_value = 1;
    config.uppercase_multiplier = 1;
    config.special_letter = 'A';

    int knownHashes[3] = { 20, 31, 31 };
    int unknownHash;

    printf("Veuillez entrer le hash du mot de passe inconnu : ");
    scanf("%d", &unknownHash);

    generatePasswords(knownHashes, unknownHash);

    return 0;
}
```

### Explications

Ce programme en langage C permet de générer des mots de passe de taille 2 et de rechercher la configuration de hachage utilisée pour produire un mot de passe inconnu. Voici comment il fonctionne :

1. On définit une structure `Configuration` qui contient les paramètres de calcul du hachage : `letter_value` (valeur d'une lettre), `uppercase_multiplier` (multiplicateur pour les majuscules) et `special_letter` (lettre spéciale).
2. On définit une fonction `hash` qui prend en paramètres un texte et une structure `Configuration`, et qui retourne le résultat du hachage en suivant les règles spécifiées dans l'énoncé.
3. On définit une fonction `generatePasswords` qui prend en paramètres les hashs connus des mots de passe, ainsi que le hash d'un mot de passe inconnu. Cette fonction génère tous les mots de passe possibles de taille 2 et vérifie si leur hash correspond au hash inconnu. Les mots de passe correspondants sont stockés dans un tableau `passwords` et affichés à l'utilisateur.
4. Dans la fonction princip

ale `main`, on initialise la structure `Configuration` avec des valeurs arbitraires.
5. On définit un tableau `knownHashes` qui contient les hashs connus des mots de passe.
6. On demande à l'utilisateur d'entrer le hash du mot de passe inconnu.
7. On appelle la fonction `generatePasswords` en lui passant les hashs connus et le hash inconnu.
8. La fonction `generatePasswords` génère les mots de passe possibles, recherche ceux qui produisent le hash inconnu, les stocke dans le tableau `passwords` et les affiche à l'utilisateur.

Ce programme permet ainsi de générer des mots de passe et de rechercher la configuration de hachage utilisée pour produire un mot de passe inconnu, en se basant sur les hashs connus.
