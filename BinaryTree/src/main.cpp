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

	
	BinarySearchTree<int> treeCasual;
	BinarySearchTree<int> treeEmpty;
	BinarySearchTree<int> treeDegenerated;

	treeCasual.insert(5);
	treeCasual.insert(4);
	treeCasual.insert(6);
	treeCasual.insert(7);
	treeCasual.print(std::cout);

	treeEmpty.print(std::cout);

	treeDegenerated.insert(5);
	treeDegenerated.insert(10);
	treeDegenerated.insert(25);
	treeDegenerated.insert(75);
	treeDegenerated.print(std::cout);

	std::cout << "\nИтеративный обход дерева (инфиксный):\n";
	std::cout << "Сбалансированное: ";
	treeCasual.iterativeInorderWalk();
	std::cout << "\nПустое: ";
	treeEmpty.iterativeInorderWalk();
	std::cout << "\nВырожденное: ";
	treeDegenerated.iterativeInorderWalk();

	std::cout << "\n\nСравнение деревьев:\n\n";
	BinarySearchTree<int> treeEqual;
	treeEqual.insert(5);
	treeEqual.insert(4);
	treeEqual.insert(6);
	treeEqual.insert(7);
	BinarySearchTree<int> treeNotEqual;
	treeNotEqual.insert(5);
	treeNotEqual.insert(4);
	treeNotEqual.insert(7);

	std::cout << "Испытуемые:\n";
	treeCasual.print(std::cout);
	treeEqual.print(std::cout);
	std::cout << "Равны? " << ((treeCasual == treeEqual) ? "Да" : "Нет") << "\n\n";

	std::cout << "Испытуемые:\n";
	treeCasual.print(std::cout);
	treeNotEqual.print(std::cout);
	std::cout << "Равны? " << ((treeCasual == treeNotEqual) ? "Да" : "Нет") << "\n\n";

	std::cout << "Испытуемые:\n";
	treeCasual.print(std::cout);
	treeEmpty.print(std::cout);
	std::cout << "Равны? " << ((treeCasual == treeEmpty) ? "Да" : "Нет") << "\n\n";

	std::cout << "Испытуемые:\n";
	treeCasual.print(std::cout);
	treeDegenerated.print(std::cout);
	std::cout << "Равны? " << ((treeCasual == treeDegenerated) ? "Да" : "Нет") << "\n\n";
}
