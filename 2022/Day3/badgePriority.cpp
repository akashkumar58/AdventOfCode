#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int main () {
    string rucksack1, rucksack2, rucksack3;
    int sum = 0;

    // we need to read rucksacks in group of 3 until EOF
    cin >> rucksack1;
    cin >> rucksack2;
    while (cin >> rucksack3) {
        // set to mark the present of an element. Since we need intersectoin between 3 groups, taking count
        // a-z will be marked at 0-25
        // A-Z will be marked at 26-51
        vector<short int> arr(52, -1);
        for(int i = 0; i < rucksack1.size(); i++) {
            if (isupper(rucksack1[i])) arr[rucksack1[i] - 'A' + 26] = 1;
            else arr[rucksack1[i] - 'a'] = 1;
        }
        for(int i = 0; i < rucksack2.size(); i++) {
            int index = 0;
            if (isupper(rucksack2[i])) index = rucksack2[i] - 'A' + 26;
            else index = rucksack2[i] - 'a';
            if (arr[index] >= 1) { // current item has already been present in the first rucksack, its common
                arr[index] = 2;
            }
        }
        for(int i = 0; i < rucksack3.size(); i++) {
            int index = 0;
            if (isupper(rucksack3[i])) index = rucksack3[i] - 'A' + 26;
            else index = rucksack3[i] - 'a';
            if (arr[index] == 2) { // current item was present in both 1st and 2nd rucksack, its common
                sum += index + 1; // update the score
                break;
            }
        }
        // read the first two rucksack for next group
        cin >> rucksack1;
        cin >> rucksack2;
    }
    cout << sum << endl;
    return 0;
}
