#include <iostream>
#include <vector>
#include <stdbool.h>

using namespace std;

//todo: maybe i don't need 0, and it's ok to compare for >= only
// return 1 if l1 > l2, 0 if l1==l2, else -1
int compare(string l1, string l2){
    for (int i; i < max(l1.size(), l2.size()), i++){
        if((char)l1[i] > (char)l2[i]) return 1;
        else if((char)l2[i] > (char)l1[i]) return -1;
    }
    return 0;
}

int find_index(string l, vector<string>* numbers_pointer, int left, int right){
    vector<string> numbers = *numbers_pointer;
    int mid = (right - left)/2;
    int comparation = 
    switch (compare(l, numbers[mid])){
        case 1:
            mid = left;
            break;
        case -1:
            mid = right
            break;
        case 0;
            return mid;
        default:
            cout << "ERROR";    
    }
    if(left == right || left = right - 1) return left;
    find_index(line, numbers_pointer, left, right);
}

int main() {
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
