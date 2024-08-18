#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm>

using namespace std;
int gr[100][100]; //grafo usando matriz de adyacencia
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

void DFS(int f, int c, int n, int m, int color){
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, -1, 0, 1};

  if(gr[f][c]!=color){
    return ;  
  }

  if(vis[f][c]==1){
    return;
  }

  vis[f][c] = 1;
  mostrarVis(n, m);
  for(int i=0;i<4;i++){
    if((c+dx[i])>=0 && (f+dy[i])>=0 && (c+dx[i])<m && (f+dy[i])<n ){
      DFS(f+dy[i], c+dx[i], n, m, color);  
    }
  }  
}

int main(){
  int n, m, total=0;
  memset( vis, 0, sizeof(vis) );
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>gr[i][j];      
    }  
  } 
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(vis[i][j]==0 && gr[i][j]!=0){
        total = total + 1;
        DFS(i, j, n, m, gr[i][j]);
      }
    }
  }
  cout<<total<<endl;
  return 0;
}