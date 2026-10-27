#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bool com = 0;
        map<char,int> map;
        string s; cin>>s;
        map[s[0]]++;
        map[s[n-1]]++;

        for (int i = 1; i < n-1; i++)
        {
            if (map[s[i]] >= 1) {
                com = 1;
                break;
            }
            map[s[i]]++;
        }
        com == 1 ? cout<<"Yes"<<'\n' : cout<<"No"<<'\n';
    }
    return 0;
}
