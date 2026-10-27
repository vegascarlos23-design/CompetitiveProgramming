#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x; cin>>x;
    int ts = 0,cur = 1;
    while (cur < x) {
        cur = cur*2 +1;
        ts++;
    }
    cout<<ts*2+3<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while(t--)  solve();
    return 0;
}