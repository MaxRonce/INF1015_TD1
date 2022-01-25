#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

struct Dictionnaire
{
    string mot;
    string natureOUgenre;
    string definition;
};

array<string,3> spliter(string ligne, char del) {
    string temp = "";
    array<string,3> splitted = {};
    int i = 0;

    for (int j = 0; j < 3; ++j) {

        stringstream ssin(ligne);
        getline(ligne, splitted[j], '\t');
    }
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
            array<string,3> splitted_line = spliter(line, '\t');

            for (int i =0; i < 3; ++i) {
                cout << splitted_line[i] << endl;
            }

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
