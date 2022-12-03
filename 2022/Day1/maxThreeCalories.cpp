#include <iostream>
using namespace std;

int main() {
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;

    int curr = 0;
    string line;
    // read unitl EOF
    while (getline(cin, line)) {
        if (line.empty()) { // update the three max
            if (max1 < curr) { // last elf has the maximum calories
                max3 = max2;
                max2 = max1;
                max1 = curr;
            } else if (max2 < curr) { // last elf has the 2nd max calories
                max3 = max2;
                max2 = curr;
            } else if (max3 < curr) { // last elf has the 3rd max calories
                max3 = curr;
            }
            curr = 0; // curr calories count to 0 as new elf needs to be processed
            continue;
        }
        curr += stoi(line);
    }
    cout << (max1 + max2 + max3) << endl;
    return 0;
}
