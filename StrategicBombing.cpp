#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

//Written by Andrew Huang 2018-06-03

using namespace std;

class Graph {

  public:

  int edges[26][26] = { 0 };
  int counter = 0;
  int visited[26] = { 0 };
  int currentNode = 0;

  void addEdge( int start, int end ) {
    edges[start][end] = 1;
    edges[end][start] = 1;
  }

  //Always to be called after an addEdge to replace the edge lost before.
  bool removeNextEdge( int *row, int *col ) {
    int localCounter = 0;
    for( int i = 0; i < 26; i ++ ) {
      for( int j = 0; j < 26; j ++ ) {
        if ( edges[i][j] == 1 && localCounter < counter ) {
          localCounter ++;
        }
        else if ( edges[i][j] == 1 && localCounter == counter ) {
          edges[i][j] = 0;
          *row = i;
          *col = j;
          counter ++;
          return true;
        }
      }
    }
    return false;
  }

  bool BFS( int start, int end ) {
    queue <int> q;

    for ( int i = 0; i < 26; i ++) {
      visited[i] = 0;
    }

    q.push( start );
    visited[ start ] = 1;

    while ( !q.empty() ) {
      currentNode = q.front();
      q.pop();
      for ( int j = 0; j < 26; j ++ ) {
        if ( edges[currentNode][j] == 1 && !visited[j] ) {
          if ( j == end ) {
            return true;
          }
          visited[j] = 1;
          q.push( j );
        }
      }
    }
    return false;
  }
};

int main() {
  
  char start = 'Z';
  char end = 'Z';
  Graph roads;
  char firstPath = 'A';
  char endPath = 'A';

  while ( start != '*' && end != '*') {
    cin >> start >> end;
    roads.addEdge( start - 65, end - 65);
  }

  bool edgeWasRemoved = true;
  int row = 0,
   col = 0,
   counter = 0;

  while ( edgeWasRemoved ) {
    edgeWasRemoved = roads.removeNextEdge( &row, &col );
    if( !roads.BFS( 0, 1 ) ) {
      firstPath += row;
      endPath += col;
      cout << firstPath << endPath << endl;
      counter ++;
      firstPath = 'A';
      endPath = 'A';
    }
    roads.addEdge( row, col );
  }
  cout << "There are " << counter << " disconnecting roads.";
}
