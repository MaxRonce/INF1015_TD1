
#include <iostream>
#include <cmath>
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
    double sommePrette, tauxInteretAnnuel, montantRembourse, tauxInteretMensuel;

    sommePrette = entreeValeurValide(0, INFINITY, "Entrer une somme positive : ");
    tauxInteretAnnuel = entreeValeurValide(0, 100, "Entrer un taux d'interet annuel positif : ");
    tauxInteretMensuel = tauxInteretAnnuel / 12;
    montantRembourse = entreeValeurValide(0, INFINITY, "Entrer un montant a rembourser : ");


    cout << sommePrette<<endl;
    cout << tauxInteretAnnuel << endl;
    cout << montantRembourse << endl;
    int mois = 0, sommeInterets = 0;
    while(sommePrette>=0){
        sommePrette = sommePrette - montantRembourse;

        sommeInterets = sommeInterets + sommePrette * tauxInteretMensuel;
        sommePrette = sommePrette + sommePrette * tauxInteretMensuel;
        mois++;
    }
    cout << "La somme a ete remboursee au bout de " << mois << " mois " << endl;
    cout << "LA somme des interets percus par le pretteur est : " << sommeInterets;

}   
