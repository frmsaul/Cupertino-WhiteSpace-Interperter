#include <iostream>
#include <string>
#include "parser.hpp"
#include "virtual_machine.hpp"

#include "../tests/test_stack_man.hpp"
#include "../tests/test_arthimetic.hpp"
#include "../tests/test_IO.hpp"
#include "../tests/test_heap.hpp"
#include "../tests/test_flow.hpp"

using namespace std;



int main(){
  cout << "White Space Interperter Testing" << endl;
  get_instruction_vector("..\\whitespace_code\\hello_world.hs");
  //get_bytes("..\\whitespace_code\\test1.ws");
  //test_heap();
  //test_IO();
  //  test_flow();
  //  test_stack_man();
  // test_arthimetic();
  return 0;
}
