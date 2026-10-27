#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    
    int dif_min = v[1] - v[0];
    int c = 0;
    for (int i = 1; i < n; i++)
    {
        int dif = v[i] - v[i-1];
        if (dif_min > dif) {
            dif_min = dif;
            c = 1;
        }
        else if (dif_min == dif) {
            c++;
        }  
    }
    cout<<dif_min<<" "<<c;
    return 0;
}