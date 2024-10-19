#include "gtest/gtest.h"
#include "BinaryTree.hpp"

TEST(binTree_tests_case, isEmpty_test)
{
    BinarySearchTree<int> sus;
    EXPECT_EQ(sus.isEmpty(), 1);
}

TEST(binTree_tests_case, isNotEmpty_test)
{
    BinarySearchTree<int> sus;
	sus.insert(5);
	sus.insert(6);

    EXPECT_EQ(sus.isEmpty(), 0);
}

TEST(binTree_tests_case, print_test) // Тест "Печать дерева"
{
    BinarySearchTree<int> sus;
	sus.insert(5);
	testing::internal::CaptureStdout();
	sus.print();
	std::string zuz = testing::internal::GetCapturedStdout();

    EXPECT_EQ(zuz, "(5()())\n");
}

TEST(binTree_tests_case, binTreeRulesInsertion_test) // Тест "Вставка узла по правилам бинарного дерева"
{
    BinarySearchTree<int> sus;
	sus.insert(5);
	sus.insert(6);
	sus.insert(4);
	sus.insert(7);
	testing::internal::CaptureStdout();
	sus.print();
    std::string zuz = testing::internal::GetCapturedStdout();

    EXPECT_EQ(zuz, "(5(4()())(6()(7()())))\n");
}

TEST(binTree_tests_case, iterativeSearch_test) // Итеративный поиск узла
{
    BinarySearchTree<int> sus;
	sus.insert(5);
	sus.insert(6);
	sus.insert(4);
	sus.insert(7);

    EXPECT_EQ((sus.iterativeSearch(4))->key_, 4);
}

TEST(binTree_tests_case, recursiveSearch_test) // Рекурсивный поиск узла
{
    BinarySearchTree<int> sus;
	sus.insert(5);
	sus.insert(6);
	sus.insert(4);
	sus.insert(7);

    EXPECT_EQ((sus.recursiveSearch(sus.getRoot(), 4))->key_, 4);
}

TEST(binTree_tests_case, minmax_test)
{
    BinarySearchTree<int> sus;
	sus.insert(5);
	sus.insert(6);
	sus.insert(4);
	sus.insert(7);

    EXPECT_EQ(sus.findMinimum(sus.getRoot())->key_, 4);
    EXPECT_EQ(sus.findMaximum(sus.getRoot())->key_, 7);
}

TEST(binTree_tests_case, inorderWalk_test) // Тест на рекурсивный обход
{
    BinarySearchTree<int> sus;
	sus.insert(5);
	sus.insert(6);
	sus.insert(4);
	sus.insert(7);
	testing::internal::CaptureStdout();
	sus.inorderWalk();
	std::string zuz = testing::internal::GetCapturedStdout();

    EXPECT_EQ(zuz, "4 5 6 7\n");
}

TEST(binTree_tests_case, iterativeInorderWalk_test) // Тест на итеративный обход
{
    BinarySearchTree<int> sus;
	sus.insert(5);
	sus.insert(6);
	sus.insert(4);
	sus.insert(7);
	testing::internal::CaptureStdout();
	sus.iterativeInorderWalk();
	std::string zuz = testing::internal::GetCapturedStdout();

    EXPECT_EQ(zuz, "4 5 6 7\n");
}

TEST(binTree_tests_case, deleteKey_test)
{
    BinarySearchTree<int> sus;
	sus.insert(5);
	sus.insert(6);
	sus.insert(4);
	sus.insert(7);
	sus.deleteKey(6);
	testing::internal::CaptureStdout();
	sus.print();
	std::string zuz = testing::internal::GetCapturedStdout();

    EXPECT_EQ(zuz, "(5(4()())(7()()))\n");
}

TEST(binTree_tests_case, height_test)
{
    BinarySearchTree<int> sus;
	sus.insert(5);
	sus.insert(6);
	sus.insert(4);
	sus.insert(7);
	sus.insert(8);
	sus.insert(9);
	sus.deleteKey(6);

    EXPECT_EQ(sus.getHeight(), 3);
}

TEST(binTree_tests_case, nodesCount_test)
{
    BinarySearchTree<int> sus;
	sus.insert(5);
	sus.insert(6);
	sus.insert(4);
	sus.insert(7);
	sus.insert(8);
	sus.insert(9);
	sus.deleteKey(6);

    EXPECT_EQ(sus.getCount(), 5);
}

TEST(binTree_tests_case, equalityTrue_test)
{
    BinarySearchTree<int> sus;
	sus.insert(5);
	sus.insert(6);
	sus.insert(4);
	sus.insert(7);
	sus.insert(8);
	sus.insert(9);
	sus.deleteKey(6);
	BinarySearchTree<int> ses;
	ses.insert(5);
	ses.insert(4);
	ses.insert(7);
	ses.insert(8);
	ses.insert(9);

    EXPECT_TRUE(sus == ses);
}

TEST(binTree_tests_case, equalityFalse_test)
{
    BinarySearchTree<int> sus;
	sus.insert(5);
	sus.insert(6);
	sus.insert(4);
	sus.insert(7);
	sus.insert(8);
	sus.insert(9);
	sus.deleteKey(6);
	BinarySearchTree<int> ses;
	ses.insert(5);

    EXPECT_FALSE(sus == ses);
}

TEST(binTree_tests_case, multipleTreesIterativeInorderWalk_test)
{
	BinarySearchTree<int> treeCasual; // Сбалансированное
	BinarySearchTree<int> treeEmpty; // Пустое
	BinarySearchTree<int> treeDegenerated; // Вырожденное

	treeCasual.insert(5);
	treeCasual.insert(4);
	treeCasual.insert(6);
	treeCasual.insert(7);

	treeDegenerated.insert(5);
	treeDegenerated.insert(10);
	treeDegenerated.insert(25);
	treeDegenerated.insert(75);

	testing::internal::CaptureStdout();
	treeCasual.iterativeInorderWalk();
	std::string zuz = testing::internal::GetCapturedStdout();
	EXPECT_EQ(zuz, "4 5 6 7\n");

	testing::internal::CaptureStdout();
	treeEmpty.iterativeInorderWalk();
	zuz = testing::internal::GetCapturedStdout();
	EXPECT_EQ(zuz, "\n");

	testing::internal::CaptureStdout();
	treeDegenerated.iterativeInorderWalk();
	zuz = testing::internal::GetCapturedStdout();
	EXPECT_EQ(zuz, "5 10 25 75\n");
}
