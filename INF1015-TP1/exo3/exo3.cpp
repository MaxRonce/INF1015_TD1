#include <iostream>
#include <cmath> 

using namespace std;

double entreeValeurValide(double borneINF, double borneSUP, string message);

int main() {
	double constanteGravite = 9.81; double hauteurFinale = 0;
	double hauteurInitiale = entreeValeurValide(0, INFINITY, "Veuillez entrer la hauteur initiale :\n");
	double nombreRebonds = entreeValeurValide(0, INFINITY, "Veuillez entrer le nombre de rebonds: \n");
	double coefficientRebonds = entreeValeurValide(0, 1, "Veuillez entrer le coefficient de rebonds: \n");
	for (double i = 1; i <= nombreRebonds; ++i) {
		double vitesseAvantRebonds = sqrt(2 * constanteGravite * hauteurInitiale);
		double vitesseApresRebonds = coefficientRebonds * vitesseAvantRebonds;
		hauteurFinale = pow(vitesseApresRebonds, 2) / (2 * constanteGravite);
		hauteurInitiale = hauteurFinale;
		vitesseAvantRebonds = vitesseApresRebonds;
	}
	cout << "hauteur max est : " << hauteurFinale;

}
double entreeValeurValide(double borneINF, double borneSUP, string message) {
	double valeur;
	do {
		cout << message;
		cin >> valeur;
	} while (valeur > borneSUP || valeur < borneINF);
	return valeur;
}