#include "yatzy.hpp"
#include <string.h>

const int NUMBER_OF_DICES = 5;


int Yatzy::Chance()
{
    int score = 0;
    for (int dice_number = 0; dice_number < NUMBER_OF_DICES; dice_number++)
    {
        score += dice[dice_number];
    }
    return score;
}


int Yatzy::YatzyCombo()
{
    int score = 0;
    for (int dice_number = 0; dice_number < NUMBER_OF_DICES - 1; dice_number++)
    {
        if (dice[dice_number] != dice[dice_number + 1])
            return 0;
    }
    return 50;

}

int Yatzy::Ones() {
    int score = 0;
    for (int dice_number = 0; dice_number < NUMBER_OF_DICES; dice_number++)
    {
        if (dice[dice_number] == 1)
            score++;
    }
    return score;
}

int Yatzy::Twos() {
    int score = 0;
    for (int dice_number = 0; dice_number < NUMBER_OF_DICES; dice_number++)
    {
        if (dice[dice_number] == 2)
            score += 2;
    }
    return score;
}


int Yatzy::Threes() {
  
    int score = 0;
    for (int dice_number = 0; dice_number < NUMBER_OF_DICES; dice_number++)
    {
        if (dice[dice_number] == 3)
            score += 3;
    }
    return score;
}

Yatzy::Yatzy()
{
}

Yatzy::Yatzy(int d1, int d2, int d3, int d4, int d5)
{
    dice = new int[5];
    dice[0] = d1;
    dice[1] = d2;
    dice[2] = d3;
    dice[3] = d4;
    dice[4] = d5;
}

int Yatzy::Fours()
{
    int score = 0;
    for (int dice_number = 0; dice_number < NUMBER_OF_DICES; dice_number++)
    {
        if (dice[dice_number] == 4)
            score += 4;
    }
    return score;
}


int Yatzy::Fives()
{
    int score = 0;
    for (int dice_number = 0; dice_number < NUMBER_OF_DICES; dice_number++)
    {
        if (dice[dice_number] == 5)
            score += 5;
    }
    return score;
}

int Yatzy::Sixes()
{
    int score = 0;
    for (int dice_number = 0; dice_number < NUMBER_OF_DICES; dice_number++)
    {
        if (dice[dice_number] == 6)
            score += 6;
    }
    return score;
}

const int MAX_POINT = 6;

void Yatzy::CountNumberOfPoint(int *count_point) {

    for (int dice_number = 0; dice_number < NUMBER_OF_DICES; dice_number++)
    {
        count_point[dice[dice_number] - 1]++;
    }
}

int Yatzy::OnePair()
{
    int count_point[MAX_POINT] = {};
    CountNumberOfPoint(count_point);
  
    for (int dice_point = MAX_POINT-1; dice_point > 0 ; dice_point--)
    {
        if (count_point[dice_point] >= 2)
            return (dice_point+1) * 2;
    }
    return 0;
   
}

int Yatzy::TwoPair()
{
    int score = 0;
    int count_point[MAX_POINT] = {};
    int count_pair = 0;
    CountNumberOfPoint(count_point);

    for (int dice_point = MAX_POINT-1; dice_point > 0; dice_point--)
    {
        if (count_point[dice_point] >= 2) {
            count_pair++;
            score += (dice_point+1);
        }
    }
    if (count_pair == 2)
        return score * 2;
    else
        return 0;
}

int Yatzy::FourOfAKind()
{
    int count_point[MAX_POINT] = {};
    CountNumberOfPoint(count_point);
      
    for (int dice_point = 0; dice_point < MAX_POINT; dice_point++)
    {
        if (count_point[dice_point] >= 4)
            return (dice_point + 1) * 4;
    } 
    return 0;
}

int Yatzy::ThreeOfAKind()
{
    int count_point[MAX_POINT] = {};
    CountNumberOfPoint(count_point);
       
    for (int dice_point = 0; dice_point < MAX_POINT; dice_point++)
    {
        if (count_point[dice_point] >= 3)
            return (dice_point + 1) * 3;
    }
    return 0;
}


int Yatzy::SmallStraight()
{
    int count_point[MAX_POINT] = {};
    bool straight_all = true;
    CountNumberOfPoint(count_point);

    for (int dice_point = 0; dice_point < MAX_POINT-1; dice_point++)
    {
        if (count_point[dice_point] != 1)
        {
            straight_all = false;
            break;
        }
    }
    if (straight_all)
        return 15;
    else
        return 0;
}

int Yatzy::LargeStraight()
{
    
    int count_point[MAX_POINT] = {};
    bool straight_all = true;
    CountNumberOfPoint(count_point);

    for (int dice_point = 1; dice_point < MAX_POINT; dice_point++)
    {
        if (count_point[dice_point] != 1)
        {
            straight_all = false;
            break;
        }
    }
    if (straight_all)
        return 20;
    else
        return 0;
}


int Yatzy::FullHouse()
{

    int count_point[MAX_POINT] = {};
    CountNumberOfPoint(count_point);
    bool straight_two = false;
    bool straight_three = false;
    int score = 0;
    for (int dice_point = 0; dice_point < MAX_POINT; dice_point++)
    {
        if (count_point[dice_point] == 2) {
            straight_two = true;
            score += (dice_point + 1)*2;
        }
        if (count_point[dice_point] == 3) {
            straight_three = true;
            score += (dice_point + 1)*3;
        }
    }
    if (straight_two && straight_three)
        return score;
    else
        return 0;
}
