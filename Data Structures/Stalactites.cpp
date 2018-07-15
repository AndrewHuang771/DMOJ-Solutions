#include <iostream>
#define MAXSIZE 251
using namespace std;

//Written by Andrew huang 2018-07-14

void update( long long int bTree[][ MAXSIZE ][ MAXSIZE ], int indX, int indY, int indZ, long int value, int size ) {
  for ( int x = indX; x <= size; x += ( x & -x ) ) {
    for ( int y = indY; y <= size; y += ( y & -y ) ) {
      for ( int z = indZ; z <= size; z += ( z & -z ) ) {
        bTree[x][y][z] += value;
      }
    }
  }
}

long long getSum( long long int bTree[][ MAXSIZE ][ MAXSIZE ], int indX, int indY, int indZ, int size ) {
  long long sum = 0;
  for ( int x = indX; x > 0; x -= ( x & -x ) ) {
    for ( int y = indY; y > 0; y -= ( y & -y ) ) {
      for ( int z = indZ; z > 0; z -= ( z & -z ) ) {
        sum += bTree[x][y][z];
      }
    }
  }
  return sum;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  long long int bTree[ MAXSIZE ][ MAXSIZE ][ MAXSIZE ] = { 0 };

  int size = 0;
  int numberOfQueries = 0;
  char command = 'A';
  int indX = 0, indY = 0, indZ = 0;
  long int value = 0;
  int x1 = 0, x2 = 0, y1 = 0, y2 = 0, z1 = 0, z2 = 0;
  long long int red = 0, yellow = 0, orange = 0, purple = 0, green = 0, blue = 0, offset = 0, largest = 0, oldValue = 0, newValue = 0, result = 0;

  cin >> size;
  cin >> numberOfQueries;

  for ( int i = 0; i < numberOfQueries; i ++ ) {
    cin >> command;

    if ( command == 'C' ) {
      cin >> indX >> indY >> indZ >> value;
      offset = getSum( bTree, indX - 1, indY - 1, indZ - 1, size );
      largest = getSum( bTree, indX, indY, indZ, size );
      red = getSum( bTree, indX - 1, indY, indZ, size );
      green = getSum( bTree, indX, indY - 1, indZ, size );
      blue = getSum( bTree, indX, indY, indZ - 1, size );

      yellow = getSum( bTree, indX - 1, indY - 1, indZ, size ) - offset;
      orange = getSum( bTree, indX, indY - 1, indZ - 1, size ) - offset;
      purple = getSum ( bTree, indX - 1, indY, indZ - 1, size ) - offset;

      oldValue = largest - red - blue - green + offset*2 + yellow + orange + purple;
      newValue = value - oldValue;
      update( bTree, indX, indY, indZ, newValue, size );
    } else if ( command == 'S' ) {
      cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
      offset = getSum( bTree, x1 - 1, y1 - 1, z1 - 1, size );
      largest = getSum( bTree, x2, y2, z2, size );
      red = getSum( bTree, x1 - 1, y2, z2, size );
      green = getSum( bTree, x2, y1 - 1, z2, size );
      blue = getSum( bTree, x2, y2, z1 - 1, size );

      yellow = getSum( bTree, x1 - 1, y1 - 1, z2, size ) - offset;
      orange = getSum( bTree, x2, y1 - 1, z1 - 1, size ) - offset;
      purple = getSum ( bTree, x1 - 1, y2, z1 - 1, size ) - offset;

      result += (largest - red - blue - green + offset*2 + orange + purple + yellow);

    }
  }
  cout << result;
}
