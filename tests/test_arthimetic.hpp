#include <iostream>
#include <assert.h>

#include "../src/instruction.hpp"
#include "../src/virtual_machine.hpp"

using std::cout;
using std::endl;

static bool test_arthimetic_1(){
  virtual_machine VM;
  VM.run_instruction(instruction(STACK_MAN, PUSH, 4));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 7));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 1));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 2));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 10));
  VM.run_instruction(instruction(ARITHMETIC, ADD, 0));
  VM.print_stack();
  return true;
}
static bool test_arthimetic_2(){
  virtual_machine VM;
  VM.run_instruction(instruction(STACK_MAN, PUSH, 4));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 7));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 1));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 2));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 10));
  VM.run_instruction(instruction(ARITHMETIC, SUBTRUCT, 0));
  VM.print_stack();
  return true;
}
static bool test_arthimetic_3(){
  virtual_machine VM;
  VM.run_instruction(instruction(STACK_MAN, PUSH, 4));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 7));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 1));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 2));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 3));
  VM.run_instruction(instruction(ARITHMETIC, MULTIPLY, 0));
  VM.print_stack();
  return true;
}
static bool test_arthimetic_4(){
  virtual_machine VM;
  VM.run_instruction(instruction(STACK_MAN, PUSH, 4));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 7));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 1));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 2));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 64));
  VM.run_instruction(instruction(ARITHMETIC, DIVIDE, 0));
  VM.print_stack();
  return true;
}
static bool test_arthimetic_5(){
  virtual_machine VM;
  VM.run_instruction(instruction(STACK_MAN, PUSH, 4));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 7));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 1));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 7));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 25));
  VM.run_instruction(instruction(ARITHMETIC, MOD, 0));
  VM.print_stack();
  return true;
}

void test_arthimetic(){
  cout << "test_arthimeticing arthimetic" << endl;
  if(test_arthimetic_1()){
    cout << "passed " << 1 << endl;
  } else{
    cout << "failed" << endl;
  }
  if(test_arthimetic_2()){
    cout << "passed " << 2 << endl;
  } else{
    cout << "failed" << endl;
  }
  if(test_arthimetic_3()){
    cout << "passed " << 3 << endl;
  } else{
    cout << "failed" << endl;
  }
  if(test_arthimetic_4()){
    cout << "passed " << 4 << endl;
  } else{
    cout << "failed" << endl;
  }
  if(test_arthimetic_5()){
    cout << "passed " << 5 << endl;
  } else{
    cout << "failed" << endl;
  }
}
