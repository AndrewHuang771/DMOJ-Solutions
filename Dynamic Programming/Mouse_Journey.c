#include "stdio.h"

/*
Written by Andrew Huang 2018-06-03
An easy way to think of this question is the maze as a tilted Pascal's Triangle.
*/

int main(void) {
  int rows=0,
    columns=0,
    numCats=0,
    catInfo=0;
    
  scanf( "%d %d", &rows, &columns );
  scanf( "%d",&numCats );
  
  int maze[rows][columns];
  int cats[numCats][2];
  
  if ( numCats > 0 ) {
    for ( i = 0; i < numCats; i ++) {
      for ( j = 0; j < 2; j ++) {
        scanf( "%d",&catInfo );
        cats[i][j] = catInfo-1;
      }
    }
  }
  
  for ( int X = 0; X < rows ; X ++) {
    for ( int Y = 0; Y < columns; Y ++ ) {
      if( X == 0 && Y == 0 ) {
        maze[X][Y] = 1;
      }
      else if ( X == 0 && Y != 0 ) {
        maze[X][Y] = maze[X][Y-1];
      }
      else if ( Y==0 && X!=0 ) {
        maze[X][Y] = maze[X-1][Y];
      }
      else {
        maze[X][Y] = maze[X-1][Y]+maze[X][Y-1];
      }
      
      for ( int a = 0; a < numCats; a ++) {
        if ( X == cats[a][0] && Y == cats[a][1] ){
          maze[X][Y] = 0;
        }
      }
    }
  }
  //This prints the number at the bottom of the maze, which like a Pascal's triangle, represents the number of routes leading to it.
  printf( "%d",maze[rows-1][columns-1] );
  return 0;
}
