#include <vector>
#include <string>
using namespace std;

bool isValid(vector<string>& board,int x,int y){
    for(int i=0;i<x;i++){
        if(board[i][y]=='Q') return false;
    }
    for(int i=x-1,j=y-1;i>=0&&j>=0;i--,j--){
        if(board[i][j]=='Q') return false;
    }
    for(int i=x-1,j=y+1;i>=0&&j<board[0].size();i--,j++){
        if(board[i][j]=='Q') return false;
    }
    return true;
}
vector<vector<string>> res;
void backtrace(vector<string>& board,int row){
    if(row==board.size()){
        res.push_back(board);
        return;
    }
    for(int j=0;j<board[0].size();j++){
        if(isValid(board,row,j)){
            board[row][j] = 'Q';
            backtrace(board,row+1);
            board[row][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n){ 
    vector<string> board(n,string(n,'.'));
    backtrace(board,0);
    return res;
}

int main(){

}