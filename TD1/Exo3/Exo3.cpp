#include <cmath>
#include <iostream>
using namespace std;

double entreeValeurValide(double borneINF, double borneSUP, string message) {
    double valeur;
    do {
        cout << message;
        cin >> valeur;
    } while (valeur > borneSUP || valeur < borneINF);
    return valeur;
}

int main()
{
    double hauteurInitiale, coefficiantRebond, nombreRebond, constGravite = 9.81;

    hauteurInitiale = entreeValeurValide(0, INFINITY, "Entrer la hauteur initiale de la balle : ");
    coefficiantRebond = entreeValeurValide(0, 1, "Entrer le coefficiant de rebond : ");
    nombreRebond = entreeValeurValide(0, INFINITY, "Entrer le nombre de rebond souhaites : ");
    nombreRebond = int(nombreRebond);

    double vitesseActuelle, vitesseSuivante,hauteurActuelle, hauteurSuivante;
    vitesseActuelle = sqrt(2 * constGravite * hauteurInitiale);
    hauteurActuelle = hauteurInitiale;

    for (int i = 0; i < nombreRebond; i++) {
        vitesseSuivante = coefficiantRebond * vitesseActuelle;
        hauteurSuivante = pow(vitesseSuivante, 2) / (2 * constGravite);
        vitesseActuelle = vitesseSuivante;
        hauteurActuelle = hauteurSuivante;
    }
    cout << "La hauteur atteinte par la balle au bout de " << nombreRebond << " rebond est : " << hauteurActuelle;

    
}
