#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    string s; cin>>s;

    set<char> t;
    for (auto& x : s) t.insert(x);
    int tp = t.size();
    
    map<char,int> freq;
    int ln = 0, co = 0, mn = n;

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (freq[c] == 0) co++;
        freq[c]++;

        while (co == tp) {
            mn = min(mn, i-ln+1);
            char lc = s[ln];
            freq[lc]--;
            if (freq[lc] == 0)  co--;
            ln++;
        }
    }
    cout<<mn;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    //cin >> t;
    while(t--)  solve();
    return 0;
}