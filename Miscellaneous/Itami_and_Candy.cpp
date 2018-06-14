#include <iostream>
//Written by Andrew Huang 2018-06-14
using namespace std;

int main() {

  int numberOfCandies = 0,
    favNumber = 0,
    numberOfWays = 0,
    maxMultiplier = 0;
  cin >> numberOfCandies >> favNumber;
  
  int count[numberOfCandies + 1] = { 0 };
  
  if ( numberOfCandies > 1 ) {
    for ( int i = 2; i <= numberOfCandies; i ++ ) {
      if ( count[i] == 0 ) {

        maxMultiplier = ((numberOfCandies - i) / favNumber);
        if ( maxMultiplier*favNumber == numberOfCandies ) { 
          numberOfWays += (maxMultiplier - 1)*2;
          numberOfWays += 3;
        } else if ( maxMultiplier == 0 ) { 
            if ( numberOfCandies - i == 0 ) {
              numberOfWays ++;
            } else {
              numberOfWays += 2;
            }
        } else { 
          numberOfWays += (maxMultiplier)*2;
          if ( numberOfCandies - maxMultiplier*favNumber - i == 0 ) {
              numberOfWays ++;
          } else {
              numberOfWays += 2;
          }
        }
      } 
      for ( int j = 1; j <= numberOfCandies/i; j ++ ) {
        count[i*j] = 1;
      }
    } 
  }
  cout << numberOfWays;
}
