#include<bits/stdc++.h>
using namespace std;

void caso1(int& num, int& k){
    for (int i = 0; i < num; i++) {
        cout<<i<<" ";
    }
    cout<<endl;
}
void caso2(int& num, int& k){
    for (int i = 0; i < num; i++) {
        if (i != k) {
            cout<<i<<" ";
        }
    }
    cout<<k<<endl;
}

int main(){
    int n; cin>>n;
    while (n--) {
        int num; cin>>num;
        int k; cin>>k;
        if (num == k) {
            caso1(num,k);
        }
        else {
            caso2(num,k);
        }
    }
    return 0;
}