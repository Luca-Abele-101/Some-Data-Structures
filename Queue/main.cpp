#include <iostream>
#include "LimitedSizeQueue.hpp"

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Ограниченная очередь:\n";
	LimitedSizeQueue<int> sus(4);

	sus.push(1);
	sus.push(2);
	sus.push(3);
	sus.push(4);

	std::cout << "\nПроверка исключения OverFlow:\n";
	try
	{
		sus.push(5);
	}
	catch (const QueueOverflow & error)
	{
		std::cout << error.what() << "\n";
	}

	std::cout << sus.pop() << "\n";
	std::cout << sus.pop() << "\n";
	std::cout << sus.pop() << "\n";
	std::cout << sus.pop() << "\n";

	std::cout << "Проверка исключения UnderFlow:\n";
	try
	{
		sus.pop();
	}
	catch (const QueueUnderflow & error)
	{
		std::cout << error.what() << "\n";
	}

	std::cout << "Проверка закольцованности внутреннего массива очереди:\n";
	for (int i = 5; i <= 17; i++) // Три раза проходим массив очереди по кругу
	{
		sus.push(i);
		std::cout << sus.pop() << "; ";
	}
	std::cout << "\n";

	return 0;
}
