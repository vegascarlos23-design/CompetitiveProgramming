#include<bits/stdc++.h>

using namespace std;

void num(string& s){
    int tam = s.length();
    int cont = 0;
    string ns = s;
    for (int i = 0; i < tam; i++)
    {
        s = ns;
        if (s[i] == '0') {
            s[i] = '1';
        }
        else {
            s[i] = '0';
        }
        for (int j = 0; j < tam; j++)
        {
            if (s[j] == '1') {
                cont++;
            }    
        }    
    }
    cout<<cont<<endl;
}


int main(){
    int n; cin>>n;
    int t;
    while (n--)
    {
        cin>>t;
        string s; cin>>s;
        num(s);
    }
    return 0;
}