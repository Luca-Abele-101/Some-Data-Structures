#include "LimitedSizeStack.hpp"

template <class T>
LimitedSizeStack<T>::LimitedSizeStack(size_t size) :
	array_(nullptr),
	top_(0),
	size_(size)
{
	try
	{
		array_ = new T[size + 1];
	}
	catch (...)
	{
		throw WrongStackSize();
	}
}

template <class T>
LimitedSizeStack<T>::LimitedSizeStack(const LimitedSizeStack<T>& src) :
	array_(nullptr),
	top_(src.top_),
	size_(src.size_)
{
	try
	{
		array_ = new T[src.size_ + 1];
	}
	catch (...)
	{
		throw WrongStackSize();
	}

	for (int i = 1; i <= src.top_; i++)
	{
		array_[i] = src.array_[i];
	}
}

template <class T>
LimitedSizeStack<T>::LimitedSizeStack(LimitedSizeStack<T>&& src) :
	array_(src.array_),
	top_(src.top_),
	size_(src.size_)
{
	src.array_ = nullptr;
	src.top_ = 0;
	src.size_ = 0;
}

template <class T>
LimitedSizeStack<T>& LimitedSizeStack<T>::operator=(const LimitedSizeStack& src)
{
	if (this == &src)
	{
		return *this;
	}

	size_ = src.size_;
	top_ = src.top_;
	delete[] array_;

	try
	{
		array_ = new T[src.size_ + 1];
	}
	catch (...)
	{
		throw WrongStackSize();
	}

	for (int i = 1; i <= src.top_; i++)
	{
		array_[i] = src.array_[i];
	}
}

template <class T>
LimitedSizeStack<T>& LimitedSizeStack<T>::operator=(LimitedSizeStack<T>&& src)
{
	if (this == &src)
	{
		return *this;
	}

	size_ = src.size_;
	top_ = src.top_;
	delete[] array_;
	array_ = src.array_;

	src.size_ = 0;
	src.top_ = 0;
	src.array_ = nullptr;
}

template <class T>
LimitedSizeStack<T>::~LimitedSizeStack()
{
	delete[] array_;
}

template <class T>
void LimitedSizeStack<T>::push(const T& a)
{
	if (top_ == size_)
	{
		throw StackOverflow();
	}
	array_[++top_] = a;
}

template <class T>
T LimitedSizeStack<T>::pop()
{
	if (top_ == 0)
	{
		throw StackUnderflow();
	}
	return array_[top_--];
}

template <class T>
T LimitedSizeStack<T>::top()
{
	if (top_ == 0)
	{
		throw ("Stack is empty!");
	}
	return array_[top_];
}

template <class T>
bool LimitedSizeStack<T>::isEmpty()
{
	return (top_ == 0);
}

template <class T>
size_t LimitedSizeStack<T>::getSize()
{
	return top_;
}

template <class T>
void LimitedSizeStack<T>::swap(LimitedSizeStack<T>& src)
{
	std::swap(array_, src.array_);
	std::swap(top_, src.top_);
	std::swap(size_, src.size_);
}
