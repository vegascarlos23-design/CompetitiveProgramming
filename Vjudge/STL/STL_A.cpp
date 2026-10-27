#include<bits/stdc++.h>
using namespace std;

void fp(string& s){
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '.') {
            cout<<s[i];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    while (n--) {
        for (int i = 0; i < 8; i++) {
            string s; cin>>s;
            fp(s);
        }
        cout<<endl;
    }
    return 0;
}