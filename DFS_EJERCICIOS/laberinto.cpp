#include <iostream>
using namespace std;

int vis[10][10] = {0}; // matriz de visitados inicializada a 0
char laberinto[10][10]; // matriz para el laberinto

void mostrarLaberinto(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << vis[i][j] << "  ";
        }
        cout << endl;
    }
}

void DFS(int f, int c, int n) {
    // Comprobación de límites y condiciones de base
    if (f < 0 || c < 0 || f >= n || c >= n || laberinto[f][c] == '#' || vis[f][c] == 1) {
        return;
    }

    vis[f][c] = 1; // Marca la celda como visitada
    mostrarLaberinto(n);

    if (laberinto[f][c] == 'S') {
        cout << "SALIDA ENCONTRADA..!!" << endl;
        exit(0); // salir del programa
    }

    // Desplazamientos en las 4 direcciones: derecha, abajo, izquierda, arriba
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    for (int i = 0; i < 4; i++) {
        int px = c + dx[i];
        int py = f + dy[i];
        DFS(py, px, n);
    }
}

int main() {
    int n;
    cin >> n; // tamaño de la matriz

    // realizar el laberinto
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> laberinto[i][j];
        }
    }

    // comenzar DFS desde des cualquier posicion
    DFS(0,0, n);
    // Comenzar DFS desde una celda no bloqueada
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (laberinto[i][j] != '#') {
                DFS(i, j, n);
                break;
            }
        }
        break;
    } */
    //cout << "No se encontro la salida" << endl;
    return 0;
}
