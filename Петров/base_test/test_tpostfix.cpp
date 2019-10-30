#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix p);
}

TEST(TPostfix, can_create_copied_postfix)
{
	TPostfix Check("a + b*c / (e-f)");

	EXPECT_EQ("a + b*c / (e-f)", Check.GetInfix());
}

TEST(TPostfix, can_convert_to_postfix_1)
{
	string Expect = "abc*+";
	TPostfix Check("a + b*c");

	string Result;
	Result = Check.ToPostfix();

	EXPECT_EQ(Expect, Result);
}

TEST(TPostfix, can_convert_to_postfix_2)
{
	string Expect = "abcd*-+";
	TPostfix Check("a + b - c * d");

	string Result;
	Result = Check.ToPostfix();

	EXPECT_EQ(Expect, Result);
}

TEST(TPostfix, can_convert_to_postfix_3)
{
	string Expect = "abc+*d+e/";
	TPostfix Check("(a * (b + c) + d) / e");

	string Result;
	Result = Check.ToPostfix();

	EXPECT_EQ(Expect, Result);
}

TEST(TPostfix, cant_convert_to_postfix_1)
{
	TPostfix Check("(a *+ (b + c) + d) / e");

	ASSERT_ANY_THROW(Check.ToPostfix());
}

TEST(TPostfix, cant_convert_to_postfix_2)
{
	TPostfix Check("(a * () + d) / e");

	ASSERT_ANY_THROW(Check.ToPostfix());
}

TEST(TPostfix, can_calculate_postfix)
{
	TPostfix Check("1 + 2*3 / (2-0)");

	Check.ToPostfix();
	double Result = Check.Calculate();

	EXPECT_EQ(4 , Result);
}


