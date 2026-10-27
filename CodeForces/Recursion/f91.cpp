#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(int n){
    if (n <= 100) {
        cout<<"f91("<<n<<") = "<< 91<<'\n';
        return;
    }
    cout<<"f91("<<n<<") = "<< n-10<<'\n';
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    bool t = 1; 
    //cin >> t;
    while(t) {
        int n; cin>>n;
        if (n == 0) t = 0;  
        else solve(n);
    }  
    return 0;
}