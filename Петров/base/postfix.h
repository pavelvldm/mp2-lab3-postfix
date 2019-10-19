#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"

using namespace std;

class TPostfix
{
  string infix;
  string postfix;
public:
  TPostfix(const string &s)
  {
    infix = s;
  }
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  string ToPostfix()
  {
	  TStack<char> operations(MaxStackSize);
	  TStack<int> priority(MaxStackSize);

	  int i = 0;

	  while (i < infix.size())
	  {
		  if ((infix[i] >= 'a') && (infix[i] <= 'z'))
			  postfix += infix[i];

		  if (infix[i] == '(')
		  {
			  operations.push(infix[i]);
			  priority.push(0);
		  }

		  if (infix[i] == ')')
		  {
			  while (priority.pop())
				  postfix += operations.pop();
			  operations.pop();
		  }

		  if ((infix[i] == '+') || (infix[i] == '-'))
			  if (operations.empty())
			  {
				  operations.push(infix[i]);
				  priority.push(1);
			  }
			  else
			  {
				  int pr = priority.pop();
				  if (1 <= pr)
				  {
					  postfix += infix[i];
					  priority.push(pr);
				  }
				  else
				  {
					  priority.push(pr);
					  priority.push(1);
					  operations.push(infix[i]);
				  }
			  }

		  if ((infix[i] == '*') || (infix[i] == '/'))
			  if (operations.empty())
			  {
				  operations.push(infix[i]);
				  priority.push(2);
			  }
			  else
			  {
				  int pr = priority.pop();
				  if (2 <= pr)
					  postfix += infix[i];
				  else
				  {
					  priority.push(pr);
					  priority.push(2);
					  operations.push(infix[i]);
				  }
			  }
		  i++;
	  }

	  while (!operations.empty())
		  postfix += operations.pop();

	  return postfix;
  }
  double Calculate(); // Ввод переменных, вычисление по постфиксной форме
};

#endif
