#include <iostream>
#define SIZE 1025
using namespace std;

void update( int bTree[][SIZE], int indxX, int indxY, int value, int size ) {
  for ( int x = indxX; x <= size; x += ( x & -x ) ) {
	  for ( int y = indxY; y <= size; y += ( y & -y ) ) {
		  bTree[ x ][ y ] += value;
    }
  } 
}

int getSum( int bTree[][SIZE], int indxX, int indxY ) {
  int sum = 0;
  for ( int x = indxX; x > 0 ; x -= ( x & -x ) ) {
    for ( int y = indxY; y > 0; y -= ( y & -y ) ) {
      sum += bTree[x][y];
    }
  }
  return sum;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  int command = -1;
  int size = 0;
  int bTree[ SIZE ][ SIZE ] = { 0 };
  int indxX, indxY;
  int value, largest, offset;
  int leftSide, rightSide;
  int x1, x2, y1, y2;
  int result = 0;
  
  while ( command != 3 ) {
    cin >> command;

    if ( command == 0 ) {
      cin >> size;
    } else if ( command == 1 ) {
      cin >> indxX >> indxY >> value;
      update( bTree, indxX + 1, indxY + 1, value, size );
    } else if ( command == 2 ) {
      cin >> x1 >> y1 >> x2 >> y2;
      largest = getSum( bTree, x2 + 1 , y2 + 1 );
      offset = getSum( bTree, x1, y1 );
      rightSide = getSum( bTree, x1, y2 + 1 );
      leftSide = getSum( bTree, x2 + 1, y1 );
      result = largest + offset - rightSide - leftSide;
      cout << result << "\n";
    }
  }
}
