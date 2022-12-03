#include <iostream>
using namespace std;

int main() {
    int maxCalories = 0;
    int curr = 0;
    string line;
    // read until EOF
    while (getline(cin, line)) {
        if (line.empty()) { // blank line, update the max calories count
            maxCalories = max(maxCalories, curr);
            curr = 0;
            continue;
        }
        curr += stoi(line); // add the calories of current item for current elf
    }
    cout << maxCalories << endl;
    return 0;
}
