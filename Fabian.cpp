#include "Fabian.h"
#include "Affichage.h"
#include <iostream>

Fabian::Fabian(Experiences E,Orbes O,Animaux A): Personnage(0, E,O,A,"Fabian",2,4,4,10,10,10,7,10,10,17){}
void Fabian::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	/*if ((Tour % 3) == 0) {
		cout << Personnage[Joueur] << " Le froid de la chambre a Fabian le renforce, il est désormait plus résistant ! " << endl;
		PersoCarac[Joueur][REDUCTION]++;
	}*/
	std::string a = nom();
	std::cout << a;
	std::cout << "-2" << std::endl;
	SOINS = soins(0.07, 0.7);
	Affichage().dessinerTexte(nom() + "Soins Unity");
	soigner(SOINS, equipeAllier().plusFaible());
	switch (choix) {

	case 0:
		DEGATS = degats(0.27, 0.77);
		std::cout << "-1" << std::endl;
		DEGATS += static_cast<int>(ceil(0.01 * equipeEnnemi().plusProcheVivant()->vie()));
		Affichage().dessinerTexte(nom() + " attaque de base");
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		while (ricoche() && equipeEnnemi().estEnVie()) {
			std::cout << "-11" << std::endl;
			Attaque(DEGATS,equipeEnnemi().plusProcheVivant());

		}
		if (attaqueDouble() && equipeEnnemi().estEnVie()) {
			std::cout << "-111" << std::endl;
			DEGATS = degats(0.27, 0.77);
			DEGATS += static_cast<int>(ceil(0.1 * equipeEnnemi().plusProcheVivant()->vie() / 10.0));
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
			while (ricoche() && equipeEnnemi().estEnVie()) {
				Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
			}
		}
		/*if (tiragePersoCarac(Joueur, CHANCEDOUBLEATTAQUE) && EquipeEnVie(TeamEnnemie(Joueur)) == true) {
			cout << " Attention j'ai fais de la muscu !  Sa force a augmentee ! " << endl;
			PersoCarac[Joueur][FORCE] = static_cast<int>(PersoCarac[Joueur][FORCE] * ((1.0 + (3 * Tour) / 100)));
		}*/
		ajouterMana(3);
		break;
	case 1:
		Affichage().dessinerTexte(nom() + " trugdorite");
		DEGATS = degats(0.77, 1.17);
		std::cout << "0" << std::endl;
		Attaque(DEGATS, equipeEnnemi().aleatoireEnVie());
		if (attaqueDouble() && equipeEnnemi().estEnVie()) {
			std::cout << "00" << std::endl;
			DEGATS = degats(0.77, 1.17);
			DEGATS += static_cast<int>(ceil(0.17 * equipeEnnemi().plusProcheVivant()->vie()));
			//Attaque(DEGATS, equipeEnnemi().plusLoinVivant());
			while (ricoche() && equipeEnnemi().estEnVie()) {
				Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
			}
		}
		/*if (tiragePersoCarac(Joueur, HABILETE)) {
			cout << endl << " BOUGE !!! " << endl;
			int a = rand_a_b(PREMIER, CINQUIEME + 1);
			int b = rand_a_b(PREMIER, CINQUIEME + 1);
			int tmp = Equipe[TeamEnnemie(Joueur)][a];
			Equipe[TeamEnnemie(Joueur)][a] = Equipe[TeamEnnemie(Joueur)][b];
			Equipe[TeamEnnemie(Joueur)][b] = tmp;
			cout << endl << " Des joueurs ont bouges . " << endl;
		}*/
		ajouterMana(-1);
		break;
	case 2:

		Affichage().dessinerTexte(nom() + " ricochet");
		for (int i = 0; i < 7 && equipeEnnemi().estEnVie(); i++) {
			std::cout << "1" << std::endl;
			DEGATS = degats(0.07 + i * 0.07, 0.17 + i * 0.17);
			Attaque(DEGATS, equipeEnnemi().aleatoireEnVie());
			while (ricoche() && equipeEnnemi().estEnVie()) {
				Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
			}
			if (attaqueDouble() && equipeEnnemi().estEnVie()) {
				DEGATS = degats(0.07 + i * 0.14, 0.17 + i * 0.34);
				Attaque(DEGATS, equipeEnnemi().aleatoireEnVie());
				while (ricoche() && equipeEnnemi().estEnVie()) {
					Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
				}
			}

		}
		ajouterMana(-2);
		break;
	case 3:
		Affichage().dessinerTexte(nom() + " raffales");
		for (int i = 0; i < 17 && equipeEnnemi().estEnVie(); i++) {
			std::cout << "2" << std::endl;
			DEGATS = degats(0.17, 0.255);
			Attaque(DEGATS, equipeEnnemi().aleatoireEnVie());
			while (ricoche() && equipeEnnemi().estEnVie()) {
				Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
			}
			if (attaqueDouble() && equipeEnnemi().estEnVie()) {
				DEGATS = degats(0.14, 0.28);
				Attaque(DEGATS, equipeEnnemi().aleatoireEnVie());
				while (ricoche() && equipeEnnemi().estEnVie()) {
					Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
				}
			}
		}
		if (attaqueDouble() && equipeEnnemi().estEnVie()) {
			std::cout << "3" << std::endl;
			for (int i = 0; i < 7 && estEnVie(); i++) {
				DEGATS = degats(0.35, 0.7);
				Attaque(DEGATS, equipeEnnemi().aleatoireEnVie());
				while (ricoche() && equipeEnnemi().estEnVie()) {
					Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
				}
				if (attaqueDouble() && equipeEnnemi().estEnVie()) {
					DEGATS = degats(0.17, 0.34);
					Attaque(DEGATS, equipeEnnemi().aleatoireEnVie());
					while (ricoche() && equipeEnnemi().estEnVie()) {
						Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
					}
				}
			}

		}
		ajouterMana(-3);
		break;
	}
}
