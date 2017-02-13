#include <gtest/gtest.h>
#include "Queue.h"

class QueueUnitTestFixture : public ::testing::Test
{
protected:
	void SetUp() override
	{
		uut = new Queue<int>;
	}

	void TearDown() override
	{
		delete uut;
	}

	Queue<int>* uut;
};

TEST_F(QueueUnitTestFixture, Ctor_Ctor_QueueEmpty)
{
	EXPECT_TRUE(uut->isEmpty());
}

TEST_F(QueueUnitTestFixture, Ctor_Push_QueueNotEmpty)
{
	uut->push(1);
	EXPECT_FALSE(uut->isEmpty());
}

TEST_F(QueueUnitTestFixture, PushPop_PushPop_QueueEmpty)
{
	uut->push(1);
	uut->pop();
	EXPECT_TRUE(uut->isEmpty());
}

TEST_F(QueueUnitTestFixture, PushPop_PushTimes2Pop_QueueNotEmpty)
{
	uut->push(1);
	uut->push(1);
	uut->pop();
	EXPECT_FALSE(uut->isEmpty());
}

TEST_F(QueueUnitTestFixture, Front_EmptyQueue_ExceptionThrown)
{
	EXPECT_THROW(
	{
		uut->front();
	}, QueueException);
}


TEST_F(QueueUnitTestFixture, Front_PushTimes3_FrontIsCorrect)
{
	uut->push(1);
	uut->push(2);
	uut->push(3);

	EXPECT_EQ(uut->front(), 1);
}

TEST_F(QueueUnitTestFixture, Front_PushTimes3Frontx2_FrontIsCorrect)
{
	uut->push(1);
	uut->push(2);
	uut->push(3);
	uut->front();

	EXPECT_EQ(uut->front(), 1);
}

TEST_F(QueueUnitTestFixture, Ctor_PushTimes3Pop_FrontIsCorrect)
{
	uut->push(1);
	uut->push(2);
	uut->push(3);
	uut->pop();

	EXPECT_EQ(uut->front(), 2);
}



TEST_F(QueueUnitTestFixture, Ctor_PushTimes3PopTimes2_FrontIsCorrect)
{
	uut->push(1);
	uut->push(2);
	uut->push(3);
	uut->pop();
	uut->pop();

	EXPECT_EQ(uut->front(), 3);
}