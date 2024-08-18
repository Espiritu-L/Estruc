#include <iostream>
#include <cstring>
using namespace std;

int gr[100][100];
int vis[100][100];

void mostrarVis (int n, int m) {
    cout << "---------------------------" << endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << vis[i][j] << " ";
        } cout << endl;
    }
    cout << "---------------------------" << endl;
}

int DFS (int f, int c, int n, int m) {
    int cont = 0;
    int aux = gr[f][c];

    if (f<0 || c<0) {
        return 0;
    }
    if(f==n || c == m){
        return 0;
    }

    if(gr[f][c] != aux) {
        return 0;
    }

    vis[f][c] = 1;
	mostrarVis(n, m);
    //Direccion de Movimiento
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int px, py;
}
int main () {

    return 0;
}