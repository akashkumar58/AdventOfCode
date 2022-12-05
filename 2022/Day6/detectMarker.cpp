#include <iostream>
#include <vector>
#define UNIQUE_COUNT_TARGET 14
using namespace std;

int main() {
    string input;
    cin >> input;
    int index = 0, n = input.size() - 1;
    int startOfNonRepeating = 0;

    int uniqueChars = 0;
    // map to store count of chars
    vector<int> hash(26, 0);
    // process chars 1 by 1
    while ( index <= n ) {
        hash[input[index] - 'a']++;
        // if current character results into duplicate in the window of chars starting at startOfNonRepeating
        if (hash[input[index] - 'a'] > 1) {
            // we need to reset count of all chars to 0 till the char arrives that is resulting into duplicate
            while(hash[input[startOfNonRepeating] - 'a'] == 1 && startOfNonRepeating < index) {
                hash[input[startOfNonRepeating] - 'a'] = 0; // reset the count to 0 as the window will shift forward
                startOfNonRepeating++;
            }
            hash[input[startOfNonRepeating] - 'a']--; // reduce the count of duplicate char
            startOfNonRepeating++; // advance startOfNonRepeating so that it point to start of next window that unique chars

        }
        uniqueChars = index - startOfNonRepeating + 1; 
        if (uniqueChars == UNIQUE_COUNT_TARGET) {
            break;
        }
        index++;
    }
    cout << (index + 1) << endl;
    return 0;
}
