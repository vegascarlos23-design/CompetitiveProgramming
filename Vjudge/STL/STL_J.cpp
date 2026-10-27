#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while (t--)
    {      
        int n;cin>>n;
        map<string,int> m;
        vector<vector<string>> v(3, vector<string> (n));
        vector<int> p(3,0);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++)
            {
                cin>>v[i][j];
                m[v[i][j]]++;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                if (m[v[i][j]] == 1) {
                    p[i] += 3;
                }
                else if (m[v[i][j]] == 2) {
                    p[i] += 1;
                }               
            }
        }  
        cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<"\n"; 
    }    
    return 0;
}