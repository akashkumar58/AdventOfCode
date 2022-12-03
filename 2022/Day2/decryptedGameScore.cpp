#include <iostream>
using namespace std;

inline int myScore(char opponent, char clue) {
    int score = 0;
    if (clue == 'X') { // I need to lose
        if (opponent == 'A') score += 3; // rock defeats scissors, so I choose scissors = 3
        else if (opponent == 'B') score += 1; // paper defeats rock, so I choose rock = 1
        else score += 2; // scisccor defetas paper, so I choose paper = 2

        // I need to lose the game so I get 0 points at the end.

    } else if (clue == 'Y') { // I need to draw
        score += opponent == 'A' ? 1 : (opponent == 'B' ? 2 : 3); // whatever opponent chooses, I choose the same;
        // I need to draw so I get default point of 3
        score += 3;
    } else { // I need to win
        if (opponent == 'A') score += 2; // paper defeats rock, so I choose paper = 2
        else if (opponent == 'B') score += 3; // scissors defeats paper, so I choose scissors = 3
        else score += 1; // rock defeats, so I choose rock = 1
        // I need to win so I get default point of 6.
        score += 6;
    }
    return score;
}

int main () {
    
    int totalScore = 0;
    char opponent, myself;

    while (cin >> opponent >> myself) {
        totalScore += myScore(opponent, myself);
    }
    cout << totalScore << endl;
    return 0;
}
