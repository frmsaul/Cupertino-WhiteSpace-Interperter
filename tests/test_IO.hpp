#include <iostream>
#include <assert.h>

#include "../src/instruction.hpp"
#include "../src/virtual_machine.hpp"

using std::cout;
using std::endl;

static bool test_IO_1(){
  virtual_machine VM;
  VM.run_instruction(instruction(STACK_MAN, PUSH, 10));
  VM.run_instruction(instruction(IO, WRITE_NUM, 10));
  //VM.print_stack();
  return true;
}
static bool test_IO_2(){
  virtual_machine VM;
  VM.run_instruction(instruction(STACK_MAN, PUSH, 65));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 66));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 67));
  VM.run_instruction(instruction(IO, WRITE_CHAR, 10));
  VM.run_instruction(instruction(STACK_MAN, POP, 66));
  VM.run_instruction(instruction(IO, WRITE_CHAR, 10));
  VM.run_instruction(instruction(STACK_MAN, POP, 66));
  VM.run_instruction(instruction(IO, WRITE_CHAR, 10));
  //VM.print_stack();
  return true;
}
static bool test_IO_3(){
  virtual_machine VM;
  VM.run_instruction(instruction(IO, READ_CHAR, 10));
  VM.run_instruction(instruction(IO, WRITE_CHAR, 10));
  VM.run_instruction(instruction(IO, WRITE_CHAR, 10));
  return true;
}
static bool test_IO_4(){
  virtual_machine VM;
  VM.run_instruction(instruction(IO, READ_NUM, 10));
  VM.run_instruction(instruction(IO, WRITE_NUM, 10));
  VM.run_instruction(instruction(IO, WRITE_NUM, 10));
  return true;
}
void test_IO(){
  cout << "testing IO" << endl;
  if(test_IO_1()){
    cout << "passed " << 1 << endl;
  } else{
    cout << "failed" << endl;
  }
  if(test_IO_2()){
    cout << "passed " << 2 << endl;
  } else{
    cout << "failed" << endl;
  }
  if(test_IO_3()){
    cout << "passed " << 3 << endl;
  } else{
    cout << "failed" << endl;
  }
  if(test_IO_4()){
    cout << "passed " << 4 << endl;
  } else{
    cout << "failed" << endl;
  }
}
