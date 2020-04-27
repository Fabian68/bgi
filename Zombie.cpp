#include "Zombie.h"
#include "Affichage.h"

Zombie::Zombie(int LVL, std::string nom, int difficulte, int animal, int rareteAnimal) : Personnage(LVL, nom, 8, 1, 1, 50, 50, 50, 0, 50, 0, 0, animal, rareteAnimal)
{
	if (difficulte == 1) {
		ajouterForce(force());
		ajouterVitesse(vitesse());
		ajouterVie(9 * vie());
	}
	if (difficulte == 2) {
		ajouterForce(force());
		ajouterVitesse(vitesse());
		ajouterVie(19 * vie());
		ajouterReduction(99);
	}
}


void Zombie::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	int cible1;
	int cible2;
	int dernier;
	
	DEGATS = degats(0.5, 2.5);
	Affichage().dessinerTexte(nom() + " mords ");
	cible1 = equipeEnnemi().plusProcheVivant()->indiceEquipe();
	if (!equipeEnnemi().plusProcheVivant()->status().estEmpoisoner()) {
		equipeEnnemi().plusProcheVivant()->status().appliquerPoison();
		equipeEnnemi().plusProcheVivant()->status().ajouterCompteurFragile(10);
	}
	Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
	if (equipeEnnemi().estEnVie()) {
		cible2 = equipeEnnemi().plusProcheVivant()->indiceEquipe();
		if (cible1 != cible2 && equipeAllier().taille() < 10) {
			Affichage().dessinerTexte(nom() + " zombification ! ");
			equipeAllier().ajouterPerso(new Zombie(niveau(), nom()));
			dernier = equipeAllier().taille() - 1;
			equipeAllier()[dernier]->setEnnemis(equipeEnnemi());
			equipeAllier()[dernier]->setAllier(equipeAllier());
			equipeAllier()[dernier]->setId(-2);
			Affichage().dessinerEquipeIA(equipeAllier());
		}

		if (attaqueDouble() && equipeEnnemi().estEnVie()) {
			DEGATS = degats(0.5, 2.5);
			Affichage().dessinerTexte(nom() + " mords ");
			cible1 = equipeEnnemi().plusProcheVivant()->indiceEquipe();
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
			if (equipeEnnemi().estEnVie()) {
				cible2 = equipeEnnemi().plusProcheVivant()->indiceEquipe();
				if (cible1 != cible2 && equipeAllier().taille() < 10) {
					Affichage().dessinerTexte(nom() + " zombification ! ");
					equipeAllier().ajouterPerso(new Zombie(niveau(), nom()));
					dernier = equipeAllier().taille() - 1;
					equipeAllier()[dernier]->setEnnemis(equipeEnnemi());
					equipeAllier()[dernier]->setAllier(equipeAllier());
					equipeAllier()[dernier]->setId(-2);
					Affichage().dessinerEquipeIA(equipeAllier());
				}
			}
		}
	}
		ajouterMana(1);
}

void Zombie::passif(int tour)
{
	for (int i = 0; i < equipeAllier().taille()&&equipeEnnemi().estEnVie(); i++) {
		if (equipeAllier()[i] != this) {
			if (equipeAllier()[i]->id() == -2) {
				equipeAllier()[i]->attaqueEnnemis();
			}
		}
	}
	if (tour % 10 == 0) {
		int SOINS = soins(0.1, 0.5);
		bouclier(SOINS, this);
	}
}

void Zombie::passifDefensif()
{
	ajouterForce(1);
	int SOINS = soins(0.01, 0.05);
	bouclier(SOINS, this);
}
