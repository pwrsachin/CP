//https://leetcode.com/problems/brace-expansion/description/
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> combinations; // Vector to store final combinations.
    vector<vector<string>> parts; // Vector of vector of strings, each representing a part of the input string.

    // Main function to expand the string.
    vector<string> expand(string s) {
        parseInputString(s); // Convert the string into parts.
        depthFirstSearch(0, ""); // Build the combinations.
        sort(combinations.begin(), combinations.end()); // Sort the combinations alphabetically.

        return combinations; // Return the combinations as a vector.
    }

private:
    // Helper function to convert the string into different parts.
    void parseInputString(const string& s) {
        string str = s; // Working copy of the input string
        while (!str.empty()) {
            if (str[0] == '{') {
                size_t endIndex = str.find("}");
                parts.push_back(split(str.substr(1, endIndex - 1), ',')); // Exclude '{' and '}'
                str = str.substr(endIndex + 1);
            } else {
                size_t endIndex = str.find("{");
                if (endIndex != string::npos) {
                    parts.push_back(vector<string>{str.substr(0, endIndex)});
                    str = str.substr(endIndex);
                } else {
                    parts.push_back(vector<string>{str});
                    break;
                }
            }
        }
    }

    // Helper function to split a string by a delimiter and return a vector of strings.
    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    // Helper function to perform depth-first search to build the combinations.
    void depthFirstSearch(int index, string current) {
        if (index == parts.size()) {
            combinations.push_back(current);
            return;
        }
        for (const string& str : parts[index]) {
            depthFirstSearch(index + 1, current + str); // Combine current string with the new part and recurse
        }
    }
};
