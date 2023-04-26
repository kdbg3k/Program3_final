#pragma once
#include <stack>
#include <string>
#include <iostream>


bool is_balanced(std::string expression); //returns true if expression has balanced parentheses, otherwise returns false

std::string infixToPostfix(std::string s); //accepts string as infix expression and converts it to postfix expression and returns result

bool is_operator(char c); //checks if character is an operator

int get_precedence(char c); //gets precedence of character
