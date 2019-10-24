#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix p);
}

TEST(TPostfix, can_create_postfix_copy)
{
	TPostfix Check("a + b*c / (e-f)");

	EXPECT_EQ("a + b*c / (e-f)", Check.GetInfix());
}

TEST(TPostfix, can_convert_to_postfix)
{
	string Expect = "abc*+";

	TPostfix Check("a + b*c");

	string Result;
	Result = Check.ToPostfix();

	EXPECT_EQ(Expect, Result);
}

/* TEST(TPostfix, can_calculate_postfix)
{
	TPostfix Check("a + b*c / (e-f)");

	Check.ToPostfix();
	double Result = Check.Calculate();

	EXPECT_EQ(7 , Result);
} */


