#include<iostream>
using namespace std;
bool isSafe(int board[][100],int i , int j,int n )
{
  for(int r=0;r<i;r++)
  {
      if(board[r][j])
      {
          return false;
      }
  }
  // now check for upper right diagonal
  int x = i,y=j;
  while(i>=0 and j<n)
  {
      if(board[i][j])
      {
          return false;
      }
      i--;
      j++;
  }
  // now check for upper left diagonal
  while(x>=0 and y>=0)
  {
      if(board[x][y])
      {
          return false;
      }
      x--;
      y--;
  }
  return true;

}

bool NQueen(int board[][100],int i , int n)
{
    // base case
    if(i==n)
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                board[i][j] == 1 ? cout<<"Q": cout<<"-";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
   }

    // recursive case
    for(int j = 0;j<n;j++)
    {
        if(isSafe(board,i,j,n))
        {
            // if safe hai tou queen rakhdo
            board[i][j] =1;
            bool kyaBaakiPlacehui = NQueen(board,i+1,n);
            if(kyaBaakiPlacehui == true)
            {
                return true;
            }
            // agar baaki queens place nhi hoti tou current queen galat hai
            board[i][j] = 0; // backtracking

        }
    }
    return false;
}
int main ()
{
    int board[100][100] = {0};
    int n = 5;
    NQueen(board , 0, n);
    return 0;
}
