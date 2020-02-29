#include "Affichage.h"
#include "Equipes.h"
#include "Personnage.h"
#include "Bouton.h"
#include "Zones.h"
#include  <iostream>

Affichage::Affichage()
{
}
void afficherTexte(int x, int y, std::string texte) {
	char *perso = const_cast<char*>(texte.c_str());
	outtextxy(x, y, perso);
}

std::string conversion(int nombre) {
	std::string nombrestr;
	if (nombre >= 1000000) {
		nombrestr = std::to_string(nombre / 1000000) + "M";
	}
	else if (nombre >= 1000) {
		nombrestr = std::to_string(nombre / 1000) + "K";
	}
	else {
		nombrestr = std::to_string(nombre);
	}
	return nombrestr;
}
void Affichage::affichageTexte(int x, int y, std::string texte) {
	char* perso = const_cast<char*>(texte.c_str());
	outtextxy(x, y, perso);
}
void Affichage::animationCercle(int xDepart, int yDepart, int xArriver, int yArriver) const
{
	int delais = 18;
	int pasX = static_cast<int>((xArriver*1.0 - xDepart*1.0) / 30.0);
	int pasY = static_cast<int>((yArriver*1.0 - yDepart*1.0) / 30.0);
	std::cout << pasY;
	setcolor(RED);
	setfillstyle(1, RED);
	fillellipse(xDepart, yDepart, 10, 10);
	delay(delais);
	for (int i = 1; i <= 31; i++) {
	 	setcolor(BLACK);
		setfillstyle(1, BLACK);
		fillellipse(xDepart + (i - 1) * pasX, yDepart + (i - 1) * pasY, 11, 11);
		setcolor(RED);
		setfillstyle(1, RED);
		circle(xDepart + i * pasX, yDepart + i * pasY, 10);
		fillellipse(xDepart + i * pasX, yDepart + i * pasY, 10, 10);
		delay(delais);
	}
}

