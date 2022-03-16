#include <iostream>
#include <vector>
#include <stdbool.h>

using namespace std;

int main() {
    string line;
    cin >> line;

    int line_nums[line.size()];
    int weights[26]; // array
    for(int i = 0; i < line.size(); i++){
        line_nums[i] = int(line[i]) - 97; //97 -- code of "a" in ascii table
        cout << "line_nums[" << i << "]=" << line_nums[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < 25; i++){
        cin >> 
    }
   
   
   
    vector<string> numbers;

    string line;    
    getline(cin, line);
    numbers.insert(numbers.begin(), line);

    while (getline(cin, line)){
        int index = find_index(line, &numbers, 0, numbers.size());
        numbers.insert(numbers.begin() + index, line);
    }

    for(int i = 0; i < numbers.size(); i++){
        cout << numbers[i];
    }
    cout << endl;
}
