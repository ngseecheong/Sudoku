#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku{
  int** board;
  int blocksize;
  int length;
  bool diagonals=false;
  
public:
  
  Sudoku(int num,int blocksize);
  Sudoku(int** board,int blocksize);

  /*
   * TODO: 
   * Destructor
   */

  void print();
  bool validMove(int num,int row,int col);
  bool solve();
  int* openPosition();
};

#endif