void Affichage::afficherJoueurs(int indice,Equipes Liste)const {
	int x = 50;
	int y = 20;
	std::string str;
	setbkcolor(BLACK);
	setcolor(WHITE);		
		str = "Pseudo : "+Liste[indice]->nom();
		afficherTexte(x, y, str);
	
		str = "Niveau : " +std::to_string(Liste[indice]->niveau());
		afficherTexte(x, y+20, str);

		str = "Force : "  +std::to_string(Liste[indice]->force());
		afficherTexte(x, y+40, str);

		str = "Vie : "  +std::to_string(Liste[indice]->vieMax());
		afficherTexte(x, y+60, str);

		str = "Vitesse : "  +std::to_string(Liste[indice]->vitesse());
		afficherTexte(x, y+80, str);

		str = "Chance de double attaque : "  +std::to_string(Liste[indice]->chanceDoubleAttaque());
		afficherTexte(x, y+100, str);

		str = "Chance de coup habile : "  +std::to_string(Liste[indice]->chanceHabileter());
		afficherTexte(x, y+120, str);

		str = "Chance de deviation : "  +std::to_string(Liste[indice]->pourcentageDeviation());
		afficherTexte(x, y+140, str);

		str = "Pourcentage de reduction de degats : "  +std::to_string(Liste[indice]->pourcentageReduction());
		afficherTexte(x, y+160, str);

		str = "Chance de ricochet : " + std::to_string(Liste[indice]->pourcentageRicochet());
		afficherTexte(x, y+180, str);

		str = "Chance esquive : " + std::to_string(Liste[indice]->pourcentageEsquive());
		afficherTexte(x, y+200, str);

		str = "Chance de blocage : " + std::to_string(Liste[indice]->pourcentageBlocage());
		afficherTexte(x, y+220, str);
	
		int x2 = x - 20;
		switch (indice) {
		case 0:
			afficherTexte(x2, y + 250, "Soigne l'allier le plus faible chaque tour");
			afficherTexte(x2, y + 270, "Augmente sa resistance tout les 7 tours");
			afficherTexte(x2, y + 290, "Augmente sa force tout les 17 tours");
			afficherTexte(x2, y + 310, "C1: Attaque ennemi proche ( vie ennemi ");
			afficherTexte(x2, y + 330, "force Fabian)");
			afficherTexte(x2, y + 350, "C2: Attaque comme précédente mais plus puissant");
			afficherTexte(x2, y + 370, "C3: Beaucoup d'attaques mais faible degats");
			afficherTexte(x2, y + 390, "ennemi aleatoire (force)");
			afficherTexte(x2, y + 410, "C4: Beaucoup d'attaques mais degats moyen");
			afficherTexte(x2, y + 430, "ennemis aleatoire (force)");
			break;
		case 1:
			afficherTexte(x2, y + 250, "Tout les 20 tours s'inflige des degats");
			afficherTexte(x2, y + 270, "A partir de 100 tour attaque les ennemis avec");
			afficherTexte(x2, y + 290, "une nouvelle competence (force)");
			afficherTexte(x2, y + 310, "Contre attaque quand se fait attaquer (force)");
			afficherTexte(x2, y + 330, "C1: Attaque cible proche, degats correct ");
			afficherTexte(x2, y + 350, "(force)");
			afficherTexte(x2, y + 370, "C2: Attaque puissante (force)");
			afficherTexte(x2, y + 390, "C3: Beaucoup d'attaques mais degats moyen");
			afficherTexte(x2, y + 410, "(force)");
			afficherTexte(x2, y + 430, "C4: Augmente la force des alliers");
			afficherTexte(x2, y + 450, "Prout");
			break;
		case 2:
			afficherTexte(x2, y + 250, "Tout les 5 tours se soigne (force)");
			afficherTexte(x2, y + 270, "Quand se fait attaquer il se donne un bouclier");
			afficherTexte(x2, y + 290, "a partir d'une partie de sa vie maximum");
			afficherTexte(x2, y + 310, "---");
			afficherTexte(x2, y + 330, "C1: Attaque cible proche, degats correct ");
			afficherTexte(x2, y + 350, "(force,vie,vie max)");
			afficherTexte(x2, y + 370, "C1 BIS: Attaque de zone (PEC vie et bouclier)");
			afficherTexte(x2, y + 390, "C2: Saute dans le tas, degats moyen (force)");
			afficherTexte(x2, y + 410, "C3: Soins moyen de l'equipe (force)");
			afficherTexte(x2, y + 430, "C4: Attaque ennemi aleatoire ");
			afficherTexte(x2, y + 450, "force,vie,vie max, bouclier ");
			afficherTexte(x2, y + 470, "Prout");
			break;
		case 3:
			afficherTexte(x2, y + 250, "Tout les 10 tours appelle un animal pour l'aider");
			afficherTexte(x2, y + 270, "maximum 2 animaux, ils defendent Fiona");
			afficherTexte(x2, y + 290, "Augmente sa reduction lorsque elle se fait attaquer");
			afficherTexte(x2, y + 310, "---");
			afficherTexte(x2, y + 330, "C1: Attaque cible proche, degats correct (force)");
			afficherTexte(x2, y + 350, "C2: Soigne le plus faible(force)");
			afficherTexte(x2, y + 370, "C3: Attaque 3 ennemis (force)");
			afficherTexte(x2, y + 390, "et reduit leurs resistances");
			afficherTexte(x2, y + 430, "C4: Attaque lennemi le plus proche(force) ");
			afficherTexte(x2, y + 450, "et reduit fortement sa resistance ");
			afficherTexte(x2, y + 470, "Prout");
			break;
		case 4:
			afficherTexte(x2, y + 250, "Moins il a de pv plus il est resistant");
			afficherTexte(x2, y + 270, "C1: Attaque l'ennemi le plus proche(force)");
			afficherTexte(x2, y + 290, "moins il a de vie plus il attaque");
			afficherTexte(x2, y + 310, "et la puissance de l'attaque augmente");
			afficherTexte(x2, y + 330, "C2: Attaque puissante ennemi proche (force)");
			afficherTexte(x2, y + 350, "C3: Comme C1 mais plus puissant");
			afficherTexte(x2, y + 370, "C4: Divise la vie par 2 et rejoue ");
			break;
		case 5:
			afficherTexte(x2, y + 250, "Augmente son pourcentage de degats critique");
			afficherTexte(x2, y + 270, "et ses degats critique chaque tour");
			afficherTexte(x2, y + 290, "Peut parfois se bouclier quand se fait attaquer");
			afficherTexte(x2, y + 310, "(vitesse)");
			afficherTexte(x2, y + 330, "Fait une attaque faible brut avant chaque C (force)");
			afficherTexte(x2, y + 350, "C1: Attaque l'ennemi le plus proche (force) ");
			afficherTexte(x2, y + 370, "C2: Attaque l'ennemi le plus faible (force) ");
			afficherTexte(x2, y + 390, "degats augmentent en fonction de la vie ennemi");
			afficherTexte(x2, y + 410, "C3: Attaque brut l'ennemi le plus loin (force)");
			afficherTexte(x2, y + 430, "C4: Ajoutes stats critique et se soigne (force)");
			break;
		case 6:
			afficherTexte(x2, y + 250, "Se soigne tout les tours (vie max)");
			afficherTexte(x2, y + 270, "C1: Attaque le plus faible (vitesse)");
			afficherTexte(x2, y + 290, "C2: Fait le passif");
			afficherTexte(x2, y + 310, "C3: Soigne et bouclier l'equipe(vitesse et force)");
			afficherTexte(x2, y + 330, "ou attaque l'equipe ennemi(vitesse et force)");
			afficherTexte(x2, y + 350, "C4: Attaque des ennemi aleatoire avec de gros ");
			afficherTexte(x2, y + 370, "degats (vitesse)");
			break;
		case 7:
			afficherTexte(x2, y + 250, "Augmente sa force et vie maximum tout les 5 tours");
			afficherTexte(x2, y + 270, "Se soigne entièrement tout les 30 tours");
			afficherTexte(x2, y + 290, "C1: Faible chance d'attaque l'ennemi proche");
			afficherTexte(x2, y + 310, "gros degats (force) ");
			afficherTexte(x2, y + 330, "C2: Se soigne longuement(force) ");
			afficherTexte(x2, y + 350, "C3: Reduit la resistance des ennemis");
			afficherTexte(x2, y + 370, "C4: Attaque un ennemi aleatoire gros degats (force)");
			afficherTexte(x2, y + 390, "C4: reduit egalement sa resistance");
			break;
		case 8:
			afficherTexte(x2, y + 250, "Si ne se fait pas toucher pendant 4 tous");
			afficherTexte(x2, y + 270, "remplie son bouclier");
			afficherTexte(x2, y + 290, "Augmente ses chances de doubles attaques");
			afficherTexte(x2, y + 310, "quand se fait attaquer");
			afficherTexte(x2, y + 330, "C1: Enormément d'Attaque sur l'ennemi le plus ");
			afficherTexte(x2, y + 350, "proche,faible degats (force)");
			afficherTexte(x2, y + 370, "C2: Attaque l'ennemi le plus faible (force) ");
			afficherTexte(x2, y + 390, "peut attaquer plusieurs fois");
			afficherTexte(x2, y + 410, "C3: Attaque puissante ennemi proche (force)");
			afficherTexte(x2, y + 430, "C4: Attaque de zone variable (force)");
			break;
		case 9:
			afficherTexte(x2, y + 250, "S'enleve de la vie tout les 5 tours");
			afficherTexte(x2, y + 270, "Augmente sa reduction quand ce fait attaquer");
			afficherTexte(x2, y + 350, "C1: Soins et bouclier de zone multiple (force) ");
			afficherTexte(x2, y + 370, "C2: Ajoute force et reduction a un allier ");
			afficherTexte(x2, y + 390, "aleatoire (niveau)");
			afficherTexte(x2, y + 410, "C3: Soigne l'equipe (force)");
			afficherTexte(x2, y + 430, "C4: Attaque l'equipe ennemi (force)");
			break;
		case 10:
			afficherTexte(x2, y + 250, "Bouclier lorsqu'il ce fait attaquer(niveau)");
			afficherTexte(x2, y + 270, "Peut attaquer tout les tours avec la competence");
			afficherTexte(x2, y + 290, "Competence tout les 10 tours :");
			afficherTexte(x2, y + 310, "Attaque brut ennemi proche(force)");
			afficherTexte(x2, y + 330, "plus lennemi est resistant plus les degats sont fort");
			afficherTexte(x2, y + 350, "C1: Attaque ennemi proche (force) ");
			afficherTexte(x2, y + 370, "reduit fortement sa resistance");
			afficherTexte(x2, y + 390, "C2: Se soigne et bouclier (force) ");
			afficherTexte(x2, y + 410, "C3: Ne fait rien");
			afficherTexte(x2, y + 430, "C4: ENORME ataque ennemi proche (force)");
			break;
		case 11:
			afficherTexte(x2, y + 250, "Tout les 5 tours augmente la reduction");
			afficherTexte(x2, y + 270, "de toute l'équipe");
			afficherTexte(x2, y + 290, "Tout les 50 tours augmente les stats de toute ");
			afficherTexte(x2, y + 310, "l'équipe, double attaque, habileter et CC");
			afficherTexte(x2, y + 330, "C1: Se bouclier(force) peut aussi attaquer ");
			afficherTexte(x2, y + 350, "ennemi proche (force)");
			afficherTexte(x2, y + 370, "C2: Se soigne (force) peut aussi attaquer");
			afficherTexte(x2, y + 390, "equipe ennemi (force,vie, vie max)");
			afficherTexte(x2, y + 410, "C3:Soigne l'equipe(force) peut aussi");
			afficherTexte(x2, y + 430, "attaquer equipe ennemi (force,vitesse)");
			afficherTexte(x2, y + 450, "C4: Attaque ennemi aleatoire (force)");
			break;
		case 12:
			afficherTexte(x2, y + 250, "Donne de l'xp a l'equipe tout les 10 tours");
			afficherTexte(x2, y + 270, "Possède 10 fois plus de vie");
			afficherTexte(x2, y + 290, "C1:Faible chance d'attaque ");
			afficherTexte(x2, y + 310, "ennemi proche (force)");
			afficherTexte(x2, y + 330, "C2: Se soigne (vie,vie max) ");
			afficherTexte(x2, y + 350, "C3:Soigne l'equipe(force)");
			afficherTexte(x2, y + 370, "C4: Ajoute enormément de reduction");
			afficherTexte(x2, y + 390, "a l'allier le plus faible");
			break;
		case 13:
			afficherTexte(x2, y + 250, "Se bouclier quand ce fait attaquer(niveau,vie max)");
			afficherTexte(x2, y + 270, "Se soigne tout les 10 tours (vie)");
			afficherTexte(x2, y + 290, "C1: Attaque ennemi proche, degats croissant ");
			afficherTexte(x2, y + 310, "nombre attaque variant (force)");
			afficherTexte(x2, y + 330, "C2: S'attaque et se soigne sur une longue ");
			afficherTexte(x2, y + 350, "durée (force)");
			afficherTexte(x2, y + 370, "C3:Augmente ses chance critiques et");
			afficherTexte(x2, y + 390, "degats critiques");
			afficherTexte(x2, y + 410, "C4: Se transforme (qu'une seule fois)");
			afficherTexte(x2, y + 430, "force*2,vie*10");
			break;

		}
		x = x + 250;
	
		rectangle(x + 80, y - 10, x + 550, y + 130);
		
		Animal A = Liste[indice]->animal();
		
		afficherTexte(x+150, y , " Animal equiper : "+A.type());
		int rareter = Liste[indice]->rareterAnimal();
		rectangle(x + 90, y + 30, x + 400, y + 70);
		afficherTexte(x + 100, y+40, " Ratio Min : ");
		afficherTexte(x + 180, y + 40, std::to_string((int)(A.ratioMin(rareter)*100))+ " %");
		afficherTexte(x + 230, y + 40, " Ratio Max : ");
		afficherTexte(x + 310, y + 40, std::to_string((int)(A.ratioMax(rareter) * 100))+ " %");

		rectangle(x + 90, y + 80, x + 515, y + 110);
		afficherTexte(x + 100, y + 90, " Pourcentage d'activation quand attaque ou est attaquer : ");
		afficherTexte(x + 475, y + 90, std::to_string(A.pourcentageActivation(rareter))+" %");

		Animaux N;

		rectangle(x + 80, y + 140, x + 500, y+600);
		x += 90;
		y += 150;
		afficherTexte(x+100, y,"Liste des animaux posseder");
		y += 50;
		std::string texteAnimaux;
		for (int i = 0; i < 9; i++) {
			if (N.animalDebloquer(Liste[indice]->id(), i, 1)&&i!=A.indice()) {
				texteAnimaux = Animal(i).type();
				rareter = N.rareteAnimal(Liste[indice]->id(), i);
				switch (rareter)
				{
				case 1:
					texteAnimaux += " commun";
					break;
				case 2:
					texteAnimaux += " rare";
					break;
				case 3:
					texteAnimaux += " epique";
					break;
				case 4:
					texteAnimaux += " legendaire";
					break;
				case 5:
					texteAnimaux += " cheater";
					break;
				}
				afficherTexte(x, y, texteAnimaux);
				Bouton(x + 275, y - 10, "Equiper",0,WHITE,WHITE).afficher();
				y += 50;
			}
		}

		y = 170;
		afficherTexte(x + 500, 10, "Les orbes sont équiper que sur une seul stat");
		afficherTexte(x + 500, 40, "Cliquer sur un bouton pour modifier le choix");
		afficherTexte(x + 500, 70, "La changement s'applique quand vous quitter cet page");
		afficherTexte(x + 500, y, "Liste des orbes equiper");
		x += 440;
		Orbes O;
		std::string texteOrbe;
		bool OrbeChoisit = false;
		int xpas;
		for (int i = 1,k= 220; i <= 5; i++) {
			if (O.orbeDebloquer(indice, i)) {
				switch (i) {
				case 1:
					texteOrbe= " commune ( 1 ";
					break;
				case 2:
					texteOrbe = " rare ( 2 ";
					break;
				case 3:
					texteOrbe = " epique ( 3 ";
					break;
				case 4:
					texteOrbe = " LEGENDAIRE ( 4 ";
					break;
				case 5:
					texteOrbe = " CHEATER ( 5 ";
					break;
				}
				texteOrbe+="S/ LVL ) Equiper : ";
				afficherTexte(x, k, texteOrbe);
				for (int jj = 1,xpas=0; jj <= 3; jj++) {
					if (O.choixOrbe(indice, i) != jj) {
						switch (jj) {
						case 1:
							Bouton(x + 210+xpas, k-10, "ATK",0,WHITE,WHITE).afficher();
							break;
						case 2 :
							Bouton(x + 210+xpas, k-10, "VIE", 0, WHITE, WHITE).afficher();
							break;
						case 3 :
							Bouton(x + 210 + xpas, k-10, "VIT", 0, WHITE, WHITE).afficher();
							break;
						}
						xpas += 50;
					}
				}
				k += 50;
			}
		}
		Experiences E;
		
		Bouton Retour(300,700, "RETOUR");
		Retour.afficher();
		Bouton Precedent(450, 700, "Precedent");
		Precedent.afficher();
		Bouton Suivant(600, 700, "Suivant");
		Suivant.afficher();
		const int DELAY = 50; // Milliseconds of delay between checks
		int xc, yc;
		bool equiperAnimal = false;
			do {
				while (!ismouseclick(WM_LBUTTONDOWN)) {
					delay(DELAY);
				}
				getmouseclick(WM_LBUTTONDOWN, xc, yc);
				for (int i = 0,k=210; i < 9; i++) {
					if (N.animalDebloquer(Liste[indice]->id(), i, 1) && i != A.indice()) {
						if (Bouton(665, k, "Equiper").comprendLesCoord(xc, yc)) {
							
							N.setAnimalPersonnage(indice, i);
							Liste[indice]->setAnimal(Animal(i));
							equiperAnimal = true;
						}
						k += 50;
					}
				}
				for (int i = 1, k = 220; i <= 5; i++) {
					if (O.orbeDebloquer(indice, i)) {
						for (int jj = 1, xpas = 0; jj <= 3; jj++) {
							if (O.choixOrbe(indice, i) != jj) {
								if (Bouton(x + 210 + xpas, k - 10, "ATK", 0, WHITE, WHITE).comprendLesCoord(xc, yc)) {
									O.setChoixOrbe(indice, i, jj);
									OrbeChoisit = true;
								}
								xpas += 50;
							}
						}
						k += 50;
					}
				}
			} while (!Retour.comprendLesCoord(xc, yc) && !Suivant.comprendLesCoord(xc, yc)&&!equiperAnimal&&!Precedent.comprendLesCoord(xc,yc)&&!OrbeChoisit);

			if (Suivant.comprendLesCoord(xc, yc)) {
				indice = (indice + 1) % Liste.taille();
				cleardevice();
				afficherJoueurs(indice, Liste);
			}
			else if (Precedent.comprendLesCoord(xc,yc)) {
				indice--;
				if (indice < 0) {
					indice = Liste.taille() - 1;
				}
				cleardevice();
				afficherJoueurs(indice, Liste);
			}
			else if (equiperAnimal||OrbeChoisit) {
				cleardevice();
				afficherJoueurs(indice, Liste);
			}
	cleardevice();
}
void Affichage::afficherAnimaux(Animaux A) const
{
	setcolor(RED);
	int x,y;
	int j = 0;
	std::string ratio;
	afficherTexte(300, 50, "Liste des animaux");
	for (int i = 0; i < 5; i++,j++) {
		x = 150 + 200 * i;
		y = 100;
		rectangle(x, y, x + 180, y + 30);
		afficherTexte(x + 5, y + 10, A.animalNumero(j).type());
	
		rectangle(x, y + 30, x + 90, y + 60);	
		afficherTexte(x + 15, y + 40,"%PROC");

		rectangle(x + 90, y + 30, x + 180, y + 60);
		afficherTexte(x + 105, y + 40, "%RATIO");
		y = y + 60;
		for (int i = 0; i < 5; i++) {
			rectangle(x, y + 30 * i, x + 90, y + 30 * (i + 1));
			afficherTexte(x + 15, y +10 + 30*i, std::to_string(A.animalNumero(j).pourcentageActivation(i+1))+" %");
			
			ratio = std::to_string((int)(A.animalNumero(j).ratioMin(i+1)*100)) + " % - " + std::to_string((int)(A.animalNumero(j).ratioMax(i+1)*100))+" %";
			rectangle(x + 90, y + 30 * i, x + 180, y + 30 * (i + 1));
			afficherTexte(x + 105, y + 10 + 30 * i,ratio);
		}
	}
	for (int i = 0; i < 5; i++,j++) {
		x = 150 + 200 * i;
		y = 400;
		rectangle(x, y, x + 180, y + 30);
		afficherTexte(x + 5, y + 10, A.animalNumero(j).type());

		rectangle(x, y + 30, x + 90, y + 60);
		afficherTexte(x + 15, y + 40, "%PROC");

		rectangle(x + 90, y + 30, x + 180, y + 60);
		afficherTexte(x + 105, y + 40, "%RATIO");
		y = y + 60;
		for (int i = 0; i < 5; i++) {
			rectangle(x, y + 30 * i, x + 90, y + 30 * (i + 1));
			afficherTexte(x + 15, y + 10 + 30 * i, std::to_string(A.animalNumero(j).pourcentageActivation(i + 1)) + " %");

			ratio = std::to_string((int)(A.animalNumero(j).ratioMin(i+1) * 100)) + " % - " + std::to_string((int)(A.animalNumero(j).ratioMax(i+1) * 100)) + " %";
			rectangle(x + 90, y + 30 * i, x + 180, y + 30 * (i + 1));
			afficherTexte(x + 105, y + 10 + 30 * i, ratio);
		}
	}
	afficherTexte(150,670,"Le proc est le pourcentage de chance que l'animal s'active quand votre personnage attaque ou ce fait attaquer pour chaque rareter.");
	afficherTexte(150, 700, "Le Ratio montre le ratio minimum et maximum de l'attaque concernant cet effet pour chaque rareter.");
	Bouton retour(50, 675, " Retour ");
	retour.afficher();
	const int DELAY = 50; // Milliseconds of delay between checks
	int xc, yc;
	do {
		while (!ismouseclick(WM_LBUTTONDOWN)) {
			delay(DELAY);
		}
		getmouseclick(WM_LBUTTONDOWN, xc, yc);
	} while (!retour.comprendLesCoord(xc, yc));
	cleardevice();
}
void Affichage::dessinerJoueur(int indice, bool equipeIA,Personnage*  P) const
{
	int x;
	if (equipeIA) {
		x = 1180 - 360;
	}
	else {
		x = 20;
	}
	std::string str = P->nom()+" "+std::to_string(P->niveau());
	char* perso = const_cast<char*>(str.c_str());
//	setcolor(GREEN);
	int y = -50 + 70 * indice;
	rectangle(x, y, x + 360, y + 65);
	outtextxy(x + 2, y + 5, perso);
	int pourcentageVie = P->pourcentageVie();
	int pourcentageBouclier = P->pourcentageBouclier();

	setfillstyle(1, GREEN);
	int Tab[8] = { x + 2,y + 25,x + 2 + pourcentageVie*2,y + 25,x + 2 + pourcentageVie * 2,y + 40,x + 2,y + 40 };
	fillpoly(4, Tab);
	setfillstyle(1, BLACK);
	int Tab3[8] = { x + 2 + pourcentageVie * 2,y + 25,x + 202,y + 25,x + 202,y + 40,x + 2 + pourcentageVie * 2,y + 40 };
	fillpoly(4, Tab3);

	// y 45 et 60
	setfillstyle(1, MAGENTA);
	int Tab2[8] = { x + 2,y + 45,x +2 + pourcentageBouclier*2,y + 45,x + 2 + pourcentageBouclier*2,y + 60,x + 2,y + 60 };
	fillpoly(4, Tab2);
	setfillstyle(1, BLACK);
	int Tab4[8] = { x + 2 + pourcentageBouclier * 2,y + 45,x + 202,y + 45,x + 202,y + 60,x + 2 + pourcentageBouclier * 2,y + 60 };
	fillpoly(4, Tab4);
	
	setfillstyle(1, BLACK);
	setcolor(BLACK);
	int Taby[8] = { x+206,y+20,x+285,y+20,x+285,y+59,x+206,y+59 };
	fillpoly(4, Taby);
	setcolor(WHITE);
	
	str = conversion(P->vie()) + " / " + conversion(P->vieMax());
	perso = const_cast<char*>(str.c_str());
	outtextxy(x +210, y + 25, perso);

	str = conversion(P->bouclier()) + " / " + conversion(P->bouclierMax());
	perso = const_cast<char*>(str.c_str());
	
	outtextxy(x +210, y + 45, perso);


}

