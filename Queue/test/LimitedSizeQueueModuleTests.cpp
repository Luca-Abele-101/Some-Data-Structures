#include "gtest/gtest.h"
#include "LimitedSizeQueue.hpp"

// Тест наполнения и опустошения очереди
TEST(limitedQueue_tests_case, pushAndPop_test)
{
    ASSERT_NO_THROW(
        {
            LimitedSizeQueue<int> sus(2);
	        sus.push(1);
	        sus.push(2);
            sus.pop();
        }
    );
}

// Тест переполнение очереди
TEST(limitedQueue_tests_case, overflowException_test)
{
    LimitedSizeQueue<int> sus(3);
	sus.push(1);
	sus.push(2);
	sus.push(3);
    EXPECT_THROW({
        try
        {
            sus.push(4);
        }
        catch( const QueueOverflow& error )
        {
            EXPECT_STREQ("Queue Overflow", error.what());
            throw;
        }
    }, QueueOverflow);
	
}

// Тест переопустошения очереди
TEST(limitedQueue_tests_case, underflowException_test)
{
    LimitedSizeQueue<int> sus(1);
	sus.push(1);
    int zuz = sus.pop();
    EXPECT_EQ(1, zuz);
    EXPECT_TRUE(sus.isEmpty());
    EXPECT_THROW({
        try
        {
            sus.pop();
        }
        catch( const QueueUnderflow& error )
        {
            EXPECT_STREQ("Queue Underflow", error.what());
            throw;
        }
    }, QueueUnderflow);
}

// Тест внутренней закольцованности массива элементов в очереди
TEST(limitedQueue_tests_case, elementsInnerCircle_test)
{
    LimitedSizeQueue<int> sus(4);
    int zuz;
	sus.push(1);
	sus.push(2);
	sus.push(3);
    ASSERT_NO_THROW({
        for (int i = 4; i <= 17; i++) // Три раза проходим массив очереди по кругу
        {
            sus.push(i);
            zuz = sus.pop();
            EXPECT_EQ(i-3, zuz);
        }
    });
}
