#include <iostream>
#include <vector>

using namespace std;

class NQueens{
public:
    vector<vector<char>> board;
    vector<vector<vector<char>>> answer;
    int n;

    void getn(){
        cout<<"enter n"<<endl;
        cin>>n;
        vector<char> a;
        for(int i=0;i<n;i++){
            a.push_back('.');
        }
        for(int i=0;i<n;i++){
            board.push_back(a);
        }
    }

    bool isSafe(vector<vector<char>> &board, int row, int col, int n){
        // check vertical
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        //check diag left
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row+1,j=col+1;i<n && j<n;i++,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        //check right diag
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row+1,j=col-1;i<n && j>=0;i++,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }

    void nqueens(vector<vector<char>> &board, int row, int urow, int n, vector<vector<vector<char>>> &ans){
        if(row==n){
            ans.push_back(board);
            return;
        }
        if(row==urow){
            nqueens(board,row+1,urow,n,ans);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(board,row,i,n)){
                board[row][i]='Q';
                nqueens(board,row+1,urow,n,ans);
                board[row][i]='.';
            }

        }
    }
    void solve(){
        int r,c;
        cout<<"enter r"<<endl;
        cin>>r;
        cout<<"enter c"<<endl;
        cin>>c;
        board[r][c]='Q';
        nqueens(board,0,r,n,answer);
    }

    
    void print_2d(vector<vector<char>> temp){
        for(int i=0;i<temp.size();i++){
            for(int j=0;j<temp[i].size();j++){
                cout<<temp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    
    void print(){
        for(int i=0;i<answer.size();i++){
            print_2d(answer[i]);
            cout<<"------------------------------"<<endl;
        }
    }

};

int main(){
    NQueens nq;
    nq.getn();
    nq.solve();
    nq.print();
    return 0;
}