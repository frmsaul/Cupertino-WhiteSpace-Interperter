#ifndef _H_INSTRUCTION
#define _H_INSTRUCTION

#include <bitset>
using namespace std;

enum IMP_TYPE { 
  STACK_MAN,
  ARITHMETIC,
  HEAP_ACC,
  FLOW_CONT,
  IO
};

typedef struct instruction instruction;
struct instruction{
  instruction(IMP_TYPE instruc_type, bitset _data){
    type = instruc_type;
    data = _data;
  }
  IMP_TYPE type = instruc_type;
  bitset data;
};



#endif
