#include <gtest/gtest.h>
#include "PriorityQueue.h"


class PriorityQueueUnitTestFixture : public ::testing::Test
{
protected:
	void SetUp() override
	{
		uut = new PriorityQueue<int>;
	}

	void TearDown() override
	{
		delete uut;
	}

	PriorityQueue<int>* uut;
};

TEST_F(PriorityQueueUnitTestFixture, IsEmpty_Ctor_QueueEmpty)
{

	EXPECT_TRUE(uut->isEmpty());
}


TEST_F(PriorityQueueUnitTestFixture, IsEmpty_Push_QueueNotEmpty)
{

	uut->push(1, PriorityQueue<int>::LOW);
	EXPECT_FALSE(uut->isEmpty());
}


TEST_F(PriorityQueueUnitTestFixture, IsEmpty_PushPop_QueueEmpty)
{

	uut->push(1, PriorityQueue<int>::LOW);
	uut->pop();
	EXPECT_TRUE(uut->isEmpty());
}

TEST_F(PriorityQueueUnitTestFixture, IsEmpty_PushPushPop_QueueNotEmpty)
{

	uut->push(1, PriorityQueue<int>::LOW);
	uut->push(2, PriorityQueue<int>::LOW);
	uut->pop();
	EXPECT_FALSE(uut->isEmpty());
}

TEST_F(PriorityQueueUnitTestFixture, IsEmpty_PushPushPop_SamePrioReturnedInFIFOOrder)
{

	uut->push(1, PriorityQueue<int>::LOW);
	uut->push(2, PriorityQueue<int>::LOW);
	int e1 = uut->front();
	uut->pop();
	int e2 = uut->front();

	EXPECT_TRUE((e1==1) && (e2 == 2));
}


TEST_F(PriorityQueueUnitTestFixture, Front_EmptyQueue_ExceptionThrown)
{
	EXPECT_THROW(
	{
	
		uut->front();
	},
	PriorityQueueException);
}

TEST_F(PriorityQueueUnitTestFixture, Front_Pushed_ElementReturned)
{

	uut->push(1, PriorityQueue<int>::LOW);

	EXPECT_TRUE(uut->front() == 1);
}


TEST_F(PriorityQueueUnitTestFixture, Front_Pushed_QueueNotEmpty)
{

	uut->push(1, PriorityQueue<int>::LOW);
	uut->front();
	EXPECT_FALSE(uut->isEmpty());
}


TEST_F(PriorityQueueUnitTestFixture, Front_LowMedPrioritiesPushed_MedPriorityElementReturned)
{

	uut->push(1, PriorityQueue<int>::LOW);
	uut->push(3, PriorityQueue<int>::MED);
	
	EXPECT_TRUE(uut->front() == 3);
}

TEST_F(PriorityQueueUnitTestFixture, Front_HighMedPrioritiesPushed_HighPriorityElementReturned)
{

	uut->push(5, PriorityQueue<int>::HIGH);
	uut->push(3, PriorityQueue<int>::MED);

	EXPECT_TRUE(uut->front() == 5);
}



TEST_F(PriorityQueueUnitTestFixture, Front_HighMedPrioritiesPushedThenOnePop_MedPriorityElementReturned)
{

	uut->push(5, PriorityQueue<int>::HIGH);
	uut->push(3, PriorityQueue<int>::MED);
	uut->pop();
	EXPECT_TRUE(uut->front() == 3);
}