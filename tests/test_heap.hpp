#include <iostream>
#include <assert.h>

#include "../src/instruction.hpp"
#include "../src/virtual_machine.hpp"

using std::cout;
using std::endl;

static bool test_heap_1(){
  virtual_machine VM;
  VM.run_instruction(instruction(STACK_MAN, PUSH, 42));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 7)); //address
  VM.run_instruction(instruction(HEAP_ACC, STORE, 7));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 7)); //address
  VM.run_instruction(instruction(HEAP_ACC, RETRIEVE, 7));
  VM.print_stack();
  return true;
}
static bool test_heap_2(){
  virtual_machine VM;
  VM.run_instruction(instruction(STACK_MAN, PUSH, 42));
  VM.run_instruction(instruction(STACK_MAN, PUSH, 7)); //address
  VM.run_instruction(instruction(HEAP_ACC, STORE, 7));

  
  VM.run_instruction(instruction(STACK_MAN, PUSH, 7)); //address
  VM.run_instruction(instruction(STACK_MAN, PUSH, 8)); //address
  VM.run_instruction(instruction(HEAP_ACC, RETRIEVE, 7));
  VM.run_instruction(instruction(HEAP_ACC, RETRIEVE, 8));
  VM.print_stack();
  return true;
}
static bool test_heap_3(){
  return true;
}
static bool test_heap_4(){
  return true;
}
static bool test_heap_5(){
  return true;
}

void test_heap(){
  cout << "test_heaping heap" << endl;
  if(test_heap_1()){
    cout << "passed " << 1 << endl;
  } else{
    cout << "failed" << endl;
  }
  if(test_heap_2()){
    cout << "passed " << 2 << endl;
  } else{
    cout << "failed" << endl;
  }
  if(test_heap_3()){
    cout << "passed " << 3 << endl;
  } else{
    cout << "failed" << endl;
  }
  if(test_heap_4()){
    cout << "passed " << 4 << endl;
  } else{
    cout << "failed" << endl;
  }
  if(test_heap_5()){
    cout << "passed " << 5 << endl;
  } else{
    cout << "failed" << endl;
  }
}
