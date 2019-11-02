#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix Check);
}

TEST(TPostfix, created_postfix_is_empty)
{
	TPostfix Check;

	EXPECT_EQ("", Check.GetInfix());
	EXPECT_EQ("", Check.GetPostfix());
}

TEST(TPostfix, can_create_copied_postfix)
{
	TPostfix Check("a + b*c / (e-f)");

	EXPECT_EQ("a + b*c / (e-f)", Check.GetInfix());
	EXPECT_EQ("", Check.GetPostfix());
}

TEST(TPostfix, throws_when_convert_empty_infix)
{
	TPostfix Check;
	ASSERT_ANY_THROW(Check.ToPostfix());
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
	string Expect = "ab+cd*-";
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

TEST(TPostfix, throws_when_there_is_no_operator)
{
	TPostfix Check("12345");
	Check.ToPostfix();

	ASSERT_ANY_THROW(Check.Calculate());
}

TEST(TPostfix, throws_when_there_is_no_operand)
{
	TPostfix Check("+");

	ASSERT_ANY_THROW(Check.Calculate());
}


