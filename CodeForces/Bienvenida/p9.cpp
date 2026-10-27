#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long a,b; cin>>a>>b;
        long long na,nb;
        if ((a-1)%2 == 0) {
            na = (a-1)/2;
        }
        else {
            na = -(a/2);
        }
        if (b%2 == 0) {
            nb = b/2;
        }
        else {
            nb = -(b+1)/2;
        }
        cout<< nb - na<<'\n';
    }
    return 0;
}