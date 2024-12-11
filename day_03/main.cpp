#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <regex>

using namespace std;

int mul(string in) {
    regex d("\\d{1,3}");
    smatch m;
    vector<int> nos;
    
    while (regex_search (in,m,d)) {
        for (auto x:m) {
           nos.push_back(stoi(x));
        }
        in = m.suffix().str();
    }

    return nos[0] * nos[1];   
}

int part1() {
    ifstream fin("input_full.txt");

    if (!fin.is_open()) {
        cerr << "Error opening the file!";
        return 1;
    }

    string s;
    int count = 0;

    regex r("mul\\(\\d{1,3}\\,\\d{1,3}\\)");

    while (getline(fin, s)) {
        smatch m;
        while (regex_search (s,m,r)) {
            for (auto x:m) {
               count += mul(x);
            }
            s = m.suffix().str();
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

    regex r("mul\\(\\d{1,3}\\,\\d{1,3}\\)|do\\(\\)|don\'t\\(\\)");
    bool enabled = true;    

    while (getline(fin, s)) {
        smatch m;
        
        while (regex_search(s,m,r)) {
            for (auto x:m) {

                cout << x << endl; 

                if (x == "don't()")  {
                    if (enabled) {
                        enabled = false;        
                    }
                } else if (x == "do()") {
                    if (!enabled) {
                        enabled = true;        
                    }
                } else {
                    if (enabled) {
                        count += mul(x);
                    }
                }
            }
            s = m.suffix().str();
        }
    }
    fin.close();

    cout << count << endl;

    return 0;
}

int main() {
    part2();
    return 0;
}