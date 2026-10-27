#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    string s; cin>>s;
    int c = 1, mxc = 1;

    for (int i = 0; i < (int)(s.size()-1); i++) {
        if (s[i] == s[i+1]) {
            c++;
        }
        else {
            mxc = max(mxc, c);
            c = 1;
        }
    }
    mxc = max(mxc,c);
    cout<<mxc;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    //cin >> t;
    while(t--)  solve();
    return 0;
}