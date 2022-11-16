#include<iostream>
#include<vector>
using namespace std;

    bool isValid(int i,int j,vector<vector<char>> &board,char ch){
        for(int k = 0;k<9;k++){
            
            // checking horizontally
            if(board[i][k]==ch)return false;
            // checking vertically
            if(board[k][j]==ch)return false;
            // checking sub matrix
            if(board[3*(i/3)+k/3][3*(j/3)+ (k%3)]==ch)return false;
            
            
        }
        return true;
    }

bool solve(vector<vector<char>> &board){

    for(int i =0;i<9;i++){
        for(int j = 0;j<9;j++){

            if(board[i][j] == '.'){

                for(char ch = '1';ch<='9';ch++){
                    if(isValid(i,j,board,ch)){
                        board[i][j] = ch;
                        if(solve(board)==true){
                            return true;
                        }
                        else{
                            board[i][j] = '.';
                        }
                        
                    }
                }
                return false;
            }
        }
    }
                return true;
}

int main(){

cout<<"Enter your Sudoku puzzle "<<endl;
vector<vector<char>> board(9,vector<char>(9));
for(int i = 0;i<9;i++){
    for(int j = 0;j<9;j++){
        cout<<"Enter "<<i+1<<" row "<<j+1<<" column ";
        cin>>board[i][j];
    }
}
cout<<endl<<"Your unsolved sudoku is : "<<endl;
for(int i = 0;i<9;i++ ){
    for(int j = 0;j<9;j++){
        cout<<board[i][j]<<"  ";
    }
    cout<<endl;
}

    solve(board);
cout<<endl<<"Your solved sudoku is : "<<endl;
for(int i = 0;i<9;i++){
    for(int j = 0;j<9;j++){
        cout<<board[i][j]<<"  ";
    }
    cout<<endl;
}

    return 0;
}
