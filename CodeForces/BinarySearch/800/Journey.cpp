#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x,a,b,c; cin>>x>>a>>b>>c;
    long long low = 0, high = 1e9, mid=0;
    
    auto check = [&](long long limit){
        long long sum = 0,days;
        if (limit%3 == 0) days = limit/3;
        else days = (limit/3) + 1;
        
        long long r = limit%3;
        if (r==0) sum+= (a*days + b*days + c*days); 
        
        else if (r==1) sum+= (a*days + b*(days-1)+ c*(days-1));
        
        else if (r==2) sum+= (a*days + b*days+ c*(days-1));
        
        if (sum < x) return false;       
        else return true; 
    };
    
    while (low<high) {
       mid = (low+high)/2;
       if (check(mid)) {
           high = mid; 
       }
       else {
           low = mid + 1;
       }  
    }
    cout<<low<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while(t--)  solve();
    return 0;
}