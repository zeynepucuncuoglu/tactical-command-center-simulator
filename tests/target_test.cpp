#include <gtest/gtest.h>
#include <stdexcept>
#include "Target.h"

TEST(TargetTest, ConstructorHappyPath) {
    Target target("1", 100.5, 200.0, 0.0, TargetType::UNKNOWN);

    EXPECT_EQ(target.getId(), "1");
    EXPECT_DOUBLE_EQ(target.getX(), 100.5);
    EXPECT_DOUBLE_EQ(target.getY(), 200.0);
    EXPECT_DOUBLE_EQ(target.getSpeed(), 0.0);
    EXPECT_EQ(target.getType(), TargetType::UNKNOWN);
}

TEST(TargetTest, ConstructorThrowsWhenIdIsEmpty)
{
    EXPECT_THROW(
        Target("", 10.0, 20.0, 100.0, TargetType::AIRCRAFT),
        std::invalid_argument
    );
}