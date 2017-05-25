// ArbreBinaireDictionnaire.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Arbre.h"


void ajouterMot(string mot, Noeud<char> &noeud);


int main()
{
	Arbre<char> *dico = new Arbre<char>();
	

	char *mot = "las";
	char *mot2 = "lit"; 
	char *mot3 = "lasse";
	char *mot4 = "bas";
	char *mot5 = "arbre";
	char *mot6 = "abas";
	char *mot7 = "arbuste";
	//Noeud<char> racine = ajouterMot(mot, dico->getRacine());
	//dico->setRacine(racine);
	
	ajouterMot(mot, *dico->getRacine());
	ajouterMot(mot2, *dico->getRacine());
	ajouterMot(mot3, *dico->getRacine());
	ajouterMot(mot4, *dico->getRacine());
	ajouterMot(mot5, *dico->getRacine());
	ajouterMot(mot6, *dico->getRacine());
	ajouterMot(mot7, *dico->getRacine());

	//afficherDict(*dico);
	//cin.get();

	system("PAUSE");
    return 0;
}


void ajouterMot(string mot, Noeud<char> &noeud)
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
			// Si la lettre est la meme que le noeud 
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
				

				if (noeud.data > lettre) {
					Noeud<char> *aux = new Noeud<char>();
					*aux = noeud;
					noeud.data = lettre;
					noeud.droite = aux;

					if (newMot.length() > 0) {
						noeud.setGauche(new Noeud<char>());
						ajouterMot(newMot, *noeud.gauche);
					}
					
				}
				else {
					ajouterMot(mot, *noeud.droite);
				}
				
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

