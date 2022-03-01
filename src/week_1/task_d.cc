#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int count_bacterias(int bacterias, size_t days, int container_size, int devidion_speed, int experiment){
    int previos_day = bacterias;
    int current_day = 0;
    int new_day_amount = 0;
    // int it =0;
    // cout << "\n";
    for(size_t i = 0; i < days; i++){
        new_day_amount = previos_day*devidion_speed;
        current_day = new_day_amount > experiment ? new_day_amount - experiment : 0;
        if (current_day >= container_size) current_day = container_size;

        // cout << current_day << " ";
        if (previos_day == current_day) break;
        else previos_day = current_day;
        // it++;
    }
    // cout << "\nIT:"<< it << "\n";
    return current_day;
}

void test_data(int bacterias, size_t days, int container_size, int devidion_speed, int experiment){
    auto start = high_resolution_clock::now();
    int result = count_bacterias(bacterias, days, container_size, devidion_speed, experiment);
    cout <<"Result:" << result << "\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time: " << duration.count() << " ms, for data:" << "\n";
    cout <<" bacterias="<< bacterias << " devidion_speed=" << devidion_speed <<" experiment=" << experiment << " container_size=" << container_size << " days=" << days << "\n\n";
}

void read_data(int* bacterias, size_t* days, int* container_size, int* devidion_speed, int* experiment){
    cin >> *bacterias >> *devidion_speed >> *experiment >> *container_size >> *days;
}

int main(){
    int bacterias; //a
    size_t days; //k
    int container_size; //d
    int devidion_speed; //b
    int experiment; //c
    read_data(&bacterias, &days, &container_size, &devidion_speed, &experiment);
    cout << count_bacterias(bacterias, days, container_size, devidion_speed, experiment);
    // int bacterias, size_t days, int container_size, int devidion_speed, int experiment
    // test_data(300, 1000, 1500, 5, 900);
    
    return 0;
}
