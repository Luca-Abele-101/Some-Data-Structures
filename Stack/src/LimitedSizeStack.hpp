#ifndef __STACK_ARRAY_HPP
#define __STACK_ARRAY_HPP

#include <iostream>
#include "StackVirtual.hpp"
#include "StackExceptions.hpp"

template <class T>
class LimitedSizeStack : public Stack<T>
{
public:
	LimitedSizeStack(size_t size = 100);
	LimitedSizeStack(const LimitedSizeStack<T>& src);
	LimitedSizeStack(LimitedSizeStack<T>&& src);
	LimitedSizeStack& operator=(const LimitedSizeStack<T>& src);
	LimitedSizeStack& operator=(LimitedSizeStack<T>&& src);
	virtual ~LimitedSizeStack();

	void push(const T& e);
	T pop();
	T top();
	bool isEmpty();
	size_t getSize();

private:
	T* array_; // Массив элементов стека (0-й элемент не используется, top_ от 1 до size_)
	size_t top_; // Вершина стека, элемент, занесенный в стек последним
	size_t size_;
	void swap(LimitedSizeStack<T>& src);
};

#include "LimitedSizeStack.tpp"

#endif
