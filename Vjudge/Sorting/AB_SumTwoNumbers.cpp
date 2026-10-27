#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    map<long long, int> p;

    for (int i = 0; i < n; i++) {
        cin>>a[i];
        long long c = x - a[i];
        if (p.count(c)) {
            cout<<p[c]<<" "<<i + 1;
            return 0;
        }
        p[a[i]] = i + 1; 
    }
    cout<<"IMPOSSIBLE";
    return 0;
}