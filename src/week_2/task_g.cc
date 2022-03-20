#include <iostream>
#include <vector>
#include <stdbool.h>

using namespace std;

int main() {
    string line;
    cin >> line;

    int line_nums[];
    int weights[26]; // array
    for(int i = 0; i < line.size(); i++){
        line_nums[int(line[i]) - 97]++; //97 -- code of "a" in ascii table
        cout << "line_nums[" << int(line[i]) - 97 << "]=" << line_nums[int(line[i]) - 97] << " ";
    }
    cout << endl;

    for(int i = 0; i < 25; i++){
        cin >> weights[i];
    }

    sort_weights()

    
}
