#include <iostream>
using namespace std;


inline bool shouldLightPixel(int & cycle, int & x) {
    bool shouldLight = false;
    // if cycle and current sprite overlaps then only we lit the pixel
    // since the sprite has length of 3 pixels, we need to make sure if
    // cycle is overlapping with any of them
    if ( (cycle - x) >= 0 && (cycle - x) <= 2) shouldLight = true;

    return shouldLight;
}

int main () {
    string line;
    int cycle = 0;
    int x = 1; // starting value of register X
    string row = "";
    // read until EOF
    while (getline(cin, line)) {
        // noop
        if (line[0] == 'n') {
            cycle++;
            shouldLightPixel(cycle, x) ? row += '#' : row += '.';
           // if 40 pixels has been covered, then print row and reset cycle and CRT row
            if(cycle == 40) {
                cout << row << endl;
                cycle = 0; row.clear();
            }
        } else { // addx instruction
            int value = stoi(line.substr(5)); // read the value to be added to sprite position
            cycle++; // first cycle of addX 
            shouldLightPixel(cycle, x) ? row += '#' : row += '.';
           // if 40 pixels has been covered, then print row and reset cycle and CRT row
            if(cycle == 40) {
                cout << row << endl;
                cycle = 0; row.clear();
            }
            cycle++; // second cycle of addX
            shouldLightPixel(cycle, x) ? row += '#' : row += '.';
           // if 40 pixels has been covered, then print row and reset cycle and CRT row
            if(cycle == 40) {
                cout << row << endl;
                cycle = 0; row.clear();
            }
            x += value;
        }
    }
    return 0;
}
