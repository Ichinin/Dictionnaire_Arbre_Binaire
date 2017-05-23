// ArbreBinaireDictionnaire.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Arbre.h"


void ajouterMot(string mot, Noeud<char> noeud);


int main()
{
	Arbre<char> *dico = new Arbre<char>();

	char *mot = "these";
	char *mot2 = "thesard";
	ajouterMot(mot, dico->getRacine());
	ajouterMot(mot2, dico->getRacine());
	//afficherDict(*dico);
	//cin.get();
    return 0;
}

void ajouterMot(string mot, Noeud<char> noeud)
{
	if (mot.length() != 0) {
		char lettre = mot[0];
		string newMot = mot.substr(1, mot.length());
		// Si noeud est vide
		if (noeud.data == 0) {
			noeud.data = lettre;
			// S'il reste encore des lettres dans le mot
			if (newMot.length() > 0) {
				noeud.gauche = new Noeud<char>();
				ajouterMot(newMot, *noeud.gauche);
			}
		}
		// Si noeud non vide
		else {
			// Si la lettre est la meme que le noeud
			if (noeud.data == lettre) {
				if (noeud.gauche == 0) {
					noeud.gauche = new Noeud<char>();
				}
				ajouterMot(newMot, *noeud.gauche);
			}
			// Si la lettre n'est pas la meme
			else {
				if (noeud.droite == 0) {
					noeud.droite = new Noeud<char>();
				}
				ajouterMot(mot, *noeud.droite);
			}
		}
		// Si le mot est fini
		if (newMot.length() == 0) {
			noeud.fin = true;
		}
	}
	else {
		cout << "bouffon" << endl;
	}
}

