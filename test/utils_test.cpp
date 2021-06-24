#include "gtest/gtest.h"
#include "utils.hpp"

TEST(AnswerTest, UltimateAnswer)
{
    ASSERT_EQ(getAnswer(), 42);
}