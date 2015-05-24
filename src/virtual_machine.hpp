#ifndef _H_WHITE_VIRTUAL_MACHINE
#define _H_WHITE_VIRTUAL_MACHINE

#include <map>
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
  map<int, int> HEAP;
  void heap_access_instruction(instruction I);
  void IO_instruction(instruction I);
};


#endif
