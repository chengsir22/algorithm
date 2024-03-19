#include<vector>

using namespace std;

vector<vector<int>> res;
vector<int> path;

void backtrace(int start,int n,int k){
    if(path.size()==k){
        res.push_back(path);
        return;
    }
    for(int i=start;i<=n;i++){
        path.push_back(i);
        backtrace(i+1,n,k);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n,int k){
    backtrace(1,n,k);
    return res;
}