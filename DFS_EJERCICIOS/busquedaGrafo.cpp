#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef map<string, vector<string>> Grafo;

ostream& operator<<(ostream &out, const Grafo &grafo){
    for (auto const &vertice: grafo) {
        out << vertice.first << ": ";
        out << "[";

        for(size_t i=0; i< vertice.second.size(); i++){
            out << vertice.second[i];
            if(i!=vertice.second.size() -1){
                out << ", ";
            } 
        }

        out << "]";
        out << endl;
    }
    return out;
}
// & para hacer referencia


int main(){
    // clace    valor
   // map<string, vector<string>> grafo;

    Grafo grafo;

    grafo["A"] = {"B","C","D"};
    grafo["B"] = {"A","H"};
    grafo["C"] = {"A","G","F"};
    grafo["D"] = {"A","E"};
    grafo["H"] = {"B","I"};
    grafo["G"] = {"C","J"};
    grafo["F"] = {"C","J"};
    grafo["E"] = {"D","K"};
    grafo["I"] = {"H","J"};
    grafo["J"] = {"G","F","I","K"};
    grafo["K"] = {"J","E"};

    cout<< grafo;

    return 0;
}