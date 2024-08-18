#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int arb[100][100]; // variable global

// para niveles
int niveles (int origen){

    int r=1;
    
    for (int i = 0; i < 100; i++) {
        if (arb[origen][i] == 1) { // Si existe una arista entre 'origen' y 'i'
            // Calcula el nivel máximo entre el nivel actual 'r'
            // y el nivel del nodo 'i' más 1 (ya que al moverse a un nodo adyacente, el nivel aumenta en 1)
            
// La función 'max(a, b)' devuelve el valor máximo entre 'a' y 'b'.
// En este contexto, 'r' representa el nivel actual del nodo 'origen',
// y 'niveles(i) + 1' representa el nivel del nodo 'i' más 1.
// Al utilizar 'max(r, niveles(i) + 1)', se está seleccionando el nivel más alto
// entre el nivel actual del nodo 'origen' y el nivel del nodo 'i' más 1.
// Esto asegura que 'r' contenga el nivel máximo entre el nodo actual y sus nodos adyacentes.

            
            r = max(r, niveles(i) + 1);
        }
    }
    return r;
}

// para mostrar
void recorridoProfundidad (int origen) {
    cout << origen <<" ";
    for(int i=0; i<100; i++){
        
        // si existe arista 
        if (arb[origen][i] == 1) {
            // recursiva
            recorridoProfundidad(i);
        }
    }
}

int main(){

    memset(arb, 0, sizeof(arb)); // matriz inicial a cero

    // arbol
    int n, p, h; // n = nodo o num de aristas, p = padre, h = hijo
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout<<"nodo padre  nodo hijo: ";
        cin >> p >> h;
        arb[p][h] = 1; // realizando el marcado
    }

    // imprimiendo
    //cout << "  1 2 3 4 5 6 7 8 9 10 11"<<endl;
    //int l =1;

    /*for(int i=1;i<=20;i++){
        //cout << l << " ";
        for(int j=1;j<=20;j++){
        cout<<arb[i][j]<<" "; 
        }
        cout<<endl; //l++;
    }*/



    recorridoProfundidad(1);
    cout << endl;
    cout << niveles(1) << endl; // niveles

}