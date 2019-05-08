#include <iterator> // begin(), end()

#include "gtest/gtest.h"
#include "../include/int_ranges.h"

using namespace ir;

// TEST negate
TEST(IntRange, NegateBasic)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5 };
    ir::value_type A_E[]{ -1, -2, -3, -4, -5 };

    auto len_before{ std::distance( std::begin(A), std::end(A) ) };
    ir::negate( std::begin(A), std::end(A) );
    auto len_after{ std::distance( std::begin(A), std::end(A) ) };
    ASSERT_EQ( len_before, len_after );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(IntRange, NegateZeros)
{
    ir::value_type A[]{ 0, 0, 0, 0, 0 };
    ir::value_type A_E[]{ 0, 0, 0, 0, 0 };

    auto len_before{ std::distance( std::begin(A), std::end(A) ) };
    ir::negate( std::begin(A), std::end(A) );
    auto len_after{ std::distance( std::begin(A), std::end(A) ) };
    ASSERT_EQ( len_before, len_after );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}
TEST(IntRange, NegateMixed)
{
    ir::value_type A[]{ 0, -2, 1, -3, 0 };
    ir::value_type A_E[]{ 0, 2, -1, 3, 0 };

    auto len_before{ std::distance( std::begin(A), std::end(A) ) };
    ir::negate( std::begin(A), std::end(A) );
    auto len_after{ std::distance( std::begin(A), std::end(A) ) };
    ASSERT_EQ( len_before, len_after );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

// TEST min
TEST(IntRange, MinBasic)
{
    ir::value_type A[]{ 1, 2, -3, 4, 0 };

    auto result = ir::min( std::begin(A), std::end(A) );
    ASSERT_EQ( result , std::begin(A)+2 );
}
TEST(IntRange, MinFirstOcurrence)
{
    ir::value_type A[]{ 1, 1, 1, 1, 1 };

    auto result = ir::min( std::begin(A), std::end(A) );
    ASSERT_EQ( result , std::begin(A) );
}

// TEST reverse
TEST(IntRange, ReverseEntireArratyEven)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
    ir::value_type A_E[]{ 6, 5, 4, 3, 2, 1 };

    ir::reverse( std::begin(A), std::end(A) );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}
TEST(IntRange, ReverseEntireArratyOdd)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5 };
    ir::value_type A_E[]{ 5, 4, 3, 2, 1 };

    ir::reverse( std::begin(A), std::end(A) );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}
TEST(IntRange, ReversePartOfArrayEven)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5, 6, 7 };
    ir::value_type A_E[]{ 1, 2, 6, 5, 4, 3, 7 };

    ir::reverse( std::begin(A)+2, std::begin(A)+6 );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}
TEST(IntRange, ReversePartOfArrayOdd)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5, 6, 7 };
    ir::value_type A_E[]{ 1, 6, 5, 4, 3, 2, 7 };

    ir::reverse( std::begin(A)+1, std::begin(A)+6 );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

