#include <iostream>
#include "sudoku.h"
#include <string.h>

using namespace std;

static int BLOCK_SIZE=3; //3x3 block size. This code is only for nxn

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
  {3,0,6,5,0,8,4,0,0},
  {5,2,0,0,0,0,0,0,0},
  {0,8,7,0,0,0,0,3,1},
  {0,0,3,0,1,0,0,8,0},
  {9,0,0,8,6,3,0,0,5},
  {0,5,0,0,9,0,6,0,0},
  {1,3,0,0,0,0,2,5,0},
  {0,0,0,0,0,0,0,7,4},
  {0,0,5,2,0,6,3,0,0}
};

int main(int argc,char** argv){

  int length=BLOCK_SIZE*BLOCK_SIZE;
  /*
   * TODO: Set non fixed sizes
  */
    
  string line;
  
  char * c_line;
  char * token;

  int** temp=new int*[length]();
  for(int i=0;i<length;i++){
    temp[i]=new int[length]();
    getline(cin,line);
    c_line = strdup(line.c_str());
    token = strtok(c_line, " ");
    for(int j=0;j<length && token != NULL;j++){
        temp[i][j] = stoi(token);
        token = strtok(NULL, " ");
    }
  }
  
  Sudoku gametest(temp,BLOCK_SIZE);

  //gametest.print();
  //cout<<"====\n";
  if(gametest.solve())
    gametest.print();
  else
    cout<<"No solution\n";

  delete [] temp;
  return 0;
}
