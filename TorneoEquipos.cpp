#include<iostream>
#include<ctime>
#include<cstdlib>
#include<random>
#include<vector>

using namespace std;

class Equipo {
  private:
    char id;
    int lvl;
  public:
    Equipo (char c, int l) {
        id = c;
        lvl = l;
    }
    char GetId() {
        return id;
    }
    int getLvl() {
        return lvl;
    }
    void setLvl(int l) {
        lvl = l;
    }
    void setId(char c) {
        id = c;
    }
};

// Se elige un numero aleatorio entre 1 y (a+b). Si el numero <= a, el ganador es a. Si no, el ganador es b.
// https://hmp.me/cpp8
char jugar(Equipo a, Equipo b) {
    int eleccion = rand() % ( a.getLvl() + b.getLvl() ) + 1;
    return (eleccion <= a.getLvl() ) ? a.GetId() : b.GetId();
}

// lo anterior, con paso por referencia
char jugar(Equipo *a, Equipo *b) {
    int eleccion = rand() % ( a->getLvl() + b->getLvl() ) + 1;
    return (eleccion <= a->getLvl() ) ? a->GetId() : b->GetId();
}

void bracket(vector<Equipo> &teams, int amount) {
    cout << endl;
    for(int i = 0; i < amount / 2; ++i) {
        cout << "Pelea el equipo " << teams[i].GetId() << " con el equipo " << teams[i+1].GetId() << endl;
        char winner = jugar(teams[i],teams[i+1]);
        cout << "Gana el equipo " << winner << "!" << endl;
        if (teams[i].GetId() == winner) {
            teams.erase(teams.begin() + i+1);
        } else {
            teams.erase(teams.begin() +   i);
        }
    }
    cout << endl;
}

void rellenar(vector<Equipo> &teams) {
    vector<int> lvl;
    vector<char> id;
    int templvl;
    char tempid;
    for(int i = 0; i < 16; ++i) {
        cout << "Ingrese identificador del equipo " << i+1 << ": ";
        cin >> tempid;
        id.push_back(tempid);
    }
    for(int i = 0; i < 16; ++i) {
        cout << "Ingrese nivel del equipo " << i+1 << ": ";
        cin >> templvl;
        lvl.push_back(templvl);
    }
    for(int i = 0; i < 16; ++i) {
        teams.push_back( Equipo(id[i], lvl[i]));
    }
}

int main() {
    srand (time(NULL));
    vector<Equipo> teams;
    rellenar(teams);
    
    cout << "Octavos de final:" << endl;
    bracket(teams, 16);
    cout << "Cuartos de final:" << endl;
    bracket(teams, 8);
    cout << "Semifinales:" << endl;
    bracket(teams, 4);
    cout << "Finales:" << endl;
    bracket(teams, 2);

    cout << endl << "Ganador final del torneo: Equipo " << teams[0].GetId();
    return 0;
}
