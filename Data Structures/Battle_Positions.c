#include "stdio.h"
#include "stdlib.h"

/*
Andrew Huang
Completed 2018-04-04
Dmoj: Battle Positions 

Method: Difference Array and Sum Array

*/

int main(void) {
  
  int numberOfPositions, requiredNumber, numberOfWaves;
  int i=0;
  
  scanf("%d",&numberOfPositions);
  scanf("%d",&requiredNumber);
  scanf("%d",&numberOfWaves);
  
  //Initializes an array size numberOfPositions-1 with 0's 
  //This is the difference array with one less memory location that number of Positions.
  int *positions=(int *)calloc(numberOfPositions-1,sizeof(int));
  
  //Differentiate first, 
  
  //O(numberOfWaves)
  for(i = 0 ; i < numberOfWaves ; i++){
    int numberOfTroops, firstPosition, lastPosition;
    
    scanf("%d%d%d",&firstPosition,&lastPosition,&numberOfTroops);
    
    positions[firstPosition-1] += numberOfTroops;
    
    //Overshoots at the end, but the end is not important.
    positions[lastPosition] -= numberOfTroops;
    
  }
  
  //Uncomment to see the difference array
  // for(i=0;i<numberOfPositions;i++){
  //   printf("%d ",positions[i]);
  // }
  
  
  //O(n)
  //Then integrate over the list to recover the original list.
  //In other words, use a variation of the prefix sum array
  
  //positionsFinal is an array containing the number of soldiers at each position 
  int positionsFinal[numberOfPositions-1], counter = 0;
  
  //Initializing the first space in the array that the rest of the spaces build on
  positionsFinal[0] = positions[0];
  
  if(positions[0] < requiredNumber){
    counter++;
  }
  
  for(i = 1 ; i < numberOfPositions ; i++){
    positionsFinal[i] = positionsFinal[i-1] + positions[i];
    if(positionsFinal[i] < requiredNumber){
      counter++;
    }
  }
  
  // printf("\n");
  
  //Uncomment to see the sum array
  // for(i=0;i<numberOfPositions;i++){
  //   printf("%d ",positionsFinal[i]);
  // }
  
  printf("%d",counter);
  return 0;
}
