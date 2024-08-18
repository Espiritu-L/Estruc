#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char grid[100][100];
int vis[100][100];
int n, m;


int DFS(int r, int c){
    if (r < 0 || c < 0 || r >= n || c >= m) {
        return 0;
    }
    if (grid[r][c] != 'A' || vis[r][c] == 1) {
        return 0;
    }

    vis[r][c] = 1;
    int size = 1;
    int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    for (int i = 0; i < 8; ++i) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        size += DFS(nr, nc);
    }

    return size;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    int r, c;   cin >> r >> c;
    memset(vis, 0, sizeof(vis));
    if(grid[r][c] != 'A'){
        cout << "El lago mide 0 celdas" <<endl;
    }else{
        int size = DFS(r, c); 
        cout << "El lago mide " << size << " celdas"<<endl;
    }
    return 0;
}
