#include <stack>
#include <iostream>

#include "virtual_machine.hpp"
#include "instruction.hpp"
#include "parser.hpp"

using namespace std;



void virtual_machine::run_instruction(instruction In){
  switch(In.type){
  case STACK_MAN:
    STACK.run_instruction(In);
    break;
  default:
  }
}
void virtual_machine::print_stack(){
  STACK.print_stack();
}
