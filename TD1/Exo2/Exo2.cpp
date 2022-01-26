#include <iostream>
using namespace std;

double entreeValeur(double borneInf, double borneSup, string message);



int main() {
	double somme, montantMensuel, tauxAnnuel, tauxMensuel;
	somme = entreeValeur(0, INFINITY, "Veuillez inserer une somme pretee positive :\n");
	montantMensuel = entreeValeur(0, INFINITY, "Veuillez inserer un montant mensuel rembourse positif :\n");
	tauxAnnuel = entreeValeur(0, 100, "Veuillez inserer un taux d'interet annuel positif inferieur à 100 :\n");
	tauxMensuel = 1 / double(12) * tauxAnnuel;
	int mois = 0; double interets = 0.0;
	while (somme >= 0) {
		somme -= montantMensuel;
		interets += somme * tauxMensuel;
		somme += somme * tauxMensuel;
		++mois;
	}
	cout << "le nombre de mois est :\n" << mois << endl;
	cout << "la somme des interets est:\n " << interets;
}


double entreeValeur(double borneInf, double borneSup, string message) {
	double valeur;
	do {
		cout << message;
		cin >> valeur;
	} while (!(valeur > borneInf || valeur <= borneSup));
	return valeur;
}