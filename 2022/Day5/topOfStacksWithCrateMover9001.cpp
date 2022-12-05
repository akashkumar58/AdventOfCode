#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    /** Intial stack configuration is given as follows:
    [H]         [D]     [P]        
[W] [B]         [C] [Z] [D]        
[T] [J]     [T] [J] [D] [J]        
[H] [Z]     [H] [H] [W] [S]     [M]
[P] [F] [R] [P] [Z] [F] [W]     [F]
[J] [V] [T] [N] [F] [G] [Z] [S] [S]
[C] [R] [P] [S] [V] [M] [V] [D] [Z]
[F] [G] [H] [Z] [N] [P] [M] [N] [D]
 1   2   3   4   5   6   7   8   9
     */
    vector<string> arrays(9);
    arrays[0] = "FCJPHTW";
    arrays[1] = "GRVFZJBH";
    arrays[2] = "HPTR";
    arrays[3] = "ZSNPHT";
    arrays[4] = "NVFZHJCD";
    arrays[5] = "PMGFWDZ";
    arrays[6] = "MVZWSJDP";
    arrays[7] = "NDS";
    arrays[8] = "DZSFM";

    vector<stack<char>> stacks(9);
    for (int i = 0; i < arrays.size(); i++) {
        for (int j = 0; j < arrays[i].size(); j++) {
            stacks[i].push(arrays[i][j]);
        }
    }
    // read the moves till EOF
    string input;
    while (getline(cin, input)) {
        int quantity = 0, source = 0, target = 0;
        int i = 5;
        // read the quantity which is in between move and from. Starting index will always be 5.
        while (input[i] != ' ') {
            quantity = (quantity * 10) + (input[i++] - '0');
        }
        // index is pointing to space before 'from ', so we move it by 5 to point to source
        i += 6;
        while (input[i] != ' ') {
            source = (source * 10) + (input[i++] - '0');
        }
        // index is pointing to space before 'to ', so we move it by 3 to point to target
        i += 4;
        while (i < input.size()) {
            target = (target * 10) + (input[i++] - '0');
        }
        // we need to move multiple items from source to taget in the same configuration.
        string popped = "";
        for(int j = 0; j < quantity; j++) {
            popped += stacks[source - 1].top();
            stacks[source - 1].pop();
        }
        // the end of the string is towards the bottom of the stack, we need to push in reverse order in order to maintain the original order
        for(int j = popped.size() - 1; j >= 0; j--) {
            stacks[target - 1].push(popped[j]);
        }
    }
    // answer will be top of all the stacks from left to right
    string ans = "";
    for(int i = 0; i < stacks.size(); i++) {
        ans += stacks[i].top();
    }
    cout << ans << endl;
    return 0;
}
