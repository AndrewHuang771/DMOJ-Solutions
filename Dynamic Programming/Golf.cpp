#include <iostream>
//Written by Andrew Huang 2018-06-10
using namespace std;

int takeSwing( int distance, int numberOfClubs, int possibleDistances[], int listOfClubs[], int moveCounter ) {
  bool madeNewDistance = false;
  if ( possibleDistances[distance - 1] == 1 ) {
    return moveCounter;
  }
  for ( int j = distance - 2; j >= 0; j -- ) { 
    if ( possibleDistances[j] == 1 ) {
      for ( int i = 0; i < numberOfClubs; i ++ ) {
        if ( j + listOfClubs[i] < distance && possibleDistances[ j + listOfClubs[i] ] != 1 ) {
          possibleDistances[ j + listOfClubs[i] ] = 1;
          madeNewDistance = true;
        }
      }
    }
  }
  if ( !madeNewDistance ) {
    return -1;
  }
  return takeSwing( distance, numberOfClubs, possibleDistances, listOfClubs, moveCounter + 1 );
}

int main() {
  int distance = 0,
  numberOfClubs = 0;
  cin >> distance;
  cin >> numberOfClubs;
  int listOfClubs[ numberOfClubs ];
  int possibleDistances[ distance ] = { 0 };
  for ( int i = 0; i < numberOfClubs; i ++ ) {
    cin >> listOfClubs[i];
    possibleDistances[ listOfClubs[i] - 1 ] = 1;
  }
  int turnsNeeded = takeSwing( distance, numberOfClubs, possibleDistances, listOfClubs, 1 );  
  if ( turnsNeeded == -1 )
    cout << "Roberta acknowledges defeat.";
  else
    cout << "Roberta wins in " << turnsNeeded << " strokes.";
}
