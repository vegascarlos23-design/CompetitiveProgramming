#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    set<int> v;
    for (int i = 0; i < n; i++){
        int x; cin>>x;
        v.insert(x);
    }
    cout<<v.size()<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while(t--)  solve();
    return 0;
}