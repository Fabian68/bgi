#include "graphics.h"
#include "Point.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include "Combat.h"
#include "Aleatoire.h"


#define PI 3.14159265

double angleEnRadian(int angleDegre) {
	return (angleDegre*PI) / 180.0;
}

void nettoyerZoneAttaque() {
	setfillstyle(1, BLACK);
	setcolor(BLACK);
	int Tab[8] = { 365,0,835,0,835,800,365,800};
	fillpoly(4, Tab);
}

double frand_a_b(double a, double b) {
	return (rand() / (double)RAND_MAX)*(b - a) + a;
}
void dessinerTriangle(Point A, Point B, Point C) {
	int Triangle[6];
	Triangle[0] = static_cast<int>(A.x());
	Triangle[1] = static_cast<int>(A.y());
	Triangle[2] = static_cast<int>(B.x());
	Triangle[3] = static_cast<int>(B.y());
	Triangle[4] = static_cast<int>(C.x());
	Triangle[5] = static_cast<int>(C.y());
	fillpoly(3, Triangle);
}

void Sierprinski(int n, Point A, Point B, Point C) {
	if (n <= 0) {}
	else {
		setfillstyle(1,n%14 +1);
		dessinerTriangle((A + B) / 2, (B + C) / 2, (A + C) / 2);
		Sierprinski(n - 1, A, (B + A) / 2, (A + C) / 2);
		Sierprinski(n - 1, (A + B) / 2, B, (B + C) / 2);
		Sierprinski(n - 1, (A + C) / 2, (B + C) / 2, C);
	}
}

void Koch(int n,Point A, Point B) {
	if (n <= 0) {
		line(static_cast<int>(A.x()), static_cast<int>(A.y()), static_cast<int>(B.x()), static_cast<int>(B.y()));
	}
	else {
		Point C = (A * 2 + B) / 3;
		Point D = (A + B * 2) / 3;
		Point E( (A.x() + B.x())/2 - (B.y() - A.y())*(-1 / (2 * sqrt(3))), (A.y() + B.y()) / 2 - (B.x() - A.x())*(1 / (2 * sqrt(3))));
		Koch(n - 1, A, C);
		Koch(n - 1, C, E);
		Koch(n - 1, E, D);
		Koch(n - 1, D, B);
	}
}

const double angleMin = 30.0;
const double angleMax = 45.0;
const double divTailleMin = 1.05;
const double divTailleMax = 1.5;
void Arbre(int n, Point A, Point B, double angle = angleEnRadian(frand_a_b(angleMin, angleMax)), double k= frand_a_b(divTailleMin, divTailleMax)) {
	if (n == 0) {

	}
	else {
		setcolor(n % 14 + 1);
		line(static_cast<int>(A.x()), static_cast<int>(A.y()), static_cast<int>(B.x()), static_cast<int>(B.y()));
		Point C(B.x() + (B.x() - A.x())*(cos(angle) / k) - (B.y() - A.y())*(sin(angle) / k), B.y() + (B.y() - A.y())*(cos(angle) / k) + (B.x() - A.x())*(sin(angle) / k));
		Point D(B.x() + (B.x() - A.x())*(cos(angle) / k) + (B.y() - A.y())*(sin(angle) / k), B.y() + (B.y() - A.y())*(cos(angle) / k) - (B.x() - A.x())*(sin(angle) / k));
		Arbre(n - 1, B, C, angleEnRadian(frand_a_b(angleMin, angleMax)), frand_a_b(divTailleMin, divTailleMax));
		Arbre(n - 1, B, D, angleEnRadian(frand_a_b(angleMin, angleMax)), frand_a_b(divTailleMin, divTailleMax));
	}
}

void afficherSupports() {
	setcolor(WHITE);
	line(100, 570, 400, 570);
	line(450, 570, 750, 570);
	line(800, 570, 1100, 570);
}

void initPiles(std::vector<int> & Pile1, std::vector<int> & Pile2, std::vector<int> & Pile3,int n) {
	Pile1.reserve(n);
	Pile2.reserve(n);
	Pile3.reserve(n);
	for (int i = 1;i <= n;i++) {
		Pile1.push_back(i);
	}
}

