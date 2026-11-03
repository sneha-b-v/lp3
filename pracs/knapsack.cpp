#include <iostream>
#include <vector>

using namespace std;

class knapsack{
    public:
    int n,m;
    vector<int> weights;
    vector<int> profits;
    vector<vector<int>>dp;

    knapsack(){
        n=0;
        m=0;
    }

    void getter(){
        cout<<"Enter number of items"<<endl;
        cin>>n;
        weights.push_back(-1);
        profits.push_back(-1);
        for(int i=1;i<=n;i++){
            int b;
            int c;
            cout<<"Enter weight of item "<< i<<" :"<<endl;
            cin>>b;
            weights.push_back(b);
            cout<<"Enter profit of item "<< i<<" :"<<endl;
            cin>>c;
            profits.push_back(c); 
        }

        cout<<"Enter capacity of knapsack"<<endl;
        cin>>m;
        vector<int> a;
        for(int j=0;j<=m;j++){
            a.push_back(0);
        }
        for(int i=0;i<=n;i++){
            dp.push_back(a);
        }
    }

    void solve(){
        for(int i=0;i<=n;i++){
            for(int w=0;w<=m;w++){
                if(i==0 || w==0){
                    dp[i][w]=0;
                }
                else if(weights[i]<=w){
                    dp[i][w]=max(profits[i]+dp[i-1][w-weights[i]], dp[i-1][w]);
                }
                else{
                    dp[i][w]=dp[i-1][w];
                }
            }
        }
    }

    int max_profit(){
        return dp[n][m];
    }

    vector<int> items(){
        vector<int> ans;
        int w=m;
        for(int i=n;i>0;i--){
            if(dp[i][w]!=dp[i-1][w]){
                ans.push_back(i);
                w=w-weights[i];
            }
        }
        return ans;
    }


};

int main(){
    knapsack k;
    k.getter();
    k.solve();
    cout<<k.max_profit()<<endl;
    vector<int> q=k.items();
    for(int i=0;i<q.size();i++){
        cout<<q[i]<<" ";
    }
    return 0;
}