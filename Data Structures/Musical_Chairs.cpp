#include <iostream>
#include <stack>
//Written by Andrew Huang 2018-06-21
using namespace std;

int main() {

  cin.sync_with_stdio(0);
  cin.tie(0);

  int numberOfChairs = 0, 
    numberOfEmpty = 0,
    index = 0;

  cin >> numberOfChairs >> numberOfEmpty;

  int chairs[ numberOfChairs ] = { 0 };
  int reference[ numberOfChairs ] = { 0 };

  for ( int i = 0; i < numberOfEmpty; i ++ ) {
    cin >> index;
    chairs[index - 1] = 1;
  }

  for ( int i = 0; i < numberOfEmpty + 1; i ++ ) {
    cin >> index;
    chairs[index - 1] += 2;
    reference[index - 1] = i + 1;
  }

  stack <int> st;
  index = 0;
  int numberSeated = 0;
  while ( numberSeated < numberOfEmpty ) {
    if ( chairs[ index % (numberOfChairs) ] == 1 ) {
      if ( !st.empty() ) {
        st.pop();
        chairs[ index % numberOfChairs ] = 0;
        numberSeated ++;
      } 
    } else if ( chairs[ index % (numberOfChairs) ] == 2 ) {
      st.push( index % (numberOfChairs) );
      chairs[ index % numberOfChairs ] = 0;
    } else if ( chairs[ index % (numberOfChairs) ] == 3 ) {
      chairs[ index % (numberOfChairs) ] = 0;
      numberSeated ++;
    }

    index ++;
  }

  int top = st.top();

  cout << reference[top];

}