// TEST scalar_multiplication
TEST(IntRange, ScalarMultiplicationBasic)
{
    ir::value_type A[]{1, 2, 3, 4, 5, 6};
    ir::value_type A_E[]{2, 4, 6, 8, 10, 12};

    ir::scalar_multiplication(std::begin(A), std::end(A), 2);
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}
TEST(IntRange, ScalarMultiplicationZeros)
{
    ir::value_type A[]{ 0, 0, 0, 0, 0 };
    ir::value_type A_E[]{ 0, 0, 0, 0, 0 };

    ir::scalar_multiplication(std::begin(A), std::end(A), 3);
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}
TEST(IntRange, ScalarMultiplicationWithNegative)
{
    ir::value_type A[]{1, 2, -3, -4, 5, -6};
    ir::value_type A_E[]{3, 6, -9, -12, 15, -18};

    ir::scalar_multiplication(std::begin(A), std::end(A), 3);
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}
TEST(IntRange, ScalarMultiplicationHalf)
{
    ir::value_type A[]{1, 2, -3, -4, 5, -6};
    ir::value_type A_E[]{1, 2, -6, -8, 10, -12};

    ir::scalar_multiplication(std::begin(A)+2, std::end(A), 2);
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}
TEST(IntRange, ScalarMultiplicationZero)
{
    ir::value_type A[]{ 6, -5, 4, 3, -1};
    ir::value_type A_E[]{0, 0, 0, 0, 0};

    ir::scalar_multiplication(std::begin(A), std::end(A), 0);
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

// TEST dot_product
TEST(IntRange, DotProductBasic)
{
    ir::value_type A[]{1, 2, -1, -2, 3, 5};

    auto result = ir::dot_product(std::begin(A), std::begin(A)+3, std::begin(A)+3);
    ASSERT_EQ( result , -1 );
}

// TEST equal
TEST(IntRange, CompactBasic)
{
    ir::value_type A[]{-4, -5, 8, 2, -1, 6};
    ir::value_type A_E[]{8, 2, 6};

    auto result = ir::compact(std::begin(A), std::end(A));
    ASSERT_TRUE(std::equal(std::begin(A), result, std::begin(A_E)));
}

// TEST copy
TEST(IntRange, CopyBasic)
{
    ir::value_type A[]{1, 2, 3, 4, 5};
    ir::value_type B[]{0, 0, 0};
    ir::value_type A_E[]{1, 2, 3};

    auto result = ir::copy(std::begin(A), std::begin(A)+3, std::begin(B));
    ASSERT_TRUE(std::equal(std::begin(B), result, std::begin(A_E)));
}
TEST(IntRange, CopyPieceFromBegin)
{
    ir::value_type A[]{1, 2, 3, 4, 5};
    ir::value_type B[]{0, 0, 0};
    ir::value_type A_E[]{1, 2, 3};

    auto result = ir::copy(std::begin(A), std::begin(A)+3, std::begin(B));
    ASSERT_TRUE(std::equal(std::begin(B), result, std::begin(A_E)));
}
TEST(IntRange, CopyPieceInTheMiddle)
{
    ir::value_type A[]{8, -2, 5, 3, -1, 10};
    ir::value_type B[]{0, 0, 0, 0, 0, 0};
    ir::value_type A_E[]{-2, 5, 3, -1};

    auto result = ir::copy(std::begin(A)+1, std::begin(A)+5, std::begin(B));
    ASSERT_TRUE(std::equal(std::begin(B), result, std::begin(A_E)));
}

// TEST unique
TEST(IntRange, UniqueBasic)
{
    ir::value_type A[]{1, 2, 2, 3, 4, 1, 5, 5, 3, 4, 6};
    ir::value_type A_E[]{1, 2, 3, 4, 5, 6};

    auto result = ir::unique(std::begin(A), std::end(A));
    ASSERT_TRUE(std::equal(std::begin(A), result, std::begin(A_E)));
}
TEST(IntRange, UniqueZeroAndOne)
{
    ir::value_type A[]{1, 0, 1, 1, 0, 0, 0, 1, 1};
    ir::value_type A_E[]{1, 0};

    auto result = ir::unique(std::begin(A), std::end(A));
    ASSERT_TRUE(std::equal(std::begin(A), result, std::begin(A_E)));
}

// TEST sort_marbles
TEST(IntRange, SortMarblesBasic)
{
    ir::value_type A[]{1, 0, 0, 1, 1, 0, 1};
    ir::value_type A_E[]{0, 0, 0};

    auto result = ir::sort_marbles(std::begin(A), std::end(A));
    ASSERT_TRUE(std::equal(std::begin(A), result, std::begin(A_E)));
}
TEST(IntRange, SortMarblesWhite)
{
    ir::value_type A[]{1, 1, 1, 1};

    auto result = ir::sort_marbles(std::begin(A), std::end(A));
    ASSERT_EQ(std::end(A), result);
}
TEST(IntRange, SortMarblesBlack)
{
    ir::value_type A[]{0, 0, 0, 0};

    auto result = ir::sort_marbles(std::begin(A), std::end(A));
    ASSERT_EQ(std::begin(A), result);
}

// TEST partition
TEST(IntRange, PartitionBasic)
{
    ir::value_type A[]{ 5, 1, 3, 4, 9, 8, 7, 0, 2, 6};
    ir::value_type A_E[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    partition(std::begin(A), std::end(A), nullptr);
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}
TEST(IntRange, PartitionSameNumberTwice)
{
    ir::value_type A[]{9, 8, 7, 6, 5, 7, 4, 3};
    ir::value_type A_E[]{3, 4, 5, 6, 7, 7, 8, 9};

    partition(std::begin(A), std::end(A), nullptr);
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}
TEST(IntRange, PartitionWithNegative)
{
    ir::value_type A[]{ -1, 0, 8, 4, -3, -3};
    ir::value_type A_E[]{-3, -3, -1, 0, 4, 8};

    partition(std::begin(A), std::end(A), nullptr);
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

// TEST rotate
TEST(IntRange, RotateBasic_0_moves)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
    ir::value_type A_E[]{ 1, 2, 3, 4, 5, 6 };

    rotate(std::begin(A), std::begin(A), std::end(A));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}
TEST(IntRange, RotateBasic_1_moves)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
    ir::value_type A_E[]{ 2, 3, 4, 5, 6, 1 };

    rotate(std::begin(A), std::begin(A)+1, std::end(A));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}
TEST(IntRange, RotateBasic_2_moves)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
    ir::value_type A_E[]{ 3, 4, 5, 6, 1, 2 };

    rotate(std::begin(A), std::begin(A)+2, std::end(A));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}
TEST(IntRange, RotateBasic_3_moves)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
    ir::value_type A_E[]{ 4, 5, 6, 1, 2, 3 };

    rotate(std::begin(A), std::begin(A)+3, std::end(A));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}
TEST(IntRange, RotateBasic_4_moves)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
    ir::value_type A_E[]{ 5, 6, 1, 2, 3, 4 };

    rotate(std::begin(A), std::begin(A)+4, std::end(A));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}
TEST(IntRange, RotateBasic_5_moves)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
    ir::value_type A_E[]{ 6, 1, 2, 3, 4, 5 };

    rotate(std::begin(A), std::begin(A)+5, std::end(A));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
