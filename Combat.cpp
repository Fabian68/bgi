#include "Combat.h"
#include "Affichage.h"
#include "Experiences.h"
#include <iostream>
#include "Aleatoire.h"

Combat::Combat(Equipes  & Joueur, Equipes  & Ia,Zones & Z,Animaux & A,Orbes & O) : _joueur{Joueur}, _ia{Ia},_tour{0}
{
	int somme = 0;
	int max = INT_MIN;
	int nombrePersonnages = _joueur.taille() + _ia.taille();
	int xp;
	xp = _ia.xpDonner();
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
	int nbFoisJouer = 0;
	int nbJouerPourAugmenterTour = nombrePersonnages / 2;
	Affichage().affichageTexte(5, 5, "Tour : " + std::to_string(_tour + 1));
	while (_joueur.estEnVie() && _ia.estEnVie()) {
		for (int i = 0;i < _quiJoue.size();i++) {
			if ((_joueur.estEnVie() && _ia.estEnVie())) {
					if (_quiJoue[i]->estEnVie()) {
						nbFoisJouer++;
						if (nbFoisJouer%nbJouerPourAugmenterTour == 0) {
							_tour++;
							Affichage().affichageTexte(5, 5, "Tour : " + std::to_string(_tour+1));
							for (int i = 0; i < _joueur.taille(); i++) {
								if (_joueur[i]->estEnVie()) {
									_joueur[i]->passif(_tour);
								}
							}
							for (int i = 0; i < _ia.taille(); i++) {
								if (_ia[i]->estEnVie()) {
									_ia[i]->passif(_tour);
								}
							}
						}
					
						_quiJoue[i]->attaqueEnnemis();
					}
			}
		}
	}
	if (_joueur.estEnVie()) {
		Z.niveauBattu();
		Experiences E;
		
		_joueur.ajouterExperience(xp, E);
		tirageRecompenses(Z, A, O);
	}
	Affichage().dessinerDeuxEquipes(_joueur, _ia);
	std::cout << "Combat finis" << std::endl;
}

void Combat::tirageRecompenses(Zones Z,Animaux A,Orbes O) {
	int indiceJoueur;
	int chanceTirage = Z.niveauActuel() * Z.niveauActuel() + Z.niveauMax();
	int nombreDuTirage;
	//Pour chaque perso
	for (int i = 0; i < _joueur.taille(); i++) {
		//Pour chaque animal
		indiceJoueur = _joueur[i]->id();
		for (int j = 0; j < 9; j++) {
			//Pour chaque rarete animal
			for (int k = 1; k <= 5; k++) {
				nombreDuTirage = pow(10000, k) ;
				if (Aleatoire(0, nombreDuTirage).entier() < chanceTirage) {
					if (!A.animalDebloquer(indiceJoueur, j, k)) {
						A.deblocageAnimal(indiceJoueur, j, k, _joueur[i]->nom());
					}
				}
			}
		}
		//Pour chaque rareter d'orbe
		for (int j = 1; j <= 5; j++) {
			nombreDuTirage = pow(10000, j) ;
			if (Aleatoire(0, nombreDuTirage).entier() < chanceTirage) {
				if (!O.orbeDebloquer(indiceJoueur,j)) {
					O.deblocageOrbe(indiceJoueur, j, _joueur[i]->nom());
				}
			}
		}
	}
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

