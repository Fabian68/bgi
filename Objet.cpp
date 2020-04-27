#include "Objet.h"
#include "Personnage.h"

Objet::Objet() : _nom{"VIDE"}, _effet{"AUCUN"},_rareter{0},_numero{0}
{
}

Objet::Objet(std::string nom, int numero, int rareter, std::string effet) : _nom{ nom }, _effet{ effet }, _rareter{rareter }, _numero{ numero }
{
}

std::string Objet::nom() const
{
	return _nom;
}

std::string Objet::effet() const
{
	return _effet;
}

int Objet::rareter() const
{
	return _rareter;
}

std::string Objet::rareterTexte() {
	std::string txt;
	switch (_rareter)
	{
	case 10:
		txt = "Commun";
		break;
	case 100:
		txt = "Rare";
		break;
	case 1000:
		txt = "Epique";
		break;
	case 10000:
		txt = "Legendaire";
		break;
	case 100000:
		txt = "Mythique";
		break;
	}

	return txt;
}

void Objet::appliquerEffet(Personnage* P) {
	switch (_numero)
	{
	case 3:
		P->ajouterVieMax(P->vieMax() / 2);
		break;
	case 6:
		P->ajouterChanceHabileter(10);
		break;
	case 7:
		P->ajouterVitesse(0.30*P->vitesse());
		break;
	case 8:
		P->ajouterVitesse(-0.96 * P->vitesse());
		break;
	case 9:
		P->ajouterDeviation(6);
		break;
	case 11:
		P->ajouterReduction(10);
		break;
	case 14:
		P->ajouterReduction(10);
		break;
	case 15:
		P->ajouterCoupCritique(5);
		P->ajouterEsquive(10);
		break;
	case 17:
		P->ajouterVitesse(0.03 * P->vitesse());
		break;
	case 18:
		P->ajouterCoupCritique(5);
		break;
	case 19:
		P->ajouterForce(10);
		P->ajouterVieMax(100);
		P->ajouterVitesse(10);
		break;
	case 20:
		P->ajouterForce(100);
		P->ajouterVieMax(1000);
		P->ajouterVitesse(100);
		break;
	case 21:
		P->ajouterForce(1000);
		P->ajouterVieMax(10000);
		P->ajouterVitesse(1000);
		break;
	case 22:
		P->ajouterForce(0.05 * P->force());
		break;
	case 23:
		P->ajouterVieMax(0.05 * P->vieMax());
		break;
	case 24:
		P->ajouterVitesse(0.05 * P->vitesse());
		break;
	case 26:
		P->ajouterForce(10000);
		P->ajouterVieMax(100000);
		P->ajouterVitesse(10000);
		break;
	case 27:
		P->ajouterChanceRicochet(7);
		break;
	default:
		break;
	}
}
int Objet::numero() const
{
	return _numero;
}
