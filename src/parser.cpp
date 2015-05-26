#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "instruction.hpp"
#include "parser.hpp"
using namespace std;


vector<instruction> get_instruction_vector(string FILE_NAME){
  vector<char> whitespace_code = get_bytes(FILE_NAME);
  vector<instruction> instrucs;
  instruction temp_inst;
  
  vector<char>::iterator CH = whitespace_code.begin();
  while(CH != whitespace_code.end()){
    //detecting IMP
    temp_inst.type = detect_imp(CH);
    CH++;
    //detecting command
    switch(temp_inst.type){
    case STACK_MAN:
      temp_inst.com = detect_stack_man_command(CH);
      break;
    case FLOW_CONT:
      temp_inst.com = detect_flow_cont_command(CH);
      break;
    case ARITHMETIC:
      temp_inst.com = detect_arith_command(CH);
      break;
    case HEAP_ACC:
      temp_inst.com = detect_heap_command(CH);
      break;
    case IO:
      temp_inst.com = detect_IO_command(CH);
      break;
    }
    CH++;
    //detecting data
    if(com_has_perem(temp_inst.com)){
      temp_inst.data = detect_data(CH);
    } else{
      temp_inst.data = -1;
    }
    temp_inst.print();
  }
}
COMMAND detect_stack_man_command(vector<char>::iterator& CH){
  if(*CH == SPACE){
    return PUSH;
  }
  else if(*CH == NEW_LINE){
    CH++;
    if(*CH == SPACE){
      return DUP_TOP;
    } else if(*CH == TAB){
      return SWOP_2_TOP;
    } else if(*CH == NEW_LINE){
      return POP;
    }
  }
  else if(*CH == TAB){
    CH++;
    if(*CH == SPACE){
      return DUP_NTH;
    } else if(*CH == NEW_LINE){
      return POP_N;
    }
  }
}
COMMAND detect_arith_command(vector<char>::iterator& CH){
  if(*CH == SPACE){
    CH++;
    if(*CH == SPACE){
      return ADD;
    } else if(*CH == TAB){
      return SUBTRUCT;
    } else if(*CH == NEW_LINE){
      return MULTIPLY;
    }
  }
  else if(*CH == TAB){
    CH++;
    if(*CH == SPACE){
      return DIVIDE;
    } else if(*CH == TAB){
      return MOD;
    }
  }
}
COMMAND detect_heap_command(vector<char>::iterator& CH){
  if(*CH == SPACE){
    return STORE;
  }
  else if(*CH == TAB){
    return RETRIEVE;
  }
}
COMMAND detect_flow_cont_command(vector<char>::iterator& CH){
  if(*CH == SPACE){
    CH++;
    if(*CH == SPACE){
      return MARK_LABLE;
    } else if(*CH == TAB){
      return CALL;
    } else if(*CH == NEW_LINE){
      return JMP;
    }
  }
  else if(*CH == TAB){
    CH++;
    if(*CH == SPACE){
      return JMP_IF_0;
    } else if(*CH == TAB){
      return JMP_IF_NEG;
    } else if(*CH == NEW_LINE){
      return RETURN;
    }
  } else if(*CH == NEW_LINE){
    CH++;
    if(*CH == NEW_LINE){
      return END_PROGRAM;
    }
  }
}
COMMAND detect_IO_command(vector<char>::iterator& CH){
  if(*CH == SPACE){
    CH++;
    if(*CH == SPACE){
      return WRITE_CHAR;
    } else if(*CH == TAB){
      return WRITE_NUM;
    }
  }
  else if(*CH == TAB){
    CH++;
    if(*CH == SPACE){
      return READ_CHAR;
    } else if(*CH == TAB){
      return READ_NUM;
    } 
  }
}

int detect_data(vector<char>::iterator& CH){
  int sign = (*CH == SPACE)? 1: -1;
  CH++;
  int data = 0;
  while(*CH != NEW_LINE){
    data = data * 2 + (*CH == TAB);
    CH++;
  }
  CH++;
  return data * sign;
}

IMP_TYPE detect_imp(vector<char>::iterator& CH){
  if(*CH == SPACE){
    return STACK_MAN;
  } else if(*CH == NEW_LINE){
    return FLOW_CONT;
  } else if(*CH == TAB){
    CH++;
    if(*CH == SPACE){
      return ARITHMETIC;
    }
    else if(*CH == TAB){
      return HEAP_ACC;
    }
    else if(*CH == NEW_LINE){
      return IO;
    }
  }
}
inline bool is_white_space_char(char c){
  return 
    ((c == SPACE) || (c == TAB) || (c == NEW_LINE));
}

vector<char> get_bytes(string FILE_NAME){
  vector<char> bytes;
  fstream FileBin(FILE_NAME.c_str());
  FileBin>> std::noskipws;
  char buffer;
  while(FileBin >> buffer){
    if(is_white_space_char(buffer)){
      cout << (int)buffer << endl;
      bytes.push_back(buffer);
    }
  }
  return bytes;
}

bool com_has_perem(COMMAND c){
  bool has = false; 
  has |= (c == PUSH);
  has |= (c == DUP_NTH);
  has |= (c == POP_N);
  
  has |= (c ==   MARK_LABLE);
  has |= (c == CALL);
  has |= (c == JMP);
  has |= (c == JMP_IF_0);
  has |= (c == JMP_IF_NEG);
  return has;
}
