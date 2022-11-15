#include<include>
using namespace std;
typedef long long ll;
int func(int n,vector<int>&dp){
    if(dp[n]!=-1)return dp[n];
    if(n==0 || n==1)return n;
    int num=func(n-1,dp)+func(n-2,dp);
    return dp[n]=num;
}
int main(){
    int n;
    cout<<"Enter Number"<<endl;
    cin>>n;
    vector<int>dp(n+1,-1);
    for(int i=0;i<n;i++){
        int num=func(i,dp);
        cout<<num<<" ";
    }
    return 0;
}
