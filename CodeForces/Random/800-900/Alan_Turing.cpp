#include<bits/stdc++.h>
using namespace std;

void cont(string& s1,string& s2){
    if (s1.length() != s2.length()) {
        cout<<"NO"<<"\n";
    }
        string cs1 = s1;
        string cs2 = s2;
        sort(cs1.begin(),cs1.end());
        sort(cs2.begin(),cs2.end());
        if (cs1 == cs2)
        {
            cout<<"SI"<<"\n";
        }
        else {
            cout<<"NO"<<"\n";
        } 
}
int main(){
    int n; cin>>n;
    while(n--) {
        string s1,s2; cin>>s1; cin>>s2; 
        cont(s1,s2);
    }

    return 0;
}