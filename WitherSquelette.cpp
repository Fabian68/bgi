#include "WitherSquelette.h"
#include "Affichage.h"

WitherSquelette::WitherSquelette(int LVL, std::string nom, int difficulte, int animal, int rareteAnimal, int id) : Personnage(LVL, nom, 2, 5, 3, 25, 25, 25, 0, 0, 0, 8, animal, rareteAnimal)
{
	setId(id);
	if (difficulte == 1) {
		ajouterForce(force());
		ajouterVitesse(vitesse());
		ajouterVie(9 * vie());
	}
}


void WitherSquelette::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;


	Affichage().dessinerTexte(nom() + " attaque ! ! ");
	equipeEnnemi().plusProcheVivant()->ajouterReduction(-5);
	int indice = equipeEnnemi().plusProcheVivant()->indiceEquipe();
	DEGATS = degats(1.5, 3.5);
	Attaque(DEGATS, equipeEnnemi()[indice]);
	if (habile()) {
		Affichage().dessinerTexte(nom() + " contamine ! ");
		DEGATS = degats(0.75, 1.75);
		Attaque(DEGATS, equipeEnnemi()[indice]);
		DEGATS = degats(0.35, 0.7);
		Attaque(DEGATS, equipeEnnemi()[indice]);
		DEGATS = degats(0.15, 0.35);
		Attaque(DEGATS, equipeEnnemi()[indice]);
	}
	if (attaqueDouble() && equipeEnnemi().estEnVie()) {
		equipeEnnemi().plusProcheVivant()->ajouterReduction(-5);
		indice = equipeEnnemi().plusProcheVivant()->indiceEquipe();
		DEGATS = degats(1.5, 3.5);
		Attaque(DEGATS, equipeEnnemi()[indice]);
		if (habile()) {
			Affichage().dessinerTexte(nom() + " contamine ! ");
			DEGATS = degats(0.75, 1.75);
			Attaque(DEGATS, equipeEnnemi()[indice]);
			DEGATS = degats(0.35, 0.7);
			Attaque(DEGATS, equipeEnnemi()[indice]);
			DEGATS = degats(0.15, 0.35);
			Attaque(DEGATS, equipeEnnemi()[indice]);
		}
	}
	
	ajouterMana(1);
}

void WitherSquelette::passif(int tour)
{
}

void WitherSquelette::passifDefensif()
{
}