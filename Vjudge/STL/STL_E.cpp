#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);  
    cin.tie(nullptr);             

    int N,Q; cin>>N>>Q;
    map<int,set<int>> sigue;
    for (int i = 0; i < Q; i++) {
        int T,A,B; cin>>T>>A>>B;
        if (T==1) {
            sigue[A].insert(B);
        }
        else if (T==2) {
            sigue[A].erase(B);
        }
        else if (T==3) {
            if (sigue[A].count(B) && sigue[B].count(A)) {
                cout<<"Yes"<<"\n";
            }
            else {
                cout<<"No"<<"\n";
            } 
        }
    }
    return 0;
}