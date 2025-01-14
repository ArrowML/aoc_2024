#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<char> split(string s) {
    vector<char> res;
    for (auto x:s) {
        res.push_back(x);   
    }
    return res;
}

bool checkChars(char a, char b, char c, char d) {
    return a == 'X' && b == 'M' && c == 'A' && d == 'S';
}

int part1() {
    ifstream fin("input_full.txt");

    if (!fin.is_open()) {
        cerr << "Error opening the file!";
        return 1;
    }

    string s;
    vector<vector<char>> letter_grid;
    
    while (getline(fin, s)) {
        vector<char> line = split(s);
        letter_grid.push_back(line);
    }
    fin.close();

    int count = 0;

    for (int y = 0; y < letter_grid.size(); y ++) {
        for (int x = 0; x < letter_grid[y].size(); x ++) {
            if (letter_grid[y][x] == 'X') {

                if (x + 3 < letter_grid[y].size()) {
                    char l1 = letter_grid[y][x];
                    char l2 = letter_grid[y][x+1];
                    char l3 = letter_grid[y][x+2];
                    char l4 = letter_grid[y][x+3];
                    if (checkChars(l1, l2, l3, l4)) {
                        count++;
                    }
                }
                
                if (x - 3 >= 0) {\
                    char r1 = letter_grid[y][x];
                    char r2 = letter_grid[y][x-1];
                    char r3 = letter_grid[y][x-2];
                    char r4 = letter_grid[y][x-3];
                    if (checkChars(r1, r2, r3, r4)) {
                        count++;
                    }
                }

                if (y - 3 >= 0) {
                    char u1 = letter_grid[y][x];
                    char u2 = letter_grid[y-1][x];
                    char u3 = letter_grid[y-2][x];
                    char u4 = letter_grid[y-3][x];
                    if (checkChars(u1, u2, u3, u4)) {
                        count++;
                    }
                }

                if (y + 3 < letter_grid.size()) {
                    char d1 = letter_grid[y][x];
                    char d2 = letter_grid[y+1][x];
                    char d3 = letter_grid[y+2][x];
                    char d4 = letter_grid[y+3][x];
                    if (checkChars(d1, d2, d3, d4)) {
                        count++;
                    }
                }

                if (x + 3 < letter_grid[y].size() && y + 3 < letter_grid.size()) {
                    char ul1 = letter_grid[y][x];
                    char ul2 = letter_grid[y+1][x+1];
                    char ul3 = letter_grid[y+2][x+2];
                    char ul4 = letter_grid[y+3][x+3];
                    if (checkChars(ul1, ul2, ul3, ul4)) {
                        count++;
                    }
                }

                if (x - 3 >= 0 && y + 3 < letter_grid.size()) {
                    char ur1 = letter_grid[y][x];
                    char ur2 = letter_grid[y+1][x-1];
                    char ur3 = letter_grid[y+2][x-2];
                    char ur4 = letter_grid[y+3][x-3];
                    if (checkChars(ur1, ur2, ur3, ur4)) {
                        count++;
                    }
                }

                if (x - 3 >= 0 && y - 3 >= 0) {
                    char dl1 = letter_grid[y][x];
                    char dl2 = letter_grid[y-1][x-1];
                    char dl3 = letter_grid[y-2][x-2];
                    char dl4 = letter_grid[y-3][x-3];
                    if (checkChars(dl1, dl2, dl3, dl4)) {
                        count++;
                    }
                }

                if (y - 3 >= 0 && x + 3 < letter_grid[y].size()) {
                    char dr1 = letter_grid[y][x];
                    char dr2 = letter_grid[y-1][x+1];
                    char dr3 = letter_grid[y-2][x+2];
                    char dr4 = letter_grid[y-3][x+3];
                    if (checkChars(dr1, dr2, dr3, dr4)) {
                        count++;
                    }
                }
            }
        }
    }

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
    vector<vector<char>> letter_grid;
    
    while (getline(fin, s)) {
        vector<char> line = split(s);
        letter_grid.push_back(line);
    }
    fin.close();

    int count = 0;

    for (int y = 1; y < letter_grid.size()-1; y ++) {
        for (int x = 1; x < letter_grid[y].size()-1; x ++) {

            if (letter_grid[y][x] == 'A') {
   
                char tl = letter_grid[y-1][x-1];
                char br = letter_grid[y+1][x+1];
                char tr = letter_grid[y-1][x+1];
                char bl = letter_grid[y+1][x-1];

                if (tl == 'M' && br == 'S' && tr == 'M' && bl == 'S') {
                    count++;
                } else if (tl == 'M' && br == 'S' && tr == 'S' && bl == 'M') {
                    count++;
                } else if (tl == 'S' && br == 'M' && tr == 'S' && bl == 'M') {
                    count++;
                } else if (tl == 'S' && br == 'M' && tr == 'M' && bl == 'S') {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}

int main() {
    //part1();
    part2();
    return 0;
}

