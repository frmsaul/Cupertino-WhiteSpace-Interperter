#include <stack>
#include <iostream>
#include <assert.h>

#include "virtual_stack.hpp"

using namespace std;

void virtual_stack::add(){
  int left = STACK.top();
  STACK.pop();
  int right = STACK.top();
  STACK.pop();
  STACK.push(left + right);
}
void virtual_stack::subtruct(){
  int left = STACK.top();
  STACK.pop();
  int right = STACK.top();
  STACK.pop();
  STACK.push(left - right);
}
void virtual_stack::multiply(){
  int left = STACK.top();
  STACK.pop();
  int right = STACK.top();
  STACK.pop();
  STACK.push(left * right);
}
void virtual_stack::divide(){
  int left = STACK.top();
  STACK.pop();
  int right = STACK.top();
  STACK.pop();
  STACK.push(left / right);
}
void virtual_stack::mod(){
  int left = STACK.top();
  STACK.pop();
  int right = STACK.top();
  STACK.pop();
  STACK.push(left % right);
}

int virtual_stack::top(){
  return STACK.top();
}

void virtual_stack::push(int n){
  STACK.push(n);
}
void virtual_stack::dup_top(){
  int temp = STACK.top();
  STACK.push(temp);
}
void virtual_stack::dup_nth(int n){
  stack<int> temp_stack;
  for(int i = 0; i < n; i++){
    temp_stack.push(STACK.top());
    STACK.pop();
  }
  int head = STACK.top();
  for(int i = 0; i < n; i++){
    STACK.push(temp_stack.top());
    temp_stack.pop();
  }
  STACK.push(head);
}
void virtual_stack::swop_2_top(){
  int temp1 = STACK.top(); STACK.pop();
  int temp2 = STACK.top(); STACK.pop();
  STACK.push(temp1);
  STACK.push(temp2);
}
void virtual_stack::pop(){
  STACK.pop();
}
void virtual_stack::pop_n(int n){
  int head = STACK.top();
  STACK.pop();
  for(int i = 0; i < n; i++){
    STACK.pop();
  }
  STACK.push(head);
}
void virtual_stack::run_arth_instruction(instruction I){
  switch(I.com){
  case ADD: 
    add();
    break;
  case SUBTRUCT: 
    subtruct();
    break;
  case MULTIPLY: 
    multiply();
    break;
  case DIVIDE:
    divide();
    break;
  case MOD:
    mod();
    break;
  default:
    cout << "command isn't an arthimatic command" << endl;
    assert(1 == 0);
  }
}

void virtual_stack::run_instruction(instruction I){
  switch(I.com){
    case PUSH: 
      push(I.data);
      break;
    case DUP_TOP: 
      dup_top();
      break;
    case DUP_NTH: 
      dup_nth(I.data);
      break;
    case SWOP_2_TOP: 
      swop_2_top();
      break;
    case POP:
      pop();
      break;
    case POP_N:
      pop_n(I.data);
      break;
    default:
      cout << "command isn't a stack command" << endl;
      assert(1 == 0);
  }
}
void virtual_stack::print_stack(){
  cout << "printing stack" << endl;
  stack<int> temp_stack;
  while(!STACK.empty()){
    temp_stack.push(STACK.top());
    cout << STACK.top() << endl;
    STACK.pop();
  }
  while(!temp_stack.empty()){
    STACK.push(temp_stack.top());
    temp_stack.pop();
  }
  cout << "done printing stack" << endl;
}
