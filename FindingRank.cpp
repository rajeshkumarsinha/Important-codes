#include <bits/stdc++.h>
using namespace std;

int m,n;
vector<vector<int> >mat;
/*
3 3
10 20 10
-20 -30 10
30 50 0
*/

void solve(vector<vector<int> >&mat){
    int Rank=min(m,n);
    //  consider matrix as Rank * Rank
    for(int i=0;i<Rank;){

        if(mat[i][i]){
            for(int j=i+1;j<Rank;j++){
                // subtract
                // multiply jth row with mat[i][i]
                // multiply ith row with mat[j][i]
                int val=mat[j][i];
                for(int k=0;k<Rank;k++){
                    mat[j][k]=mat[j][k]*mat[i][i] - mat[i][k]*val;
                }
            }
            i++;
            continue;
        }
        if(mat[i][i]==0){
            int j=i+1;
            for(;j<Rank;j++){
                if(mat[j][i])break;
            }
            if(j!=Rank){
                swap(mat[i],mat[j]);
                continue;
            }
            // swap current column i and the last column Rank-1
            if(j==Rank){
                for(int j=0;j<Rank;j++){
                    swap(mat[j][i],mat[j][Rank-1]);
                }
                Rank--;
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)cout<<mat[i][j]<<" ";cout<<endl;
    }
    cout<<Rank<<endl;
}
int main(){
    cin>>m>>n;
    for(int i=0;i<m;i++){
        vector<int>vec(n,0);
        mat.push_back(vec);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)cin>>mat[i][j];
    }
    solve(mat);
}
