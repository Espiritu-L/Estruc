// ejercicio. el programa debe indicar se logro vistar a todas las letras
// 'A'. salida si se logro vistar a todos mostrar si SI no retornar NO

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
	
int DFS(int f, int c, int n, int m){ //f -> fila y c->columna n->tamaño filas m->tamaño columnas
	int r=0;
	if(f<0 || c<0){
		return 0;
	}
	if(f==n || c==m){
		return 0;
	}
	if(gr[f][c] == '#'){
		return 0; 
	}

	if(vis[f][c]==1){
		return 0;
	}
	if(gr[f][c] == 'A'){
		r++;
		vis[f][c] = 1;
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
		r = r + DFS(py, px, n, m);
		//DFS(c+dx[i], f+dy[i], n);
	}
	
	return r;
}		
int main(){
	int n, m, letrasA=0, total = 0;
	memset( vis, 0, sizeof(vis) );
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>gr[i][j];
			if(gr[i][j] == 'A'){
				letrasA++;
			}
		}  
	} 
	total = DFS(0,0,n, m);
	
	if(total == letrasA){
		cout << "SI :)" << endl;
	}else{
		cout << "NO :(" << endl;
	}
	return 0;
}

