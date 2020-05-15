#include <iostream>
#include <vector>

enum {
    CONNECT = ' ',
    MINUS = '-',
    PLUS = '+',
    MULTIPLY = '*',

};

using namespace std;

//vector<char> signs = {' ', '-', '+', '*'};
vector<char> signs = {0, 1, 2, 3};

void Anal(vector<int>& source, vector<char>& res) {
    for (auto i : source) {
        switch (i) {
            case 0:
                res.push_back(' '); //?????????
                break;
            case 1:
                res.push_back('-');
                break;
            case 2:
                res.push_back('+');
                break;
            case 3:
                res.push_back('*');
                break;
            default:
                cout << "nooooo";
        }
    }
}

int calcOfResult (vector<int>& numerals, vector<int>& sq) {

    int result = 0;
    int k = 1;

    vector<int>new_numerals;
    vector<int>new_sq;

    size_t i, j = 0;

    new_numerals.push_back(numerals[j]);

    for (i = 0, j = 0; i < sq.size(); i++, j++) {

        if (sq[i] == 1 || sq[i] == 2) {
            new_numerals.push_back(numerals[j + 1]);
            new_sq.push_back(sq[i]);
        }
        else if (sq[i] == 3) {
            new_numerals[new_sq.size()] = numerals[j] * numerals[j+1];
            numerals[j + 1] = numerals[j] * numerals[j+1];
        }
        else if (sq[i] == 0) {
            new_numerals[new_sq.size()] = numerals[j] * 10 + numerals[j+1];
            numerals[j + 1] = numerals[j] * 10 + numerals[j+1];
        }
        else {
            cout << "((((((" << endl;
        }

    }

    result = new_numerals[k - 1];

    for (auto x : new_sq) {
        switch (x) {
            case 1:
                result -= new_numerals[k];
                break;
            case 2:
                result += new_numerals[k];
                break;
            default:
                cout << "bl";

        }
        k++;
    }

    return result;
}

void recursiveCombination(const vector<int>& numerals, vector<int>& sequence, int result_number, size_t level) {

    if (level == sequence.size()) {

        vector<int> copy_numerals = numerals;

        int result = calcOfResult(copy_numerals, sequence);

        if (result == result_number) {

            vector<char> operations; //+-*_
            Anal (sequence, operations);

            cout << result_number << " = ";
            for (size_t j = 0; j < numerals.size(); j++) {
                cout << numerals[j] << operations[j];
            }
            cout << endl;
        }

        return;
    }

    for (size_t i = 0; i < signs.size(); i++) {
        sequence[level] = signs[i];
        recursiveCombination(numerals, sequence, result_number, level + 1);
    }
}

int main(int argc, char ** argv) {

    int result_number = strtoll(argv[1], nullptr, 10);

    vector<int> numerals;
    for (int i = 2; i < argc; i++) {
        numerals.push_back(strtoll(argv[i], nullptr, 10));
    }

    vector<int> sq(numerals.size() - 1);          //0123

    recursiveCombination(numerals, sq, result_number, 0);

    return 0;
}
