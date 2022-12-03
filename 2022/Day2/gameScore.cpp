#include <iostream>
using namespace std;

int moveToScore(char ch) {
    switch(ch) {
        case 'A': // Rock
        case 'X': // Rock
            return 1;
        case 'B': // Paper
        case 'Y': // Paper
            return 2;
        case 'C': // Scissors
        case 'Z': // Scissors
            return 3;
    }
    return 0;
}

inline int getMyScore(char opponent, char myself) {
    int myScore = 0;
    myScore += moveToScore(myself);
    if (opponent == 'A') { // opponent is rock
        if (myself == 'X')  myScore += 3; // match tie; rock vs rock
        else if (myself == 'Y') myScore += 6; // paper overcomes rock
        else myScore += 0; // rock defeats scissors
    } else if (opponent == 'B') { // opponent is paper
        if (myself == 'X')  myScore += 0; // paper defeats rock
        else if (myself == 'Y') myScore += 3; // tie; paper vs paper
        else myScore += 6; // scissors defeats paper
    } else { // opponent is scissors
        if (myself == 'X')  myScore += 6; // rock defeats scissors
        else if (myself == 'Y') myScore += 0; // scissors defeats paper
        else myScore += 3; // tie; scissors vs scissors
    }
    return myScore;
}

int main () {
    
    int totalScore = 0;
    char opponent, myself;

    // read opponent's move and my move
    while (cin >> opponent >> myself) {
        totalScore += getMyScore(opponent, myself);
    }
    cout << totalScore << endl;
    return 0;
}
