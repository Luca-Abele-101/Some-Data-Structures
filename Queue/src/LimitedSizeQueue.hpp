#ifndef __LIMITED_SIZE_QUEUE_HPP
#define __LIMITED_SIZE_QUEUE_HPP

#include "QueueVirtual.hpp"
#include "QueueExceptions.hpp"

template <typename T>
class LimitedSizeQueue final : public QueueVirtual<T> // Модификатор final запрещает наследование от класса.
{
public:
	explicit LimitedSizeQueue(size_t size);
	LimitedSizeQueue(const LimitedSizeQueue<T>& src) = delete;
	LimitedSizeQueue(LimitedSizeQueue<T>&& src) noexcept;
	virtual ~LimitedSizeQueue() override;

	LimitedSizeQueue<T>& operator=(const LimitedSizeQueue<T>& src) = delete;
	LimitedSizeQueue<T>& operator=(LimitedSizeQueue<T>&& src) noexcept;

	void push(const T& e) override;
	T pop() override;
	bool isEmpty() const override;

private:
	T* array_; // Массив элементов очереди.
	size_t head_ = 1; // Очередь пуста, если head[Q] = tail[Q].
	size_t tail_ = 1; // Первоначально: head[Q] = tail[Q] = 1;
	size_t size_; // Размер очереди.

	void swap(LimitedSizeQueue<T>& other);
};

#include "LimitedSizeQueue.tpp"

#endif
