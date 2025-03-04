ft_printf

Description

ft_printf est une réimplémentation de la fonction standard printf en C. Elle permet d'afficher du texte formaté sur la sortie standard tout en prenant en charge plusieurs types de conversions.

Fonctionnalités

La fonction ft_printf gère les conversions suivantes :

%c : Affiche un caractère

%s : Affiche une chaîne de caractères

%p : Affiche un pointeur en notation hexadécimale

%d : Affiche un entier en base 10 (décimal signé)

%i : Affiche un entier en base 10 (identique à %d)

%u : Affiche un entier non signé en base 10

%x : Affiche un entier en hexadécimal (lettres minuscules)

%X : Affiche un entier en hexadécimal (lettres majuscules)

%% : Affiche un pourcentage

Compilation et Utilisation

Compilation

Pour compiler la bibliothèque, exécutez la commande suivante :

make

Cela génère une bibliothèque libftprintf.a que vous pouvez utiliser dans vos projets.

Utilisation

Incluez le fichier d'en-tête dans votre projet :

#include "ft_printf.h"

Puis, utilisez ft_printf comme printf :

ft_printf("Hello %s!", "world");

Exemples

ft_printf("Caractère : %c\n", 'A');
ft_printf("Chaîne : %s\n", "Bonjour");
ft_printf("Entier : %d\n", 42);
ft_printf("Hexadécimal : %x\n", 255);
ft_printf("Pointeur : %p\n", &main);

Nettoyage

Pour supprimer les fichiers objets et la bibliothèque compilée, utilisez :

make fclean

Auteur

Projet réalisé par hinel-mo dans le cadre de l'école 42.

Ce projet a été développé pour apprendre à manipuler les fonctions variadiques et la gestion de formatage en C.