void Affichage::dessinerDegats(Personnage* P, int degats) const {
	int x;
	if (P->equipeAllier().ia()) {
		x = 1200 - 95;
		
	}
	else {
		x = 310;
	}
	int y = -20 + 70 * (P->indiceEquipe()+1);
	setcolor(BLACK);
	setfillstyle(1,BLACK);
	int Tab[8] = { x - 5,y -5,x +50 ,y -5,x+50 ,y + 20,x -5,y + 20 };
	fillpoly(4, Tab);
	std::string texte = " - " + conversion(degats);
	setcolor(RED);
	char* txt = const_cast<char*>(texte.c_str());
	outtextxy(x, y,txt);
	delay(50);
}

void Affichage::dessinerSoins(Personnage* P, int soins) const {
	int x;
	if (P->equipeAllier().ia()) {
		x = 1200 - 95;
	}
	else {
		x = 310;
	}
	int y = -20 + 70 * (P->indiceEquipe() + 1);
	setcolor(BLACK);
	setfillstyle(1, BLACK);
	int Tab[8] = { x - 5,y - 5,x + 50 ,y - 5,x + 50 ,y + 20,x - 5,y + 20 };
	fillpoly(4, Tab);
	setcolor(GREEN);
	std::string texte = " + " + conversion(soins);
	
	char* txt = const_cast<char*>(texte.c_str());
	outtextxy(x, y, txt);
	delay(50);
}

