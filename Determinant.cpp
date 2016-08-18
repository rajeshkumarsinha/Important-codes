#include <bits/stdc++.h>
using namespace std;


/*
    Na duniya ka dar tha na rishto ke bandhan
    Badi khubsoorat thi wo zindagani
*/
int solve(vector<vector<double> >mat){
    int n=mat.size();
    if(n==1)    return mat[0][0];
    double ans=0;
    for(int i=0;i<n;i++){
        // except i th column
        vector<vector<double> >temp1;
        for(int j=1;j<n;j++){
            vector<double>temp2;
            for(int k=0;k<n;k++){
                if(k==i)continue;
                temp2.push_back(mat[j][k]);
            }
            temp1.push_back(temp2);
        }
        if(i&1)ans-=mat[0][i]*solve(temp1);
        else   ans+=mat[0][i]*solve(temp1);
    }
    return ans;
}



int main(){
    vector<vector<double> >mat;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<double>vec(n,0);
        mat.push_back(vec);
        for(int j=0;j<n;j++)cin>>mat[i][j];
    }
    cout<<solve(mat);
}
