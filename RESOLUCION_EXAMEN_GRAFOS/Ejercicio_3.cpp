#include <iostream>
#include <map>
#include <vector>
#include <cstring>

using namespace std;
int vis[1000];

void DFS(map<int, vector<int>>& gr, int nodo, int res) {
    if (vis[nodo] == 1) {
        return;
    }
    if (nodo == res) {
        vis[nodo] = 1;
        return;
    }
    vis[nodo] = 1;
    for (int i = 0; i < gr[nodo].size(); i++) {
        if (!vis[gr[nodo][i]]) {
            DFS(gr, gr[nodo][i], res);
        }
    }
}

int main() {
    map<int, vector<int>> gr;
    int n;  cin >>n;

    for (int i= 0; i <n; i++) {
        int a, b; cin>> a>> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    int q; cin >> q;

    for(int i =0; i <q;i++) {
        int s, e;
        cin >> s >> e;
        memset(vis, 0, sizeof(vis));
        DFS(gr, s, e);

        if(vis[e] == 1) {
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
