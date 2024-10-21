#include "gtest/gtest.h"
#include "bracketsOperations.hpp"

TEST(limitedStackBrackets_tests_case, simpleBrackets_test)
{
    const char* test1 = "( ) must be OK";
    EXPECT_TRUE(checkBalanceBrackets(test1));
}

TEST(limitedStackBrackets_tests_case, complexBrackets_test)
{
    const char* test2 = "( {} ( [] ) [] ) must be OK";
    EXPECT_TRUE(checkBalanceBrackets(test2));
}

TEST(limitedStackBrackets_tests_case, extraOpeningBrackets_test)
{
    const char* test3 = "( ( [ ] ) ";
    EXPECT_FALSE(checkBalanceBrackets(test3));
}

TEST(limitedStackBrackets_tests_case, extraClosingBrackets_test)
{
    const char* test4 = "( [ ] ) ) extra closing bracket";
    EXPECT_FALSE(checkBalanceBrackets(test4));
}

TEST(limitedStackBrackets_tests_case, differentTypesOfBrackets_test)
{
    const char* test5 = "( { ] )  different types of brackets";
    EXPECT_FALSE(checkBalanceBrackets(test5));
}

TEST(limitedStackBrackets_tests_case, closingBracketsBeforeOpeningBrackets_test)
{
    const char* test6 = ") ) ( ) closing brackets before opening brackets";
    EXPECT_FALSE(checkBalanceBrackets(test6));
}

TEST(limitedStackInfixToPostfix_tests_case, postfix7_test)
{
    const char* test7 = "(A+B)*(C+D)-E*F*G+H/I";
    std::string post7 = "";
    EXPECT_TRUE(getPostfixFromInfix(test7, post7));
    EXPECT_EQ(post7, "AB+CD+*EF*G*-HI/+");
}

TEST(limitedStackInfixToPostfix_tests_case, postfix8_test)
{
    const char* test8 = "A*(B+C)/D*(E+F)";
    std::string post8 = "";
    EXPECT_TRUE(getPostfixFromInfix(test8, post8));
    EXPECT_EQ(post8, "ABC+*D/EF+*");
}

TEST(limitedStackInfixToPostfix_tests_case, postfix9_test)
{
    const char* test9 = "A*(B+C)/(D*(E+F))";
    std::string post9 = "";
    EXPECT_TRUE(getPostfixFromInfix(test9, post9));
    EXPECT_EQ(post9, "ABC+*DEF+*/");
}

TEST(limitedStackInfixToPostfix_tests_case, postfix10_test)
{
    const char* test10 = "A+[B+C]*D-";
    std::string post10 = "";
    EXPECT_FALSE(getPostfixFromInfix(test10, post10));
}

TEST(limitedStackInfixToPostfix_tests_case, postfix11_test)
{
    const char* test11 = "(A-B";
    std::string post11 = "";
    EXPECT_FALSE(getPostfixFromInfix(test11, post11));
}

TEST(calculatingPostfix_tests_case, postfix12_test)
{
    const char* test12 = "7+3*5-6";
    int post12 = evaluatePostfix(test12);
    EXPECT_EQ(16, post12);
}

TEST(calculatingPostfix_tests_case, postfix13_test)
{
    const char* test13 = "2*(7+3)/(8-3)*2";
    int post13 = evaluatePostfix(test13);
    EXPECT_EQ(8, post13);
}

TEST(calculatingPostfix_tests_case, postfix14_test)
{
    const char* test14 = "2*(7+3)/((8-3)*2)";
    int post14 = evaluatePostfix(test14);
    EXPECT_EQ(2, post14);
}

TEST(calculatingPostfix_tests_case, postfix15_test)
{
    const char* test15 = ")+5*[(**/)";
    EXPECT_THROW(evaluatePostfix(test15), EvaluatingPostfixException);
}
