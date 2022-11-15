#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isValid(int row,int col,vector<vector<char>>&board,int n){
    
    int dup_row=row;
    int dup_col=col;
    while(col>=0 && row>=0){
        if(board[row][col]=='Q')return false;
        row--;
        col--;
    }
    row=dup_row;
    col=dup_col;
    while(col>=0){
        if(board[row][col]=='Q')return false;
        col--;
    }
    col=dup_col;
    while(row<n && col>=0){
        if(board[row][col]=='Q')return false;
        row++;
        col--;
    }
    return true;
}
bool placeQueen(int col,vector<vector<char>>&board,int n){
    if(col==n)return true;
    for(int i=0;i<n;i++){
        if(isValid(i,col,board,n)){
            board[i][col]='Q';
            bool check=placeQueen(col+1,board,n);
            if(check==true)return true;
            board[i][col]='.';
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<vector<char>>board(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]='.';
        }
    }
    placeQueen(0,board,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
