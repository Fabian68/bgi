#include "CompetenceFabian.h"
#include "Aleatoire.h"
#include <string>
#include "Affichage.h"





CompetenceFabian::CompetenceFabian(Personnage & P,Equipes & E,Equipes & A)
{
	int choix = Aleatoire(0, (P.mana() % 4 + 1)).entier();
	int DEGATS;
	int SOINS;
	/*if ((Tour % 3) == 0) {
		cout << Personnage[Joueur] << " Le froid de la chambre a Fabian le renforce, il est désormait plus résistant ! " << endl;
		PersoCarac[Joueur][REDUCTION]++;
	}*/
	std::string a = P.nom();
	std::cout<<a;
	std::cout << "-2" << std::endl;
	SOINS = P.soins(0.07, 0.7);
	Affichage().dessinerTexte(P.nom()+"Soins Unity");
	P.soigner(SOINS, A.plusFaible());
	switch (choix) {

	case 0:
		DEGATS = P.degats(0.27,0.77);
		std::cout << "-1" << std::endl;
		DEGATS += static_cast<int>(ceil(0.01*E.plusProcheVivant().vie()));
		Affichage().dessinerTexte(P.nom() + " attaque de base");
		P.Attaque(DEGATS,E.plusProcheVivant());
		while (P.ricoche() && E.estEnVie()) {
			std::cout << "-11" << std::endl;
			P.Attaque(DEGATS, E.plusProcheVivant());

		}
		if (P.attaqueDouble() && E.estEnVie()) {
			std::cout << "-111" << std::endl;
			DEGATS = P.degats(0.27, 0.77);
			DEGATS += static_cast<int>(ceil(0.1*E.plusProcheVivant().vie() / 10.0));
			P.Attaque(DEGATS, E.plusProcheVivant());
			while (P.ricoche() && E.estEnVie()) {
				P.Attaque(DEGATS, E.plusProcheVivant());
			}
		}
		/*if (tiragePersoCarac(Joueur, CHANCEDOUBLEATTAQUE) && EquipeEnVie(TeamEnnemie(Joueur)) == true) {
			cout << " Attention j'ai fais de la muscu !  Sa force a augmentee ! " << endl;
			PersoCarac[Joueur][FORCE] = static_cast<int>(PersoCarac[Joueur][FORCE] * ((1.0 + (3 * Tour) / 100)));
		}*/
		P.ajouterMana(3);
		break;
	case 1:
		Affichage().dessinerTexte(P.nom() + " trugdorite");
		DEGATS = P.degats(0.77, 1.17);
		std::cout << "0" << std::endl;
		P.Attaque(DEGATS, E.aleatoireEnVie());
		if (P.attaqueDouble() && E.estEnVie()) {
			std::cout << "00" << std::endl;
			DEGATS = P.degats(0.77, 1.17);
			DEGATS += static_cast<int>(ceil(0.17*E.plusProcheVivant().vie()));
			P.Attaque(DEGATS, E.plusLoinVivant());
			while (P.ricoche() && E.estEnVie()) {
				P.Attaque(DEGATS, E.plusProcheVivant());
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
		P.ajouterMana(-1);
		break;
	case 2:
		
		Affichage().dessinerTexte(P.nom() + " ricochet");
		for (int i = 0;i < 7 && E.estEnVie();i++) {
			std::cout << "1" << std::endl;
			DEGATS = P.degats(0.07+i*0.07, 0.17+i*0.17);
			P.Attaque(DEGATS, E.aleatoireEnVie());
			while (P.ricoche() && E.estEnVie()) {
				P.Attaque(DEGATS, E.plusProcheVivant());
			}
			if (P.attaqueDouble() && E.estEnVie()) {
				DEGATS = P.degats(0.07 + i * 0.14, 0.17 + i * 0.34);
				P.Attaque(DEGATS, E.aleatoireEnVie());
				while (P.ricoche() && E.estEnVie()) {
					P.Attaque(DEGATS, E.plusProcheVivant());
				}
			}
			
		}
		P.ajouterMana(-2);
		break;
	case 3:
		Affichage().dessinerTexte(P.nom() + " raffales");
		for (int i = 0;i < 17 && E.estEnVie();i++) {
			std::cout << "2" << std::endl;
			DEGATS = P.degats(0.17,0.255);
			P.Attaque(DEGATS, E.aleatoireEnVie());
			while (P.ricoche() && E.estEnVie()) {
				P.Attaque(DEGATS, E.plusProcheVivant());
			}
			if (P.attaqueDouble() && E.estEnVie()) {
				DEGATS = P.degats(0.14, 0.28);
				P.Attaque(DEGATS, E.aleatoireEnVie());
				while (P.ricoche() && E.estEnVie()) {
					P.Attaque(DEGATS, E.plusProcheVivant());
				}
			}	
		}
		if (P.attaqueDouble() && E.estEnVie()) {
			std::cout << "3" << std::endl;
			for (int i = 0;i < 7 && E.estEnVie();i++) {
				DEGATS = P.degats(0.35, 0.7);
				P.Attaque(DEGATS, E.aleatoireEnVie());
				while (P.ricoche() && E.estEnVie()) {
					P.Attaque(DEGATS, E.plusProcheVivant());
				}
				if (P.attaqueDouble() && E.estEnVie()) {
					DEGATS = P.degats(0.17, 0.34);
					P.Attaque(DEGATS, E.aleatoireEnVie());
					while (P.ricoche() && E.estEnVie()) {
						P.Attaque(DEGATS, E.plusProcheVivant());
					}
				}
			}
			
		}
		P.ajouterMana(-3);
		break;
	}
}


CompetenceFabian::~CompetenceFabian()
{
}
/*
AttaquerTRUGDOR(int Joueur) {
	int choix=rand_a_b(0,(PersoCarac[Joueur][MANA])%4+1);
	int DEGATS;
	int TeamTMP;
	int soins;
	if (PersoCarac[Joueur][EQUIPE] == TEAM1) {
		TeamTMP = TEAM1;
	}
	else {
		TeamTMP = TEAM2;
	}
	
	cout << Personnage[Joueur] << " Soins Unity ! " << endl;
	soins = static_cast<int>(ceil(frand_a_b(0.6, 1.2)*PersoCarac[Joueur][FORCE]));
	Soins(TeamTMP, PositionJoueur(CibleFaible(CibleProche(Joueur))), soins, Joueur);
	switch(choix) {

		case 0:
			cout<<Personnage[Joueur]<<" fleche dans le genoue ! "<<endl;
			DEGATS = static_cast<int>(ceil(frand_a_b(0.27,0.77)*PersoCarac[Joueur][FORCE]));
			DEGATS+= static_cast<int>(ceil(0.1*PersoCarac[CibleProche(Joueur)][VITALITE]));
			Attaque(DEGATS,CibleProche(Joueur),Joueur);
			if(tiragePersoCarac(Joueur,CHANCEDOUBLEATTAQUE)&&EquipeEnVie(TeamEnnemie(Joueur))==true) {
				cout<< " deuxieme fleche !  "<<endl;
				DEGATS = static_cast<int>(ceil(frand_a_b(0.17,0.77)*PersoCarac[Joueur][FORCE]));
				DEGATS+= static_cast<int>(ceil(0.07*PersoCarac[CibleProche(Joueur)][VITALITE]));
				Attaque(DEGATS,CibleProche(Joueur),Joueur);
			}
			if (tiragePersoCarac(Joueur, CHANCEDOUBLEATTAQUE) && EquipeEnVie(TeamEnnemie(Joueur)) == true) {
				cout << " Attention j'ai fais de la muscu !  Sa force a augmentee ! " << endl;
				PersoCarac[Joueur][FORCE] = static_cast< int>(PersoCarac[Joueur][FORCE]*((1.0 + (3 * Tour) / 100)));
			}
			PersoCarac[Joueur][MANA]++;
			break;
		case 1:
			cout<<Personnage[Joueur]<<" vise la pomme ! "<<endl;

			DEGATS = static_cast<int>(ceil(frand_a_b(0.77,1.27)*PersoCarac[Joueur][FORCE]));
			Attaque(DEGATS,CibleAlea(Joueur),Joueur);
			if(tiragePersoCarac(Joueur,CHANCEDOUBLEATTAQUE)&&EquipeEnVie(TeamEnnemie(Joueur))==true) {
				cout<<" ca touche ! "<<endl;

				DEGATS = static_cast<int>(ceil(frand_a_b(1.27,2.27)*PersoCarac[Joueur][FORCE]));
				DEGATS+= static_cast<int>(ceil(0.17*PersoCarac[CibleProche(Joueur)][VIE]));
				Attaque(DEGATS,CibleLoin(Joueur),Joueur);
			}
			if(tiragePersoCarac(Joueur,HABILETE)){
				cout<<endl<<" BOUGE !!! "<<endl;
				int a=rand_a_b(PREMIER,CINQUIEME+1);
				int b=rand_a_b(PREMIER,CINQUIEME+1);
				int tmp=Equipe[TeamEnnemie(Joueur)][a];
				Equipe[TeamEnnemie(Joueur)][a]=Equipe[TeamEnnemie(Joueur)][b];
				Equipe[TeamEnnemie(Joueur)][b]=tmp;
				cout<<endl<<" Des joueurs ont bouges . "<<endl;
			}
			PersoCarac[Joueur][MANA]--;
			break;
		case 2:
			cout<<Personnage[Joueur]<<" Envoie une fleche  ! "<<endl;

			for(int i=0;i<5&&EquipeEnVie(TeamEnnemie(Joueur))==true;i++) {

				cout<< " Ricoche ! "<<endl;
				DEGATS = static_cast<int>(ceil(frand_a_b(i*0.7,0.7+i*0.7)*PersoCarac[Joueur][FORCE]));
				Attaque(DEGATS,CibleAlea(Joueur),Joueur);
				if(tiragePersoCarac(Joueur,CHANCEDOUBLEATTAQUE)&&EquipeEnVie(TeamEnnemie(Joueur))==true) {
					cout<<" DOUBLE Ricoche ! "<<endl;
					DEGATS = static_cast<int>(ceil(frand_a_b(i*0.7,0.7+i*0.7)*PersoCarac[Joueur][FORCE]));
					Attaque(DEGATS,CibleAlea(Joueur),Joueur);
				}
			}
			PersoCarac[Joueur][MANA]-=2;
			break;
		case 3:
			cout<<Personnage[Joueur]<<" volee de fleche ! "<<endl;

			for(int i=0;i<21&&EquipeEnVie(TeamEnnemie(Joueur))==true;i++) {

				DEGATS = static_cast<int>(ceil(frand_a_b(0.14,0.28)*PersoCarac[Joueur][FORCE]));
				Attaque(DEGATS,CibleAlea(Joueur),Joueur);
				if(tiragePersoCarac(Joueur,CHANCEDOUBLEATTAQUE)&&EquipeEnVie(TeamEnnemie(Joueur))==true) {
					cout<<" DOUBLE FLECHE ! "<<endl;
					DEGATS = static_cast<int>(ceil(frand_a_b(0.14,0.28)*PersoCarac[Joueur][FORCE]));
					Attaque(DEGATS,CibleAlea(Joueur),Joueur);
				}
			PersoCarac[Joueur][MANA]++;
			}
			if(tiragePersoCarac(Joueur,CHANCEDOUBLEATTAQUE)&&EquipeEnVie(TeamEnnemie(Joueur))==true) {
					cout<<" DOUBLE VOLEE ! "<<endl;

				for(int i=0;i<11&&EquipeEnVie(TeamEnnemie(Joueur))==true;i++) {
						DEGATS = static_cast<int>(ceil(frand_a_b(0.14,0.28)*PersoCarac[Joueur][FORCE]));
						Attaque(DEGATS,CibleAlea(Joueur),Joueur);
						if(tiragePersoCarac(Joueur,CHANCEDOUBLEATTAQUE)&&EquipeEnVie(TeamEnnemie(Joueur))==true) {
							cout<<" DOUBLE FLECHE ! "<<endl;
								DEGATS = static_cast<int>(ceil(frand_a_b(0.14,0.28)*PersoCarac[Joueur][FORCE]));
								Attaque(DEGATS,CibleAlea(Joueur),Joueur);
						}
					PersoCarac[Joueur][MANA]++;
					}
			}
			PersoCarac[Joueur][MANA]-=3;
			break;
	}
}
*/
