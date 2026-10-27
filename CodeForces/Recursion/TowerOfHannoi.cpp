#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(int n, int sr, int dr){
    if (n == 1) {
        cout<<"Move from "<< char(sr + 'A')<<" to "<<char(dr + 'A') << "."<<'\n';
        return;
    }
    int er = 3-sr-dr;
    solve(n-1, sr, er);
    cout<<"Move from "<< char(sr + 'A')<<" to "<<char(dr + 'A') << "."<<'\n';
    solve(n-1, er, dr);
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while(t--) {
        int n; cin>>n;
        char sr,dr; cin>>sr>>dr;
        solve(n, sr - 'A', dr - 'A');
        cout<<"Done!"<<'\n';
    }  
    return 0;
}