#include "Objets.h"
#include <fstream>
#include "Affichage.h"
#include "Bouton.h"

Objets::Objets()
{
	FILE* file = fopen("objdblc.txt", "r");
	if (file == NULL) {
		std::ofstream os("objdblc.txt");

		for (int i = 0; i < 300; i++) {
			os << 0;
			os << std::endl;
		}
		os.close();
	}
	else {
		fclose(file);
	}
	_objetsDebloquer.resize(300);
	std::ifstream is("objdblc.txt");
	for (int i = 0; i < 25; i++) {
		is >> _objetsDebloquer[i];
	}
	is.close();


	FILE* file2 = fopen("objeqp.txt", "r");
	if (file2 == NULL) {
		std::ofstream os("objeqp.txt");

		for (int i = 0; i < 25; i++) {
			os << 0 <<" "<< 0;
			os << std::endl;
		}
		os.close();
	}
	else {
		fclose(file2);
	}
	_listeObjetEquiper.resize(25);
	std::ifstream is2("objeqp.txt");
	int v1, v2;
	for (int i = 0; i < 25; i++) {
		is2 >> v1;
		is2 >> v2;
		_listeObjetEquiper[i].first = v1;
		_listeObjetEquiper[i].second= v2;
	}
	is2.close();


	_listeObjets.reserve(300);
	_listeObjets.push_back(Objet());
	_listeObjets.push_back(Objet("Antidote", 1, 100000, "Rend insensible au poison"));
	_listeObjets.push_back(Objet("Voile de feu", 2, 100000, "Les brûlures vous soignent"));
	_listeObjets.push_back(Objet("Bénédiction", 3, 1000, "Augmente la vie Maximum de 50%"));
	_listeObjets.push_back(Objet("Sceptre de druide", 4, 1000, "20% de chance qu'un soins donne également du bouclier, 10% de chance qu'ajouter du bouclier ocrtoire une protection."));
	_listeObjets.push_back(Objet("Malediction", 5, 100, "Consomme votre bouclier et reduit votre vie de 10% de votre vie max chaque tour mais augmente vos dégats de 150%"));
	_listeObjets.push_back(Objet("Cape habilete", 6, 10000, "+10% coup habile, 10% de chance que les coup habile fassent 3 fois plus de dégats et 5% de chance qu'elle fassent 4 fois plus de dégats"));
	_listeObjets.push_back(Objet("Patte de lapin", 7, 100000, "+30% vitesse, l'experience gagner au comba par ce personnage est multiplir par 3"));
	_listeObjets.push_back(Objet("Beuh", 8, 10000, "-96% vitesse, l'experience gagner par ce personnage est multiplier par 5"));
	_listeObjets.push_back(Objet("Voile miroir", 9, 1000, "+ 6% de chance de deviation, les attaques devier sont 50% plus puissantes"));
	_listeObjets.push_back(Objet("Marshmallow", 10, 1000, "10% de chance d'absorber une attaque ennemi et de transformer les dégats en bouclier"));
	_listeObjets.push_back(Objet("Armure du protecteur", 11, 100000, "+10% de reduction de dégats, 25% de chance de recevoir une attaque qui cible un allier a sa place"));
	_listeObjets.push_back(Objet("Kunai", 12, 1000, "Toute les 3 attaques voient leurs dégats augmenter de 30%"));
	_listeObjets.push_back(Objet("Flèche transpercante", 13, 10000, "Après chaque attaques vous infliger une attaque brute avec 5% à 10% de votre force"));
	_listeObjets.push_back(Objet("Armure de Sakeratsu", 14, 100000, "+10% de reduction de dégats, renvoie 10% des dégats reçu sous forme de dégats brut a l'ennemi"));
	_listeObjets.push_back(Objet("Cape de ninja", 15, 10000, "+10% de chance d'esquive, +5% de chance de coup critique, effectuer une esquive augmente vos dégats critique de 5%"));
	_listeObjets.push_back(Objet("Dague de ninja", 16, 10000, "Augmente les dégats de 20%, après avoir effectuer une esquive vous faites une attaque brute sur l'ennemi le plus faible a hauteur de 20% à 40% de votre force "));
	_listeObjets.push_back(Objet("Soie de lapin", 17, 10, "+3% de vitesse"));
	_listeObjets.push_back(Objet("Sauciflar", 18, 100, "+5% chance de coup critique"));
	_listeObjets.push_back(Objet("J&B", 19, 100, "+10 points dans chaque stats"));
	_listeObjets.push_back(Objet("Colère de Florian ", 20, 1000, "+100 points dans chaque stats"));
	_listeObjets.push_back(Objet("Trinité", 21, 10000, "+1000 points dans chaque stats"));
	_listeObjets.push_back(Objet("Debardeur de Nicolas ", 22, 100, "+5% d'attaque"));
	_listeObjets.push_back(Objet(" Jue de pomme", 23, 100, "+5% de vie max"));
	_listeObjets.push_back(Objet("Les chaussetes de FLO", 24, 100, "+5% de vitesse"));
	_listeObjets.push_back(Objet(" Gilet par balle", 25, 10000," Les dégats sont reduit de 1 par niveau du personnage "));
	_listeObjets.push_back(Objet("EXCALIBUR", 26, 10000, "+10000 points dans chaque stats"));
	_listeObjets.push_back(Objet("Flèches tranchantes", 27, 10000, "+7% de chance de ricochet, les ricochet font 30% de plus de dégats."));
	//_listeObjets.push_back(Objet("Antidote", 18, 100000, "Rend insensible au poison"));

	_tableLoot.resize(300);
	for (int niveau = 1;niveau <= 300;niveau++) {
		_tableLoot[niveau].reserve(10);
	}

	_tableLoot[1].push_back(_listeObjets[17]);
	_tableLoot[1].push_back(_listeObjets[8]);
	_tableLoot[1].push_back(_listeObjets[18]);

	_tableLoot[2].push_back(_listeObjets[17]);
	_tableLoot[2].push_back(_listeObjets[18]);

	_tableLoot[3].push_back(_listeObjets[17]);
	_tableLoot[3].push_back(_listeObjets[18]);

	_tableLoot[4].push_back(_listeObjets[17]);
	_tableLoot[4].push_back(_listeObjets[18]);

	_tableLoot[5].push_back(_listeObjets[17]);
	_tableLoot[5].push_back(_listeObjets[17]);
	_tableLoot[5].push_back(_listeObjets[7]);
	_tableLoot[5].push_back(_listeObjets[19]);

	_tableLoot[6].push_back(_listeObjets[22]);
	_tableLoot[7].push_back(_listeObjets[22]);
	_tableLoot[8].push_back(_listeObjets[22]);
	_tableLoot[9].push_back(_listeObjets[22]);
	
	_tableLoot[10].push_back(_listeObjets[14]);

	_tableLoot[11].push_back(_listeObjets[23]);
	_tableLoot[12].push_back(_listeObjets[23]);
	_tableLoot[13].push_back(_listeObjets[23]);
	_tableLoot[14].push_back(_listeObjets[23]);

	_tableLoot[15].push_back(_listeObjets[3]);
	_tableLoot[15].push_back(_listeObjets[4]);
	_tableLoot[15].push_back(_listeObjets[20]);

	_tableLoot[16].push_back(_listeObjets[24]);
	_tableLoot[17].push_back(_listeObjets[24]);
	_tableLoot[18].push_back(_listeObjets[24]);
	_tableLoot[19].push_back(_listeObjets[24]);

	_tableLoot[20].push_back(_listeObjets[5]);
	_tableLoot[20].push_back(_listeObjets[9]);
	_tableLoot[20].push_back(_listeObjets[10]);
	_tableLoot[20].push_back(_listeObjets[11]);

	_tableLoot[21].push_back(_listeObjets[1]);
	_tableLoot[22].push_back(_listeObjets[1]);


	_tableLoot[23].push_back(_listeObjets[13]);
	_tableLoot[23].push_back(_listeObjets[12]);

	_tableLoot[24].push_back(_listeObjets[13]);
	_tableLoot[24].push_back(_listeObjets[12]);
	_tableLoot[25].push_back(_listeObjets[13]);
	_tableLoot[25].push_back(_listeObjets[12]);

	_tableLoot[26].push_back(_listeObjets[25]);
	_tableLoot[27].push_back(_listeObjets[25]);
	_tableLoot[28].push_back(_listeObjets[25]);
	_tableLoot[29].push_back(_listeObjets[25]);

	_tableLoot[30].push_back(_listeObjets[2]);
	_tableLoot[30].push_back(_listeObjets[21]);

	_tableLoot[31].push_back(_listeObjets[2]);

	_tableLoot[32].push_back(_listeObjets[25]);

	_tableLoot[33].push_back(_listeObjets[15]);
	_tableLoot[33].push_back(_listeObjets[16]);
	_tableLoot[34].push_back(_listeObjets[15]);
	_tableLoot[34].push_back(_listeObjets[16]);

	_tableLoot[35].push_back(_listeObjets[27]);
	_tableLoot[36].push_back(_listeObjets[27]);
	_tableLoot[37].push_back(_listeObjets[27]);


	_tableLoot[44].push_back(_listeObjets[9]);
	_tableLoot[45].push_back(_listeObjets[9]);

	_tableLoot[50].push_back(_listeObjets[6]);

	_tableLoot[100].push_back(_listeObjets[26]);
}

