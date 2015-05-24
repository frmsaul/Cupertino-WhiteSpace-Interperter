#ifndef _H_INSTRUCTION
#define _H_INSTRUCTION

using namespace std;

enum IMP_TYPE { 
  STACK_MAN,
  ARITHMETIC,
  HEAP_ACC,
  FLOW_CONT,
  IO
};
enum COMMAND {
  /*Stack Manipulation*/
  PUSH,
  DUP_TOP, 
  DUP_NTH,
  SWOP_2_TOP,
  POP,
  POP_N,
  /*Arithmetic operation*/
  ADD,
  SUBTRUCT,
  MULTIPLY,
  DIVIDE,
  MOD,
  /*HEAP Access*/
  STORE, 
  RETRIEVE,
  /*FLOW Control*/
  MARK_LABLE,
  CALL,
  JMP, 
  JMP_IF_0,
  JMP_IF_NEG,
  RETURN,
  END_PROGRAM,
  /*IO*/
  WRITE_CHAR,
  WRITE_NUM,
  READ_CHAR,
  READ_NUM
};


typedef struct instruction{
  instruction(IMP_TYPE instruc_type, COMMAND _com, int _data){
    type = instruc_type;
    com = _com;
    data = _data;
  }
  IMP_TYPE type;
  COMMAND com;
  int data;
} instruction;



#endif
