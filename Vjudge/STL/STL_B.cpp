#include<bits/stdc++.h>
using namespace std;

bool func(vector<int>& v1,int n){
    for (int i = 1; i < n - 1; ++i) {
            if (v1[i - 1] < v1[i] && v1[i] > v1[i + 1]) {
                cout << "YES"<<endl;
                cout << i << " " << i + 1 << " " << i + 2 << endl;
                return false;
            }
        }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int> v1(n);
        for (int r = 0; r < n; r++) {
            cin>>v1[r];
        }       
        if (func(v1,n))
        {
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}