void initPiles2(std::vector<int> & Pile1, std::vector<int> & Pile2, std::vector<int> & Pile3, int n) {
	Pile1.reserve(n);
	Pile2.reserve(n);
	Pile3.reserve(n);
	for (int i = 1;i <= n;i++) {
		Pile1.push_back(i);
		Pile1.push_back(i);
	}
}
void afficherUnePile(const std::vector<int> & Pile1, int milieuSupport) {
	int milieu;
	int base = 570;
	int base2;
	for (int i = 0;i < Pile1.size();i++) {
		setfillstyle(1, Pile1[i]);
		milieu = (300-Pile1[i]*25) / 2;
		base2 = 32 - 2*Pile1[i];
		int Tab[8] = { milieuSupport-milieu,base,milieuSupport+milieu,base,milieuSupport + milieu,base-base2,milieuSupport - milieu,base-base2};
		base -= base2;
		fillpoly(4, Tab);
	}
	int Tab[8] = { milieuSupport - 150,base-1,milieuSupport + 150,base-1,milieuSupport + 150,0,milieuSupport -150,0 };
	setfillstyle(1, BLACK);
	setcolor(BLACK);
	fillpoly(4, Tab);
	setcolor(WHITE);
}

void afficherUnePile2(const std::vector<int> & Pile1, int milieuSupport) {
	int milieu;
	int base = 570;
	int base2;
	for (int i = 0;i < Pile1.size();i++) {
		setfillstyle(1, Pile1[i]%2+1);
		milieu = (300 - Pile1[i] * 25) / 2;
		base2 = 32 - 2 * Pile1[i];
		int Tab[8] = { milieuSupport - milieu,base,milieuSupport + milieu,base,milieuSupport + milieu,base - base2,milieuSupport - milieu,base - base2 };
		base -= base2;
		fillpoly(4, Tab);
	}
	int Tab[8] = { milieuSupport - 150,base - 1,milieuSupport + 150,base - 1,milieuSupport + 150,0,milieuSupport - 150,0 };
	setfillstyle(1, BLACK);
	setcolor(BLACK);
	fillpoly(4, Tab);
	setcolor(WHITE);
}
void afficherPiles(const std::vector<int> & Pile1, const std::vector<int> & Pile2, const std::vector<int> & Pile3) {
	afficherUnePile(Pile1, 250);
	afficherUnePile(Pile2, 600);
	afficherUnePile(Pile3, 950);
}

void afficherPiles2(const std::vector<int> & Pile1, const std::vector<int> & Pile2, const std::vector<int> & Pile3) {
	afficherUnePile2(Pile1, 250);
	afficherUnePile2(Pile2, 600);
	afficherUnePile2(Pile3, 950);
}
void deplacer(std::vector<int>& Pile1, std::vector<int> & Pile2) {
	Pile2.push_back(Pile1.back());
	Pile1.pop_back();
}

void hanoi(int n, std::vector<int>&Pile1, std::vector<int>&Pile2, std::vector<int>&Pile3, std::vector<int>&Pile12, std::vector<int>&Pile22, std::vector<int>&Pile32) {
	if (n > 0) {
		hanoi(n - 1, Pile1, Pile3, Pile2,Pile12,Pile22,Pile32);
		delay(1000/60);
		//cleardevice();
		deplacer(Pile1, Pile3);
		afficherSupports();
		afficherPiles(Pile12, Pile22, Pile32);
		hanoi(n - 1, Pile2, Pile1, Pile3, Pile12, Pile22, Pile32);
	}
}

void hanoi2(int n, std::vector<int>&Pile1, std::vector<int>&Pile2, std::vector<int>&Pile3, std::vector<int>&Pile12, std::vector<int>&Pile22, std::vector<int>&Pile32) {
	if (n > 0) {
		hanoi2(n - 1, Pile1, Pile2, Pile3, Pile12, Pile22, Pile32);
		delay(1000 / 60);
		//cleardevice();
		deplacer(Pile1, Pile2);
		afficherSupports();
		afficherPiles(Pile12, Pile22, Pile32);
		hanoi2(n - 1, Pile3, Pile2, Pile1, Pile12, Pile22, Pile32);
		delay(1000 / 60);
		//cleardevice();
		deplacer(Pile2, Pile3);
		afficherSupports();
		afficherPiles(Pile12, Pile22, Pile32);
		hanoi2(n - 1, Pile1, Pile2, Pile3, Pile12, Pile22, Pile32);
	}
}

