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



int main(int argc, char *argv[]){
  if(argc < 2){
    cout << "you need to enter the whitespace file name" << endl;
    cout << "ex: whitespace [filename]" << endl;
    return 1;
  }
  //  cout << "White Space Interperter Testing" << endl;
  //  vector<instruction> Insts = 
  //  get_instruction_vector("..\\whitespace_code\\hello_world.hs");
  vector<instruction> Insts = 
    get_instruction_vector(argv[1]);
  virtual_machine VM(Insts);
  VM.start();
  return 0;
}
