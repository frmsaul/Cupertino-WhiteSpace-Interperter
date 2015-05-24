#include <stack>
#include <iostream>
#include <assert.h>

#include "virtual_machine.hpp"
#include "instruction.hpp"
#include "parser.hpp"

using namespace std;


void virtual_machine::start(){
  while(!program_ptr_stack.empty()){
    instruction temp = program_memory[program_ptr_stack.top()];
    program_ptr_stack.top()++;
    //    cout << "program ptr: " << program_ptr_stack.top() << endl;
    run_instruction(temp);
  }
}

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
  case FLOW_CONT:
    FLOW_instruction(In);
    break;
  case IO:
    IO_instruction(In);
    break;
  default:
    break;
  }
}
void virtual_machine::FLOW_instruction(instruction In){
  switch(In.com){
  case MARK_LABLE:
    break;
  case CALL:
    program_ptr_stack.push(lables[In.data]);
    break;
  case JMP:
    program_ptr_stack.top() = lables[In.data];
    break;
  case JMP_IF_0:
    if(STACK.top() == 0){
      program_ptr_stack.top() = lables[In.data];
    }
    break;
  case JMP_IF_NEG:
    if(STACK.top() < 0){
      program_ptr_stack.top() = lables[In.data];
    }
    break;
  case RETURN:
    program_ptr_stack.pop();
    break;
  case END_PROGRAM:
    program_ptr_stack.pop();
    cout << "program has ended" << endl;
    break;
  default:
    cout << "not a valid flow control commend" << endl;
    break;
  }
}
void virtual_machine::heap_access_instruction(instruction In){
  switch(In.com){
  case STORE:
    {
    int address = STACK.top();
    STACK.pop();
    int value = STACK.top();
    STACK.pop();
    HEAP[address] = value;
    break;
    }
  case RETRIEVE:
    {
      if(HEAP.count(STACK.top()) > 0){
	int temp = HEAP[STACK.top()];
	STACK.pop();
	STACK.push(temp);
      }
      else{
	cout << STACK.top() << " isn't in the heap" << endl;
      }
    break;
    }
  default:
    cout << "not a valid heap access command" << endl;
  }
}
void virtual_machine::print_stack(){
  STACK.print_stack();
}
virtual_machine::virtual_machine(){ }
virtual_machine::virtual_machine(vector<instruction> machine_code){
  program_memory = machine_code;
  program_ptr_stack.push(0);
}
void virtual_machine::IO_instruction(instruction In){
  switch(In.com){
  case WRITE_CHAR:
    cout << (char)STACK.top() << endl;
    break;
  case WRITE_NUM:
    cout << STACK.top() << endl;
    break;
  case READ_CHAR:
    {
    char buffer;
    cin >> buffer;
    STACK.push(buffer);
    break;
    }
  case READ_NUM:
    {
    int buffer;
    cin >> buffer;
    STACK.push(buffer);
    break;
    }
  default:
    cout << "not a valid IO command" << endl;
  }
}
