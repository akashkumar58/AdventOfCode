#include <iostream>
#include <utility>
using namespace std;

pair<int, int> parseInterval(string str) {
    pair<int, int> interval(0, 0);
    int i = 0, num = 0;
    while (str[i] != '-') {
        interval.first = (interval.first * 10) + (str[i++] - '0');
    }
    // str[i] is at '-', increase by 1 and go til index
    i++;
    while (i < str.size()){
        interval.second = (interval.second * 10) + (str[i++] - '0');
    }
    return interval;
}

// if one interval intersects with the other one at all.
inline bool isInBetween(pair<int, int> interval1, pair<int, int> interval2) {
    if ( interval1.first >= interval2.first && interval1.first <= interval2.second ) return true;
    if ( interval1.second >= interval2.first && interval1.second <= interval2.second) return true;
    if ( interval2.first >= interval1.first && interval2.first <= interval1.second ) return true;
    if ( interval2.second >= interval1.first && interval2.second <= interval1.second) return true;
    return false;
}

int main () {
    string line;
    int ans = 0;
    // read until EOF
    while ( cin >> line ) {
        // line would be in the format of num-num,num-num
        pair<int, int> elf1, elf2;
        int index = line.find(',');
        elf1 = parseInterval(line.substr(0, index));
        elf2 = parseInterval(line.substr(index + 1));

        ans += isInBetween(elf1, elf2);
    }
    cout << ans << endl;
    return 0;
}
