#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int vis[100];


void DFS(map<int, vector<int>> gr, int nodo) {
    if (vis[nodo] == 1) {
        return;
    }
    vis[nodo] = 1;
    //cout << nodo << " "; // mostrar el elemento vistado
    for (int i = 0; i < gr[nodo].size(); i++) {
        DFS(gr, gr[nodo][i]);
    }
}

int main() {
    map<int, vector<int>> gr;
    int n, m;  // n: Número de Nodos, m: Número de Aristas
    int a, b;  // a->origen, b->Destino
    cin >> n >> m;  // Leer número de nodos y aristas

    // Construir la lista de adyacencia
    for (int i = 0; i < m; i++) {  
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);  // Grafo no dirigido
    }

    memset(vis, 0, sizeof(vis));
    
    int componentes = 0;
    // Contar componentes conexas
    for (int i = 1; i <= n; i++) {  // Asumimos que los nodos están numerados del 1 al n
        if (vis[i] == 0) {
            DFS(gr, i);
            componentes++;
        }
    }

    cout << componentes << endl;
    return 0;
}
