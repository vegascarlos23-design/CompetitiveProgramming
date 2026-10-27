#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int Fx,Cy; cin>>Fx>>Cy;
    
    vector<vector<char>> G (Fx, vector<char>(Cy));
    vector<vector<bool>> vis(Fx, vector<bool>(Cy));

    for (int i = 0; i < Fx; i++) {
        for (int j = 0; j < Cy; j++) {
            cin>> G[i][j];
        }
    }
    vector<int> Ex = {-1,1,0,0};
    vector<int> Ey = {0,0,-1,1};

    function<void(int,int)> dfs = [&](int x, int y){
        vis[x][y] = 1;
        for (int k = 0; k < 4; k++) {
            int Px = x + Ex[k];
            int Py = y + Ey[k];

            if (Px >= 0 && Px < Fx && Py >= 0 && Py < Cy && G[Px][Py] == '.' && !vis[Px][Py]) {
                dfs(Px,Py);
            }
        } 
    };
    int c = 0;
    for (int i = 0; i < Fx; i++) {
        for (int j = 0; j < Cy; j++) {
            if (G[i][j] == '#' || vis[i][j]) continue;
            dfs(i,j);
            c++;    
        }
    }
    cout<<c;  
    return 0;
}
