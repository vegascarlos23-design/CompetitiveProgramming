#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int t; cin>>t;
    while (t--)
    {
        int Fx,Cy; cin>>Fx>>Cy;
    
        vector<vector<int>> G (Fx, vector<int>(Cy));
        vector<vector<bool>> vis(Fx, vector<bool>(Cy));

        for (int i = 0; i < Fx; i++) {
            for (int j = 0; j < Cy; j++) {
                cin>> G[i][j];
            }
        }
        vector<int> Ex = {-1,1,0,0};
        vector<int> Ey = {0,0,-1,1};
        int sum = 0;
        int max_sum = 0;

        function<void(int,int)> dfs = [&](int x, int y){
            vis[x][y] = 1;
            for (int k = 0; k < 4; k++) {
                int Px = x + Ex[k];
                int Py = y + Ey[k];
                if (Px >= 0 && Px < Fx && Py >= 0 && Py < Cy && G[Px][Py] != 0 && !vis[Px][Py]) {
                    sum += G[Px][Py];
                    dfs(Px,Py);
                }
            }
        };
        for (int i = 0; i < Fx; i++) {
            for (int j = 0; j < Cy; j++) {
                if (G[i][j] == 0 || vis[i][j]) continue;
                sum += G[i][j];
                dfs(i,j); 
                max_sum = max(max_sum, sum);
                sum = 0;
            }
        }
        cout<<max_sum<<'\n';   
    }
    return 0;
}
