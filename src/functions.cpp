#include "functions.h"
#include <iostream>
#include <string>
#include <vector>
#include <stack>


//Author: David Baas
//Version: 2/19/2018
//Since: 2/13/2018

/**********************************************************************
 * The balancedSymbols function looks at a string and determines 
 * weather or not there is symbol balance for the parentetical symbols:
 * '()', '[]', and the '{}'. It accomplishes this by using a stack
 * structture to track left parenthetical symbols. When a right 
 * parenthetical symbol is come across, it is compared to the current 
 * left parenthetical symbol on the top of the stack. If the stack is 
 * empty, false is returned. If the symbols don't match, false is 
 * returned. If they symbols match, the top symbol is popped and the 
 * next char in the input string is assesed. If at the end of the
 * input string the stack is empty, true is returned.
 *
 * @param input string that is the input being tested.
 * @return true if the stack is empty at the end of the input string
 * analysis. False if one of the reasons above occurs.
 **********************************************************************/
  bool balancedSymbols(std::string input){
	std::stack<char, std::vector<char> > input_stack;
	for(auto input_it = input.begin(); input_it != input.end(); input_it++){
		//Check the char to see if it matches a lef parethetical symbol.
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
		//Check if the char is a right parenthetical symbol.
			case ')':
				// Is the stack empty? if yes, then this is
				//  an error and there won't be balance.
				if(input_stack.empty())
					return false;
				// Does the top match the current char symbol?
				//  If yes, pop the top.
				else if(input_stack.top() == '('){ 
					input_stack.pop();
					break;
				}
				//The symbols don't match return false.
				else
					return 0;
	
			case ']':
				if(input_stack.empty())
					return 0;
				else if(input_stack.top() == '['){ 
					input_stack.pop();
					break;
				}
				else
					return 0;
			case '}':
				if(input_stack.empty())  							
                               		return 0;
		        	else if(input_stack.top() == '{'){ 
					input_stack.pop();
					break;
				}
				else 
					return 0;
		}
	}		
	//Is the stack empty after the string analysis?
	//If yes, return true.
	if(input_stack.empty())
		return 1;
	
	return 0;
  }
/***********************************************************************
 * The iToP converts an infix expression to a reverse Polish expression.
 *
 *
 **********************************************************************/
  std::string iToP(std::string input){
	std::string output;
	std::stack<char, std::vector<char> > input_stack;

	//read the entire expression 
	for(auto input_it = input.begin(); input_it != input.end(); input_it++){
		switch(*input_it){
			case '+':
				if(input_stack.empty())
					input_stack.push(*input_it);
				else{
					while(!input_stack.empty() && input_stack.top() != '('){
						output.append(1, input_stack.top());
						input_stack.pop();
					}
					input_stack.push(*input_it);
						
				}
				break;
			case '-':	
				if(input_stack.empty())
					input_stack.push(*input_it); 
				else{
					while(!input_stack.empty() && input_stack.top() != '('){
						output.append(1, input_stack.top());
						input_stack.pop();
					}
					input_stack.push(*input_it);
				}
                                break;
			case '/':
				if(input_stack.empty())
					input_stack.push(*input_it);
				else{
					while(!input_stack.empty() && input_stack.top() != '(' &&
					 input_stack.top() != '+' && input_stack.top() != '-'){
						output.append(1, input_stack.top());
						input_stack.pop();
					}
					input_stack.push(*input_it);
				}	
				break;
			case '*':
				if(input_stack.empty())
					input_stack.push(*input_it);
				else{
					while(!input_stack.empty() && input_stack.top() != '(' &&
						input_stack.top() != '+' && input_stack.top() != '-'){
						output.append(1, input_stack.top());
						input_stack.pop();
					}
					input_stack.push(*input_it);
				}	
				break;
			case '(':
//				if(!input_stack.empty())//If this isn't the start of the expression.
//					output.append(1, input_stack.top());
				input_stack.push(*input_it);
				break;
			case ')':
				while(input_stack.top() != '('){
					output.append(1, input_stack.top());
					input_stack.pop();
				}
				input_stack.pop(); //Pop off the '('.
 				break;
			default:
				output.append(1, *input_it);
				break;		
		}
	}
	
	while(!input_stack.empty()){
		output.append(1,input_stack.top());
		input_stack.pop();
		}
	return output;

 }  
 
