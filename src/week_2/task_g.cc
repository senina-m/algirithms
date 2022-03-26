#include <iostream>
#include <vector>
#include <stdbool.h>

using namespace std;

void sort_weights(int n, int* weights, int* line_numbers, char* alphabet){
    int max_weight, corresponging_i;
	for (int i = 1; i < n; i++) {
		max_weight = weights[i];
        //sort from bigger to smaller by weights all arrays
	}
}

int main() {
    string line;
    cin >> line; //string line
    int n = line.length();

    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i','j', 'k', 'm', 'n',
     'l', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v','w', 'x', 'y', 'z'};
    int line_nums[26]; //frequency of numbers
    int weights[26]; //weight of numbers
    for(int i = 0; i < line.size(); i++){
        line_nums[int(line[i]) - 97]++; //97 -- code of "a" in ascii table
        cout << "line_nums[" << int(line[i]) - 97 << "]=" << line_nums[int(line[i]) - 97] << " ";
    }
    cout << endl;

    for(int i = 0; i < 25; i++){
        cin >> weights[i];
    }

    sort_weights(n, weights, line_nums, alphabet);

    char output[n];
    int k = 0;
    int it = 0;
    while (k < 26){
        if(line_nums[k] >= 2){
            output[k] = alphabet[k];
            output[n - k - 1] = alphabet[k];
            line_nums[k] -=2;
        }else{
            k++;
        }
    }

    it = k;
    k = 0;
    while (k < 26 && line_nums[k] == 1){
        output[it] = alphabet[k];
        it++;
        k++;
    }
}
