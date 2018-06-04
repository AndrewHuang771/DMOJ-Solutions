#include <iostream>
#include <queue>

using namespace std;

struct coords {
  int x = -1;
  int y = -1;
};

class Graph {

  public:

  coords possibleMoves[8];
  int visited[8][8] = { 0 };
  coords currentNode;

  bool checkInBounds( int x, int y ) {
    return  x < 8 && x >= 0 && y < 8 && y >= 0;
  }

  int findEdges( int x, int y ) {
    int counter = 0;
    coords potentialMove;
    if ( checkInBounds( x - 1, y + 2) && visited[x-1][y+2] == 0 ) {
      potentialMove.x = x - 1;
      potentialMove.y = y + 2;
      possibleMoves[counter] = potentialMove; 
      counter ++;
    }
    if ( checkInBounds( x + 1, y + 2) && visited[x+1][y+2] == 0 ) {
      potentialMove.x = x + 1;
      potentialMove.y = y + 2;
      possibleMoves[counter] = potentialMove; 
      counter ++;
    }
    if ( checkInBounds( x - 2, y + 1) && visited[x-2][y+1] == 0 ) {
      potentialMove.x = x - 2;
      potentialMove.y = y + 1;
      possibleMoves[counter] = potentialMove; 
      counter ++;
    }
    if ( checkInBounds( x + 2, y + 1) && visited[x+2][y+1] == 0 ) {
      potentialMove.x = x + 2;
      potentialMove.y = y + 1;
      possibleMoves[counter] = potentialMove; 
      counter ++;
    }
    if ( checkInBounds( x + 2, y - 1) && visited[x+2][y-1] == 0 ) {
      potentialMove.x = x + 2;
      potentialMove.y = y - 1;
      possibleMoves[counter] = potentialMove; 
      counter ++;
    }
    if ( checkInBounds( x - 2, y - 1) && visited[x-2][y-1] == 0 ) {
      potentialMove.x = x - 2;
      potentialMove.y = y - 1;
      possibleMoves[counter] = potentialMove; 
      counter ++;
    }
    if ( checkInBounds( x + 1, y - 2) && visited[x+1][y-2] == 0 ) {
      potentialMove.x = x + 1;
      potentialMove.y = y - 2;
      possibleMoves[counter] = potentialMove; 
      counter ++;
    }
    if ( checkInBounds( x - 1, y - 2 ) && visited[x-1][y-2] == 0 ) {
      potentialMove.x = x - 1;
      potentialMove.y = y - 2;
      possibleMoves[counter] = potentialMove; 
      counter ++;
    }
    return counter;
  }

  int BFS( coords start, coords end ) {
    int numberOfMoves = 0;
    int moveCounter = 0;
    int depthDelay = 1;

    queue <coords> q;
    q.push( start ); 
    visited[start.x][start.y] = 1;

    while ( !q.empty() ) {

      currentNode = q.front();
      numberOfMoves = findEdges( currentNode.x, currentNode.y );
      q.pop();
      depthDelay --;

      for ( int i = 0; i < numberOfMoves; i ++ ) {

        if ( possibleMoves[i].x == end.x && possibleMoves[i].y == end.y ) {
            return moveCounter;
        }

        if ( visited[possibleMoves[i].x][possibleMoves[i].y] == 0 ) {  
          visited[possibleMoves[i].x][possibleMoves[i].y] = 1;
          q.push( possibleMoves[i] );
        }
      }
      
      if ( depthDelay == 0 ) {
        moveCounter ++;
        depthDelay = q.size();
      }

    }
    return -1;
  }
};

int main() {

  Graph chessBoard;
  int startX = 0,
    endX = 0,
    startY = 0,
    endY = 0;

  cin >> startX >> startY;
  cin >> endX >> endY;

  coords start, end;
  start.x = 8 - startY;
  start.y = startX - 1;
  end.x = 8 - endY;
  end.y = endX - 1;

  int numberOfMoves = chessBoard.BFS( start, end );
  cout << numberOfMoves + 1;

}
