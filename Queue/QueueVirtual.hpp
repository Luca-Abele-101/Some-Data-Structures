#ifndef __QUEUE_VIRTUAL_HPP
#define __QUEUE_VIRTUAL_HPP

template <class T>
class QueueVirtual
{
public:
	virtual ~QueueVirtual() = default;

	virtual void push(const T& e) = 0;  //  Добавление элемента в хвост (может вызвать overflow)
	virtual T pop() = 0;  //  Удаление и возвращение головного элемента (может вызвать underflow)
	virtual bool isEmpty() const = 0;
};

#endif
