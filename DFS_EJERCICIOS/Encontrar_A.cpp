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

bool DFS(int f, int c, int n) {
    bool r=false;
    
    if(f<0 || c<0 || f==n || c==n || gr[f][c] == '#'|| vis[f][c] == 1){
        return false;
    }
    
    // visitar
    vis[f][c] = 1;
    if(gr[f][c] == 'A'){
        return true;
    }
    
    mostrarVis(n);
    //Direccion de Movimiento
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int px, py;
    for(int i=0;i<4;i++){
        px = c + dx[i]; // calculando la nueva posicion de X (Columnas) 
        py = f + dy[i]; // la nueva posicion de Y (Filas)
        if(DFS(py, px, n)){
            return true;
        }
    }
  
    return false;
}
int main () {
    memset(vis, 0, sizeof(vis));

    int n; cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> gr[i][j];
        }
    }
    //DFS(0,0,n);
    if(DFS(0,0,n)){
        cout << "si";
    }else {
        cout << "no";
    }
    
    return 0;
}