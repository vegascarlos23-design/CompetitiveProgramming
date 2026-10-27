#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    map<int,int> m;
    vector<int> A(n);
    int c = 0;
    for (int i = 0; i < n; i++) {
        cin>>A[i];
        if (m.count(A[i])) {
            c++;
            m.erase(A[i]);
        }
        else {
            m[A[i]] = 1;
        }
    }
    cout << c;
    return 0;
}