#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
  string expression;
  double res;

  setlocale(LC_ALL, "Russian");
  cout << "Введите арифметическое выражение: ";
  cin >> expression;
  cout << expression << endl;

  TPostfix Example(expression);

  cout << "Арифметическое выражение: " << Example.GetInfix() << endl;
  Example.ToPostfix();
  cout << "Постфиксная форма: " << Example.GetPostfix() << endl;

  res = Example.Calculate();

  cout << res << endl;

  return 0;
}
