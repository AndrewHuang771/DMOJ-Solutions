#include <iostream>
#include <cmath>
#include <queue>

//Written by Andrew Huang 2018-06-03

using namespace std;

class Beacon {

  public:

  int x = 0;
  int y = 0;
  int r = 0;
  bool visited = false;

  void establishPosition( int xCoord, int yCoord, int radius ) {
    x = xCoord;
    y = yCoord;
    r = radius;
    visited = false;
  }
};

float findDistance( int x1, int y1, int x2, int y2 ) {
  return abs( pow( (float)pow( x2 - x1, 2 ) + (float)pow( y2 - y1, 2), 0.5 ));
}

bool modifiedBFS( int startIndex, int endIndex, Beacon list[], int numberOfBeacons ) {

  int currentNode = 0;

  for( int i = 0; i < numberOfBeacons; i ++ ){
    list[i].visited = false;
  }

  queue <int> q;
  q.push( startIndex - 1 );
  list[ startIndex - 1].visited = true;

  while ( !q.empty() ) {
    currentNode = q.front();
    q.pop();
    
    for ( int i = 0; i < numberOfBeacons; i ++ ) {
      if ( !list[i].visited ) {
        float distance = findDistance( list[currentNode].x, list[currentNode].y, list[i].x, list[i].y );
        if ( distance <= list[currentNode].r ) {

          if ( i == endIndex - 1 )
            return true;

          q.push(i);
          list[i].visited = true;
        }
      }
    }
  }
  return false;
}

int main() {

  cin.sync_with_stdio(0);
  cin.tie(0);

  int numberOfBeacons = 0;
  int numberOfQueries = 0;

  cin >> numberOfBeacons >> numberOfQueries; 

  Beacon list[numberOfBeacons];

  for ( int i = 0; i < numberOfBeacons; i ++ ) {

    Beacon beacon;
    int xCoord = 0,
      yCoord = 0,
      radius = 0;

    cin >> xCoord >> yCoord >> radius;
    beacon.establishPosition( xCoord, yCoord, radius );
    list[i] = beacon;

  }

  for ( int i = 0; i < numberOfQueries; i ++ ){

    bool connected = true;
    int beaconIndexStart = 0,
      beaconIndexEnd = 0;

    cin >> beaconIndexStart >> beaconIndexEnd;
    connected = modifiedBFS( beaconIndexStart, beaconIndexEnd, list, numberOfBeacons );

    if (connected)
      cout << "YES\n";
    else 
      cout << "NO\n";
    
  }

  return 0;

}