void Affichage::dessinerBouclier(Personnage* P, int soins) const {
	int x;
	if (P->equipeAllier().ia()) {
		x = 1200 - 95;
	}
	else {
		x = 310;
	}
	int y = -20 + 70 * (P->indiceEquipe() + 1);
	setcolor(BLACK);
	setfillstyle(1, BLACK);
	
	int Tab[8] = { x - 5,y - 5,x + 50 ,y - 5,x + 50 ,y + 20,x - 5,y + 20 };
	fillpoly(4, Tab);
	setcolor(MAGENTA);
	std::string texte = " + " + conversion(soins);

	char* txt = const_cast<char*>(texte.c_str());
	outtextxy(x, y, txt);
	delay(50);
}

void Affichage::dessinerTexte(std::string texte)const {
	delay(500);
	setfillstyle(1, BLACK);
	setcolor(BLACK);
	int Tab[8] = { 385,0,780,0,780,30,385,30 };
	fillpoly(4, Tab);

	setfillstyle(1, BLACK);
	setcolor(BLACK);
	int Tab2[8] = { 385,30,801,30,801,800,385,800 };
	fillpoly(4, Tab2);
	setcolor(RED);

	setcolor(RED);
	char* txt = const_cast<char*>(texte.c_str());
	outtextxy(390,5, txt);	
	delay(500);
}
void Affichage::dessinerEquipeJoueur(Equipes J) const
{
	for (int i = 0;i < J.taille();i++) {
		dessinerJoueur(i + 1, false, J.perso(i));
	}
}

