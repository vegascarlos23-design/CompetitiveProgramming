#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n,s; cin>>n>>s;
        int minv = 0, maxv = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin>>v[i];
        }
        if (s>=v[n-1])  {
            cout<<s-v[0]<<'\n';
        }
        else if (s<=v[0])   {
            cout<<v[n-1]-s <<'\n';
        }
        else    {
            minv = min(abs(s-v[0]),abs(s-v[n-1]));
            maxv = max(abs(s-v[0]),abs(s-v[n-1]));
            cout<<minv*2 + maxv<<'\n';
        }
        
    }
    return 0;
}
