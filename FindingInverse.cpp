#include <bits/stdc++.h>
using namespace std;

vector<vector<double> >mat;
int n;

void solve(){
    vector<vector<double> >inv;
    for(int i=0;i<n;i++){
        vector<double>vec(n,0);
        inv.push_back(vec);
        inv[i][i]=1;
    }
    for(int i=0;i<n;){
        if(mat[i][i]){
            for(int j=0;j<n;j++){
                if(j==i)continue;

                double val=mat[j][i];
                for(int k=0;k<n;k++){
                    inv[j][k]=inv[j][k]*mat[i][i]  -inv[i][k]*val;
                    mat[j][k]=mat[j][k]*mat[i][i]  -mat[i][k]*val;
                }
            }
            i++;continue;
        }

        if(mat[i][i]==0){
            int j=i+1;
            for(;j<n;j++){
                if(mat[j][i])break;
            }
            swap(mat[i],mat[j]);
            swap(inv[i],inv[j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            inv[i][j]/=mat[i][i];
            cout<<inv[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        vector<double>vec(n,0);
        mat.push_back(vec);
        for(int j=0;j<n;j++)cin>>mat[i][j];
    }

    solve();
}
