#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

bool isNotAlpha(int elem) {
    return isalpha(elem);
}

int main(int argc, char * argv[]) {

    map<string, int> vocabulary;

    string all;

    while(!cin.eof()) {
        getline(cin, all);

        replace_if(all.begin(), all.end(), isNotAlpha, ' ');
//        cout << all << endl;

        stringstream stream(all);

        while(!stream.eof()) {
            string cur;
            stream >> cur;
            vocabulary[cur]++;
        }
    }

    for (auto& i : vocabulary) {
        cout << i.first << " : " << i.second << endl;
    }

    return 0;
}
