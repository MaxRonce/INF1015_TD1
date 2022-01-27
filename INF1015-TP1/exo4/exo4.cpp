#include <iostream>
#include <iomanip>
#include <cstdlib>
#include<ctime>

using namespace std;


double nombreAleatoire();
bool pointDansCercle(double valeur1, double valeur2);
void ecartRelatif(double valeur);

int main() {
	srand((unsigned)time(NULL)); // permet de generer un nombre different a chque generation (date)
	double iterations;
	double dansCercle = 0;
	cout << "Veuillez inserer le nombre d'iterations :\n";
	cin >> iterations;
	for (int i = 0; i < iterations; ++i) {
		double randomx = nombreAleatoire();
		double randomy = nombreAleatoire();
		if (pointDansCercle(randomx, randomy)) {
			++dansCercle;
		}
	}
	double valeurApprochee = (dansCercle / iterations) * 4;
	cout << "la valeur approchee avec une precision de 10e-6 est : " << setprecision(6) << valeurApprochee << "\n";
	ecartRelatif(valeurApprochee);


}

double nombreAleatoire() {
	return ((double)(rand()) / (RAND_MAX / 2)) - 1; // randmax=2^32 and 2 c'est la longueur d'intervalle
}

bool pointDansCercle(double valeur1, double valeur2) {
	if (pow(valeur1, 2) + pow(valeur2, 2) < 1) {
		return true;
	}
	else {
		return false;
	}
}

void ecartRelatif(double valeur) {
	double valeurPiPrecise = 3.1415932;
	double ecart = abs(valeur - valeurPiPrecise);
	cout << "l'ecart relatif entre cette valeur approchee et la valeur precise a 10e-6 est : " << ecart << "\n";
}