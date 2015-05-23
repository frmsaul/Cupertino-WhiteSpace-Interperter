#include <iostream>
#include "virtual_machine.hpp"

using namespace std;

void test_stack(){
  virtual_machine VM();
  cout << "was able to build" << endl;
}


int main(){
  cout << "White Space Interperter Testing" << endl;
  test_stack();
  return 0;
}
