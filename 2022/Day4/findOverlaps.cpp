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

        // check if 2nd one is covered by 1st
        if (elf2.first >= elf1.first && elf2.second <= elf1.second) ans++;
        // check if 1st one is covered by 2nd
        else if (elf1.first >= elf2.first && elf1.second <= elf2.second) ans++;
    }
    cout << ans << endl;
    return 0;
}
