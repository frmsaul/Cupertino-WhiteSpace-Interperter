#include <iostream>
#include <vector>
#include <assert.h>

#include "../src/instruction.hpp"
#include "../src/virtual_machine.hpp"

using std::cout;
using std::endl;
using std::vector;

static bool test_flow_1(){
  vector<instruction> program;
  program.push_back(
		    instruction(STACK_MAN, PUSH, 4)
		    );
  program.push_back(
		    instruction(STACK_MAN, PUSH, 6)
		    );
  program.push_back(
		    instruction(IO, WRITE_NUM, 6)
		    );
  program.push_back(
		    instruction(IO, WRITE_NUM, 6)
		    );
  program.push_back(
		    instruction(STACK_MAN, POP, 6)
		    );
  program.push_back(
		    instruction(IO, WRITE_NUM, 6)
		    );
  program.push_back(
		 instruction(FLOW_CONT, END_PROGRAM, 6)
		 );
  virtual_machine VM(program);
  VM.start();
  return true;
}
static bool test_flow_2(){
  vector<instruction> program;
  program.push_back(
		    instruction(STACK_MAN, PUSH, 72) //H
		    );
  program.push_back(
		    instruction(IO, WRITE_CHAR, 6)
		    );
  program.push_back(
		    instruction(STACK_MAN, POP, 6)
		    );
  program.push_back(
		    instruction(STACK_MAN, PUSH, 101) //e
		    );
  program.push_back(
		    instruction(IO, WRITE_CHAR, 6)
		    );
  program.push_back(
		    instruction(STACK_MAN, POP, 6)
		    );
  program.push_back(
		    instruction(STACK_MAN, PUSH, 108) //l
		    );
  program.push_back(
		    instruction(IO, WRITE_CHAR, 6)
		    );
  program.push_back(
		    instruction(STACK_MAN, POP, 6)
		    );
  program.push_back(
		    instruction(STACK_MAN, PUSH, 108) //l
		    );
  program.push_back(
		    instruction(IO, WRITE_CHAR, 6)
		    );
  program.push_back(
		    instruction(STACK_MAN, POP, 6)
		    );
  program.push_back(
		    instruction(STACK_MAN, PUSH, 111) //o
		    );
  program.push_back(
		    instruction(IO, WRITE_CHAR, 6)
		    );
  program.push_back(
		    instruction(STACK_MAN, POP, 6)
		    );
  program.push_back(
		    instruction(STACK_MAN, PUSH, 10) //new line
		    );
  program.push_back(
		    instruction(IO, WRITE_CHAR, 6)
		    );
  program.push_back(
		    instruction(STACK_MAN, POP, 6)
		    );
  program.push_back(
		 instruction(FLOW_CONT, END_PROGRAM, 6)
		 );
  virtual_machine VM(program);
  VM.start();
  return true;
}
static bool test_flow_3(){
  vector<instruction> program;
  program.push_back( //go to the begining of the program
		    instruction(FLOW_CONT, JMP, 2) 
		     );
  program.push_back( //declear function
		    instruction(FLOW_CONT, MARK_LABLE, 1) 
		    );
  program.push_back( //IO
		    instruction(IO, WRITE_CHAR, 6)
		     );
  program.push_back(
		    instruction(STACK_MAN, POP, 6)
		    );
  program.push_back(
		    instruction(FLOW_CONT,RETURN, 6)
		    );
  program.push_back( //begins program
		    instruction(FLOW_CONT, MARK_LABLE, 2) 
		     );
  program.push_back(
		    instruction(STACK_MAN, PUSH, 72)
		    );
  program.push_back( 
		    instruction(FLOW_CONT, CALL, 1) 
		     );
  program.push_back(
		    instruction(STACK_MAN, PUSH, 101)
		    );
  program.push_back( 
		    instruction(FLOW_CONT, CALL, 1) 
		     );
  program.push_back(
		    instruction(STACK_MAN, PUSH, 108)
		    );
  program.push_back( 
		    instruction(FLOW_CONT, CALL, 1) 
		     );
  program.push_back(
		    instruction(STACK_MAN, PUSH, 108)
		    );
  program.push_back( 
		    instruction(FLOW_CONT, CALL, 1) 
		     );
  program.push_back(
		    instruction(STACK_MAN, PUSH, 111)
		    );
  program.push_back( 
		    instruction(FLOW_CONT, CALL, 1) 
		     );
  program.push_back(
		    instruction(STACK_MAN, PUSH, 10) //new line
		    );
  program.push_back( 
		    instruction(FLOW_CONT, CALL, 1) 
		     );
  program.push_back( 
		    instruction(FLOW_CONT, END_PROGRAM, 1) 
		     );
  virtual_machine VM(program);
  VM.start();
  return true;
}
static bool test_flow_4(){
  vector<instruction> program;
  program.push_back( //initial number
		    instruction(STACK_MAN, PUSH, 10) 
		     );
  program.push_back( //begining of loop
		    instruction(FLOW_CONT, MARK_LABLE, 1) 
		     );
  program.push_back( //begining of loop
		    instruction(IO, WRITE_NUM, 1) 
		     );
  program.push_back( //step size
		    instruction(STACK_MAN, PUSH, -1) 
		     );
  program.push_back( //do step
		    instruction(ARITHMETIC, ADD, -1) 
		     );
  program.push_back( //break if reached to end
		    instruction(FLOW_CONT, JMP_IF_0, 2) 
		     );
  program.push_back( //loop again
		    instruction(FLOW_CONT, JMP, 1) 
		     );
  program.push_back( //where to get out of the loop
		    instruction(FLOW_CONT, MARK_LABLE, 2) 
		     );
  program.push_back( //where to get out of the loop
		    instruction(FLOW_CONT, END_PROGRAM, 2) 
		     );
  virtual_machine VM(program);
  VM.start();
  return true;
}
static bool test_flow_5(){
  vector<instruction> program;
  program.push_back( //initial number
		    instruction(STACK_MAN, PUSH, 5) 
		     );
  program.push_back( //call factorial
		    instruction(FLOW_CONT, CALL, 24) 
		     );
  program.push_back( //print result
		    instruction(IO, WRITE_NUM, 4) 
		     );
  program.push_back(
		    instruction(FLOW_CONT, END_PROGRAM, -1) 
		    );
  program.push_back( //decleare factorial
		    instruction(FLOW_CONT, MARK_LABLE, 24) 
		     );
  program.push_back(
		    instruction(FLOW_CONT, JMP_IF_0, 1) 
		     );
  program.push_back(
		    instruction(STACK_MAN, DUP_TOP, 1) 
		     );
  program.push_back(
		    instruction(STACK_MAN, PUSH, -1) 
		     );
  program.push_back(
		    instruction(ARITHMETIC, ADD, 1) 
		     );
  program.push_back(
		    instruction(FLOW_CONT, CALL, 24) 
		     );
  program.push_back(
		    instruction(ARITHMETIC, MULTIPLY, 1) 
		     );
  program.push_back(
		    instruction(FLOW_CONT, RETURN, 24) 
		    );
  program.push_back(
		    instruction(FLOW_CONT, MARK_LABLE, 1) 
		    );
  program.push_back(
		      instruction(STACK_MAN, POP, -1) 
		      );
  program.push_back(
		    instruction(STACK_MAN, PUSH, 1) 
		    );
  program.push_back(
		    instruction(FLOW_CONT, RETURN, -1) 
		    );
  virtual_machine VM(program);
  VM.start();
  return true;
}

void test_flow(){
  cout << "test_flowing flow" << endl;
  if(test_flow_1()){
    cout << "passed " << 1 << endl;
  } else{
    cout << "failed" << endl;
  }
  if(test_flow_2()){
    cout << "passed " << 2 << endl;
  } else{
    cout << "failed" << endl;
  }
  if(test_flow_3()){
    cout << "passed " << 3 << endl;
  } else{
    cout << "failed" << endl;
  }
  if(test_flow_4()){
    cout << "passed " << 4 << endl;
  } else{
    cout << "failed" << endl;
  }
  if(test_flow_5()){
    cout << "passed " << 5 << endl;
  } else{
    cout << "failed" << endl;
  }
}
