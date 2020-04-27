#include "Magicien.h"
#include "Affichage.h"

Magicien::Magicien(int LVL, std::string nom, int difficulte, int animal, int rareteAnimal) : Personnage(LVL, nom, 1, 3, 6, 5, 5, -50, 1, 1, 1, 1, animal, rareteAnimal), stade{1}
{
	setNom("Petit magicien");
}

void Magicien::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	int nb = equipeAllier().nbEnVie();
	double ratio = vieMax() / vie();
	int indice;
	int mult1 = 0, mult2 = 0;
	switch (choix) {

	case 0:
		if (stade <= 3) {
			DEGATS = degats(0.6, 0.6 + 0.1 * stade * 2);
			Affichage().dessinerTexte(nom() + " boule de feu ");
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		}
		else if (stade == 4) {
			Affichage().dessinerTexte(nom() + " 3 boule de feu ");
			for (int i = 0;i < 3;i++) {
				DEGATS = degats(0.9, 1.6);
				Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
			}
		}
		else if (stade == 5) {
			Affichage().dessinerTexte(nom() + " météores ! ");
			for (int i = 0;i < 5;i++) {
				DEGATS = degats(2.6, 5.2);
				Attaque(DEGATS, equipeEnnemi().aleatoireEnVie());
			}
		}
		ajouterMana(1);
		break;
	case 1:

		if (stade <= 3) {
			equipeEnnemi().plusProcheVivant()->ajouterReduction(-stade);
			DEGATS = degats(0.8, 1.0 + 0.1 * stade * 2);
			Affichage().dessinerTexte(nom() + " pique de glace ");
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		}
		else if (stade == 4) {
			Affichage().dessinerTexte(nom() + " 3 pique de glace ");

			equipeEnnemi().plusProcheVivant()->ajouterReduction(-2*stade);
			indice = equipeEnnemi().aleatoireEnVie()->id();
			equipeEnnemi()[indice]->ajouterReduction(-2 * stade);
			equipeEnnemi().plusLoinVivant()->ajouterReduction(-2 * stade);
			
			DEGATS = degats(1.2, 1.9);
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());

			DEGATS = degats(1.4, 2.1);
			Attaque(DEGATS, equipeEnnemi()[indice]);

			DEGATS = degats(1.7, 2.4);
			Attaque(DEGATS, equipeEnnemi().plusLoinVivant());
			
		}
		else if (stade == 5) {
			Affichage().dessinerTexte(nom() + " tempete de neige ! ");
			for (int i = 0;i <=30;i++) {
				DEGATS = degats(0.1, 1.0);
				indice = equipeEnnemi().aleatoireEnVie()->id();
				equipeEnnemi()[indice]->ajouterReduction(-3);
				AttaqueBrut(DEGATS, equipeEnnemi()[indice]);
			}
		}
		
		ajouterMana(-1);
		break;
	case 2:

		if (stade <= 3) {
			equipeEnnemi().plusProcheVivant()->ajouterReduction(-stade);
			DEGATS = degats(0.6, 1.0 + 0.1 * stade );
			Affichage().dessinerTexte(nom() + " éclair ");
			AttaqueBrut(DEGATS, equipeEnnemi().plusProcheVivant());
		}
		else if (stade == 4) {
			Affichage().dessinerTexte(nom() + " Tonerre ");

			for (int i = 1;i <= 4;i++) {
				DEGATS = degats(0.4*i, 0.8*i);
				AttaqueBrut(DEGATS, equipeEnnemi().aleatoireEnVie());
			}

		}
		else if (stade == 5) {
			Affichage().dessinerTexte(nom() + "Maelstrom ! ");
			for (int i = 0;i <equipeEnnemi().taille();i++) {
				DEGATS = degats(5.0, 10.0);
				AttaqueBrut(DEGATS, equipeEnnemi()[i]);
			}
		}

		ajouterMana(-1);
		break;
	case 3:
		Affichage().dessinerTexte(nom() + " SOINS HABILE ! ");
		for (int i = 0;i < equipeAllier().taille();i++) {
			SOINS = soins(0.3, 0.9);
			soigner(SOINS, equipeAllier()[i]);
			equipeAllier()[i]->ajouterChanceDoubleAttaque(2);
			equipeAllier()[i]->ajouterChanceHabileter(2);
			equipeAllier()[i]->ajouterCoupCritique(2);
			equipeAllier()[i]->ajouterDegatsCritique(5);
			equipeAllier()[i]->ajouterReduction(5);
			equipeAllier()[i]->ajouterVieMax(vieMax()/10);
		}
		ajouterVieMax(bouclier());
		reduireBouclier(bouclier());
		ajouterMana(-3);
		break;
	}
}

void Magicien::passif(int tour)
{
	if (tour == 20) {
		stade = 2;
		ajouterChanceDoubleAttaque(5);
		ajouterChanceHabileter(5);
		ajouterCoupCritique(5);
		ajouterDegatsCritique(10);
		ajouterReduction(10);
		ajouterVieMax(vieMax());
		setNom("Apprenti Magicien");
		status().ajouterCompteurProteger(4);
	}
	else if (tour == 40) {
		stade = 3;
		ajouterChanceDoubleAttaque(10);
		ajouterChanceHabileter(10);
		ajouterCoupCritique(5);
		ajouterDegatsCritique(20);
		ajouterReduction(20);
		ajouterVieMax(vieMax());
		setNom("Magicien confirmé");
		status().ajouterCompteurProteger(12);
	}
	else if (tour == 80) {
		stade = 4;
		ajouterChanceDoubleAttaque(10);
		ajouterChanceHabileter(10);
		ajouterCoupCritique(5);
		ajouterDegatsCritique(40);
		ajouterReduction(30);
		ajouterVieMax(vieMax());
		setNom("Grand mage");
		status().ajouterCompteurProteger(36);
	}
	else if (tour == 160) {
		stade = 5;
		ajouterChanceDoubleAttaque(10);
		ajouterChanceHabileter(10);
		ajouterCoupCritique(5);
		ajouterDegatsCritique(80);
		ajouterReduction(40);
		ajouterVieMax(vieMax());
		setNom("Archimage");
		status().ajouterCompteurProteger(118);
	}
	if ((tour + 1) % 5 == 0) {
		AjouterBouclier(0.1 * stade * bouclierMax());
		status().ajouterCompteurProteger(5);
		if (stade == 5) {
			attaqueEnnemis();
			status().ajouterCompteurProteger(10);
		}
	}
}

void Magicien::passifDefensif()
{
}
