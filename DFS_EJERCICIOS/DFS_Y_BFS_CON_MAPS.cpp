#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;
int vis[100];

void DFS(map< int, vector<int> > gr, int nodo){
  if(vis[nodo]==1){
    return;
  }
  cout<<nodo<<" ";
  vis[nodo] = 1;
  for(int i=0; i < gr[nodo].size();i++){
    DFS(gr, gr[nodo][i]);  
  }
}

void BFS(map< int, vector<int> > gr, int nodo){
  queue<int> cola;
  cola.push(nodo);
  int d;
  while(!cola.empty()){
    d = cola.front();
    cout<<d<<" ";
    cola.pop();
    vis[d] = 1;
    for(int i=0; i<gr[d].size();i++){
      if(vis[ gr[d][i] ] == 0 ){
        cola.push(gr[d][i]);
        vis[ gr[d][i] ] = 1;
      }
    }
  }
}

int main(){
  map< int, vector<int> > gr;
  map< int, vector<int> >::iterator it;
  int n;//Numero de Aristas
  int a, b; //a->origen, b->Destino
  cin>>n;
  for(int i=0;i<n;i++){ //Construida la Lista de Adyacencia
    cin>>a>>b;
    // a ambos lados
    gr[a].push_back(b);
    gr[b].push_back(a);
    sort(gr[a].begin(), gr[a].end());
    sort(gr[b].begin(), gr[b].end());
  }

  for(it=gr.begin(); it!=gr.end(); it++){
      cout<<(it)->first<<" -> ";
      for(int i=0;i<(int)(*it).second.size();i++){
        cout<<(*it).second[i]<<" ";
      }
      cout<<endl;
  }
  memset(vis, 0, sizeof(vis));
  cout<<"DFS"<<endl;
  DFS(gr, 1);
  cout<<endl;
  cout<<"BFS"<<endl;
  memset(vis, 0, sizeof(vis));
  BFS(gr, 1);
  return 0;
}
