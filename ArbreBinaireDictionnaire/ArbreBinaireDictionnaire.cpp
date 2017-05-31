// ArbreBinaireDictionnaire.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Arbre.h"
#include <queue>
#include <stack>
#include <fstream>


// Ajoute un mot. Il faut fournir le mot et la racine du dictionnaire. Les mots sont ajoutes dans l'ordre alphabetiques
void ajouterMot(string mot, Noeud<char> &noeud);
// Affiche le dictionnaire mot par mot
void afficherDictionnaire(queue<char> &liste, Noeud<char> &noeud);
// Cherche un mot dans le dictionnaire. Prend la racine du dictionnaire. Renvoie true si mot present
bool chercherMot(string mot, Noeud<char> &noeud);
// Supprime un mot du dictionnaire
void enleverMot(string mot, Noeud<char> *noeud);
// Ajoute tous les mots du file dans le dictionnaire
void lireFile(string fileName, Arbre<char> &dico);

int main()
{
	Arbre<char> *dico = new Arbre<char>();
	std::string fileName = "FichierTest/alain.dico";
	//Test des differentes fonctions du dictionnaire
	/*
	char *mot = "las";
	char *mot2 = "lit";
	char *mot3 = "lasse";
	char *mot4 = "bas";
	char *mot5 = "arbre";
	char *mot6 = "abas";
	char *mot7 = "arbuste";


	ajouterMot(mot, *dico->getRacine());
	ajouterMot(mot2, *dico->getRacine());
	ajouterMot(mot3, *dico->getRacine());
	ajouterMot(mot4, *dico->getRacine());
	ajouterMot(mot5, *dico->getRacine());
	ajouterMot(mot6, *dico->getRacine());
	ajouterMot(mot7, *dico->getRacine());

	queue<char> *liste = new queue<char>();
	afficherDictionnaire(*liste, *dico->getRacine());
	cout << endl;

	cout << chercherMot("arbuste", *dico->getRacine()) << endl;
	cout << chercherMot("carotte", *dico->getRacine()) << endl;

	enleverMot("arbre", dico->getRacine());
	afficherDictionnaire(*liste, *dico->getRacine());
	cout << endl;

	enleverMot("las", *dico->getRacine());
	afficherDictionnaire(*liste, *dico->getRacine());
	*/

	// Test avec un des fichiers texte propose
	cout << "AJOUT DES MOTS DANS LE DICTIONNAIRE" << endl;
	lireFile(fileName, *dico);

	cout << "AFFICHAGE DU DICTIONNAIRE" << endl;
	afficherDictionnaire(* new queue<char>(), *dico->getRacine());

	cout << "TEST FONCTION SUPPRIMER MOT DICO" << endl;
	enleverMot("a", dico->getRacine());
	enleverMot("vont", dico->getRacine());
	enleverMot("carotte", dico->getRacine());
	afficherDictionnaire(* new queue<char>(), *dico->getRacine());
	
	cout << "TEST FONCTION RECHERCHE DICO" << endl;
	cout << "1) recherche mot present" << endl;
	string mot1 = "sous";
	if (chercherMot(mot1, *dico->getRacine())) {
		cout << mot1 << " present" << endl;
	}
	else {
		cout << mot1 << " absent" << endl;
	}
	cout << "2) recherche mot absent" << endl;
	string mot2 = "a";
	if (chercherMot(mot2, *dico->getRacine())) {
		cout << mot2 << " present" << endl;
	}
	else {
		cout << mot2 << " absent" << endl;
	}


	system("PAUSE");
	return 0;
}

void lireFile(string fileName, Arbre<char> &dico) {
	std::ifstream input(fileName);

	for (std::string ligne; getline(input, ligne); )
	{
		ajouterMot(ligne, *dico.getRacine());
		cout << ligne << endl;
	}
}

