#ifndef _H_PARSER
#define _H_PARSER

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "instruction.hpp"

#define SPACE 32
#define TAB 9
#define NEW_LINE 10

enum PARSER_STATE{
  DETECTING_IMP,
  DETECTING_COMMAND,
  DETECTING_DATA
};

std::vector<instruction> get_instruction_vector(std::string FILE_NAME);
inline bool is_white_space_char(char c);
std::vector<char> get_bytes(std::string FILE_NAME);
IMP_TYPE detect_imp(std::vector<char>::iterator& CH);
COMMAND detect_stack_man_command(std::vector<char>::iterator& CH);
bool com_has_perem(COMMAND c);


#endif
