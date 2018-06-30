#include <iostream>
//Written by Andrew Huang 2018-06-30
using namespace std;

long long getSum( int end, long long bTree[] ) {
  long long sum = 0;
  for ( ; end > 0; end -= (end & -end) ) {
    sum += bTree[end];
  }
  return sum;
}

void update( int idx, int val, long long bTree[], int numEle ) {
  for ( ; idx < numEle + 1; idx += (idx & -idx) ) {
    bTree[idx] += val;
  }
}

int main() {

  cin.sync_with_stdio(0);
  cin.tie(0);

  int numOfEle = 0,
    numOfQueries = 0,
    left = 0,
    right = 0,
    index = 0,
    value = 0;
  
  long long result = 0,
    result1 = 0;

  char type = 'a';

  cin >> numOfEle >> numOfQueries;

  int list[ numOfEle ] = { 0 };
  long long bTree[ numOfEle + 1 ] = { 0 };
  long long sumTree[ 100001 ] = { 0 };

  for ( int i = 0; i < numOfEle; i ++ ) {
    cin >> list[i];
    bTree[i + 1] = list[i];
    update( list[i], 1, sumTree, 100001 );
  }

  for ( int idx = 1; idx <= numOfEle; idx ++ ) {
    int idx2 = idx + ( idx & -idx );
    if ( idx2 <= numOfEle )
      bTree[idx2] += bTree[idx];
  } 

  for ( int i = 0; i < numOfQueries; i ++ ) {
    cin >> type;

    if ( type == 'C' ) {
      cin >> index >> value;
      int oldValue = (getSum( index, bTree ) - getSum( index - 1, bTree));
      update( index, value - oldValue, bTree, numOfEle );
      update( oldValue, -1, sumTree, 100001 );
      update( value, 1, sumTree, 100001 );
    } else if ( type == 'Q' ) {
      cin >> index;
      result = getSum( index, sumTree );
      cout << result << "\n";
    } else if ( type == 'S' ) {
      cin >> left >> right;
      result = getSum( right, bTree );
      result1 = getSum( left - 1, bTree );
      cout << result - result1 << "\n";
    }
  }
}
