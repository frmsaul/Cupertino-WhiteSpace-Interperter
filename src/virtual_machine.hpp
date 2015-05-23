#ifndef _H_WHITE_VIRTUAL_MACHINE
#define _H_WHITE_VIRTUAL_MACHINE

#include "instruction.hpp"
#include "parser.hpp"
#include "virtual_stack.hpp"


class virtual_machine{
public:
  virtual_machine();
  void run_instruction(instruction I);
  void print_stack();
private:
  virtual_stack STACK;
};


#endif
