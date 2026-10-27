#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int i = 0;
    while (i < s.length() && (s[i] != '+') && (s[i] != '-') && (s[i] != '*') && (s[i] != '/')) {
        i++;
    }
    char op = s[i];
    int a = stoi(s.substr(0,i));
    int b = stoi(s.substr(i+1));
    switch (op) {
        case '+':
            cout<<a+b<<'\n';
            break;
        case '-':
            cout<<a-b<<'\n';
            break;
        case '*':
            cout<<a*b<<'\n';
            break;
        case '/':
            cout<<a/b<<'\n';
            break;
    }
    return 0;
}