#include <iostream>
#include <vector>
#include <stdbool.h>

using namespace std;

void print_vector(vector<string>* vector){
    cout << "[";
    for(int i = 0; i < (*vector).size(); i++){
        cout << (*vector)[i] << " ";
    }
    cout << "]\n";
}

//todo: maybe i don't need 0, and it's ok to compare for >= only
// return 1 if l1 > l2, 0 if l1==l2, else -1
int compare(string l1, string l2){
    for (int i = 0; i < max(l1.size(), l2.size()); i++){
        if((char)l1[i] > (char)l2[i]) return 1;
        else if((char)l2[i] > (char)l1[i]) return -1;
    }
    // if(l1.size() > l2.size()) return -1;
    // if(l1.size() < l2.size()) return 1;
    return 0;
}

int find_index(string l, vector<string>* numbers_pointer, int left, int right, int level){
    cout << "New level "<< level <<": str=" << l << ", left=" << left << ", right=" << right<< endl;
    vector<string> numbers = *numbers_pointer;
    int mid = (right - left) / 2;
    switch (compare(l, numbers[mid])){
        case 1:
            right = mid;
            cout << "case 1: mid=right=" << right << endl;
            break;
        case -1:
            left = mid;
            cout << "case -1: mid=left=" << left << endl;
            break;
        case 0:
            cout << "case 0: mid+1=" << mid + 1 << endl;
            return mid + 1;
        default:
            cout << "ERROR";    
    }

    if(right - left <= 1) { 
        if(compare(l, numbers[right]) == -1) { cout << "l < right\n"; return right + 1;}
        else if (compare(l, numbers[left]) == 1)  { cout << "l > left\n"; return left;}
        else {cout << "l == left || l == right || left > l > right\n"; return left + 1;}
    }

    if(level > 20) return -1;
    return find_index(l, numbers_pointer, left, right, ++level);
}

int main() {
    vector<string> numbers;

    string line;    
    getline(cin, line);
    numbers.insert(numbers.begin(), line);

    while (getline(cin, line)){
        // cout << endl;
        print_vector(&numbers);
        int index = find_index(line, &numbers, 0, numbers.size() - 1, 0);
        // cout << "Found index:" << index <<endl;
        numbers.insert(numbers.begin() + index, line);
    }

    for(int i = 0; i < numbers.size(); i++){
        cout << numbers[i];
    }
    cout << endl;
}
