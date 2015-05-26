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
  instruction(){}
  string get_type(){
    switch(type){
    case STACK_MAN:
      return "STACK_MAN";
    case ARITHMETIC:
      return "ARITHMETIC";
    case HEAP_ACC:
      return "HEAP_ACC";
    case FLOW_CONT:
      return "FLOW_CONT";
    case IO:
      return "IO";
    }
  }
  string get_command(){
    switch(com){
    case PUSH:
      return "PUSH";
    case DUP_TOP:
      return "DUP_TOP";
    case DUP_NTH:
      return "DUP_NTH";
    case SWOP_2_TOP:
      return "STOP_2_TOP";
    case POP:
      return "POP";
    case POP_N:
      return "POP_N";
      /////
    case ADD:
      return "ADD";
    case SUBTRUCT:
      return "SUBTRUCT";
    case MULTIPLY:
      return "MULTIPLY";
    case DIVIDE:
      return "DIVIDE";
    case MOD:
      return "MOD";
      //
    case STORE:
      return "STORE";
    case RETRIEVE:
      return "RETRIEVE";
      //
    case JMP:
      return "JMP";
    case JMP_IF_0:
      return "JMP_IF_0";
    case JMP_IF_NEG:
      return "JMP_IF_NEG";
    case CALL:
      return "CALL";
    case MARK_LABLE:
      return "MARK_LABLE";
    case RETURN:
      return "RETURN";
    case END_PROGRAM:
      return "END_PROGRAM";
      ///
    case WRITE_CHAR:
      return "WRITE_CHAR";
    case WRITE_NUM:
      return "WRITE_NUM";
    case READ_CHAR:
      return "READ_CHAR";
    case READ_NUM:
      return "READ_NUM";
    }
  }
  void print(){
    string type = get_type();
    string command = get_command();
    cout << "type: " << type << " command: " << command << " data: "
	 << data << endl;
  }
  IMP_TYPE type;
  COMMAND com;
  int data;
} instruction;



#endif
