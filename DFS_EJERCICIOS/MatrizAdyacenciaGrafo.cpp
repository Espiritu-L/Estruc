#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int gr[100][100];
int vis[100];

void DFS(int origen) {
    if(vis[origen]==1){
        return ;
    }

    vis[origen] = 1;  
    
    cout << origen << " ";
    for (int i = 0; i < 100; i++) {
        if (gr[origen][i] == 1) {
            DFS(i);
        } 
    }

}

int main(){
    memset(gr, 0, sizeof(gr));

    int n, o, d;
    // numero de aristas
    cin >> n;

    for (int i=0; i<n; i++) {
        cout << "nodo padre, nodo hijo: ";
        cin >> o >> d;
        gr[o][d] = 1;
        gr[d][o] = 1;
    }

    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            cout << gr[i][j] << " ";
        } cout << endl;
    }

    memset(vis, 0, sizeof(vis));
    DFS(1);
    cout << endl;

    memset(vis, 0, sizeof(vis));
    DFS(2);
    cout << endl;

    memset(vis, 0, sizeof(vis));
    DFS(3);
    cout << endl;  

    return 0;
}
