#pragma once
template<typename E>
class Noeud
{
public:
	Noeud() : gauche(0), data(0), droite(0), hauteur(0), debut(false), fin(false) {}
	Noeud(const E &d) : gauche(0), data(d), droite(0), hauteur(0), debut(false), fin(false) {}
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
Noeud<E>::~Noeud()
{
}
