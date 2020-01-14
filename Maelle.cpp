#include "Maelle.h"
#include "Affichage.h"

Maelle::Maelle(Experiences E, Orbes O, Animaux A) : Personnage(13, E, O, A, "Maelle", 1, 8, 1, 50, 50, 20, 0, 0, 0, 0)
{
	estTransformer = false;
}

void Maelle::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	int indice;
	double k = 0.5;
	if (habile()) {
		switch (choix) {

		case 0:
			DEGATS = degats(0.01, 1.0);
			
			Affichage().dessinerTexte(nom() + " s'enerve ! ");
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
			while (habile() && equipeEnnemi().estEnVie()) {
				Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
				DEGATS = degats(k, k*2);
				k *= 2;
			}
			if (attaqueDouble()) {
				k /= 2;
				while (habile() && equipeEnnemi().estEnVie()) {
					Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
					DEGATS = degats(k, k * 2);
					k *= 2;
				}
			}
			
			break;
		case 1:

			Affichage().dessinerTexte(nom() + " fait du tapis roulant !  ");
			for (double i = 1.0;i <= 25.0&&this->estEnVie();i += 1.0) {
				DEGATS = degats(i/100, i/50);
				Attaque(DEGATS,this);
				SOINS = soins(i / 200, i / 100);
				soigner(SOINS, this);
			}
			ajouterMana(-1);
			break;
		case 2:

			Affichage().dessinerTexte(nom() + " joue a la tablette !  ");
			ajouterCoupCritique(5);
			ajouterDegatsCritique(10);
			ajouterMana(-2);
			break;
		case 3:
			if (estTransformer == false) {
				Affichage().dessinerTexte(nom() + " Se transforme en dinausore ! ");
				setNom("Maellosaure");
				ajouterForce(force());
				ajouterVitesse(vitesse());
				ajouterVie(9 * vie());
				ajouterMana(-3);
				estTransformer = true;
			}
			break;
		}
	}
	else {
		Affichage().dessinerTexte(nom() + " ne fait rien !  ");
		ajouterMana(1);
	}
}

void Maelle::passif(int tour)
{
	if ((tour + 1) % 10 == 0) {
		Affichage().dessinerTexte(nom() + " Les graisses de Maelle la guerrissent ! ");
		soigner(vie()/10, this);
	}
}

void Maelle::passifDefensif()
{
	Affichage().dessinerTexte(nom() + " La graisse protege maelle ! ");
	bouclier(vieMax()/100+niveau(), this);
}
