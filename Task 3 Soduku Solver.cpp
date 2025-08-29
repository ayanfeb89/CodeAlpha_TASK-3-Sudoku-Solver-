#include<iostream>
using namespace std;
const int MAX=9;
void printboard(int board[MAX][MAX])
{
    for(int i=0;i<MAX;i++)
    {
       if(i%3==0 && i!=0)
       {
           cout<<endl;
           cout<<"------------------------------------";
           cout<<endl;
       }
        for(int j=0;j<MAX;j++)
        {
            if(j%3==0 && j!=0)
            {
                cout<<"| ";
            }
            if(board[i][j]==0)
            {
                cout<<"_  ";
            }
            else{
                cout<<board[i][j]<<"  ";
            }
        }
        cout<<endl;
    }
}
bool istrue(int board[MAX][MAX],int row,int col,int num)
{
    for(int i=0;i<MAX;i++)
    {
        if(board[row][i]==num)
        {
            return false;
        }
        if(board[i][col]==num)
        {
            return false;
        }
    }
    int initialrow=row-row%3;
    int initialcol=col-col%3;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[initialrow+i][initialcol+j]==num)
            {
                return false;
            }
        }
    }
    return true;
}
bool solved(int board[MAX][MAX])
{
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            if(board[i][j]==0)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int board[MAX][MAX]={
    {0, 9, 0, 6, 8, 0, 1, 0, 3},
    {1, 0, 3, 0, 2, 9, 0, 4, 0},
    {0, 4, 0, 3, 0, 5, 2, 0, 7},
    {9, 0, 1, 0, 4, 0, 5, 6, 0},
    {0, 6, 0, 1, 0, 3, 0, 7, 0},
    {7, 0, 4, 0, 5, 0, 9, 0, 1},
    {0, 7, 0, 4, 0, 8, 0, 1, 9},
    {4, 0, 9, 0, 7, 0, 6, 0, 3},
    {0, 1, 0, 9, 0, 2, 0, 8, 0}
};
   cout<<"Welcome to a SUDOKU GAME"<<endl<<"\tLET'S PLAY\t"<<endl;
   printboard(board);
   int play;
   do{
   while(true)
   {
       int r,c,n;
       cout<<"Enter row(1-9) of number you want to change(---->For Exit type 0 here<----): ";
       cin>>r;
       cout<<"Enter column(1-9) of number you want to change(---->For Exit type 0 here<----): ";
       cin>>c;
       cout<<"Enter the replacement number(---->For Exit type 0 here<----): ";
       cin>>n;
       if(r==0 || c==0 || n==0)
       {
           break;
       }
       if(r<1 || r>MAX || c<1 || c>MAX || n<1 || n>MAX)
       {
           cout<<"Error: Invalid choice, you are exploiting Sudoku rules"<<endl;
           continue;
       }
         r--;
       c--;
       if(board[r][c]!=0)
       {
           cout<<"Error: Cell already Fill."<<endl;
           continue;
       }
       if(istrue(board,r,c,n))
       {
         board[r][c]=n;
         cout<<"Number placed Successfully"<<endl;
       }
       else{
        cout<<"Invalid Move"<<endl;
       }
       printboard(board);
       if(solved(board))
       {
           cout<<"You successfully solved the SUDOKU."<<endl;
           break;
       }
   }
   cout<<"Thank you for playing"<<endl;
   cout<<"Do you want to play again(Click 1 for YES and 0 for NO): ";
   cin>>play;
   if(play==1)
   {
       printboard(board);
   }
   }while(play!=0);
}
