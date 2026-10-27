#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin>>v[i];
    
    sort(v.begin(),v.end());
    auto solve1 = [&](int x){
        int c=0;
        for (int i = 0; i < n; i++)
        {
            if ((x+v[i])%2!=0){
                c++;
            }
            else    {
                return c;
            }
        }
        return c;
    };
    auto solve2 = [&](int y){
        int c=0;
        for (int i = n-1; i >= 0; i--)
        {
            if ((y+v[i])%2!=0){
                c++;
            }
            else    {
                return c;
            }
        }
        return c;
    };
    cout<<min(solve1(v[n-1]),solve2(v[0]))<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while(t--)  solve();
    return 0;
}