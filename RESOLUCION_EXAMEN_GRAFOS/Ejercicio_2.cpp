#include <iostream>
#include <cstring>

using namespace std;

char gr[100][100]; 
int vis[100][100]; 

void DFS(int f, int c, int n, int m, char dato){
    if (f <0 ||c < 0||f>= n||c>= m) {
        return;
    }
    if(gr[f][c] !=dato ||vis[f][c]== 1){
        return;
    }
    
    vis[f][c] = 1;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    for(int i = 0;i < 4; ++i){
        int nx = f + dx[i];
        int ny = c + dy[i];
        DFS(nx, ny, n, m, dato);
    }
}

int main() {
    int n, m;
    cin >>n >>m; 
    
    for(int i = 0; i < n;i++){
        for(int j = 0;j< m;j++){
            cin>> gr[i][j];
        }
    }
    
    memset(vis, 0, sizeof(vis));
    int total = 0;
    for(int i = 0; i<n;i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j]==0 && gr[i][j]== 'L'){
                total++;
                DFS(i, j, n, m, 'L');
            }
        }
    }
    cout << total << endl;
    return 0;
}
