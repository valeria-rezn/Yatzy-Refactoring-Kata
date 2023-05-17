#ifndef YATZY_INCLUDED
#define YATZY_INCLUDED

class Yatzy
{
public:
    Yatzy();
    Yatzy(int d1, int d2, int d3, int d4, int _5);
    int Ones();
    int Twos();
    int Threes();
    int Fours();
    int Fives();
    int Sixes();
    void CountNumberOfPoint(int *point_array);
    int Chance();
    int YatzyCombo();
    int OnePair();
    int TwoPair();
    int ThreeOfAKind();
    int FourOfAKind();
    int SmallStraight();
    int LargeStraight();
    int FullHouse();
    
protected:
    int * dice;
};

#endif
