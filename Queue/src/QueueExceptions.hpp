#ifndef __QUEUE_EXCEPTIONS_HPP
#define __QUEUE_EXCEPTIONS_HPP

#include <exception>

// Исключение в случае попытки добавить элемент
// в полностью заполненную ограниченную очередь.
class QueueOverflow : public std::exception
{
public:
	QueueOverflow() : reason_("Queue Overflow") {}

	const char* what() const noexcept override
	{
		return reason_;
	}

private:
	const char* reason_;
};

// Исключение в случае попытки изъять
// элемент из пустой очереди.
class QueueUnderflow : public std::exception
{
public:
	QueueUnderflow() : reason_("Queue Underflow") {}

	const char* what() const noexcept override
	{
		return reason_;
	}

private:
	const char* reason_;
};

// Исключительная ситуация WrongQueueSize может возникнуть,
// если в конструкторе очереди неправильно задан размер.
class WrongQueueSize : public std::exception
{
public:
	WrongQueueSize() : reason_("Wrong Queue Size") {}

	const char* what() const noexcept override
	{
		return reason_;
	}

private:
	const char* reason_;
};

#endif
