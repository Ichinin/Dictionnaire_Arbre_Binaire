// ArbreBinaireDictionnaire.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Arbre.h"

template<typename E>
Noeud<E> ajouterMot(string mot, Noeud<E> noeud);


int main()
{
	Arbre<char> *dico = new Arbre<char>();
	

	char *mot = "these";
	char *mot2 = "thesard";
	Noeud<char> racine = ajouterMot(mot, dico->getRacine());
	dico->setRacine(racine);

	//ajouterMot(mot2, dico->getRacine());


	//afficherDict(*dico);
	//cin.get();

	system("PAUSE");
    return 0;
}

template<typename E>
Noeud<E> ajouterMot(string mot, Noeud<E> noeud)
{

	if (mot.length() != 0) {
		char lettre = mot[0];
		string newMot = mot.substr(1, mot.length());
		// Si noeud est vide
		if (noeud.data == 0) {
			noeud.setData(lettre);
			// S'il reste encore des lettres dans le mot
			if (newMot.length() > 0) {
				noeud.setGauche(new Noeud<char>());
				ajouterMot(newMot, *noeud.gauche);
			}
		}
		// Si noeud non vide
		else {
			// Si la lettre est la meme que le noeud <!Il faut faire le test sur son fils gauche et non pas lui même !>
			if (noeud.data == lettre) {
				if (noeud.gauche == 0) {
					noeud.setGauche(new Noeud<char>());
				}
				ajouterMot(newMot, *noeud.gauche);
			}
			// Si la lettre n'est pas la meme
			else {
				if (noeud.droite == 0) {
					noeud.setDroit(new Noeud<char>());
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
	
	return noeud;
}

