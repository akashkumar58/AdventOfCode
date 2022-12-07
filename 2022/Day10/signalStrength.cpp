#include <iostream>
using namespace std;

// if cycle is at any of the special locations 20, 60, 100, 140, 180, 220
// then we need to multiply register x value with the cycle number and add to total result.
inline void processSignal(int & val, int cycle, int &total) {
    if (cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 || cycle == 180 || cycle == 220) {
        total += (val * cycle);
    }
}

int main () {
    string line;
    int cycle = 0;
    int x = 1; // initial value of register x
    int total = 0;
    // read until EOF
    while (getline(cin, line)) {
        // noop
        if (line[0] == 'n') {
            cycle++;
            processSignal(x, cycle, total);
        } else { // addX instruction
            int value = stoi(line.substr(5)); // read the value argument of addX instruction
            cycle++; // first cycle of addX processing
            processSignal(x, cycle, total);
            cycle++; // second cycle of addX processing 
            processSignal(x, cycle, total);
            x += value; // after cycles are over, update te value of register x
        }
    }
    cout << total << endl;
    return 0;
}
