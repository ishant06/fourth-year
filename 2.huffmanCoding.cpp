#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Node{
    public:
    char data;
    int freq;
    Node *left,*right;
    Node(char data,int freq){
        this->data=data;
        this->freq=freq;
        left=right=NULL;
    }
};

class cmp{
    public:
    bool operator()(Node* a,Node* b){
        return a->freq>b->freq;
    }
};

void printTree(Node *head,string str=""){
    if(head==NULL)return;
    if(head->left==NULL && head->right==NULL){
        cout<<head->data<<" -> "<<str<<endl;
        return;
    }
    printTree(head->left,str+"0");
    printTree(head->right,str+"1");
}

Node* buildTree(vector<char>&arr,vector<int>&frequency){
    priority_queue<Node*,vector<Node*>,cmp>pq;
    for(int i=0;i<arr.size();i++){
        pq.push(new Node(arr[i],frequency[i]));
    }
    while(pq.size()>1){
        Node *a=pq.top();
        pq.pop();
        Node *b=pq.top();
        pq.pop();
        Node *c=new Node('$',a->freq+b->freq);
        c->left=a;
        c->right=b;
        pq.push(c);
    }
    return pq.top();
}

int main(){
    int n;
    cin>>n;
    vector<char>arr(n);
    vector<int>frequency(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>frequency[i];
    }
    Node *head=buildTree(arr,frequency);
    printTree(head);
    return 0;
}
