#include <iostream>
#include <algorithm>


using namespace std;

void print_int_arr(string name, int* arr, int n){
    cout << "\n" << name << "=[";
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << "]\n";
}

int main(){
    int n;
    int k;
    cin >> n;
    cin >> k;

    int items[n];
    for (int i = 0; i < n; i++){
        cin >> items[i];
    }

    sort(items, items + n, std::greater<>());
    
    int sum = 0;
    for(int i = 0; i < n; i++){
        // cout << "item[i]" << items[i];
        if((i+1) % k != 0){
            // cout << " => in check"; 
            sum += items[i];
        }
        // cout << endl;
    }
    
    cout << sum;
}