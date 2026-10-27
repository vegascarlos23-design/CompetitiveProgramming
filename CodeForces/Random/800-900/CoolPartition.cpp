#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--)  {
        int n,c=0; cin>>n;

        vector<int> v(n);
        set<int> a, b;
        for (int i = 0; i < n; i++) cin>>v[i];
        a.insert(v[0]);
        for (int i = 0; i < n; i++) {
            a.erase(v[i]);
            b.insert(v[i]);
            if (a.empty())  {
                c++;
                a = b;
                b.clear();
            }
        }
        cout<<c<<'\n';
            
    }
    return 0;
}