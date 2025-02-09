#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> st(-5));
}

TEST(TStack, cant_create_too_large_stack)
{
	ASSERT_ANY_THROW(TStack<int> st(MaxStackSize + 1));
}

TEST(TStack, created_stack_is_empty)
{
	TStack<int> testStack(3);

	EXPECT_EQ(true, testStack.empty());
}

TEST(TStack, throws_when_pop_from_empty)
{
	TStack<int> testStack(3);

	ASSERT_ANY_THROW(testStack.pop());
}

TEST(TStack, can_push_element)
{
	TStack<int> testStack(3);
	int elem = 5;

	testStack.push(elem);

	EXPECT_EQ(false, testStack.empty());
}

TEST(TStack, can_pop_element)
{
	TStack<int> testStack(3);
	int elem = 5;

	testStack.push(elem);

	EXPECT_EQ(elem, testStack.pop());
}

TEST(TStack, stack_is_really_full)
{
	TStack<int> testStack(1);
	testStack.push(1);

	EXPECT_EQ(true, testStack.full());
}

TEST(TStack, throws_when_push_full_stack)
{
	TStack<int> testStack(3);
	testStack.push(1);
	testStack.push(1);
	testStack.push(1);

	ASSERT_ANY_THROW(testStack.push(1));
}