#include <iostream>
//Made by Andrew Huang 2018-06-13
using namespace std;

int box( int sumArray[], int limit, int size ) {

  int runningTotal = 0,
    lowerBound = 0,
    upperBound = 0,
    max = 0;

  runningTotal = sumArray[ lowerBound ];

  while( lowerBound < size ) {
    //Subset of length 1 that fails
    if ( runningTotal > limit && lowerBound == upperBound ) {
      lowerBound ++;
      if ( upperBound + 1 < size ) {
        upperBound ++;
        runningTotal = sumArray[lowerBound];
      }
    //Subset of length > 1 that fails
    } else if ( runningTotal > limit ) {
      runningTotal -= sumArray[lowerBound];
      lowerBound ++;
    //Any subset that passes
    } else {
      if ( upperBound + 1 == size ) {
        //Might as well return max because max isn't getting any bigger once upperBound hits the end.
        return max + 1;
      } else {
        upperBound ++;
        runningTotal += sumArray[upperBound];
      }
    }
    //Update max if applicable
    if ( upperBound - lowerBound > max && runningTotal <= limit ) {
      max = upperBound - lowerBound;
    }
   
  }
  if ( max == 0 )
    return 0;
  else 
    return max + 1;
}

int main() {
  int numberOfCups = 0,
    numberOfFillings = 0;

  cin >> numberOfCups >> numberOfFillings;

  int diffArray[ numberOfCups ] = { 0 };
  int startInd = 0,
    endInd = 0,
    value = 0;

  for ( int i = 0; i < numberOfFillings; i ++ ) {
    cin >> startInd >> endInd >> value; 
    diffArray[ startInd - 1 ] += value;
    if ( endInd < numberOfCups )
      diffArray[ endInd ] -= value;
  }

  for ( int j = 1; j < numberOfCups; j ++ ) {
    diffArray[j] = diffArray[j] + diffArray[j-1];
  }

  int limit = 0;
  cin >> limit;

  int number = box( diffArray, limit, numberOfCups );
  cout << number;
}
