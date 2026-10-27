#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    map<string,int> m;
    while (n--)
    {    
        string name = ""; cin>>name;
        if (m.count(name)) {
            cout<<name<<m[name]<<"\n";
            m[name]++;
        }
        else {
            cout<<"OK"<<"\n";
            m[name] = 1;
        }
    }  
    return 0;
}