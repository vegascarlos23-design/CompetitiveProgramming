#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,A,B; cin>>n>>A>>B;
    vector<int> v(n);
    int num1; cin>>num1;
    int sum = num1;
    for (int i = 0; i < n-1; i++) {
        cin>>v[i];
        sum += v[i];
    }
    sort(v.rbegin(),v.rend());
    
    int c = 0;
    
    for (int i = 0; i < n; i++) {
        if ((A*num1)/(sum) >= B) {
        cout<<c;
        return 0;
        }
        c++;
        sum -= v[i];
    }
    return 0;
}