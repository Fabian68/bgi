#include "Moustick.h"
#include "Affichage.h"

Moustick::Moustick(Experiences E, Orbes O, Animaux A, Objets Obj) : Personnage(4, E, O, A, Obj, "Moustick", 3, 4, 3, 0, 0, 0, 0, 0, 0, 0) {}


void Moustick::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	int ratio = 100 * static_cast<int>(1.0 - (vie() * 1.0) / (vieMax() * 1.0));
	ratio = min(99, ratio);
	int ratioPositif = static_cast<int>((vieMax() * 1.0) / (vie() * 1.0));
	ratioPositif = min(ratioPositif, 20);
	setReduction(ratio);
	
	switch (choix) {

	case 0:
		

	
		Affichage().dessinerTexte(nom() + " attaque de base");
		
		for (int i = 0; i < ratioPositif&&equipeEnnemi().estEnVie(); i++) {
			DEGATS = degats(ratioPositif / 8.0, ratioPositif / 4.0);
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
			ajouterMana(1);
		}
		break;
	case 1:
		Affichage().dessinerTexte(nom() + " attaque enrage");
		DEGATS = degats(ratioPositif / 4.0, ratioPositif / 2.0);
		if (bouclier() > bouclierMax() / 2) {
			DEGATS += static_cast<int>(bouclier() * 0.2);
			ajouterBouclier(-bouclierMax() / 2);
			
		}
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		ajouterMana(-1);
		break;
	case 2:

		Affichage().dessinerTexte(nom() + "attaques puissante ! ");
		for (int i = 0; i < ratioPositif && equipeEnnemi().estEnVie(); i++) {
			DEGATS = degats(ratioPositif / 3.0, ratioPositif / 1.5);
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
			ajouterMana(1);
		}
		ajouterMana(-2);
		break;
	case 3:
		Affichage().dessinerTexte(nom() + " nuit de folie ");
		reduireVie(vie() / 2);
		ajouterMana(-3);
		attaqueEnnemis();
		break;
	}
}

void Moustick::passif(int tour)
{
	reduireVie(static_cast<int>(vie() / 20.0));

	int ratio = 100*static_cast<int>(1.0-(vie() * 1.0) / (vieMax() * 1.0));
	ratio = min(99, ratio);
	setReduction(ratio);
}

void Moustick::passifDefensif()
{
	int ratio = 100 * static_cast<int>(1.0 - (vie() * 1.0) / (vieMax() * 1.0));
	ratio = min(99, ratio);
	setReduction(ratio);
}
