#include <iostream>
#include <utility>
#include <vector>
#include <set>
using namespace std;

int main() {
    // Rope with length 10 where 0 is head and 9 is tail
    vector<pair<int,int>> rope(10, {0, 0});
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
                    rope[0].first++;
                    break;
                case 'L':
                    rope[0].first--;
                    break;
                case 'U':
                    rope[0].second++;
                    break;
                case 'D':
                    rope[0].second--;
                    break;
            }
            for (int i = 1; i < 10; i++) {
                if (rope[i - 1].first > rope[i].first + 1) {
                    rope[i].first++;
                    if (rope[i - 1].second > rope[i].second) rope[i].second++;
                    else if (rope[i - 1].second < rope[i].second) rope[i].second--;
                } else if (rope[i - 1].first < rope[i].first - 1) {
                    rope[i].first--;
                    if (rope[i - 1].second > rope[i].second) rope[i].second++;
                    else if (rope[i - 1].second < rope[i].second) rope[i].second--;
                } else if (rope[i - 1].second > rope[i].second + 1) {
                    rope[i].second++;
                    if (rope[i - 1].first > rope[i].first) rope[i].first++;
                    else if (rope[i - 1].first < rope[i].first) rope[i].first--;
                } else if (rope[i - 1].second < rope[i].second - 1) {
                    rope[i].second--;
                    if (rope[i - 1].first > rope[i].first) rope[i].first++;
                    else if (rope[i - 1].first < rope[i].first) rope[i].first--;
                }
            }
            visited.insert(rope.back());
        }
    }
    cout << visited.size() << endl;
    return 0;
}
