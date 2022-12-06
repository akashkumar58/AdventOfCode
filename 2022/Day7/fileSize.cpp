#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

int main () {
    string input;
    // vector to store the pwd where each element is directory name in the current path
    vector<string> pwd;
    pwd.push_back("/");
    // map to store sizes of all the directory
    unordered_map<string, size_t> sizes;
    // read lines unitl EOF
    while (getline(cin, input)) {
        if (input[0] == '$') { // input is command - either cd or ls
            if (input[2] == 'c') { // process cd
                string directory = input.substr(5);
                switch (directory[0]) {
                    case '/': pwd.resize(1); break; // we need to be back to the first level directory i.e. /
                    case '.': pwd.pop_back(); break; // it cd .., we need to go back in the curr path
                    default: pwd.push_back(directory); break; // move to next directory
                }
            }
            // ignore ls command but not its output. That is covered in next block
        }
        else if ( input[0] == 'd') { 
            // ignore dir as it just contains the name of the directory
            // we are only dealing with dirs when we do cd and then map gets updated with the size
        }
        else { // procedd file and sizes
            size_t fileSize = stoi(input.substr(0, input.find(" "))); // size is first string of the line
            // iterate through all the directory from start "/" and update the size of all path
            for (auto itr = pwd.begin(); itr != pwd.end(); itr++) { 
                string path = accumulate(pwd.begin(), itr + 1, string{}); // concatenate all the strings
                sizes[path] += fileSize; // update the size of the directory as new file was discovered
            }
        }
    }
    size_t sumSizeLessThan100k = 0; // sum of directory with size less than 100k
    size_t minToDelete = sizes["/"];
    size_t minSizeNeeded = 30000000 - (70000000 - sizes["/"]);
    for (const auto &kvPair : sizes) {
      if (kvPair.second < 100000) // first part answer where we need sum of size of dir having size < 100k
        sumSizeLessThan100k += kvPair.second;
      if (kvPair.second > minSizeNeeded) // second part where we need to find min size dir to delete
          minToDelete = min(minToDelete, kvPair.second);
    }
    cout << sumSizeLessThan100k << endl; // first part answer
    cout << minToDelete << endl; // second part answer
    return 0;
}
