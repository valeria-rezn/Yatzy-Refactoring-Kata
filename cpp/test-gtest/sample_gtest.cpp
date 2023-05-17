#include <gtest/gtest.h>

#include "yatzy.hpp"

using namespace std;

static int *ints(int a, int b, int c, int d, int e) {
    int *r = new int[5];
    r[0] = a;
    r[1] = b;
    r[2] = c;
    r[3] = d;
    r[4] = e;
    return r;
}

TEST(YatzyTest, ChanceScoresSumOfAllDice) {
    int expected = 15;
    int actual = Yatzy(2, 3, 4, 5, 1).Chance();
    EXPECT_EQ(expected, actual);
    EXPECT_EQ(16, Yatzy(3, 3, 4, 5, 1).Chance());
}

TEST(YatzyTest, YatzyScores50) {
    int expected = 50;
    int actual = Yatzy(4, 4, 4, 4, 4).YatzyCombo();
    EXPECT_EQ(expected, actual);
    EXPECT_EQ(50, Yatzy(6, 6, 6, 6, 6).YatzyCombo());
    EXPECT_EQ(0, Yatzy(6, 6, 6, 6, 3).YatzyCombo());
}

TEST(YatzyTest, Test_1s) {
    EXPECT_EQ(Yatzy(1, 2, 3, 4, 5).Ones(), 1);
    EXPECT_EQ(2, Yatzy(1, 2, 1, 4, 5).Ones());
    EXPECT_EQ(0, Yatzy(6, 2, 2, 4, 5).Ones());
    EXPECT_EQ(4, Yatzy(1, 2, 1, 1, 1).Ones());
}

TEST(YatzyTest, test_2s) {
    EXPECT_EQ(4, Yatzy(1, 2, 3, 2, 6).Twos());
    EXPECT_EQ(10, Yatzy(2, 2, 2, 2, 2).Twos());
}

TEST(YatzyTest, test_threes) {
    EXPECT_EQ(6, Yatzy(1, 2, 3, 2, 3).Threes());
    EXPECT_EQ(12, Yatzy(2, 3, 3, 3, 3).Threes());
}

TEST(YatzyTest, fours_test) {
    EXPECT_EQ(12, Yatzy(4, 4, 4, 5, 5).Fours());
    EXPECT_EQ(8,  Yatzy(4, 4, 5, 5, 5).Fours());
    EXPECT_EQ(4, Yatzy(4, 5, 5, 5, 5).Fours());
}

TEST(YatzyTest, fives) {
    EXPECT_EQ(10, Yatzy(4, 4, 4, 5, 5).Fives());
    EXPECT_EQ(15, Yatzy(4, 4, 5, 5, 5).Fives());
    EXPECT_EQ(20, Yatzy(4, 5, 5, 5, 5).Fives());
}

TEST(YatzyTest, sixes_test) {
    EXPECT_EQ(0, Yatzy(4, 4, 4, 5, 5).Sixes());
    EXPECT_EQ(6, Yatzy(4, 4, 6, 5, 5).Sixes());
    EXPECT_EQ(18, Yatzy(6, 5, 6, 6, 5).Sixes());
}

TEST(YatzyTest, one_pair) {
    EXPECT_EQ(6, Yatzy(3, 4, 3, 5, 6).OnePair());
    EXPECT_EQ(10, Yatzy(5, 3, 3, 3, 5).OnePair());
    EXPECT_EQ(12, Yatzy(5, 3, 6, 6, 5).OnePair());
}

TEST(YatzyTest, two_Pair) {
    EXPECT_EQ(16, Yatzy(3, 3, 5, 4, 5).TwoPair());
    EXPECT_EQ(16, Yatzy(3, 3, 5, 5, 5).TwoPair());
}

TEST(YatzyTest, three_of_a_kind) {
    EXPECT_EQ(9, Yatzy(3, 3, 3, 4, 5).ThreeOfAKind());
    EXPECT_EQ(15, Yatzy(5, 3, 5, 4, 5).ThreeOfAKind());
    EXPECT_EQ(9, Yatzy(3, 3, 3, 3, 5).ThreeOfAKind());
}

TEST(YatzyTest, four_of_a_kind) {
    EXPECT_EQ(12, Yatzy(3, 3, 3, 3, 5).FourOfAKind());
    EXPECT_EQ(20, Yatzy(5, 5, 5, 4, 5).FourOfAKind());
    EXPECT_EQ(12, Yatzy(3, 3, 3, 3, 3).FourOfAKind());
}

TEST(YatzyTest, smallStraight) {
    EXPECT_EQ(15, Yatzy(1, 2, 3, 4, 5).SmallStraight());
    EXPECT_EQ(15, Yatzy(2, 3, 4, 5, 1).SmallStraight());
    EXPECT_EQ(0, Yatzy(1, 2, 2, 4, 5).SmallStraight());
}

TEST(YatzyTest, largeStraight) {
    EXPECT_EQ(20, Yatzy(6, 2, 3, 4, 5).LargeStraight());
    EXPECT_EQ(20, Yatzy(2, 3, 4, 5, 6).LargeStraight());
    EXPECT_EQ(0, Yatzy(1, 2, 2, 4, 5).LargeStraight());
}

TEST(YatzyTest, fullHouse) {
    EXPECT_EQ(18, Yatzy(6, 2, 2, 2, 6).FullHouse());
    EXPECT_EQ(0, Yatzy(2, 3, 4, 5, 6).FullHouse());
}
