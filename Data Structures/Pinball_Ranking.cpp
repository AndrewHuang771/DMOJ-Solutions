#include <iostream>
#include <algorithm>
//Written by Andrew Huang 2018-07-05
using namespace std;

void update( int bTree[], int value, int indx, int size ) {
  for ( ; indx <= size ; indx += ( indx & -indx ) ) {
    bTree[indx] += value;
  }
}

int getSum( int end, int bTree[] ) {
  int sum = 0;
  for ( ; end > 0; end -= (end & -end) ) {
    sum += bTree[end];
  }
  return sum;
}

void convert( unsigned long arr[], int n ) {

  int temp[n];
  for ( int i = 0; i < n; i ++ )
    temp[i] = arr[i];
  sort(temp, temp+n);

  for ( int i = 0; i < n; i ++ ) {
    arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1;
  }
}

int main() {

  cin.sync_with_stdio(0);
  cin.tie(0);

  int numberOfScores = 0,
   amountLessThan = 0;

  cin >> numberOfScores;

  long long rankingTotal = 0;
  unsigned long scoreBoard[ numberOfScores ] = { 0 };
  int bTree[ numberOfScores + 1 ] = { 0 };

  for ( int i = 0; i < numberOfScores; i ++ ) {
    cin >> scoreBoard[i];
  }

  convert( scoreBoard, numberOfScores );

  for ( int i = 0; i < numberOfScores; i ++ ) {
    update( bTree, 1, scoreBoard[i], numberOfScores );
  }

  for ( int i = numberOfScores - 1; i >= 0; i -- ) {
    amountLessThan = getSum( scoreBoard[i], bTree );
    rankingTotal += numberOfScores - amountLessThan - i + 1;
    update( bTree, -1, scoreBoard[i], numberOfScores );
  }

  double total = (double)rankingTotal / (double)numberOfScores; 

  printf("%.2f", total );

}