void hanoif(int n, std::vector<int>&Pile1, std::vector<int>&Pile2, std::vector<int>&Pile3, std::vector<int>&Pile12, std::vector<int>&Pile22, std::vector<int>&Pile32) {
	if (n > 0) {
		hanoif(n - 1, Pile1, Pile3, Pile2, Pile12, Pile22, Pile32);
		hanoif(n - 1, Pile2, Pile1, Pile3, Pile12, Pile22, Pile32);
		delay(1000 / 60);
		//cleardevice();
		deplacer(Pile1, Pile2);
		afficherSupports();
		afficherPiles(Pile12, Pile22, Pile32);
		hanoif(n - 1, Pile3, Pile1, Pile2, Pile12, Pile22, Pile32);
		hanoif(n - 1, Pile2, Pile3, Pile1, Pile12, Pile22, Pile32);
		delay(1000 / 60);
		//cleardevice();
		deplacer(Pile2, Pile3);
		afficherSupports();
		afficherPiles(Pile12, Pile22, Pile32);
		hanoif(n - 1, Pile1, Pile3, Pile2, Pile12, Pile22, Pile32);
		hanoif(n - 1, Pile2, Pile1, Pile3, Pile12, Pile22, Pile32);
	}
}

void hanoiv(int n, std::vector<int>&Pile1, std::vector<int>&Pile2, std::vector<int>&Pile3, std::vector<int>&Pile12, std::vector<int>&Pile22, std::vector<int>&Pile32) {
	if (n > 0) {
		hanoiv(n - 1, Pile1, Pile3, Pile2, Pile12, Pile22, Pile32);
		delay(1000 / 60);
		//cleardevice();
		deplacer(Pile1, Pile3);
		afficherSupports();
		afficherPiles2(Pile12, Pile22, Pile32);
		delay(1000 / 60);
		//cleardevice();
		deplacer(Pile1, Pile3);
		afficherSupports();
		afficherPiles2(Pile12, Pile22, Pile32);
		hanoiv(n - 1, Pile2, Pile1, Pile3, Pile12, Pile22, Pile32);
	}
}
int main()
{
	srand(time(0));

	initwindow(1200,800, "First Sample");
	setbkcolor(0);
	setcolor(RED);
	
	Point A(100, 575);
	Point C(600, 25);
	Point B(1100, 575);
	//Sierprinski(11, A, B, C);

	Point D(300, 200);
	Point E(600, 500);
	Point F(900, 200);
	int NivFlocon = 8;
	//Koch(NivFlocon, D, F);
	//Koch(NivFlocon, E, D);
	//Koch(NivFlocon, F, E);

	Point G(600, 550);
	Point H(600, 475);
	//Arbre(20, G, H );
	
	/*
	for (size_t i = 0; i <= 3000; i++)
	{
		dessinerAttaque(static_cast<int>(frand_a_b(1.0, 9.0)), static_cast<int>(frand_a_b(1.0, 9.0)), static_cast<int>(frand_a_b(0.0, 2.0)));
		delay(200);
		nettoyerZoneAttaque();
	}*/

	
	Personnage Fabian(1, 1, "Fabian", 2000, 4, 4, 100, 100, 70, 0, 0, 7, 17, 0);
	Personnage Nicolas(1, 1, "Niquola", 2, 4, 4, 10, 10, 10, 0, 0, 7, 17, 0);
	Equipes Gentil(false);
	Gentil.ajouterPerso(Nicolas);
	Gentil.ajouterPerso(Fabian);

	Personnage Didier(1, 1, "Didier", 8, 1, 1,10,10,75,5,50,15,5,1);
	Personnage LOOL(1, 1, "LOL", 6, 2, 2,10,10,10,10,10,10,10,1) ;
	Personnage THOMY(1, 1, "THOMY", 6, 2, 2, 10,10,50,75,50,0,0,1);
	Personnage SACAPV(1, 3, "PVVV", 100, 10, 10, 0, 0, 0, 0, 0, 0, 0, 1);
	Equipes Meuchant(true);
	Meuchant.ajouterPerso(Didier);
	Meuchant.ajouterPerso(LOOL);
	Meuchant.ajouterPerso(THOMY);
	Meuchant.ajouterPerso(SACAPV);
	Combat(Gentil, Meuchant);
	/*Affichage Hi;
	Hi.dessinerDeuxEquipes(Gentil,Meuchant);
	for (int i = 0;i <= 100000000000;i++) {
		Attaque(Gentil.perso(1), Meuchant, Gentil);
	
		//Attaque(Didier, Gentil, Meuchant);
		//std::cout << Fabian.vie() <<" "<<Gentil[1].vie()<<std::endl;
		delay(500);
		Hi.dessinerDeuxEquipes(Gentil, Meuchant);

	}*/
	
	/*
	int n = 5;
	std::vector<int> Pile1, Pile2, Pile3;
	initPiles2(Pile1, Pile2, Pile3, n);
	afficherSupports();
	afficherPiles(Pile1, Pile2, Pile3);

	hanoiv(n, Pile1, Pile2, Pile3, Pile1, Pile2, Pile3);
	
	*/
	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}