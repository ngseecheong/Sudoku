#include<iostream>
#include<time.h>
#include<random>
#include "sudoku.h"
using namespace std;

Sudoku::Sudoku(int** board,int blocksize){
	this->board=board;
	this->blocksize=blocksize;
	this->length=blocksize*blocksize;
}

Sudoku::Sudoku(int num,int blocksize){
    this->length=blocksize*blocksize;
    this->blocksize=blocksize;
    this->board=new int*[this->length];
    for(int i=0;i<this->length;i++){
      this->board[i]=new int[this->length];
    }

    random_device rd;
    default_random_engine re(rd());
    uniform_int_distribution<int> number_range(0,8);
    
    int count=0;
    while(count<=num){
      int row = number_range(re);
      int col = number_range(re);
      int n = number_range(re) + 1;

      if(validMove(n,row,col)){
	   board[row][col]=n;
	   count++;
      }
    }
  }

/*
* TODO: 
* Destructor
*/

void Sudoku::print(){
	for(int i=0;i<length;i++){
		for(int j=0;j<length;j++){
			if(j)
				cout<<' '<<board[i][j];
			else
				cout<<board[i][j];
		}
		cout<<"\n";
	}
}

bool Sudoku::validMove(int num,int row,int col){

	//Check across row
	for(int i=0;i<length;i++){
		if(num==board[row][i])
			return false;
	}

	//Check down column
	for(int i=0;i<length;i++){
		if(num==board[i][col])
			return false;
	}

	//Check in block
	//Calculate block positions
	int row_min=(row/blocksize)*blocksize; //Integer division does truncation/floor
	int col_min=(col/blocksize)*blocksize;
	int row_max=row_min+blocksize;
	int col_max=col_min+blocksize;

	for(int i=row_min;i<row_max;i++){
		for(int j=col_min;j<col_max;j++){
			if(num==board[i][j])
				return false;
		}
	}

	//All checks passed validPosition

	return true;
}

//Start row and col
bool Sudoku::solve(){
	//this->print();
	int row,col;
	int* temp=openPosition();
	if(temp!=NULL){
		row=temp[0];
		col=temp[1];
	}else{
		return true;
	}

	//cout<<row<<" "<<col<<"\n";
	for(int i=1;i<=length;i++){
		if(validMove(i,row,col)){
			board[row][col]=i;
			if(solve())
				return true;
			board[row][col]=0;
		}
	}

	return false;
}

int* Sudoku::openPosition(){
	int* temp = new int[2];
	for(int i=0;i<length;i++){
		for(int j=0;j<length;j++){
			if(board[i][j]==0){
				temp[0]=i;
				temp[1]=j;
				return temp;
			}
		}
	}
	return NULL;
}
