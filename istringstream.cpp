#include <bits/stdc++.h>
using namespace std;

int main () {
    istringstream ss;//input string stream
    string str,u;//str stores the tokenized parts of string
    //u has been taken as input
    int t;
    //t is no of test cases
    ss.clear();//clears the buffer
    getline(cin,u);//takes the input
    ss.str(u);
    ss>>t;
    while (t--) {
        ss.clear();
        getline(cin,u);
        ss.str(u);
        while(ss>>str)cout<<str<<" ";cout<<endl;
    }

}
