#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    map<int, vector<int>> gr;
    int n; cin >> n; // carretera
    int a, b; 
    for(int i=0; i<n;i++){
        cin >> a>> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    int p;      cin >> p;

    //ordenando los nodos de la lista de adayacencia
    for(auto num : gr) {
        sort(num.second.begin(), num.second.end());
    }

    //ndos conectados a p
    if(gr.find(p) != gr.end()){
        for(int i = 0; i< gr[p].size(); i++) {
            cout << gr[p][i] << " ";
        }
        cout<< endl;
    }

    return 0;
}
