#include "stdio.h"

int main(void) {
  
  int numberOfTrees = 0,
    numberOfIntervals = 0,
    startingIndex = 0,
    endingIndex = 0,
    overallWeight = 0;
  
  scanf("%d",&numberOfTrees);
  
  int weights[numberOfTrees];
  for( int i = 0; i < numberOfTrees; i ++ ) {
    scanf( "%d", &weights[i] );
  }
  
  //Construct a prefix sum array with offset 0
  int sumOfWeightsUpTo[ numberOfTrees + 1 ];
  
  sumOfWeightsUpTo[0] = 0;
  
  for ( int j = 0; j < numberOfTrees; j ++) {
    sumOfWeightsUpTo[j+1] = sumOfWeightsUpTo[j] + weights[j];
  }
  
  scanf( "%d", &numberOfIntervals );
  
  for ( int g = 0; g < numberOfIntervals; g ++) {
    scanf( "%d%d", &startingIndex, &endingIndex );
    overallWeight = sumOfWeightsUpTo[ endingIndex+1 ] - sumOfWeightsUpTo[ startingIndex ];
    printf( "%d\n", overallWeight );
  }
  
  return 0;
}
