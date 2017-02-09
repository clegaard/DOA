#include <gtest/gtest.h>
#include "LLToolkit.h"
#include "Node.h"


//================================================
// Test fixture for LLToolkit
//================================================
class LLToolkitTest : public ::testing::Test
{
protected:
	LLToolkitTest()
	{
		valToInsert = 2;// In some tests, explicitly declared value to insert
						//	pointer is necessary due to strict typing in templates

		emptyList = nullptr;
		singleElementList = new Node<int>(valToInsert);

		n3 = new Node<int>(3);
		n2 = new Node<int>(2, n3);
		n1 = new Node<int>(1, n2);
	}

	~LLToolkitTest()
	{
	}


	// Test members
	LLToolkit<int> uut;
	Node<int>* emptyList;
	Node<int>* singleElementList;
	int valToInsert;


	Node<int>* n1;
	Node<int>* n2;
	Node<int>* n3;
};

TEST_F(LLToolkitTest, HeadInsert_EmptyList_HeadValueIsCorrect)
{
	Node<int>* head = nullptr;

	uut.headInsert(head, valToInsert);
	EXPECT_EQ(head->info, valToInsert);
}

TEST_F(LLToolkitTest, HeadInsert_NonEmptyList_HeadValueIsCorrect)
{
	uut.headInsert(n1, valToInsert);
	EXPECT_EQ(n1->info, valToInsert);
}


TEST_F(LLToolkitTest, HeadInsert_NonEmptyList_HeadNextCorrect)
{
	Node<int>* oldN1 = n1;
	uut.headInsert(n1, valToInsert);
	EXPECT_EQ(n1->next, oldN1);
}

TEST_F(LLToolkitTest, HeadRemove_Called_NewHeadCorrect)
{
	uut.headRemove(n1);
	EXPECT_EQ(n1, n2);
}

TEST_F(LLToolkitTest, HeadRemove_ListEmpty_NoError)
{
	uut.headRemove(emptyList);
}


TEST_F(LLToolkitTest, Insert_PrevPtrnullptr_NoError)
{
	uut.insert(emptyList, valToInsert);
}


TEST_F(LLToolkitTest, Insert_MiddleOfList_InsertedValCorrect)
{
	uut.insert(n1, valToInsert);
	EXPECT_EQ(n1->next->info, valToInsert);
	
}


TEST_F(LLToolkitTest, Insert_MiddleOfList_ListReconnected)
{
	uut.insert(n1, valToInsert);

	EXPECT_EQ(n1->next->next, n2);
}

TEST_F(LLToolkitTest, Insert_EndOfList_InsertedValCorrect)
{
	uut.insert(n3, valToInsert);
	EXPECT_EQ(n3->next->info, valToInsert);
}

TEST_F(LLToolkitTest, Insert_EndOfList_ListReconnedted)
{
	uut.insert(n3, valToInsert);
	EXPECT_EQ(n3->next->next, nullptr);
}


TEST_F(LLToolkitTest, Remove_PrevPtrNull_NoError)
{
	uut.remove(emptyList);
}


TEST_F(LLToolkitTest, Remove_MiddleOfList_ListReconnected)
{
	uut.remove(n1);
	EXPECT_EQ(n1->next, n3);
}

TEST_F(LLToolkitTest, Remove_EndOfList_NoError)
{
	uut.remove(n3);
	//EXPECT_EQ(n2->next, n3);
}

TEST_F(LLToolkitTest, Copy_EmptyList_NoError)
{
	Node<int>* result = uut.copy(emptyList);
	EXPECT_EQ(result, emptyList);
}

TEST_F(LLToolkitTest, Copy_NonEmptyList_ResultIsCopyOfSource)
{
	Node<int>* result = uut.copy(n1);

	bool testResult = (
		(result->info == n1->info) &&
		(result->next->info == n2->info) &&
		(result->next->next->info == n3->info));

	EXPECT_TRUE(testResult);
}

TEST_F(LLToolkitTest, Copy_NonEmptyList_ResultIsDeepCopyOfSource)
{
	Node<int>* result = uut.copy(n1);
	n1->info = 4;
	n1->next->info = 5;
	n1->next->next->info = 6;

	bool testResult = (
		(result->info == 1) &&
		(result->next->info == 2) &&
		(result->next->next->info == 3));

	EXPECT_TRUE(testResult);
}
