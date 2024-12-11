#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

int allIncreasingInRange(vector<string> line) {
    for (int i = 0; i < line.size() - 1; i++) {
        int curr = stoi(line[i]);
        int next = stoi(line[i+1]);
        int diff = next - curr;
        if (next < curr || (diff < 1 || diff > 3)) {
            return i;
        }
    }
    return -1;
}

int allDecreasingInRange(vector<string> line) {
    for (int i = 0; i < line.size() - 1; i++) {
        int curr = stoi(line[i]);
        int next = stoi(line[i+1]);
        int diff = curr - next;
        if (next > curr || (diff < 1 || diff > 3)) {
            return i;
        }
    }
    return -1;
}

bool isSafe(vector<string> line) {

    if (allIncreasingInRange(line) == -1) {
        return true;
    } 

    if (allDecreasingInRange(line) == -1) {
        return true;
    }

    return false;
}

int part1() {
    ifstream fin("input_full.txt");

    if (!fin.is_open()) {
        cerr << "Error opening the file!";
        return 1;
    }

    string s;
    int count = 0;

    while (getline(fin, s)) {
        vector<string> parts = split(s, " ");
        if (isSafe(parts)) {
            count += 1;
        }
    }
    fin.close();

    cout << count << endl;

    return 0;
}

int part2() {
    ifstream fin("input_full.txt");

    if (!fin.is_open()) {
        cerr << "Error opening the file!";
        return 1;
    }

    string s;
    int count = 0;

    while (getline(fin, s)) {
        vector<string> parts = split(s, " ");
        vector<string> partsCopy = parts;

        if (isSafe(parts)) {
            count += 1;
        } else {
            for (int i = 0; i < parts.size(); i++) {
                partsCopy.erase(partsCopy.begin() + i);
                if (isSafe(partsCopy)) {
                    count += 1;
                    break;
                } else {
                    partsCopy = parts;
                }
            }
        }      
    }
    fin.close();

    cout << count << endl;

    return 0;
}

int main() {
    part1();
    part2();
    return 0;
}