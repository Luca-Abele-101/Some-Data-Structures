#include <iostream>

#include "Queue.hpp"
#include "BinaryTree.hpp"

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Ограниченная очередь:\n";
	QueueArray<int> sus(4);

	sus.enQueue(1);
	sus.enQueue(2);
	sus.enQueue(3);
	sus.enQueue(4);

	std::cout << "\nПроверка исключения OverFlow:\n";
	try
	{
		sus.enQueue(5);
	}
	catch (const QueueOverflow & error)
	{
		std::cout << error.what() << "\n";
	}

	std::cout << sus.deQueue() << "\n";
	std::cout << sus.deQueue() << "\n";
	std::cout << sus.deQueue() << "\n";
	std::cout << sus.deQueue() << "\n";

	std::cout << "Проверка исключения UnderFlow:\n";
	try
	{
		sus.deQueue();
	}
	catch (const QueueUnderflow & error)
	{
		std::cout << error.what() << "\n";
	}

	std::cout << "Проверка закольцованности очереди:\n";
	for (int i = 5; i <= 17; i++) // Три раза проходим массив очереди по кругу
	{
		sus.enQueue(i);
		std::cout << sus.deQueue() << "; ";
	}

	return 0;
}
