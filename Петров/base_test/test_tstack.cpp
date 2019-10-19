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

TEST(TStack, stack_is_not_really_empty)
{
	ADD_FAILURE();
}

TEST(TStack, stack_is_really_empty)
{
	TStack<int> testStack(10);

	EXPECT_EQ(true, testStack.empty());
}

TEST(TStack, can_put_element)
{
	TStack<int> testStack(10);

	int elem = 5;
	ASSERT_NO_THROW(testStack.push(elem));

}

TEST(TStack, cant_put_element_when_stack_is_full)
{
	ADD_FAILURE();
}

TEST(TStack, can_get_element)
{
	ADD_FAILURE();
}

TEST(TStack, cant_get_element_when_stack_is_empty)
{

}