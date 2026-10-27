#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n; cin>>n;
    if (n == 1){
        cout<<1;
        return;
    }
    if (n<=3) {
        cout<<"NO SOLUTION";
        return;
    }
    vector<int> v(n);
    v[0] = 1;
    bool fl = 1;
    if (n%2 == 0) {
        v[0] = 2;
        for (int i = 1; i < n; i++) {
            v[i] = v[i-1] + 2;
            if (v[i] == n) {
                v[i+1] = 1;
                i++;
            }
        }
        for(auto& x : v) cout<<x<<" ";
        return;
    }
    else {
        for (int i = 1; i < n; i++) {
            if (fl) {
                v[i] = v[i-1] + 2;
                if (v[i] == n) {
                    v[i+1] = v[i] - 3;
                    v[i+2] = n-1;
                    i+= 3;
                    if (n > 5) {
                        v[i] = v[i-2]-2;
                        fl = 0;
                    }
                
                }
            }
            else  v[i] = v[i-1] - 2;
        }
        for(auto& x : v) cout<<x<<" ";
        return;
    }
    
    
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    //cin >> t;
    while(t--)  solve();
    return 0;
}