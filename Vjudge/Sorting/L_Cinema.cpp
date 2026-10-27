#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin>>n;
    map<int,int> vr;
    for (int i = 0; i < n; i++) {
        long long t; cin>>t;
        vr[t]++;
    }

    int m; cin>>m;
    vector<long long> a(m), s(m);

    for (int i = 0; i < m; i++)     cin>>a[i];
    for (int i = 0; i < m; i++)     cin>>s[i];
    
    int mi = 0,mp1 = -1,mp2 = -1;

    for (int i = 0; i < m; i++) {
        int p1 = vr[a[i]], p2 = vr[s[i]];
        if (p1>mp1 || (p1 == mp1 && p2 > mp2))
        {
            mp1 = p1;
            mp2 = p2;
            mi = i+1;
        }
    }
    cout<<mi;
    return 0;
}