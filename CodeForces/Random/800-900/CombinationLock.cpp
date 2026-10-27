#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> v(n);
    if (n%2 == 0) {
        cout<<-1<<'\n';
        return;
    }
    if (n == 1) {
        cout<<1<<'\n';
        return;
    }
    if (n == 3) {
        cout<<1<<" "<<3<<" "<<2<<'\n';
        return;
    }
    int cur = 4;
    for (int i = 0; i < n; i++) {
        v[i] = cur;
        cur += 2;
        if (cur > n) {
            cur -= n;
        }
    }
    for (auto& x : v) {
        cout<<x<<" ";
    }
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while(t--)  solve();
    return 0;
}