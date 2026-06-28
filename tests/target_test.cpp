#include <gtest/gtest.h>
#include <stdexcept>
#include "Target.h"
#include "TargetManager.h"

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

TEST(TargetManagerTest, AddAndFindTargetById)
{
    TargetManager manager;

    Target target(
        "T-001",
        10.0,
        20.0,
        300.0,
        TargetType::AIRCRAFT
    );

    manager.addTarget(target);

    auto found = manager.findTargetById("T-001");

    ASSERT_TRUE(found.has_value());
    EXPECT_EQ(found->getId(), "T-001");
    EXPECT_DOUBLE_EQ(found->getX(), 10.0);
    EXPECT_DOUBLE_EQ(found->getY(), 20.0);
    EXPECT_DOUBLE_EQ(found->getSpeed(), 300.0);
    EXPECT_EQ(found->getType(), TargetType::AIRCRAFT);
}

TEST(TargetManagerTest, FindTargetByIdReturnsNulloptWhenNotFound)
{
    TargetManager manager;

    auto found = manager.findTargetById("UNKNOWN");

    EXPECT_FALSE(found.has_value());
}

TEST(TargetManagerTest, GetAllTargets)
{
    TargetManager manager;

    Target target1("T-001", 10.0, 20.0, 300.0, TargetType::AIRCRAFT);
    Target target2("T-002", 30.0, 40.0, 400.0, TargetType::SHIP);

    manager.addTarget(target1);
    manager.addTarget(target2);

    auto allTargets = manager.getAllTargets();

    EXPECT_EQ(allTargets.size(), 2);
}

TEST(TargetManagerTest, RemoveTargetById)
{
    TargetManager manager;

    Target target("T-001", 10.0, 20.0, 300.0, TargetType::AIRCRAFT);
    manager.addTarget(target);

    bool removed = manager.removeTargetById("T-001");
    EXPECT_TRUE(removed);

    auto found = manager.findTargetById("T-001");
    EXPECT_FALSE(found.has_value());
}   

TEST(TargetManagerTest, RemoveTargetByIdReturnsFalseWhenNotFound)
{
    TargetManager manager;

    bool removed = manager.removeTargetById("UNKNOWN");
    EXPECT_FALSE(removed);
}

