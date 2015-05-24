#include <iostream>
#include "virtual_machine.hpp"

#include "../tests/test_stack_man.hpp"
#include "../tests/test_arthimetic.hpp"
#include "../tests/test_IO.hpp"
#include "../tests/test_heap.hpp"
#include "../tests/test_flow.hpp"

using namespace std;



int main(){
  cout << "White Space Interperter Testing" << endl;
  test_heap();
  //test_IO();
  //test_flow();
  //  test_stack_man();
  // test_arthimetic();
  return 0;
}
