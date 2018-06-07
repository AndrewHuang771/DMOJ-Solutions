#include <iostream>
#include <queue>

using namespace std;

struct coords{
  int x = -1;
  int y = -1;
};

class Graph {

  public:

  int width = 0,
    height = 0;

  queue <coords> q;

  void declareSize( int w, int h ) {
    width = w;
    height = h;
  }

  bool inBounds( int x, int y ) {
    return x < height && x >= 0 && y < width && y >= 0;
  } 

  bool findEdge( coords currentLocation, char map[][50], int visited[][50] ) {
    coords potentialMove;
    
    if ( inBounds( currentLocation.x + 1, currentLocation.y ) && !visited[currentLocation.x + 1][currentLocation.y] && (map[currentLocation.x + 1][currentLocation.y] == 'O' || map[currentLocation.x + 1][currentLocation.y] == 'W')) {
      if ( map[currentLocation.x + 1][currentLocation.y] == 'W' ) {
        return true;
      }
      else {
        potentialMove.x = currentLocation.x + 1;
        potentialMove.y = currentLocation.y;
        q.push(potentialMove);
        visited[potentialMove.x][potentialMove.y] = 1;
      }
    }
    if ( inBounds( currentLocation.x - 1, currentLocation.y ) && !visited[currentLocation.x - 1][currentLocation.y] && (map[currentLocation.x - 1][currentLocation.y] == 'O' || map[currentLocation.x - 1][currentLocation.y] == 'W' )) {
      if ( map[currentLocation.x - 1][currentLocation.y] == 'W' ) {
        return true;
      }
      else {
        potentialMove.x = currentLocation.x - 1;
        potentialMove.y = currentLocation.y;
        q.push(potentialMove);
        visited[potentialMove.x][potentialMove.y] = 1;
      }
    }
    if ( inBounds( currentLocation.x, currentLocation.y + 1 ) && !visited[currentLocation.x][currentLocation.y + 1] && (map[currentLocation.x][currentLocation.y + 1] == 'O' || map[currentLocation.x][currentLocation.y + 1] == 'W' )) {
      if ( map[currentLocation.x][currentLocation.y + 1] == 'W' ) {
        return true;
      }
      else {
        potentialMove.x = currentLocation.x;
        potentialMove.y = currentLocation.y + 1;
        q.push(potentialMove);
        visited[potentialMove.x][potentialMove.y] = 1;
      }
    }
    if ( inBounds( currentLocation.x, currentLocation.y - 1 ) && !visited[currentLocation.x][currentLocation.y - 1] && (map[currentLocation.x][currentLocation.y - 1] == 'O' || map[currentLocation.x][currentLocation.y - 1] == 'W' ) ) {
      if ( map[currentLocation.x][currentLocation.y - 1] == 'W' ) {
        return true;
      }
      else {
        potentialMove.x = currentLocation.x;
        potentialMove.y = currentLocation.y - 1;
        q.push(potentialMove);
        visited[potentialMove.x][potentialMove.y] = 1;        
      }
    }
    return false;
  }

  int BFS( coords start, coords end, char map[][50] ) {

    coords currentNode;
    int visited[height][50] = { 0 };
    int counter = 0;
    int depthCounter = 1;
    bool foundWashroom;
    q.push( start );
    visited[ start.x ][ start.y ] = 1;

    while ( !q.empty() ) {
      currentNode = q.front();
      q.pop();
      depthCounter --;
      foundWashroom = findEdge( currentNode, map, visited );
      if ( foundWashroom || counter > 58 ) {
        return counter + 1;
      }
      if ( depthCounter == 0 ) {
        depthCounter = q.size();
        counter ++;
      }
    }
    return -1;
  }
};

int main() {

  int numberOfTests = 0,
    height = 0,
    width = 0;

  cin >> numberOfTests;

  for ( int i = 0; i < numberOfTests; i ++ ) {

    Graph path;
    cin >> width >> height;
    path.declareSize( width, height );
    char map[height][50];
    char input;
    coords start, end;

    for ( int j = 0; j < height; j ++ ) {
      for ( int k = 0; k < width; k ++ ) {
        cin >> input;
        map[j][k] = input;
        if ( input == 'W' ) {
          end.x = j;
          end.y = k;
        } else if ( input == 'C' ) {
          start.x = j;
          start.y = k;
        }
      }
    }

    int numberOfMoves = path.BFS( start, end, map );

    if ( numberOfMoves > 59 ) 
      cout << "#notworth" << endl;
    else if ( numberOfMoves == -1 )
      cout << "#notworth" << endl;
    else
      cout << numberOfMoves << endl;
  }
}
