#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main () {
    int gr[20][20];
    int vis[20];
    memset(gr, 0, sizeof(gr));
    memset(vis, 0 , sizeof(vis));


    int aristas, origen, destino;

    cin >> aristas;

    
    for(int i=0; i<aristas; i++){
        cin >> origen >> destino;

        gr[origen][destino] = 1;
        gr[destino][origen] = 1;

    }

    // mostrar la matriz de adyacencia
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            cout << gr[i][j] << " ";
        } cout << endl;
    }

    queue<int> q;
    
    q.push(1);

    while (!q.empty())
    {
        origen = q.front();
        q.pop();

        cout << origen << "  ";

        for(int i=0; i<6; i++){   
            if(gr[origen][i] == 1 && vis[i] == 0){
                q.push(i); 
                vis[i] = 1;
            }
        }
    }
    
    
    return 0;
}