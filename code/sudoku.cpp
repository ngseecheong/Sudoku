#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

static int BLOCK_SIZE=3; //3x3 block size, i.e 1...9

int test_game[9][9]={
  {5,0,0,0,1,0,0,0,4},
  {2,7,4,0,0,0,6,0,0},
  {0,8,0,9,0,4,0,0,0},
  {8,1,0,4,6,0,3,0,2},
  {0,0,2,0,3,0,1,0,0},
  {7,0,6,0,9,1,0,5,8},
  {0,0,0,5,0,3,0,1,0},
  {0,0,5,0,0,0,9,2,7},
  {1,0,0,0,2,0,0,0,3}
};

int test_game2[9][9] = {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}
};

class Sudoku{
  int** board;
  int size;
  int blockSize;

public:
  Sudoku(int num,int size,int blockSize){
    this->size=size;
    this->blockSize=blockSize;
    srand(time(NULL)); // use current time as seed for random generator
    board=new int*[size*blockSize];
    for(int i=0;i<size*blockSize;i++){
      board[i]=new int[size*blockSize];
    }

    int count=0;
    while(count<=num){
      int row = rand() % (size*blockSize);
      int col = rand() % (size*blockSize);
      int n = rand() % (size*blockSize+1);

      if(validMove(n,row,col)){
	board[row][col]=n;
	count++;
      }
    }
  }
  
  Sudoku(int** board,int size,int blockSize){
    this->board=board;
    this->size=size;
    this->blockSize=blockSize;
  }

  void print(){
    int n=size*blockSize;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	cout<<board[i][j]<<" ";
      }
      cout<<"\n";
    }
  }

  bool validMove(int num,int row,int col){
    int n=size*blockSize;
    if(row<0 || col<0 || row>=n || col>=n)
      return false;

    //Check across row
    for(int i=0;i<n;i++){
      if(num==board[row][i])
	return false;
    }

    //Check down column
    for(int i=0;i<n;i++){
      if(num==board[i][col])
	return false;
    }
    /*
    //Check diagonals
    if(row==col){
      for(int i=0;i<n;i++){
	if(num==board[i][i])
	  return false;
      }
    }
    if((row+col)==(n-1)){
      for(int i=0;i<n;i++){
	if(num==board[i][n-1-i])
	  return false;
      }
    }
    */
    //Check in block
    //Calculate block positions
    int row_min=(row/blockSize)*3;
    int col_min=(col/blockSize)*3;
    int row_max=row_min+2;
    int col_max=col_min+2;

    for(int i=row_min;i<=row_max;i++){
      for(int j=col_min;j<col_max;j++){
	if(num==board[i][j])
	  return false;
      }
    }

    //All checks passed validPosition

    return true;
  }

  //Start row and col
  bool solve(){
    //this->print();
    int n=size*blockSize;
    int row,col;
    int* temp=openPosition();
    if(temp!=NULL){
      row=temp[0];
      col=temp[1];
    }else{
      return true;
    }
    
    //cout<<row<<" "<<col<<"\n";
    for(int i=1;i<=n;i++){
      if(validMove(i,row,col)){
	board[row][col]=i;
	if(solve())
	  return true;
	board[row][col]=0;
      }
    }

    return false;
  }

  int* openPosition(){
    int n=size*blockSize;
    int* temp = new int[2];
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	if(board[i][j]==0){
	  temp[0]=i;
	  temp[1]=j;
	  return temp;
	}
      }
    }
    return NULL;
  }
};

int main(int argc,char** argv){
  int n = 3; //Number of rows and coloums nxn

  int** temp=new int*[9];
  for(int i=0;i<9;i++){
    temp[i]=new int[9];
    for(int j=0;j<9;j++){
      temp[i][j]=test_game2[i][j];
    }
  }
  
  Sudoku gametest(temp,3,3);

  gametest.print();
  cout<<"====\n";
  if(gametest.solve())
    gametest.print();
  else
    cout<<"No solution\n";
  return 0;
}
