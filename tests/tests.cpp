#include "gtest/gtest.h"
#include "foo.hpp"

TEST(FooTests, CheckGreeting)
{
	EXPECT_EQ(GetGreeting(), "Hello");
}
