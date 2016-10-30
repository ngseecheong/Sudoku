#include <iostream>
#include "sudoku.h"
#include <string.h>
#include <chrono>
using namespace std;

using  ns = chrono::microseconds;
using get_time = chrono::steady_clock;

static int BLOCK_SIZE=3; //3x3 block size. This code is only for nxn

int main(int argc,char** argv){

  int length=BLOCK_SIZE*BLOCK_SIZE;
  /*
   * TODO: Set non fixed sizes
  */
    
  int n = stoi(argv[1]);
  
  Sudoku gametest(n,BLOCK_SIZE);

  //gametest.print();
  //cout<<"====\n";
  auto start = get_time::now();
  bool solutionExists=gametest.solve();
  auto end = get_time::now();
  auto diff = end - start;
  //gametest.print();
  cout<<chrono::duration_cast<ns>(diff).count()<<"\n";
  return 0;
}
