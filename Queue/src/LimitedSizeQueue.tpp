#include "LimitedSizeQueue.hpp"

template <typename T>
LimitedSizeQueue<T>::LimitedSizeQueue(size_t size) :
	array_(nullptr),
	head_(1),
	tail_(1),
	size_(size)
{
	try
	{
		array_ = new T[size + 1]; // Пытаемся заказать память под элементы очереди
	}
	catch (...) // Если что-то случилось (например, размер слишком большой)
	{
		throw WrongQueueSize(); // - возникает bad_alloc.
	}
}

template <typename T>
LimitedSizeQueue<T>::LimitedSizeQueue(LimitedSizeQueue<T>&& src) noexcept :
	array_(src.array_),
	head_(src.head_),
	tail_(src.tail_),
	size_(src.size_)
{
	src.array_ = nullptr;
	src.head_ = 1;
	src.tail_ = 1;
	src.size_ = 0;
}

template <typename T>
LimitedSizeQueue<T>::~LimitedSizeQueue()
{
	delete[] array_;
}

template <typename T>
LimitedSizeQueue<T>& LimitedSizeQueue<T>::operator=(LimitedSizeQueue<T>&& src) noexcept
{
	array_ = src.array_;
	head_ = src.head_;
	tail_ = src.tail_;
	size_ = src.size_;

	src.array_ = nullptr;
	src.head_ = 1;
	src.tail_ = 1;
	src.size_ = 0;
}

template <typename T>
void LimitedSizeQueue<T>::push(const T& e)
{
	if ((head_ == tail_ + 1) || ((head_ == 0) && (tail_ == size_)))
	{
		throw QueueOverflow();
	}

	array_[tail_] = e;
	(tail_ != size_) ? tail_++ : tail_ = 0;
}

template <typename T>
T LimitedSizeQueue<T>::pop()
{
	if (head_ == tail_)  //  Очередь пуста
	{
		throw QueueUnderflow();
	}
	T result = array_[head_];
	(head_ != size_) ? head_++ : head_ = 0;
	return result;
}

template <typename T>
bool LimitedSizeQueue<T>::isEmpty() const
{
	return head_ == tail_;
}

template <typename T>
void LimitedSizeQueue<T>::swap(LimitedSizeQueue<T>& other)
{
	std::swap(array_, other.array_);
	std::swap(head_, other.head_);
	std::swap(tail_, other.tail_);
	std::swap(size_, other.size_);
}