void Objets::objetsDuPersonnage(int numero, Objet& obj1, Objet& obj2) const
{
	obj1 = _listeObjets[_listeObjetEquiper[numero].first];
	obj2 = _listeObjets[_listeObjetEquiper[numero].second];
}

void Objets::sauvegarderObjetsEquiper() {
	std::ofstream os("objeqp.txt");

	for (int i = 0; i < 25; i++) {
		os << _listeObjetEquiper[i].first << " " << _listeObjetEquiper[i].second;
		os << std::endl;
	}
	os.close();
}

void Objets::equiperObjetDuPersonnage(int numero,Objet obj, bool premier) {

	if (premier == true) {
		_listeObjetEquiper[numero].first = obj.numero();
	}
	else {
		_listeObjetEquiper[numero].second = obj.numero();
	}
	sauvegarderObjetsEquiper();
}

std::vector<Objet> Objets::objetsDuNiveau(int numero) {
	return _tableLoot[numero];
}

bool Objets::estDebloquer(Objet& obj)const {
	return _objetsDebloquer[obj.numero()] == 1;
}

int Objets::nombreObjets()const {
	return _listeObjets.size() - 1;
}

Objet Objets::objetNumero(int numero) {
	return _listeObjets[numero];
}

void Objets::deblocageObjet(int indiceObjet)
{
	std::string txt = "";
	txt += "Vous avez débloquer l'objet : ";
	txt += _listeObjets[indiceObjet].nom() + " " + _listeObjets[indiceObjet].rareterTexte();
	Bouton(300, 400, txt, 0, GREEN, GREEN).afficher();

	txt = _listeObjets[indiceObjet].effet();

	Bouton(300, 450, txt, 0, GREEN, GREEN).afficher();


	Bouton Continuer(340, 500, " Continuer ", 0, GREEN, GREEN);
	Continuer.afficher();

	_objetsDebloquer[indiceObjet] = 1;
	sauvegarderObjetsDebloquer();

	int xc, yc;
	int DELAY = 50;
	do {
		while (!ismouseclick(WM_LBUTTONDOWN)) {
			delay(DELAY);
		}
		getmouseclick(WM_LBUTTONDOWN, xc, yc);
	
	} while (!Continuer.comprendLesCoord(xc,yc));
	cleardevice();
}

void Objets::sauvegarderObjetsDebloquer() {
	std::ofstream os("objdblc.txt");

	for (int i = 0; i < 300; i++) {
		os << _objetsDebloquer[i];
		os << std::endl;
	}
	os.close();
}