#include "postfix.h"
#include "stack.h"

bool IsOperand(const char &opd)
{
	const string alphabet = "abcdefghijklmnopqrstuvwxyz";
	const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if (alphabet.find(opd) != string::npos)
		return true;

	if (ALPHABET.find(opd) != string::npos)
		return true;

	return false;
}

int IsOperator(const char &op)
{
	const string operPr1 = "+-";
	const string operPr2 = "*/";

	if (operPr1.find(op) != string::npos)
		return 1;

	if (operPr2.find(op) != string::npos)
		return 2;

	return 0;
}

bool CheckString(const string &s)
{
	if (s.size() == 0)
		return false;

	if (s.find("()") != string::npos)
		return false;

	if (s.find("((") != string::npos)
		return false;

	if (s.find("))") != string::npos)
		return false;

	if (s.find("++") || s.find("+-") || s.find("+*") || s.find("+/"))
		return false;

	if (s.find("-+") || s.find("--") || s.find("-*") || s.find("-/"))
		return false;

	if (s.find("*+") || s.find("*-") || s.find("**") || s.find("*/"))
		return false;

	if (s.find("/+") || s.find("/-") || s.find("/*") || s.find("//"))
		return false;

	return true;
}

string TPostfix::ToPostfix()
{
	TStack<char> operation(10);
	TStack<int> priority(10);

	for (int i = 0; i < infix.size(); i++)
	{
		if (IsOperand(infix[i]))
		{
			postfix += infix[i];
			continue;
		}

		// Если нашли оператор
		if (IsOperator(infix[i]) != 0)
		{

			int pr = 0;									// Для отслеживания приоритета операций
			int OpPr = IsOperator(infix[i]);			// Приоритет текущей операции

			// Стек пустой, то кидаем операцию в стек
			if (operation.empty())
			{
				operation.push(infix[i]);
				priority.push(OpPr);

				continue;
			}

			// Стек не пуст
			else
			{
				pr = priority.pop();

				// Если в стеке открывающая скобка, операция в стек
				if (pr == 0)
				{
					priority.push(pr);
					operation.push(infix[i]);
					priority.push(OpPr);

					continue;
				}
				else
					priority.push(pr);

				pr = priority.pop();

				// Если приоритет операции выше операции в вершине стека, новая операция в стек
				if ((pr != 0) && (OpPr >= pr))
				{
					priority.push(pr);
					priority.push(OpPr);
					operation.push(infix[i]);

					continue;
				}
				else
					priority.push(pr);

				pr = priority.pop();

				// Если приоритет операции меньше или равен, вытаскиваем операции из стека, новую кладём в стек
				if ((pr != 0) && (OpPr < pr))
				{
					while (pr >= OpPr)
					{
						postfix += operation.pop();

						if (priority.empty() == false)
							pr = priority.pop();
						else
						{
							priority.push(OpPr);
							operation.push(infix[i]);
							pr = -1;
						}
					}

					if (pr == 0)
					{
						operation.pop();
						priority.push(OpPr);
						operation.push(infix[i]);

						continue;
					}

					if ((pr > 0) && (pr < OpPr))
					{
						priority.push(pr);
						priority.push(OpPr);
						operation.push(infix[i]);

						continue;
					}
				}
				else
					priority.push(pr);
			}
		}

		// Если открывающая скобка, кладём в стек
		if (infix[i] == '(')
		{
			priority.push(0);
			operation.push(infix[i]);
		}

		// Если закрывающая скобка, вытаскиваем операции из стека до тех пор, пока не '('
		if (infix[i] == ')')
		{
			while ((!priority.empty()) && (priority.pop() != 0))
			{
				postfix += operation.pop();
			}

			operation.pop();
		}
	}

	// Вытаскиваем оставшиеся операции до тех пор, пока не опустошим стек
	while (!operation.empty())
	{
		postfix += operation.pop();
		priority.pop();
	}

	return postfix;
}

double TPostfix::Calculate()
{
  return 0;
}
