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
  case ARITHMETIC:
    STACK.run_arth_instruction(In);
    break;
  case HEAP_ACC:
    heap_access_instruction(In);
    break;
  case IO:
    IO_instruction(In);
    break;
  default:
    break;
  }
}
void virtual_machine::heap_access_instruction(In){
  switch(In.com){
  case STORE:
    int address = STACK.top();
    STACK.pop();
    int value = STACK.top();
    STACK.pop();
    HEAP[address] = value;
    break;
  case RETRIEVE:
    int temp = HEAP[STACK.top()];
    STACK.pop();
    STACK.push(temp);
    break;
  default:
    cout << "not a valid heap access command" << endl;
  }
}
void virtual_machine::print_stack(){
  STACK.print_stack();
}
virtual_machine::virtual_machine(){ }
void virtual_machine::IO_instruction(In){
  switch(In.com){
  case WRITE_CHAR:
    cout << (char)STACK.top() << endl;
    break;
  case WRITE_NUM:
    cout << (char)STACK.top() << endl;
    break;
  case READ_CHAR:
    char buffer;
    cin >> buffer;
    STACK.push(buffer);
    break;
  case READ_NUM:
    int buffer;
    cin >> buffer;
    STACK.push(buffer);
    break;
  default:
    cout << "not a valid heap access command" << endl;
  }
}
