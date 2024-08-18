#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int vis[100];

void BFS(map<int, vector<int>> gr, int nodo) {
    queue<int> cola;
    cola.push(nodo);
    int d;
    while (!cola.empty()) {
        d = cola.front();
        cout << d << " ";
        cola.pop();
        vis[d] = 1;
        for (int i = 0; i < gr[d].size(); i++) {
            if (vis[gr[d][i]] == 0) {
                cola.push(gr[d][i]);
                vis[gr[d][i]] = 1;
            }
        }
    }
}

int main() {
    map<int, vector<int>> gr;
    int n;  // Número de Aristas
    int a, b;  // a->origen, b->Destino
    cin >> n;
    for (int i = 0; i < n; i++) {  // Construida la Lista de Adyacencia
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
        sort(gr[a].begin(), gr[a].end());
        sort(gr[b].begin(), gr[b].end());
    }

    memset(vis, 0, sizeof(vis));
    cout << "BFS" << endl;
    BFS(gr, 1);
    return 0;
}
