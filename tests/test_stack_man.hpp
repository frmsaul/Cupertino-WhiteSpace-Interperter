#include <iostream>
#include <assert.h>

#include "../src/instruction.hpp"
#include "../src/virtual_machine.hpp"

using std::cout;
using std::endl;

static bool test_1(){
  virtual_machine VM;
  VM.run_instruction(instruction(STACK_MAN, PUSH, 4));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 7));
  VM.print_stack();
  return true;
}
static bool test_2(){
  virtual_machine VM;
  for(int i = 0; i < 5; i++){
    VM.run_instruction(instruction(STACK_MAN, PUSH, i));
  }
  VM.run_instruction(instruction(STACK_MAN, DUP_TOP, 0));
  VM.print_stack();
  return true;
}
static bool test_3(){
  virtual_machine VM;
  for(int i = 0; i < 5; i++){
    VM.run_instruction(instruction(STACK_MAN, PUSH, i));
  }
  VM.run_instruction(instruction(STACK_MAN, DUP_NTH, 2));
  VM.print_stack();
  return true;
}
static bool test_4(){
  virtual_machine VM;
  for(int i = 0; i < 5; i++){
    VM.run_instruction(instruction(STACK_MAN, PUSH, i));
  }
  VM.run_instruction(instruction(STACK_MAN, SWOP_2_TOP, 0));
  VM.print_stack();
  return true;
}
static bool test_5(){
  virtual_machine VM;
  for(int i = 0; i < 5; i++){
    VM.run_instruction(instruction(STACK_MAN, PUSH, i));
  }
  VM.run_instruction(instruction(STACK_MAN, POP, 0));
  VM.print_stack();
  return true;
}
static bool test_6(){
  virtual_machine VM;
  for(int i = 0; i < 5; i++){
    VM.run_instruction(instruction(STACK_MAN, PUSH, i));
  }
  VM.run_instruction(instruction(STACK_MAN, POP_N, 2));
  VM.print_stack();
  return true;
}

void test_stack_man(){
  cout << "testing stack manipulations" << endl;
  if(test_1()){
    cout << "passed " << 1 << endl;
  } else{
    cout << "failed" << endl;
  }
  if(test_2()){
    cout << "passed " << 2 << endl;
  } else{
    cout << "failed" << endl;
  }
  if(test_3()){
    cout << "passed " << 3 << endl;
  } else{
    cout << "failed" << endl;
  }
  if(test_4()){
    cout << "passed " << 4 << endl;
  } else{
    cout << "failed" << endl;
  }
  if(test_5()){
    cout << "passed " << 5 << endl;
  } else{
    cout << "failed" << endl;
  }
  if(test_6()){
    cout << "passed " << 6 << endl;
  } else{
    cout << "failed" << endl;
  }
}