void Affichage::dessinerEquipeIA(Equipes I) const
{
	for (int i = 0;i < I.taille();i++) {
		dessinerJoueur(i + 1, true, I.perso(i));
	}
}

void Affichage::choixNiveau(Zones Z, int & niveau,int & repetition) const
{
	
	int niveauMax = Z.niveauMax();
	if (niveau < 1) {
		niveau = 1;
	}
	else if (niveau > niveauMax) {
		niveau = niveauMax;
	}
	if (repetition < 1) {
		repetition = 1;
	}
	else if (repetition > 100) {
		repetition = 100;
	}

	afficherTexte(100, 100, "Choix du niveau, niveau max = "+std::to_string(niveauMax));
	Bouton plus1(100, 200, " + 1 ");
	Bouton moins1(100, 300, " - 1 ");
	Bouton plus10(200, 200, " + 10 ");
	Bouton moins10(200, 300, " - 10 ");
	Bouton niveauActuel(330, 90, std::to_string(niveau));
	
	afficherTexte(400, 100, "Choix du nombre de repetition, max = 100 ");
	Bouton plus1r(400, 200, " + 1 ");
	Bouton moins1r(400, 300, " - 1 ");
	Bouton plus10r(500, 200, " + 10 ");
	Bouton moins10r(500, 300, " - 10 ");
	Bouton repetitionActuel(680, 90, std::to_string(repetition));
	
	Bouton confirmer(150, 400, "Confirmer");
	
	plus1.afficher();
	moins1.afficher();
	plus10.afficher();
	moins10.afficher();
	niveauActuel.afficher();

	confirmer.afficher();

	plus1r.afficher();
	moins1r.afficher();
	plus10r.afficher();
	moins10r.afficher();
	repetitionActuel.afficher();

	bool bouttonHit = false;
	const int DELAY = 50; // Milliseconds of delay between checks
	int xc, yc;
	do {
		while (!ismouseclick(WM_LBUTTONDOWN)) {
			delay(DELAY);
		}
		getmouseclick(WM_LBUTTONDOWN, xc, yc);

		if (plus1.comprendLesCoord(xc, yc)) {
				
			bouttonHit = true;
			choixNiveau(Z, ++niveau,repetition);
		}else if (plus10.comprendLesCoord(xc, yc)) {
			bouttonHit = true;
			niveau = niveau + 10;
			choixNiveau(Z, niveau,repetition);
		}else if (moins1.comprendLesCoord(xc, yc)) {

			bouttonHit = true;
			choixNiveau(Z, --niveau,repetition);
		}
		else if (moins10.comprendLesCoord(xc, yc)) {
			bouttonHit = true;
			niveau = niveau - 10;
			choixNiveau(Z, niveau,repetition);
		}
		else if (plus1r.comprendLesCoord(xc, yc)) {

			bouttonHit = true;
			choixNiveau(Z, niveau, ++repetition);
		}
		else if (plus10r.comprendLesCoord(xc, yc)) {
			bouttonHit = true;
			repetition += 10;
			choixNiveau(Z, niveau, repetition);
		}
		else if (moins1r.comprendLesCoord(xc, yc)) {

			bouttonHit = true;
			choixNiveau(Z, niveau, --repetition);
		}
		else if (moins10r.comprendLesCoord(xc, yc)) {

			bouttonHit = true;
			repetition -= 10;
			choixNiveau(Z, niveau, repetition);
		}
	} while (!confirmer.comprendLesCoord(xc,yc)&&!bouttonHit);
	cleardevice();
}

