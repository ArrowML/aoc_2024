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

int calcDiff(int a, int b) {
    if (a >= b) {
        return a - b;
    }
    return b - a;
}

int part1() {
    ifstream fin("input_full.txt");

    if (!fin.is_open()) {
        cerr << "Error opening the file!";
        return 1;
    }

    string s;
    vector<int> listA;
    vector<int> listB;
    int dist = 0;
    
    while (getline(fin, s)) {
        vector<string> parts = split(s, "   ");

        int v1 = stoi(parts[0]);
        listA.push_back(v1);

        int v2 = stoi(parts[1]);
        listB.push_back(v2);
    }
    fin.close();

    sort(listA.begin(), listA.end());
    sort(listB.begin(), listB.end());

    for (int i = 0; i < listB.size(); i++) {
        int diff = calcDiff(listA[i], listB[i]);
        dist += diff;
    }

    cout << dist << endl;

    return 0;

}

int part2() {
    ifstream fin("input_full.txt");

    if (!fin.is_open()) {
        cerr << "Error opening the file!";
        return 1;
    }

    string s;
    vector<int> listA;
    vector<int> listB;
    int dist = 0;
    
    while (getline(fin, s)) {
        vector<string> parts = split(s, "   ");

        int v1 = stoi(parts[0]);
        listA.push_back(v1);

        int v2 = stoi(parts[1]);
        listB.push_back(v2);
    }
    fin.close();

    sort(listA.begin(), listA.end());

    int count = 0;
    map<int, int> nums;


    for (int i = 0; i < listB.size(); i++) {
        nums[listB[i]] = nums[listB[i]] + 1;
    }


    for (int i = 0; i < listA.size(); i++) {
        
        if (nums.find(listA[i]) != nums.end()) {
            int val = listA[i] * nums[listA[i]];
            count += val;
        }

    }

    cout << count << endl;
    return 0;
    
}

int main() {
    part1();
    part2();
    return 0;
}


