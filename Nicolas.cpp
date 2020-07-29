#include "Nicolas.h"
#include "Aleatoire.h"
#include "Affichage.h"


Nicolas::Nicolas(Experiences E,Orbes O,Animaux A, Objets Obj) : Personnage(1, E,O,A, Obj, "Niquola", 4, 3, 3, 10, 10, 50, 0, 50, 25, 0) {}


void Nicolas::attaqueEnnemis() {
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	std::string a = nom();

	int i, j;
	switch (choix) {

	case 0:
		DEGATS = degats(0.6, 0.8);
		Affichage().dessinerTexte(nom() + " Coup de couteau ");
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());

		if (attaqueDouble() && equipeEnnemi().estEnVie()) {
		
			Affichage().dessinerTexte(nom() + " Coup de couteau ");
			DEGATS = degats(0.4, 0.7);
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
			ajouterMana(1);
		}
		ajouterMana(1);
		break;
	case 1:
		i = 0;
		j;
		while (i < equipeEnnemi().taille() && !equipeEnnemi()[i]->estEnVie()) {
			i++;
		}
		if (i < equipeEnnemi().taille()) {
			DEGATS = degats(1.0, 2.5);
			Affichage().dessinerTexte(nom() + " Coup de pompe ");
			
			Attaque(DEGATS, equipeEnnemi()[i]);
			if (attaqueDouble()) {
				Attaque(DEGATS, equipeEnnemi()[i]);
			}
			i++;
		}
		j = i;
		while (i < equipeEnnemi().taille()) {
			if (equipeEnnemi()[i]->estEnVie()) {
				DEGATS = degats(0.10, 0.25);
				Affichage().dessinerTexte(nom() + " residues de pompes ");
				Attaque(DEGATS, equipeEnnemi()[i]);
				if (attaqueDouble()) {
					Attaque(DEGATS, equipeEnnemi()[i]);
				}
			}
			i++;
		}
		
		if (attaqueDouble()) {
			while (j < equipeEnnemi().taille()) {
				if (equipeEnnemi()[j]->estEnVie()) {
					DEGATS = degats(0.10, 0.25);
					Affichage().dessinerTexte(nom() + " residues de pompes ");
					Attaque(DEGATS, equipeEnnemi()[j]);
					if (attaqueDouble()) {
						Attaque(DEGATS, equipeEnnemi()[j]);
					}
				}
				j++;
			}
		}
		ajouterMana(-1);
		break;
	case 2:

		Affichage().dessinerTexte(nom() + " fusil d'assaut ! ");
		for (int i = 0; i< Aleatoire(20, 40).entier() && equipeEnnemi().estEnVie() ; i++) {
			DEGATS = degats(0.10, 0.25);
			Attaque(DEGATS, equipeEnnemi().plusFort());
		}
		if (attaqueDouble() && equipeEnnemi().estEnVie()) {
			for (int i = 0; i < Aleatoire(10, 50).entier() && equipeEnnemi().estEnVie(); i++) {
				DEGATS = degats(0.05, 0.30);
				Attaque(DEGATS, equipeEnnemi().plusFort());
			}
		}
		ajouterMana(-2);
		break;
	case 3:
		Affichage().dessinerTexte(nom() + " partage Equipement Minecraft !");
		for (int i = 0; i <equipeAllier().taille(); i++) {
			if (equipeAllier()[i] != this && equipeAllier()[i]->estEnVie()) {
				equipeAllier()[i]->ajouterForce(round(equipeAllier()[i]->force() / 10.0));
			}
		}
		ajouterMana(-3);
		break;
	}
}

void Nicolas::passif(int tour)
{
	if ((tour+1)%20==0 ) {
	
		Affichage().dessinerTexte(this->nom() + " ce fait mal en voulant impressioner ses amis ! ");
		reduireVie(vie() / 2);
		ajouterForce(niveau());
	}
	if (tour>100) {
		int Degats = degats(tour/100.0, tour/50.0);
		Affichage().dessinerTexte(this->nom() + " est enerver le combat est trop long ! ");
		equipeEnnemi().attaqueZone(Degats, this);
	}
}

void Nicolas::passifDefensif()
{
	if (Aleatoire(0, 101).entier() <= 10) {
		int Degats = degats(0.25, 0.5);
		Affichage().dessinerTexte(this->nom() + " contre attaque ");
		Attaque(Degats, equipeEnnemi().plusProcheVivant());
	}
}
