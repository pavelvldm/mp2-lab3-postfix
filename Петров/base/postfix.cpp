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

bool IsNumber(const char &opd)
{
	const string numbers = "0123456789";

	if (numbers.find(opd) != string::npos)
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

	if (s.find("++") != string::npos)
		return false;

	if (s.find("+-") != string::npos)
		return false;

	if (s.find("+*") != string::npos)
		return false;

	if (s.find("+/") != string::npos)
		return false;

	if (s.find("-+") != string::npos)
		return false;

	if (s.find("--") != string::npos)
		return false;

	if (s.find("-*") != string::npos)
		return false;

	if (s.find("-/") != string::npos)
		return false;

	if (s.find("*+") != string::npos)
		return false;

	if (s.find("*-") != string::npos)
		return false;

	if (s.find("**") != string::npos)
		return false;

	if (s.find("*/") != string::npos)
		return false;

	if (s.find("/+") != string::npos)
		return false;

	if (s.find("/-") != string::npos)
		return false;

	if (s.find("/*") != string::npos)
		return false;

	if (s.find("//") != string::npos)
		return false;

	return true;
}

string TPostfix::ToPostfix()
{
	TStack<char> operation(MaxStackSize);
	TStack<int> priority(MaxStackSize);

	if (!CheckString(infix))
		throw exception("Wrong string");

	for (int i = 0; i < infix.size(); i++)
	{
		// Если операнд - буква
		if (IsOperand(infix[i]))
		{
			postfix += infix[i];
			continue;
		}

		// Если операнд - цифра
		if (IsNumber(infix[i]))
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
					else continue;
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

			if (!operation.empty())
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
	if (!postfix.size())
		throw exception("Wrong postfix");

	double Result = 0;
	TStack<double> Value(MaxStackSize);

	for (int i = 0; i < postfix.size(); i++)
	{
		if (IsOperand(postfix[i]))
		{
			double temp;
			cout << "Insert " << postfix[i] << " : ";
			cin >> temp;
			Value.push(temp);

			continue;
		}

		if (IsNumber(postfix[i]))
		{
			switch (postfix[i])
			{
			case '0':
				Value.push(0);
				break;
			case '1':
				Value.push(1);
				break;
			case '2':
				Value.push(2);
				break;
			case '3':
				Value.push(3);
				break;
			case '4':
				Value.push(4);
				break;
			case '5':
				Value.push(5);
				break;
			case '6':
				Value.push(6);
				break;
			case '7':
				Value.push(7);
				break;
			case '8':
				Value.push(8);
				break;
			case '9':
				Value.push(9);
				break;
			}
		}

		if (IsOperator(postfix[i]))
		{
			if (postfix[i] == '+')
			{
				double a = Value.pop();
				double b = Value.pop();

				b = b + a;

				Value.push(b);
			}

			if (postfix[i] == '-')
			{
				double a = Value.pop();
				double b = Value.pop();

				b = b - a;

				Value.push(b);
			}

			if (postfix[i] == '*')
			{
				double a = Value.pop();
				double b = Value.pop();

				b = b * a;

				Value.push(b);
			}

			if (postfix[i] == '/')
			{
				double a = Value.pop();
				double b = Value.pop();

				b = b / a;

				Value.push(b);
			}
		}
	}

	Result = Value.pop();
	return Result;
}
