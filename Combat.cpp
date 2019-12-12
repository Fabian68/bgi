#include "Combat.h"
#include "Affichage.h"
#include <iostream>

Combat::Combat(Equipes  & Joueur, Equipes  & Ia) : _joueur{Joueur}, _ia{Ia}
{
	int somme = 0;
	int max = INT_MIN;
	int nombrePersonnages = _joueur.taille() + _ia.taille();

	std::vector<int> nombreTourJoueur(_joueur.taille());
	std::vector<int> nombreTourIa(_ia.taille());
	for (int i = 0;i < _joueur.taille();i++) {
		somme += _joueur.perso(i)->vitesse();
	}
	for (int i = 0;i < _ia.taille();i++) {
		somme += _ia.perso(i)->vitesse();
	}
	int moyenne = somme / nombrePersonnages;

	for (int i = 0;i < _joueur.taille();i++) {
		nombreTourJoueur[i] = ceil((_joueur.perso(i)->vitesse()*1.0) / (moyenne*1.0));
		if (nombreTourJoueur[i] > max) {
			max = nombreTourJoueur[i];
		}
	}
	for (int i = 0;i < _ia.taille();i++) {
		nombreTourIa[i] = ceil((_ia.perso(i)->vitesse() *1.0) / (moyenne*1.0));
		if (nombreTourIa[i] > max) {
			max = nombreTourIa[i];
		}
		std::cout << max << std::endl;
	}
	for (int j = max;j > 0;j--) {
		for (int i = 0;i < _joueur.taille();i++) {
			if (nombreTourJoueur[i] >= j) {
				_quiJoue.push_back(_joueur.perso(i));
			}
		}
		for (int i = 0;i < _ia.taille();i++) {
			if (nombreTourIa[i] >= j) {
				_quiJoue.push_back(_ia.perso(i));
			}
		}
	}
	Affichage().dessinerDeuxEquipes(_joueur, _ia);
	while (_joueur.estEnVie() && _ia.estEnVie()) {
		for (int i = 0;i < _quiJoue.size();i++) {
			if ((_joueur.estEnVie() && _ia.estEnVie())) {
					if (_quiJoue[i]->estEnVie()) {
						_quiJoue[i]->attaqueEnnemis();
					}
			}
		}
	}
	
	std::cout << "Combat finis" << std::endl;
}


Combat::~Combat()
{
}



/*
void InitQuiJoue(){
	long long int somme = 0;
	for(int i=PREMIER;i<=CINQUIEME;i++) {
		somme+=PersoCarac[Equipe[TEAM1][i]][AGILITE];
		somme+=PersoCarac[Equipe[TEAM2][i]][AGILITE];
	}
	int Ratio[10];
	for(int i=0;i<=4;i++) {
		Ratio[i]=static_cast<int>(PersoCarac[Equipe[TEAM1][i]][AGILITE]/(1.0*somme/12));
		Ratio[i+5]=static_cast<int>(PersoCarac[Equipe[TEAM2][i]][AGILITE]/(1.0*somme/12));
	}

  for(double i=0.9;i>-0.1;i=i-0.1) {
	for(int j=0;j<=4;j++) {
		if(Ratio[j]>=i) {
			QuiJoue.push_back(Equipe[TEAM1][j]);
		  }
		if(Ratio[j+5]>=i) {
			QuiJoue.push_back(Equipe[TEAM2][j]);
		  }
	  }

  }
}
*/

