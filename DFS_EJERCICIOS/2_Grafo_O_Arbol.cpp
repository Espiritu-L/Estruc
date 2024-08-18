//Aquí tienes una implementación en C++ que verifica si
// cada grafo de entrada es un árbol:
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(map<int, vector<int>> &gr, vector<int> &vis, int nodo, int &edges) {
    if (vis[nodo] == 1) {
        return;
    }
    vis[nodo] = 1;
    for (int i = 0; i < gr[nodo].size(); i++) {
        edges++;
        DFS(gr, vis, gr[nodo][i], edges);
    }
}

bool isTree(map<int, vector<int>> &gr, int n, int m) {
    if (m != n - 1) {
        return false; // Un árbol con n nodos tiene exactamente n-1 aristas
    }

    vector<int> vis(n + 1, 0);
    int componentes = 0, edges = 0;

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            componentes++;
            DFS(gr, vis, i, edges);
        }
    }

    // Verificar que el grafo sea conexo y sin ciclos
    return (componentes == 1 && edges == 2 * (n - 1));
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        map<int, vector<int>> gr;

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            gr[a].push_back(b);
            gr[b].push_back(a);  // Grafo no dirigido
        }

        if (isTree(gr, n, m)) {
            cout << "SI" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
