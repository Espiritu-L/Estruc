#include <iostream>
#include <cstring>
using namespace std;

char gr[100][100];
int vis[100][100];

void mostrarVis(int n){
    cout << "---------------------------\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------------\n";
}

void DFS(int f, int c, int n) {
    if(f<0 || c<0){
        return ;
    }

    if(f==n || c==n){
        return ;
    }

    if(gr[f][c] == '#'){
        return ;
    }

    if(vis[f][c] == 1){
        return ;
    }

    vis[f][c] = 1;

    mostrarVis(n);
    //Direccion de Movimiento
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int px, py;
    for(int i=0;i<4;i++){
        px = c + dx[i]; // calculando la nueva posicion de X (Columnas) 
        py = f + dy[i]; // la nueva posicion de Y (Filas)
        DFS(py, px, n);
        //DFS(c+dx[i], f+dy[i], n);
    }
  
    return ;
}
int main () {
    memset(vis, 0, sizeof(vis));

    int n; cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> gr[i][j];
        }
    }

    DFS(2,2,n);
    return 0;
}