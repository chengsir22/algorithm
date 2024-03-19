#include <iostream>
#include <vector>
using namespace std;

// 数组A中给定可以使用的1~9的数，返回由A数组中的元素组成的小于n的最大数。例如A={1, 2, 4, 9}，x=2533，返回2499

vector<int> choice={1, 2, 4, 9};
int num = 0,res=0;
int target=2533;

void backtrace(int num) {
    for(int i=0;i<choice.size();i++){
        if(num*10+choice[i]>target){
            return;
        }else{
            res = max(res,num*10+choice[i]);
            backtrace(num*10+choice[i]);
        }
    }
}

int main() {
    backtrace(0);
    cout<<res;
}