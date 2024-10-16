#include <iostream>

#include "BinaryTree.hpp"

int main()
{
	setlocale(LC_ALL, "rus");

    BinarySearchTree<int> sus;
	std::cout << "Пусто ли дерево (0/1): " << sus.isEmpty() << "\n";
	sus.insert(5);
	sus.insert(6);
	sus.insert(4); // Тест 2.1 (Вставка узла по правилам бинарного дерева)
	sus.insert(7);
	std::cout << "Пусто ли дерево (0/1): " << sus.isEmpty() << "\n\n";

	// Тест 4.1 (Печать дерева)
	std::cout << "Печать дерева:\n";
	sus.print(std::cout);

	// Тест 1.1 (Итеративный поиск узла)
	std::cout << "\nЭлемент со значением \"4\": " << (sus.iterativeSearch(4))->key_ << "\n";

	// Тест 1.2 (Рекурсивный поиск узла)
	std::cout << "\nЭлемент со значением \"4\": " << (sus.recursiveSearch(sus.getRoot(), 4))->key_ << "\n\n";

	// Тест на нахождение минимума и максимума в подветке
	std::cout << "Minimum: " << sus.findMinimum(sus.getRoot())->key_ << "\n";
	std::cout << "Maximum: " << sus.findMaximum(sus.getRoot())->key_ << "\n\n";

	// Тест 8.1, (рекурсивный обход), 8.1 (итеративный обход)
	sus.inorderWalk();
	std::cout << "\n";
	sus.iterativeInorderWalk();
	std::cout << "\n\n";

	// Тест на удаление элемента
	sus.deleteKey(6);
	sus.print(std::cout);
	std::cout << "\n";

	// Тест 6.1 (Подсчет высоты дерева)
	sus.insert(8);
	sus.insert(9);
	sus.print(std::cout);
	std::cout << "Tree height: " << sus.getHeight() << "\n\n";

	// Тест (Подсчёт количества узлов)
	std::cout << "Number of nodes: " << sus.getCount() << "\n\n";

	// Тест (Равенство деревьев)
	BinarySearchTree<int> ses;
	ses.insert(5);
	sus.print(std::cout);
	ses.print(std::cout);
	std::cout << "Равны ли деревья: " << ((sus == ses) ? "Да" : "Нет") << "\n";
	ses.insert(4);
	ses.insert(7);
	ses.insert(8);
	ses.insert(9);
	sus.print(std::cout);
	ses.print(std::cout);
	std::cout << "Равны ли деревья: " << ((sus == ses) ? "Да" : "Нет") << "\n";



}
