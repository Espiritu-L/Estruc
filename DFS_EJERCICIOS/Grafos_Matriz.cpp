#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm>

using namespace std;
int gr[100][100]; //grafo usando matriz de adyacencia
int vis[100][100]; // Para saber si un nodo fue visitado(1) o no visitado(0)

void mostrarVis(int n){ //mostrar array de visitados
  cout<<"-------------------------------------"<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<vis[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"-------------------------------------"<<endl;
}

void DFS(int f, int c, int n){ //f -> fila y c->columna n->tamaño del mapa

    if(f<0 || c<0){
        return ;
    }
    if(f==n || c==n){
        return ;
    }
    if(gr[f][c] == '#'){
        return ; 
    }
  
    if(vis[f][c]==1){
        return ;
    }

    vis[f][c] = 1;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int px, py; // py fila, px columna

    // mostrar cada paso del recorrido
    mostrarVis(n);

    for(int i=0;i<4;i++){
        px = c + dx[i]; // calculando la nueva posicion de X (Columnas) 
        py = f + dy[i]; // la nueva posicion de Y (Filas)
        DFS(py, px, n);
    }
  
    return ;
}

int main(){
    
    memset(vis, 0, sizeof(vis));
    char laberinto[10][10];
    int n; // tamanio de la matriz
    cin >> n;

    cout << "Ingrese los elementos de la matriz:" << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //cin >> gr[i][j];
            cin >> laberinto[i][j];
        }
    }

    DFS(0,0, n);
    return 0;
}