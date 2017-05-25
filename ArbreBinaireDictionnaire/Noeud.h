#pragma once
template<typename E>
class Noeud
{
public:
	Noeud() : gauche(0), data(0), droite(0), hauteur(0), debut(false), fin(false) {}
	Noeud(const E &d) : gauche(0), data(d), droite(0), hauteur(0), debut(false), fin(false) {}
	void setGauche(Noeud * noeudGauche);
	void setDroit(Noeud * noeudDroit);
	void setData(E donnee);
	E getData();
	~Noeud();
	E data;
	Noeud *gauche;
	Noeud *droite;
	int card;
	int hauteur;
	bool debut;
	bool fin;


};

template<typename E>
E Noeud<E>::getData() {
	return data;
}
template<typename E>
void Noeud<E>::setData(E donnee) {
	data = donnee;
}

template<typename E>
void Noeud<E>::setGauche(Noeud* noeudGauche) {
	gauche = noeudGauche;
}

template<typename E>
void Noeud<E>::setDroit(Noeud* noeudDroit) {
	droite = noeudDroit;
}

template<typename E>
Noeud<E>::~Noeud()
{
}
