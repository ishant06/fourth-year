#include<iostream>
using namespace std;
typedef long long ll;
void printFibonacciNumbers(int n){
    if(n>=0)cout<<0<<" ";
    if(n>=1)cout<<1<<" ";
    int prev2=0,prev1=1;
    for(int i=2;i<n;i++){
        int curr=prev2+prev1;
        prev2=prev1;
        prev1=curr;
        cout<<curr<<" ";
    }
    return;
}
int main(){
    int n;
    cout<<"Enter Number"<<endl;
    cin>>n;
    printFibonacciNumbers(n);
    return 0;

}
