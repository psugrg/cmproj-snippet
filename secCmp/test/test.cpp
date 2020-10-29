#include <gtest/gtest.h>

#include "Example.hpp"

class ReverseTests : public ::testing::Test
{
};

TEST_F(ReverseTests, simple)
{
  example::Example e = example::Example(10);

  EXPECT_EQ(e.getA(), 10);
}

TEST_F(ReverseTests, simple_fail)
{
  example::Example e = example::Example(10);

  EXPECT_EQ(e.getA(), 1);
}
