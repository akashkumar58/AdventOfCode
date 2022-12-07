#include <iostream>
#include <utility>
#include <set>
using namespace std;

int main() {
    // variables to denote current position of head and tail
    pair<int, int> head(0, 0);
    pair<int, int> tail(0, 0);
    // set to store the visited pos by tail
    set<pair<int, int>> visited; // = {{0, 0}};
    // variables to read the direction and steps
    char dir;
    int steps;
    // read util EOF
    while (cin >> dir >> steps) {
        for (int i = 0; i < steps; i++) {
            switch (dir) {
                case 'R':
                    head.first++;
                    break;
                case 'L':
                    head.first--;
                    break;
                case 'U':
                    head.second++;
                    break;
                case 'D':
                    head.second--;
                    break;
            }
            if (head.first > tail.first + 1) {
                tail.first++;
                if (head.second > tail.second) tail.second++;
                else if (head.second < tail.second) tail.second--;
            } else if (head.first < tail.first - 1) {
                tail.first--;
                if (head.second > tail.second) tail.second++;
                else if (head.second < tail.second) tail.second--;
            } else if (head.second > tail.second + 1) {
                tail.second++;
                if (head.first > tail.first) tail.first++;
                else if (head.first < tail.first) tail.first--;
            } else if (head.second < tail.second - 1) {
                tail.second--;
                if (head.first > tail.first) tail.first++;
                else if (head.first < tail.first) tail.first--;
            }
            visited.insert(tail);
        }
    }
    cout << visited.size() << endl;
    return 0;
}
