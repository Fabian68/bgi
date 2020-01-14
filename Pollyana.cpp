#include "Pollyana.h"
#include "Affichage.h"

Pollyana::Pollyana(Experiences E, Orbes O, Animaux A) : Personnage(14, E, O, A, "Pollyana", 6, 1, 3, 0, 30, -20, 0, 80, 0, 0)
{
	
}


void Pollyana::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;

	switch (choix) {

	case 0:
		
		Affichage().dessinerTexte(nom() + " masochisme ! ");
		DEGATS = degats(1.2, 2.4);
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		DEGATS = degats(0.6, 1.2);
		AttaqueBrut(DEGATS, this);

		ajouterMana(1);
		break;
	case 1:
		Affichage().dessinerTexte(nom() + " transfusion ");
		DEGATS = degats(0.2, 0.4);
		AttaqueBrut(DEGATS, equipeEnnemi().plusProcheVivant());
		SOINS = soins(0.6, 1.6);
		soigner(SOINS, this);
		ajouterMana(1);
		break;
	case 2:

		Affichage().dessinerTexte(nom() + " Attaque des ombres ");
		DEGATS = degats(3.0, 9.0);
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		DEGATS = degats(2.0, 7.0);
		AttaqueBrut(DEGATS, this);
		ajouterMana(-2);
		break;
	case 3:

		if (!ombre&& habile()) {
			Affichage().dessinerTexte(nom() + " Pacte avec les ombres ");
			ajouterReduction(70);
			ajouterForce(force());
			reduireVieMax(vieMax() / 2);
			ombre = true;
			setNom("Pollyana des ombres");
		}
		else passif(20);

		ajouterMana(-3);
		break;
	}
}

void Pollyana::passif(int tour)
{
	if (tour % 20 == 0) {
		if (!habile()) {
			Affichage().dessinerTexte(nom() + " Resurection ");
			for (int i = 0;i < equipeAllier().taille();i++) {
				if (!equipeAllier()[i]->estEnVie()) {
					equipeAllier()[i]->reduireVieMax(equipeAllier()[i]->vieMax() / 2);
					equipeAllier()[i]->AjouterVie(1);
				}
			}
		}
		else {
			Affichage().dessinerTexte(nom() + " Resurection des ombres");
			for (int i = 0;i < equipeAllier().taille();i++) {
				if (!equipeAllier()[i]->estEnVie()) {
					equipeAllier()[i]->ajouterVieMax(equipeAllier()[i]->vieMax());
					equipeAllier()[i]->AjouterVie(equipeAllier()[i]->vieMax());
				}
			}
		}
	
	}
}

void Pollyana::passifDefensif()
{
	if (!habile()) {
		int DEGATS = degats(0.1, 0.2);
		Attaque(DEGATS, this);
	}
}
