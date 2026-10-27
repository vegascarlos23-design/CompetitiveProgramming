#include<bits/stdc++.h>
using namespace std;
     
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<pair<int,int>,int> m;
    pair<int,int> p = {0,0};
    m[p] = 1;
    int n; cin>>n;
    for (int i = 0; i < n; i++) {   
        char c; cin>>c;
        pair<int, int> pt;
        switch (c) {
            case 'R':
                p.first += 1;
                pt = {p.first, p.second};
                m[pt]++;
                break;
            case 'L':
                p.first += -1;
                pt = {p.first, p.second};
                m[pt]++;
                break;
            case 'D':
                p.second += -1;
                pt = {p.first, p.second};
                m[pt]++;
                break;
            case 'U':
                p.second += 1;
                pt = {p.first, p.second};
                m[pt]++;
                break;
        }
        if (m[pt] >= 2)
        {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}