void Affichage::menuModifierEquipe(Equipes& Gentil, Equipes choix,int max) const
{
	afficherTexte(100, 20, "Equipe actuel");
	for (int i = 0; i < Gentil.taille(); i++) {
		Bouton(100, (i + 1) * 50, std::to_string(i) + Gentil[i]->nom()).afficher();
	}
	if (max > 0) {
		afficherTexte(400, 10, "Personnages selectionnable");
		for (int i = 0; i < choix.taille(); i++) {
			Bouton(400, (i + 1) * 45, std::to_string(i) +" "+ choix[i]->nom()+ " LVL : " +std::to_string(choix[i]->niveau())).afficher();
		}
	}
	else {
		afficherTexte(400, 20, "Maximum de personnages selectionnable atteintes");
	}
	Bouton retirer(100, 700, "Retirer le dernier personnage");
	if (Gentil.taille() > 0) {
		retirer.afficher();
	}

	Bouton Sauvegarder(600, 700, "Sauvegarder");
	Sauvegarder.afficher();
	Bouton Retour(800, 700, "Retour");
	Retour.afficher();
	const int DELAY = 50; // Milliseconds of delay between checks
	int xc, yc;
	bool boutonSelectionnerPerso = false;
	bool boutonSelectionnerAutre = false;
	do {
		while (!ismouseclick(WM_LBUTTONDOWN)) {
			delay(DELAY);
		}
		getmouseclick(WM_LBUTTONDOWN, xc, yc);
		if (max > 0) {
			for (int i = 0; i < choix.taille(); i++) {
				if (Bouton(400, (i + 1) * 45, std::to_string(i) + choix[i]->nom()).comprendLesCoord(xc, yc)) {
					Gentil.ajouterPerso(choix[i]);
					boutonSelectionnerPerso = true;
					menuModifierEquipe(Gentil, choix, --max);
				}
			}
		}
		if (Gentil.taille() > 0) {
			if (retirer.comprendLesCoord(xc, yc)) {
				boutonSelectionnerAutre = true;
				Gentil.retirerDernierPerso();
				cleardevice();
				menuModifierEquipe(Gentil, choix, ++max);
			}
		}
		if (Sauvegarder.comprendLesCoord(xc, yc)) {
			Gentil.sauvegarderEquipe();
			boutonSelectionnerAutre = true;
			menuModifierEquipe(Gentil, choix, max);
		}
		else if (Retour.comprendLesCoord(xc, yc)) {
			boutonSelectionnerAutre = true;
		}
	} while (!boutonSelectionnerPerso && !boutonSelectionnerAutre);
	cleardevice();
}

