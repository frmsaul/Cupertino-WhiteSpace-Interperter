#ifndef _H_VIRTUAL_STACK
#define _H_VIRTUAL_STACK

#include <stack>
#include "instruction.hpp"

typedef struct virtual_stack{
  //  virtual_stack();
  void print_stack();
  void run_instruction(instruction I);
  void run_arth_instruction(instruction I);
  std::stack<int> STACK;
  
  /*Stack manipulation stuff*/
  void push(int);
  void dup_top();
  void dup_nth(int);
  void swop_2_top();
  void pop();
  void pop_n(int);
  /*Arthimetic stuff*/
  void add();
  void subtruct();
  void multiply();
  void divide();
  void mod();
} virtual_stack;


#endif 
