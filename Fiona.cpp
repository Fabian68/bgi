#include "Fiona.h"
#include "Affichage.h"
#include "Lapin.h"

Fiona::Fiona(Experiences E, Orbes O, Animaux A) : Personnage(3, E, O, A, "Fiona", 3, 5, 2, 0, 7, -17, 7, 7, 7, 70) , _nbAnimaux{0} {}

void Fiona::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	
	switch (choix) {

	case 0:
		equipeEnnemi().plusProcheVivant()->ajouterReduction(-1);
		DEGATS = degats(0.1, 0.2);

		
		Affichage().dessinerTexte(nom() + " tire oreille");
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());

		ajouterMana(1);
		break;
	case 1:
		Affichage().dessinerTexte(nom() + " soins picher ");
		for (int i = 0; i < 5; i++) {
			while (ricoche()) {
				SOINS = soins(0.1, 0.2);
				soigner(SOINS, equipeAllier().aleatoireEnVie());
			}
		}
		ajouterMana(+1);
		break;
	case 2:

		Affichage().dessinerTexte(nom() + " les 3 pichnettes ");
		for (int i = 1; i <= 3 && equipeEnnemi().estEnVie(); i++) {
			equipeEnnemi().plusProcheVivant()->ajouterReduction(-1);
			DEGATS = degats(0.1 * i , 0.2 *i);
			Attaque(DEGATS, equipeEnnemi().aleatoireEnVie());
		}
		ajouterMana(-2);
		break;
	case 3:

		equipeEnnemi().plusProcheVivant()->ajouterReduction(-1);
		DEGATS = degats(0.7, 1.7);
		equipeEnnemi().plusProcheVivant()->ajouterReduction(-7);

		Affichage().dessinerTexte(nom() + " pûissance 17 ");
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());

		ajouterMana(1);
		ajouterMana(-3);
		break;
	}
}

void Fiona::passif(int tour)
{
	std::string nom;

	if (((tour + 1) % 5) == 0) {
		if (equipeAllier().taille() < 10) {
			if (_nbAnimaux == 0) {
				nom = " Perle";
			}
			else if (_nbAnimaux == 1) {
				nom = " Oxanne";
			}
			if (_nbAnimaux < 2) {
				Affichage().dessinerTexte(this->nom() + " adopte un animal ! ");
				equipeAllier().ajouterPerso(new Lapin(this->niveau(), nom, 1, 9, 5,3));
				equipeAllier()[equipeAllier().taille() - 1]->setEnnemis(equipeEnnemi());
				equipeAllier()[equipeAllier().taille() - 1]->setAllier(equipeAllier());
				Affichage().dessinerEquipeJoueur(equipeAllier());
				_nbAnimaux++;
			}
		}
	}
}

void Fiona::passifDefensif()
{
	ajouterReduction(1);
	for (int i = 0; i < equipeAllier().taille()&&equipeEnnemi().estEnVie();i++) {
		if (equipeAllier()[i]->id() == 3 && equipeAllier()[i]->nom() != nom()) {
			equipeAllier()[i]->attaqueEnnemis();
		}
	}
}
