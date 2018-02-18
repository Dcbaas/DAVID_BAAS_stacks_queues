#include "functions.h"
#include <iostream>
#include <string>
#include <vector>
#include <stack>

  bool balancedSymbols(std::string input){
	std::stack<char, std::vector<char> > input_stack;
	for(auto input_it = input.begin(); input_it != input.end(); input_it++){
		//Add a starting parenthese to the stack (, [, or {.
		switch(*input_it){
			case '(':
				input_stack.push(*input_it);
				break;

			case '[':
				input_stack.push(*input_it);
				break;

			case '{':
				input_stack.push(*input_it);
				break;
		
			case ')':
				if(input_stack.empty())// is the stack empty. if yes then this is an error and there won't be balance
					return false;
				else if(input_stack.top() == '('){ // Does the top match the current char symbol. if yes pop the top.
					input_stack.pop();
					break;
				}
				else
					return 0;
	
			case ']':
				if(input_stack.empty())// is the stack empty. if yes then this is an error and there won't be balance
					return 0;
				else if(input_stack.top() == '['){ // Does the top match the current char symbol. if yes pop the top.
					input_stack.pop();
					break;
				}
				else
					return 0;
			case '}':
				if(input_stack.empty())// is the stack empty. if yes then this is an error and there won't be balance  							
                               		return 0;
		        	else if(input_stack.top() == '{'){ // Does the top match the current char symbol. if yes pop the top.
					input_stack.pop();
					break;
				}
				else 
					return 0;
		}
	}		

	if(input_stack.empty())
		return 1;
	
	return 0;
  }

  std::string iToP(std::string input){
	return "String";

  }  
 
