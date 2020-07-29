#include "Florian.h"
#include "Affichage.h"
#include "Aleatoire.h"

Florian::Florian(Experiences E, Orbes O, Animaux A, Objets Obj) : Personnage(11, E, O, A, Obj, "Florian", 8, 1, 1, 20, 20, 20, 0, 0, 0, 0) {}

void Florian::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	
	switch (choix) {

	case 0:
		SOINS = degats(0.25, 0.75);
		Affichage().dessinerTexte(nom() + " se détend ");
		bouclier(SOINS, this);

		if (attaqueDouble() && equipeEnnemi().estEnVie()) {

			Affichage().dessinerTexte(nom() + " se trompe ");
			DEGATS = degats(0.37, 1.37);
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
			ajouterMana(-2);
		}
		ajouterMana(3);
		break;
	case 1:
		Affichage().dessinerTexte(nom() + " bois un coup");

		SOINS = degats(0.75, 1.75);
		soigner(SOINS, this);

		if (habile() && equipeEnnemi().estEnVie()) {
			Affichage().dessinerTexte(nom() + " rote ");
			DEGATS = degats(0.15, 0.25);
			DEGATS += static_cast<int>(Aleatoire(0.02, 0.07).decimal() * vieMax()+ Aleatoire(0.04, 0.14).decimal() * vie()) ;
			equipeEnnemi().attaqueZone(DEGATS, this);
			ajouterMana(-4);
		}
		ajouterMana(3);
		break;
	case 2:

		Affichage().dessinerTexte(nom() + " sert l'apero ");
		for (int i = 0;i < equipeAllier().taille();i++) {
			SOINS = soins(0.33, 0.99);
			soigner(SOINS, equipeAllier()[i]);
			
		}
		if (habile() && attaqueDouble()) {
			Affichage().dessinerTexte(nom() + " est fauché et fauche les ennemis ");
			DEGATS = degats(0.20, 0.60) + static_cast<int>(Aleatoire(0.6, 2.6).decimal() * vitesse());
			equipeEnnemi().attaqueZone(DEGATS, this);
			ajouterMana(-2);
		}
		ajouterMana(1);
		
		break;
	case 3:
		Affichage().dessinerTexte(nom() + " fait du bilboquet et touche un ennemi ! ");
		DEGATS = degats(0.65, 6.5);
		Attaque(DEGATS, equipeEnnemi().aleatoireEnVie());
		ajouterMana(-3);
		break;
	}
}

void Florian::passif(int tour)
{
	if ((tour + 1) % 5 == 0) {
		Affichage().dessinerTexte(nom() + " prie pour l'équipe ! ");
		for (int i = 0;i < equipeAllier().taille();i++) {
			equipeAllier()[i]->ajouterReduction(1);
			if (habile()) {
				equipeAllier()[i]->ajouterReduction(2);
				if (attaqueDouble()) {
					equipeAllier()[i]->ajouterReduction(3);
				}
			}
		}
	}
	if ((tour + 1) % 20 == 0) {
		Affichage().dessinerTexte(nom() + " joue sa piece de théatre ! ");
		for (int i = 0;i < equipeAllier().taille();i++) {
			equipeAllier()[i]->ajouterChanceDoubleAttaque(5);
			equipeAllier()[i]->ajouterChanceHabileter(5);
			equipeAllier()[i]->ajouterCoupCritique(5);
			equipeAllier()[i]->ajouterDegatsCritique(10);
			if (habile()) {
				equipeAllier()[i]->ajouterChanceDoubleAttaque(6);
				equipeAllier()[i]->ajouterChanceHabileter(6);
				equipeAllier()[i]->ajouterCoupCritique(6);
				equipeAllier()[i]->ajouterDegatsCritique(12);
			}
			if (attaqueDouble()) {
				equipeAllier()[i]->ajouterChanceDoubleAttaque(8);
				equipeAllier()[i]->ajouterChanceHabileter(8);
				equipeAllier()[i]->ajouterCoupCritique(8);
				equipeAllier()[i]->ajouterDegatsCritique(16);
				if (habile()) {
					equipeAllier()[i]->ajouterChanceDoubleAttaque(10);
					equipeAllier()[i]->ajouterChanceHabileter(10);
					equipeAllier()[i]->ajouterCoupCritique(10);
					equipeAllier()[i]->ajouterDegatsCritique(20);
				}
			}
		}
	}
}

void Florian::passifDefensif()
{
	Affichage().dessinerTexte(nom() + " est protéger par jesus ! ");
	int SOINS = soins(0.2, 2.0);
	soigner(SOINS, this);
}
