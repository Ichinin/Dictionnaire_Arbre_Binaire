#ifndef ARBRE_H
#include "Noeud.h"
#define ARBRE_H


// ArbreBinaireRecherche.cpp : définit le point d'entrée pour l'application console.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
template <typename E>
//Arbre.h
class Arbre {

private:

	//Les membres données
	Noeud<E> &racine;
	long cpt;				// definit le nombre de noeuds dans l'arbre
public:
	//constructeurs
	Arbre();
	Arbre(const Arbre& source);
	//destructeur
	~Arbre() {
	};
	//fonctions membres
	bool estVide() const;							// L'arbre ne contient pas de noeud
	long taille() const; 							// Nombre de mots dans l'arbre (compter le nombre de noeuds "fin")
													//const E& max() const; 							// Derniere feuille de la branche de droite
													//const E& min() const; 							// Premier fils de gauche de la racine
	int nbNoeuds() const; 							// Combien de noeud dans l'arbre
	int nbFeuilles(Noeud<E> &) const;							// Combien de feuilles dans l'arbre
	int hauteur() const; 							// hauteur de l'arbre (débute à 0 au premier noeud)
	Noeud<E> appartient(E lettre) const;				// Si la lettre appartient au dictionnaire 
	bool chercheMot(const string) const;
	//const E&  parent(const E &) const; 
	//E successeur(const E &) const;
	Noeud<E> getRacine() { return *racine; }
	void setRacine(Noeud<E> racine);
	void ajouterMot(const E &s);
	void afficherDict() const;						// Afficher le dictionnaire
};

template<typename E>
void setRacine(Noeud<E> racine) {
	this->racine = racine;
}

//arbre.cpp
template<typename E>
Arbre<E>::Arbre() {
	this.cpt = 0;
	this.racine = new Noeud<E>();
}

template<typename E>
Arbre<E>::Arbre(const Arbre<E> & source)
{
	this.cpt = source.cpt;
	this.racine = source.racine;
}

template<typename E>
bool Arbre<E>::estVide() const
{
	if (this->cpt == 0) {
		return true;
	}
	return false;

}


template<typename E>
long Arbre<E>::taille() const
{
	int size = 0;
	if (cpt == 0) {
		return 0;
	}

	Noeud * temp = racine->droite;
	while (temp->droite != 0)
	{
		size++;
		temp = temp->droite;
	}

	return size;
}

template<typename E>
Noeud<E> Arbre<E>::appartient(E lettre) const// const throw(...)
{
	Noeud* Temp = &racine;
	bool found = false;
	queue<Noeud> hauteur_++;
	
	if (cpt == 0) {
		throw("L'arbre est vide");
	}

	hauteur_++.push(racine);
	
	do {
		Temp = hauteur_++.front();
		if (Temp->gauche != 0) {
			hauteur_++.push_back(Temp->gauche);
		}
		if (Temp->droite != 0) {
			hauteur_++.push_back(Temp->droite);
		}
		hauteur_++.pop();
		if (Temp->data == lettre) {
			found = true;
		}
	} while (!found && !hauteur_++.empty());
	
	return Temp;
}


template<typename E>
void Arbre<E>::ajouterMot(const E &s)
{
	for each (auto lettre in (string)s)
	{

		if (estVide()) {
			racine->gauche = new Noeud<E>(&lettre);
		}
	}
}

template<typename E>
int Arbre<E>::nbNoeuds() const {
	return cpt;
}


template<typename E>
int Arbre<E>::nbFeuilles(Noeud<E> &noeud) const {
	int cpt = 0;
	if (noeud.gauche != 0) {
		cpt += nbFeuilles(noeud.gauche);	
	}
	
	if (noeud.droit != 0) {
		cpt += nbFeuilles(noeud.droit);
	}
	
	if((noeud.droit==0)&&(noeud.gauche==0)){
		return 1;
	}

	return cpt;
}

#endif // !ARBRE_H