void enleverMot(string mot, Noeud<char> *noeud) {
	// On met tous les noeuds qui constituent le mot
	stack<Noeud<char>* > *listeNoeudsMot = new stack<Noeud<char>*>();
	Noeud<char> *noeudCourant = new Noeud<char>();
	noeudCourant = noeud;
	bool continuer = true;

	int numChar = 0;
	char lettre = mot[numChar];

	//Extraction de la liste des noeuds constituant le mot
	while (continuer) {
		//Si le noeud courant correspond à la lettre
		if (noeudCourant->data == lettre) {
			//Si c'est la fin du mot
			if (numChar == (mot.length() - 1)) {
				if (noeudCourant->fin) {
					listeNoeudsMot->push(noeudCourant);
				}
				continuer = false;
			}
			//Ce n'est pas la fin du mot
			else {
				listeNoeudsMot->push(noeudCourant);

				if (noeudCourant->gauche != 0) {
					numChar++;
					lettre = mot[numChar];
					noeudCourant = noeudCourant->gauche;
				}
				else {
					continuer = false;
				}

			}
		}
		else {
			if (noeudCourant->droite != 0) {
				noeudCourant = noeudCourant->droite;
			}
			else {
				continuer = false;
			}
		}
	}

	//Si le mot est présent
	if (listeNoeudsMot->size() == mot.length()) {

		while (!listeNoeudsMot->empty()) {
			noeudCourant = listeNoeudsMot->top();
			listeNoeudsMot->pop();

			//Si le noeud courant as un fils gauche
			if (noeudCourant->gauche != 0) {
				noeudCourant->fin = false;
			}
			else {
				//S'il as un fils droit
				if (noeudCourant->droite != 0) {
					Noeud<char>* temp = new Noeud<char>();
					temp = noeudCourant->droite;
					noeudCourant->data = temp->data;
					noeudCourant->droite = temp->droite;
					noeudCourant->gauche = temp->gauche;
					noeudCourant->fin = temp->fin;
				}
				//s'il n'a ni fils droit ni fils gauche
				else if (!listeNoeudsMot->empty()) {
						Noeud<char>* parent = listeNoeudsMot->top();

						if (parent->gauche->data == noeudCourant->data) {
							parent->gauche = 0;
						}
						else {
							parent->droite = 0;
						}

						delete noeudCourant;
				}
					
			}
		}
	}
	else {
		cout << "Le mot: " << mot << " n'est pas present" << endl;
	}


}

bool chercherMot(string mot, Noeud<char> &noeud) {
	char lettre = mot[0];
	string newMot = mot.substr(1, mot.length());

	// Si le noeud courant correspond a la lettre
	if (noeud.data == lettre) {
		// Si il reste encore des lettres
		if (newMot.length() > 0) {
			// S'il a un noeud gauche
			if (noeud.gauche != 0) {
				return chercherMot(newMot, *noeud.gauche);
			}
			// S'il n'a pas de noeud gauche
			else {
				return false;
			}
		}
		// S'il ne reste plus de lettres
		else
			if (noeud.fin) {
				return true;
			}
			else { return false; }
	}
	// Si le noeud ne corrspond a la lettre
	else {
		// On regarde dans le noeud droit
		if (noeud.droite != 0) {
			return chercherMot(mot, *noeud.droite);
		}
		// La lettre n'est pas dans l'arbre
		else {
			return false;
		}
	}

}

void afficherDictionnaire(queue<char> &liste, Noeud<char> &noeud) {

	queue<char> *copie = new queue<char>(liste);

	if (noeud.fin) {
		queue<char> *copie1 = new queue<char>(liste);
		copie1->push(noeud.data);
		int size = copie1->size();
		for (int i = 0; i < size; i++) {
			cout << copie1->front();
			copie1->pop();
		}
		cout << endl;
		delete copie1;
	}
	if (noeud.gauche != 0) {
		liste.push(noeud.data);
		afficherDictionnaire(liste, *noeud.gauche);
	}

	if (noeud.droite != 0) {
		afficherDictionnaire(*copie, *noeud.droite);
	}

	delete copie;
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
			else {
				noeud.fin = true;
			}
		}
		// Si noeud non vide
		else {
			// Si la lettre est la meme que le noeud 
			if (noeud.data == lettre) {
				if (noeud.gauche == 0) {
					noeud.setGauche(new Noeud<char>());
				}
				if (newMot.length() > 0) {
					ajouterMot(newMot, *noeud.gauche);
				}
				else {
					noeud.fin = true;
				}
			}
			// Si la lettre n'est pas la meme
			else {
				if (noeud.droite == 0) {
					noeud.setDroit(new Noeud<char>());
				}
				// Si la nouvelle lettre est plus petite que la lettre courante (alphabetiquement)
				if (noeud.data > lettre) {
					Noeud<char> *aux = new Noeud<char>();
					*aux = noeud;
					noeud.data = lettre;
					noeud.droite = aux;
					noeud.setGauche(new Noeud<char>());
					noeud.fin = false;
					if (newMot.length() > 0) {
						ajouterMot(newMot, *noeud.gauche);
					}
					else {
						noeud.fin = true;
					}

				}
				else {
					ajouterMot(mot, *noeud.droite);
				}

			}
		}
	}
	else {
		cout << "Erreur : vous avez saisi un mot vide" << endl;
	}
}

