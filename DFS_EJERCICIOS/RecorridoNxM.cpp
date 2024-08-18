// recorer dimension nxm

#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm>

using namespace std;
char gr[100][100]; //grafo usando matriz de adyacencia
int vis[100][100]; // Para saber si un nodo fue visitado(1) o no visitado(0)

void mostrarVis(int n, int m){ //mostrar array de visitados
	cout<<"-------------------------------------"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<vis[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"-------------------------------------"<<endl;
}
	
void DFS(int f, int c, int n, int m){ //f -> fila y c->columna n->tamaño filas m->tamaño columnas
	
	if(f<0 || c<0){
		return ;
	}
	if(f==n || c==m){
		return ;
	}
	if(gr[f][c] == '#'){
		return ; 
	}
	
	if(vis[f][c]==1){
		return ;
	}
	
	vis[f][c] = 1;
	mostrarVis(n, m);
	//Direccion de Movimiento
	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};
	//Cambios en x e y
	int px, py;
	for(int i=0;i<4;i++){
		px = c + dx[i]; // calculando la nueva posicion de X (Columnas) 
		py = f + dy[i]; // la nueva posicion de Y (Filas)
		DFS(py, px, n, m);
		//DFS(c+dx[i], f+dy[i], n);
	}
	
	return ;
}

int main(){
	int n, m;
	memset( vis, 0, sizeof(vis) );
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>gr[i][j];
		}  
	} 
	DFS(0,0,n, m);
	return 0;
}
