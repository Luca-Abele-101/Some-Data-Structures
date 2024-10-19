#ifndef __STACK_ARRAY_EXCEPTIONS_HPP
#define __STACK_ARRAY_EXCEPTIONS_HPP

#include <exception>

// Исключение в случае попытки добавить элемент
// в полностью заполненный ограниченный стек.
class StackOverflow : public std::exception
{
public:
	StackOverflow() : reason_("Stack Overflow!") {}

	const char* what() const noexcept
	{
		return reason_;
	}
private:
	const char* reason_;
};

// Исключение в случае попытки изъять
// элемент из пустого стека.
class StackUnderflow : public std::exception
{
public:
	StackUnderflow() : reason_("Stack Underflow!") {}

	const char* what() const noexcept
	{
		return reason_;
	}
private:
	const char* reason_;
};

// Исключительная ситуация WrongStackSize может возникнуть,
// если в конструкторе стека неправильно задан размер.
class WrongStackSize : public std::exception
{
public:
	WrongStackSize() : reason_("Wrong Stack Size!") {}

	const char* what() const noexcept
	{
		return reason_;
	}
private:
	const char* reason_;
};

#endif
