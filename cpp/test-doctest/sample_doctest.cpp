#include "ApprovalTests.hpp"
#include "doctest/doctest.h"

#include "yatzy.hpp"

static int *ints(int a, int b, int c, int d, int e) {
    int *r = new int[5];
    r[0] = a;
    r[1] = b;
    r[2] = c;
    r[3] = d;
    r[4] = e;
    return r;
}

TEST_CASE ("Sample") {
    SUBCASE("Chance scores sum of all dice") {
        int expected = 15;
        int actual = Yatzy(2, 3, 4, 5, 1).Chance();
        CHECK(expected == actual);
        CHECK(16 == Yatzy(3, 3, 4, 5, 1).Chance());
    }SUBCASE("Yatzy scores 50") {
        int expected = 50;
        int actual = Yatzy(4, 4, 4, 4, 4).YatzyCombo();
        CHECK(expected == actual);
        CHECK(50 == Yatzy(6, 6, 6, 6, 6).YatzyCombo());
        CHECK(0 == Yatzy(6, 6, 6, 6, 3).YatzyCombo());
    }SUBCASE("Test 1s") {
        CHECK(Yatzy(1, 2, 3, 4, 5).Ones() == 1);
        CHECK(2 == Yatzy(1, 2, 1, 4, 5).Ones());
        CHECK(0 == Yatzy(6, 2, 2, 4, 5).Ones());
        CHECK(4 == Yatzy(1, 2, 1, 1, 1).Ones());
    }SUBCASE("test 2s") {
        CHECK(4 == Yatzy(1, 2, 3, 2, 6).Twos());
        CHECK(10 == Yatzy(2, 2, 2, 2, 2).Twos());
    }
    SUBCASE("test threes") {
        CHECK(6 == Yatzy(1, 2, 3, 2, 3).Threes());
        CHECK(12 == Yatzy(2, 3, 3, 3, 3).Threes());
    }SUBCASE("fours test") {
        CHECK(12 == Yatzy(4, 4, 4, 5, 5).Fours());
        CHECK(8 == Yatzy(4, 4, 5, 5, 5).Fours());
        CHECK(4 == Yatzy(4, 5, 5, 5, 5).Fours());
    } SUBCASE("fives") {
        CHECK(10 == Yatzy(4, 4, 4, 5, 5).Fives());
        CHECK(15 == Yatzy(4, 4, 5, 5, 5).Fives());
        CHECK(20 == Yatzy(4, 5, 5, 5, 5).Fives());
    }SUBCASE("sixes test") {
        CHECK(0 == Yatzy(4, 4, 4, 5, 5).Sixes());
        CHECK(6 == Yatzy(4, 4, 6, 5, 5).Sixes());
        CHECK(18 == Yatzy(6, 5, 6, 6, 5).Sixes());
    }SUBCASE("one pair") {
        CHECK(6 == Yatzy(3, 4, 3, 5, 6).OnePair());
        CHECK(10 == Yatzy(5, 3, 3, 3, 5).OnePair());
        CHECK(12 == Yatzy(5, 3, 6, 6, 5).OnePair());
    } SUBCASE("two Pair") {
        CHECK(16 == Yatzy(3, 3, 5, 4, 5).TwoPair());
        CHECK(16 == Yatzy(3, 3, 5, 5, 5).TwoPair());
    }
    SUBCASE("three of a kind") {
        CHECK(9 == Yatzy(3, 3, 3, 4, 5).ThreeOfAKind());
        CHECK(15 == Yatzy(5, 3, 5, 4, 5).ThreeOfAKind());
        CHECK(9 == Yatzy(3, 3, 3, 3, 5).ThreeOfAKind());
    }SUBCASE("four of a kind") {
        CHECK(12 == Yatzy(3, 3, 3, 3, 5).FourOfAKind());
        CHECK(20 == Yatzy(5, 5, 5, 4, 5).FourOfAKind());
        CHECK(12 == Yatzy(3, 3, 3, 3, 3).FourOfAKind());
    } SUBCASE("smallStraight") {
        CHECK(15 == Yatzy(1, 2, 3, 4, 5).SmallStraight());
        CHECK(15 == Yatzy(2, 3, 4, 5, 1).SmallStraight());
        CHECK(0 == Yatzy(1, 2, 2, 4, 5).SmallStraight());
    }SUBCASE("largeStraight") {
        CHECK(20 == Yatzy(6, 2, 3, 4, 5).LargeStraight());
        CHECK(20 == Yatzy(2, 3, 4, 5, 6).LargeStraight());
        CHECK(0 == Yatzy(1, 2, 2, 4, 5).LargeStraight());
    } SUBCASE("fullHouse") {
        CHECK(18 == Yatzy(6, 2, 2, 2, 6).FullHouse());
        CHECK(0 == Yatzy(2, 3, 4, 5, 6).FullHouse());
    }
}


