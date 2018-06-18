#include <iostream>
#include <vector>
#include <algorithm>
//Written by Andrew Huang 2018-06-18
using namespace std;

int latchOn( int heights[], int number, int index, int total, int memo[] ) {
  int tempTotal = total;
  vector <int> totals;
  totals.push_back( total );
  for ( int i = index + 1; i < number; i ++ ) {
    if ( heights[i] > heights[index] ) {
      tempTotal = total + heights[i];
      if ( memo[i] == 0 ) {
        totals.push_back(latchOn( heights, number, i, tempTotal, memo ));
      } else {
        totals.push_back( memo[i] + total );
      }
    }
  }
  int maxTotal = *max_element(totals.begin(), totals.end());
  return maxTotal;
}

int main() {

  int number = 0;
  cin >> number;
  int heights[number] = { 0 };
  vector <int> total;
  int memo[number] = { 0 };

  for ( int i = 0; i < number; i ++ ) {
    cin >> heights[i];
  }

  for ( int i = number - 1; i >= 0; i -- ) {
    int localMax = latchOn( heights, number, i, heights[i], memo );
    total.push_back( localMax );
    memo[i] = localMax;
  }

  int maxTotal = 0;
  maxTotal = *max_element(total.begin(), total.end());  
  cout << maxTotal;
}
