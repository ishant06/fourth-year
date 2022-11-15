#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int func(int i,int j,vector<int> &val,vector<int> &wt,vector<vector<int>> &dp){
    if(i==0){
        if(wt[i]<=j)return val[i];
        else return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int notTake=func(i-1,j,val,wt,dp);
    int take=0;
    if(wt[i]<=j){
        take=val[i]+func(i-1,j-wt[i],val,wt,dp);
    }
    return dp[i][j]=max(take,notTake);
}
int knapsack(int n,vector<int>&val,vector<int>&wt,int W){
    vector<vector<int>>dp(n,vector<int>(W+1,-1));
    int ans=func(n-1,W,val,wt,dp);   
    
    return ans;
}

// int knapsack(int n,vector<int>&val,vector<int>&wt,int W){
// iterative approach
// can be space optimized
//     vector<vector<int>>dp(n,vector<int>(W+1,0));
//     for(int j=wt[0];j<=W;j++)dp[0][j]=val[0];
//     for(int i=1;i<n;i++){
//         for(int j=0;j<=W;j++){
//             int notTake=dp[i-1][j];
//             int take=0;
//             if(wt[i]<=j){
//                 take=val[i]+dp[i-1][j-wt[i]];
//             }
//             dp[i][j]=max(take,notTake);
//         }
//     }
//     return dp[n-1][W];
// }
int main(){
    int n,W;
    cin>>n>>W;
    vector<int>val(n),wt(n);
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    int maxValue=knapsack(n,val,wt,W);
    cout<<maxValue<<endl;
    return 0;
}
