#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int stones;
    cin >> stones;
    int current;
    int array[stones];

    int first_heap = 0;
    int second_heap = 0;

    for(int i = 0; i < stones; i++){
        cin >> array[i];
    }

    if(stones == 1){
        cout << array[0];
        return 0;
    }
    // cout << "++++++++++++" << endl;

    unsigned int min_diff = (0xffffffff);
    for (unsigned int i = 0; i < 1<<stones; i++){
        first_heap = 0;
        second_heap = 0;

        // bitset<8> y(i);
        // cout << y << '\n';

        for(int j = 0; j < stones; j++){
            if((i>>j) & 1) first_heap += array[j];
            else second_heap += array[j];
        }
        if(min_diff > abs(first_heap - second_heap)) min_diff = abs(first_heap - second_heap);
        // cout << "first_heap=" << first_heap << "  second_heap=" << second_heap << endl;
    }

    cout << min_diff;
}