#include <gtest/gtest.h>
#include "fibonacci.h"

TEST(FibonacciTest, HandlesZero) {
    EXPECT_EQ(fibonacci(0), 0);
}

TEST(FibonacciTest, HandlesOne) {
    EXPECT_EQ(fibonacci(1), 1);
}

TEST(FibonacciTest, HandlesTwo) {
    EXPECT_EQ(fibonacci(2), 1);
}

TEST(FibonacciTest, HandlesNegative) {
    EXPECT_THROW(fibonacci(-1), std::invalid_argument);
}

TEST(FibonacciTest, HandlesLargeNumber) {
    EXPECT_EQ(fibonacci(10), 55);
    EXPECT_EQ(fibonacci(20), 6765);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
