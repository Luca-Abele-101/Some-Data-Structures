#ifndef __BINARY_SEARCH_TREE_HPP
#define __BINARY_SEARCH_TREE_HPP

#include <iostream>
#include <stack>
#include <vector>

template <class T>
class BinarySearchTree
{
public:
	template <class N>
	struct Node
	{
		N  key_;
		Node<N>* left_;
		Node<N>* right_;
		Node<N>* p_;

		Node(N key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) :
			key_(key), left_(left), right_(right), p_(p)
		{  }
	};

	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree<T>& scr) = delete;
	BinarySearchTree(BinarySearchTree<T>&& src);

	BinarySearchTree <T>& operator= (const BinarySearchTree <T>& src) = delete;
	BinarySearchTree<T>& operator= (BinarySearchTree<T>&& src);
	bool operator== (const BinarySearchTree<T>& src);

	virtual ~BinarySearchTree();

	Node<T>* iterativeSearch(const T& key) const;
	Node<T>* recursiveSearch(Node<T>* x, const T& key) const;
	Node<T>* findMinimum(Node<T>* subtree) const;
	Node<T>* findMaximum(Node<T>* subtree) const;
	Node<T>* getRoot() const;

	bool insert(const T& key);
	bool deleteKey(const T& key);
	void print(std::ostream& out = std::cout) const;
	int getCount() const;
	int getHeight() const;
	bool isEmpty();

	// Инфиксный обход дерева (итеративный)
	void iterativeInorderWalk(std::ostream& out = std::cout) const;
	// Инфиксный обход дерева (рекурсивный)
	void inorderWalk(std::ostream& out = std::cout) const;

private:
	Node<T>* root_;

	bool insertNode(Node<T>* key, Node<T>* start);
	void swap(BinarySearchTree <T>& left, BinarySearchTree <T>& right);
	void deleteSubtree(Node<T>* node);
	void printNode(std::ostream& out, Node<T>* root) const;
	int getCountSubTree(const Node<T>* node) const;

	// Рекурсивная функция определения высоты дерева
	int getHeightSubTree(Node<T>* node) const;
	Node<T>* findMinimumNode(Node<T>* subtree) const;
	Node<T>* findMaximumNode(Node<T>* subtree) const;
	Node<T>* iterativeSearchNode(const T& key) const;
	Node<T>* recursiveSearchNode(Node<T>* x, const T& key) const;
	void inorderWalk(Node<T>* node, std::ostream& out) const;
	void iterativeInorderWalk(Node<T>* node, std::ostream& out) const;
};

#include "BinaryTree.tpp"

#endif