void Affichage::dessinerDeuxEquipes(Equipes Joueur,Equipes IA) const
{
	dessinerEquipeJoueur(Joueur);
	dessinerEquipeIA(IA);
}

void Affichage::dessinerAttaque(Personnage * Attaquant, Personnage * Defenseur) {
	
	setfillstyle(1, BLACK);
	setcolor(BLACK);
	int Tab[8] = { 385,30,801,30,801,800,385,800 };
	fillpoly(4, Tab);
	setcolor(RED);
	
	int i, j;
	if (!Attaquant->equipeAllier().ia()) {
		 i = Attaquant->indiceEquipe() + 1;
		 j = Defenseur->indiceEquipe() + 1;
		//animationCercle(390, -20 + 70 * i, 810, -20 + 70 * j);
		
	}
	else {
		 j = Attaquant->indiceEquipe() + 1;
		 i = Defenseur->indiceEquipe() + 1;
	//	animationCercle(810, -20 + 70 * j, 390, -20 + 70 * i);
	}
	line(385, -25 + 70 * i, 800, -25 + 70 * j);
	if (!Attaquant->equipeAllier().ia()) {
		
		line(780, -5 + 70 *j, 800, -25 + 70 * j);
		line(780, -45 + 70 * j, 800, -25 + 70 * j);
	}
	else {
		line(405, -5 + 70 * i, 385, -25 + 70 * i);
		line(405, -45 + 70 * i, 385, -25 + 70 * i);
		
	}
	delay(25);
}

Affichage::~Affichage()
{
}
