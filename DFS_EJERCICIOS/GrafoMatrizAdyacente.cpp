#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// Matriz de adyacencia que representa el grafo
int gr[100][100];
// Arreglo que almacena el estado de visita de cada nodo
int vis[100];

// Función que realiza el recorrido en profundidad (DFS)
void recorridoProfundidad(int origen) {
    // Si el nodo 'origen' ya ha sido visitado, se retorna
    if(vis[origen]==1){
        return;
    }

    // Marca el nodo 'origen' como visitado
    vis[origen] = 1;
    // Imprime el nodo 'origen'
    cout << origen << " ";
    // Recorre todos los posibles nodos 'i'
    for (int i = 0; i < 100; i++) {
        // Si existe una arista entre 'origen' y 'i'
        if (gr[origen][i] == 1) {
            // Llama recursivamente a 'recorridoProfundidad' para explorar el subárbol a partir de 'i'
            recorridoProfundidad(i);
        }
    }
}

int main(){
  // Inicializa la matriz de adyacencia 'gr' a cero
  memset(gr, 0, sizeof(gr));

  int n, o, d;
  // Lee la cantidad de aristas
  cin >> n;

  // Lee los pares de nodos origen-destino y marca las aristas en 'gr'
  for (int i=0; i<n; i++) {
      cout << "nodo padre, nodo hijo: ";
      cin >> o >> d;
      gr[o][d] = 1;
      gr[d][o] = 1;
  }

  // Imprime la matriz de adyacencia 'gr'
  for(int i=0; i<20; i++){
      for(int j=0; j<20; j++){
          cout << gr[i][j] << " ";
      } cout << endl;
  }

  // Inicializa el arreglo 'vis' a cero
  memset(vis, 0, sizeof(vis));
  // Llama a 'recorridoProfundidad' para explorar el grafo a partir del nodo 1
  recorridoProfundidad(1);
  cout << endl;

  // Inicializa el arreglo 'vis' a cero
  memset(vis, 0, sizeof(vis));
  // Llama a 'recorridoProfundidad' para explorar el grafo a partir del nodo 2
  recorridoProfundidad(2);
  cout << endl;

  // Inicializa el arreglo 'vis' a cero
  memset(vis, 0, sizeof(vis));
  // Llama a 'recorridoProfundidad' para explorar el grafo a partir del nodo 3
  recorridoProfundidad(3);
  cout << endl;  

  return 0;
}
