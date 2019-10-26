#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <vector>

const int MaxStackSize = 100;

template <class T>
class TStack
{
  T *pMem;
  int size;
  int top;
public:
	TStack(int _size)
	{
		if ((_size < 1) || (_size > MaxStackSize))
			throw std::exception("Wrong size");
		else
		{
			size = _size;
			top = -1;
			pMem = new T[size];
		}
	}

	~TStack()
	{
		delete[] pMem;
	}

	bool empty()
	{
		return top == -1;
	}

	bool full()
	{
		return top == size;
	}

	void push(T el)
	{
		if (full())
			throw std::exception("No space\n");

		top++;
		pMem[top] = el;
	}

	T pop()
	{
		if (empty())
			throw std::exception("Stack is empty\n");

		return pMem[top--];
	}
};

#endif
