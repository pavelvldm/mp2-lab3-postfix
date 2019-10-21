#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix p);
}

TEST(TPostfix, can_convert_to_postfix_1)
{
	TPostfix Check("a+b*c");

	EXPECT_EQ("abc*+", Check.ToPostfix());
}

TEST(TPostfix, can_convert_to_postfix_2)
{
	TPostfix Check("a+b-c*d");

	EXPECT_EQ("abcd*-+", Check.ToPostfix());
}

