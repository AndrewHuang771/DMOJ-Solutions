#include <iostream>
//Written by Andrew Huang 2018-06-15
using namespace std;

int main() {
  int numberOfCases = 0,
    start = 0,
    counter = 0,
    end = 0;

  cin >> numberOfCases;

  for ( int i = 0; i < numberOfCases; i ++ ) {
    cin >> start >> end;
    counter = 0;
    int eras[ end ] = { 0 };
    bool reached = false;

    for ( int j = 2; j < end; j ++ ) {
      if ( eras[j] == 0 ) {
        if ( !reached && j >= start ) {
          reached = true;
        }
        if ( reached ) {
          counter ++;
        }
        for ( int k = 2; k <= end/j; k ++ ) {
          eras[j*k] = 1;
        }
      }
    }
    cout << counter << "\n";
  }

}
