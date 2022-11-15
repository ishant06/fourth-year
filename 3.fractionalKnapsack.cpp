#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Item{
    public:
    int value;
    int weight;
};

bool cmp(Item a,Item b){
    double r1=(double)a.value/(double)a.weight;
    double r2=(double)b.value/(double)b.weight;
    return r1>r2;
}

double fractionalKnapsack(vector<Item>items,int W){
    sort(items.begin(),items.end(),cmp);
    double mx=0;
    for(int i=0;i<items.size();i++){
        if(items[i].weight<=W){
            mx+=items[i].value;
            W-=items[i].weight;
        }
        else{
            mx+=(items[i].value/(double)items[i].weight)*(double)W;
            break;
        }
    }
    return mx;
}
int main(){
    int n,W;
    cin>>n>>W;
    vector<Item>items(n);
    for(int i=0;i<n;i++){
        cin>>items[i].value;
        cin>>items[i].weight;
    }
    double maxValue=fractionalKnapsack(items,W);
    cout<<maxValue<<endl;
    return 0;
}
