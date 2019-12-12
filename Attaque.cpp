#include "Attaque.h"
#include "CompetenceFabian.h"


Attaque::Attaque(Personnage & P, Equipes & E, Equipes & A)
{
	switch (P.id()) {
		case 1:
			CompetenceFabian(P,E,A);
			break;
	}
}

Attaque::~Attaque()
{
}
/*
void choixArme(int Joueur) {
	switch(PersoCarac[Joueur][ARME]) {
		case ISIDOOR:
			AttaquerISIDORE(Joueur);
			break;
		case SPARTAN:
			AttaquerSPARTAN(Joueur);
			break;
		case BATON:
			AttaquerBATON(Joueur);
			break;
		case VENTRE:
			AttaquerVENTRE(Joueur);
			break;
		case ALACOOL:
			AttaquerALACOOL(Joueur);
			break;
		case TRUGDOR:
			AttaquerTRUGDOR(Joueur);
			break;
		case DAGUES:
			AttaquerDAGUES(Joueur);
			break;
		case NINI:
			AttaquerNINI(Joueur);
			break;
		case JBI:
			AttaquerJBI(Joueur);
			break;
		case LAPIN:
			AttaquerLAPIN(Joueur);
			break;
		case SANGLIER:
			AttaquerSANGLIER(Joueur);
			break;
		case CERF:
			AttaquerCERF(Joueur);
			break;
		case PETITPONEY:
			AttaquerPETITPONEY(Joueur);
			break;
		case ASALIM:
			AttaquerSALIM(Joueur);
			break;
		case ADRAGON:
			AttaquerDRAGON(Joueur);
			break;
		case KUNGFU:
			AttaquerKUNGFU(Joueur);
			break;
		case TELLURIQUE:
			AttaquerTELLURIQUE(Joueur);
			break;
		case AMAELLE:
			AttaquerMaelle(Joueur);
			break;
		case ADEMO:
			AttaquerDEMO(Joueur);
			break;
		case ELITE:
			AttaquerELITE(Joueur);
			break;
		case GROGNARD:
			AttaquerGROGNARD(Joueur);
			break;
		case CHASSEUR:
			AttaquerCHASSEUR(Joueur);
			break;
		case HUNTER:
			AttaquerHUNTER(Joueur);
			break;
		case BRUTE:
			AttaquerBRUTE(Joueur);
			break;
		case SQUELETEARCHER:
			AttaquerSqueletteArcher(Joueur);
			break;
		case CREEPER:
			AttaquerCreeper(Joueur);
			break;
		case GHAST:
			AttaquerGhast(Joueur);
			break;
		case ZOMBIE:
			AttaquerZombie(Joueur);
			break;
		case WITHERSQUELETTE:
			AttaquerWitherSquelette(Joueur);
			break;
		case WITHER:
			AttaquerWITHER(Joueur);
			break;
		case ABERSERKER:
			AttaquerBERSERKER(Joueur);
			break;
		case BARDIABLE:
			AttaquerBardeDiable(Joueur);
			break;
		case PICHNETTE:
			AttaquerPichnette(Joueur);
			break;

	}
}
*/
