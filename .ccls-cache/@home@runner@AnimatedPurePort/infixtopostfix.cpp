#include "infixtopostfix.h"

bool is_balanced(std::string expression){
  std::stack<char> c;
  for (int i = 0; i < expression.length(); i++){
    if (c.empty()) {
      c.push(expression[i]);
    }
    else if ((c.top() == '(' && expression[i] == ')') || (c.top() == '{' && expression[i] == '}') ||(c.top() == '[' && expression[i] == ']'))
      c.pop();

    else
      c.push(expression[i]);
  }

  if (c.empty()){
    return true;
  }
  else
    return false;
}

int get_precedence(char c) {
  if (c == '+' || c == '-') {
      return 1;
  } 
  else if (c == '*' || c == '/' || c == '%') {
      return 2;
  }
  else
    return 0;
}

bool is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}



std::string infixToPostfix(std::string infix) {
  if (!is_balanced(infix)) {
    return "Invalid expression - unbalanced parentheses";
  }

  std::stack<char> st;
  std::string postfix;

  for (char c : infix) {
    if (c == '(' || c == '[' || c == '{') {
      st.push(c);
    } else if (c == ')' || c == ']' || c == '}') {
      char top = st.top();
      st.pop();
      if (top != '(' && top != '[' && top != '{') {
        return "Invalid expression - unbalanced parentheses";
      }
    } else if (is_operator(c)) {
      while (!st.empty() && is_operator(st.top()) && get_precedence(c) <= get_precedence(st.top())) {
        postfix += st.top();
        st.pop();
      }
      st.push(c);
    } else {
      postfix += c;
    }
  }

  while (!st.empty()) {
    postfix += st.top();
    st.pop();
  }

  return postfix;
}