#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    while (n--) {    
        string s; cin>>s;
        stack<char> st;
        bool pr = true;
        for (char& c : s) {
            if (c == '{' || c == '(' || c == '[' ) {
                st.push(c);
            }
            else {
                if (st.empty()){
                    pr = false;
                    break;
                }
                char u = st.top();
                if ( (c == '}' && u == '{') || (c == ')' && u == '(') || (c == ']' && u == '[') ) {
                    st.pop();
                }
                else {
                    pr = false;
                    break;
                }
            }
        } 
        if (st.empty() && pr) {
            cout<<"YES"<<'\n';
        }
        else {
            cout<<"NO"<<'\n';
        }  
    }
    return 0;
}  
