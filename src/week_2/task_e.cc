#include <iostream>
#include <stdbool.h>

using namespace std;

//check if we can place "cows_num" cows with min. distance between equal to "dist"
//just count distant spaces from start and try to fill stall sequentially
bool check_if_can_place(int* stalls, int n, int dist, int cows_num){
    // cout << " ______ check " << cows_num << " cows" << " with dist=" << dist << " ______ " << endl; 
    int cows = 0;
    int current_space = 0;
    for (int i = 0; i < n - 1; i++){
        current_space += stalls[i + 1] - stalls[i]; 
        if(current_space >= dist){
            // cout << "set cow at i=" << i << ", distance from previos=" << current_space << endl;
            current_space = 0;
            cows++;
            if(cows >= cows_num - 1) return true;
        }
    }
    return false;
}k

int main(){
    int n, cows_num;
    cin >> n >> cows_num;

    int stalls[n];
    for(int i = 0; i < n; i++){
        cin >> stalls[i];
    }

    //binseach of needed value
    int l = 1;
    int r = stalls[n - 1] - stalls[0];
    while (l < r - 1){
        int mid_dist = (r + l)/2;
        // cout << "==============  r=" << r << " l=" << l << " mid_dist=" << mid_dist << "  ============="<< endl;
        if(check_if_can_place(stalls, n, mid_dist, cows_num)) l = mid_dist;
        else r = mid_dist;
    }

    if (check_if_can_place(stalls, n, r, cows_num)) cout << r;
	else cout << l;
}