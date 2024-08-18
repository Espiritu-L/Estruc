#include<iostream>
#include<cstring>

using namespace std;

int gr[100][100];
int vis[100][100];

void mostrarVis(int n, int m){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<vis[i][j]<<" ";
    }
    cout<<endl;
  }
}

void DFS(int fila, int col, int n, int m,int c){
  mostrarVis( n, m);
  if(fila<0 || col< 0){
    return ;
  }
  if(fila>=n || col>=m){
    return ;
  }

  if(vis[fila][col]==1){
    return ;
  }

  if(gr[fila][col]!=c){
    return ;
  }

  vis[fila][col] = 1;

  int dx[]={0, 1, 0, -1};
  int dy[]={-1, 0, 1, 0};
  for(int i=0;i<4;i++){
    DFS(fila+dy[i], col+dx[i], n, m, c);
  }
}

int main(){
  int n, m, c;
  memset(vis, 0, sizeof(vis));
  cin>>n>>m>>c;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>gr[i][j];
    }
  }

  int r = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(gr[i][j]!=0 && gr[i][j]!=c && vis[i][j]==0){
        DFS(i, j, n, m, gr[i][j]);
        r = r + 1;
      }
    }
  }
  cout<<r<<endl;
  

  
}