#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Dictionnaire
{
    string mot;
    string natureOUgenre;
    string definition;
};

vector<string> spliter(string ligne, char del) {
    string temp = "";
    vector<string> splitted = {};

    for (int i = 0; i < (int)ligne.size(); i++) {
        if (ligne[i] != del) {
            temp += ligne[i];
        }
        else {
            splitted.push_back(temp);
            temp = "";
        } 
    }
    splitted.push_back(temp);
    return splitted;
}

int main()
{
    ifstream contenu;
    string line, word;
    contenu.open("dictionnaire.txt");
    vector<string> dico;
    Dictionnaire dico_max = {};

    if (contenu.is_open()) {
        vector<Dictionnaire> dictionnaire;
        while (!contenu.eof()) {

            Dictionnaire dico_temp = {};

            getline(contenu, line);

            vector<string> splitted_line = spliter(line, '\t');

            dico_temp.mot = splitted_line[0];
            dico_temp.natureOUgenre = splitted_line[1];
            dico_temp.definition = splitted_line[2];
            dictionnaire.push_back(dico_temp);

            }
        dico_max.mot = dictionnaire[0].mot;
        for (auto j : dictionnaire) {
            if (j.mot.length() > dico_max.mot.length()) {
                dico_max.mot = j.mot;
                dico_max.natureOUgenre = j.natureOUgenre;
                dico_max.definition = j.definition;

            }
        }
        cout << dico_max.mot << " (" << dico_max.natureOUgenre << ") : " << dico_max.definition;
        }
    contenu.close();
    return 0;
}
