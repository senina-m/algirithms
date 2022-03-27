#include <iostream>
#include <vector>
#include <stdbool.h>

using namespace std;

void print_char_arr(string name, char* arr, int n){
    cout << "\n" << name << "=[";
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << "]\n";
}

void print_int_arr(string name, int* arr, int n){
    cout << "\n" << name << "=[";
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << "]\n";
}

void sort_weights(int n, int* weights, int* line_numbers, char* alphabet){
	for(int i = 1; i < n; i++){
		for(int j = i; j > 0 && weights[j - 1] <= weights[j]; j--){
            //swap j and j-1 wheights
			int int_tmp = weights[j-1];
			weights[j-1] = weights[j];
			weights[j] = int_tmp;

            //swap j and j-1 in line_nums
            int_tmp = line_numbers[j-1];
			line_numbers[j-1] = line_numbers[j];
			line_numbers[j] = int_tmp;

            //swap j and j-1 in max_alphabet
            char str_tmp = alphabet[j-1];
			alphabet[j-1] = alphabet[j];
			alphabet[j] = str_tmp;
		}
	}
}

int main() {
    string line;
    cin >> line; //string line
    int n = line.length();

    int alph_len = 26;
    char alphabet[alph_len] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    int line_nums[alph_len] = {0}; //frequency of numbers
    int weights[alph_len]; //weight of numbers
    for(int i = 0; i < line.size(); i++){
        line_nums[int(line[i]) - 97]++; //97 -- code of "a" in ascii table
        // cout << "\n" << line[i] << "=[" << int(line[i]) - 97 << "]\n";
    }

    // print_int_arr("line_nums", line_nums, alph_len);

    for(int i = 0; i < alph_len; i++){
        cin >> weights[i];
    }

    // print_int_arr("weights", weights, alph_len);
    // print_char_arr("alphabet", alphabet, alph_len);
    

    sort_weights(alph_len, weights, line_nums, alphabet);

    // cout << "after sort \n";
    // print_int_arr("line_nums", line_nums, alph_len);
    // print_int_arr("weights", weights, alph_len);
    // print_char_arr("alphabet", alphabet, alph_len);

    char output[n];
    int k = 0;
    int it = 0;
    while (k < alph_len){
        // cout << "k=" << k << " ";
        // cout << "line_nums[k]=" << line_nums[k] << endl;

        if(line_nums[k] >= 2){
            output[it] = alphabet[k];
            output[n - it - 1] = alphabet[k];
            line_nums[k] -=2;
            it++;
        }else{
            k++;
        }
    }

    k = 0;
    for (k; k < alph_len; k++){
        if(line_nums[k] == 1){
            // cout << "k=" << k << "line_nums[k]=" << line_nums[k] << endl;
            output[it] = alphabet[k];
            it++;
        }
    }

    for (int i = 0; i < n; i++){
        cout << output[i];
    }
    
}
