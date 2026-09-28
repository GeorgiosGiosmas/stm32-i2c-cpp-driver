#include <gtest/gtest.h>
#include "drv/ticks.hpp"

TEST(DemoGroupTest, DemoTestNormalCase){

    EXPECT_EQ(elapsed_ticks(100, 400), 300);
}

TEST(DemoGroupTest, DemoTestSameValue){

    EXPECT_EQ(elapsed_ticks(100, 100), 0);
}

TEST(DemoGroupTest, DemoTestWrapAround){

    EXPECT_EQ(elapsed_ticks(0xFFFFFFF0, 0x00000010), 32);
}
