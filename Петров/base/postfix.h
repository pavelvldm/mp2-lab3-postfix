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
	TPostfix()
	{
		infix = '\0';
		postfix = '\0';
	}

  TPostfix(const string &s)
  {
	  if (s.size())
		  infix = s;
	  else throw exception("Empty");
  }

  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  string ToPostfix();
  double Calculate(); // Ввод переменных, вычисление по постфиксной форме
};

#endif
