#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int main () {
    string rucksack;
    int sum = 0;

    // read until EOF
    while (cin >> rucksack) {
        int n = rucksack.size();
        // set to mark the present of an element
        // a-z will be marked at 0-25
        // A-Z will be marked at 26-51
        vector<bool> arr(52, false);
        
        for(int i = 0; i < n / 2; i++) { // iterate through the first half of rucksack
            if (isupper(rucksack[i])) arr[rucksack[i] - 'A' + 26] = true;
            else arr[rucksack[i] - 'a'] = true;
        }
        for(int i = n / 2; i < n; i++) { // process 2nd half items and compare the presence with 1st half
            int index = 0;
            if (isupper(rucksack[i])) index = rucksack[i] - 'A' + 26;
            else index = rucksack[i] - 'a';
            // if current item was present in the first half then its the common item in rucksack
            if (arr[index]) {
                sum += index + 1;
                arr[index] = false;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
