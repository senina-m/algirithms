#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>

using namespace std;

bool cmp(pair<int, int> pair1, pair<int, int> pair2) { return pair1.first > pair2.first;}

void print_queue(queue<int> q){
  if (!q.empty()){
    cout << q.front() << " ";
    int val = q.front();
    q.pop();
    print_queue(q);
    q.push(val);
  }
}

void print_map(unordered_map<int, queue<int>> map){
    cout << "map:\n";
    for(auto it = map.begin(); it != map.end(); ++it){
        cout << it->first << " => ";
        print_queue(it->second);
        cout << "\n";
    }
}

void print_set(unordered_set<int> s){
    cout << "floor: ";
    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it << ' ';
    }
    cout << endl;
}

void print_priority(set<pair<int, int>,  decltype(&cmp)> s){
    cout << "priority: ";
    for(auto it = s.begin(); it != s.end(); it++){
        cout << "(" << ((*it).first) << ", " << ((*(it)).second)  << ")" << ' ';
    }
    cout << endl;
}

void print_arr(int* cars_order, int n, int k){
    cout << "[";
    for(int i = k; i < n; i++){
        cout << cars_order[i] << ' ';
    }
    cout << "]" << endl;
}


int main(){
    int n, k, p;
    cin >> n >> k >> p;

    int* cars_order = new int[p];
    unordered_set<int> floor;
    unordered_map<int, queue<int>> table;
    set<pair<int, int>, decltype(&cmp)> priority(cmp);

    int actions = 0;
    for (int i = 0; i < p; i++){
        cin >> cars_order[i];
        table[cars_order[i]].push(i);
    }

    for(int i = 0; i < p; i++){
        cout << "______step" << i << "______\n";
        print_arr(cars_order, p, i);
        print_map(table);
        print_set(floor);
        print_priority(priority);

        if(floor.find(cars_order[i]) != floor.end()) table[cars_order[i]].pop();
        else{
            if(floor.size() >= k){
                //освобождаем пол
                // find farest car
                pair<int, int> car = *priority.begin();
                floor.extract(car.second);
                priority.extract(car);
                actions++;
            }
            // снимаем машинку со cтола
            // actions++;
            //если машинка на полу её нужно будет сравнивать с другими машинками
            priority.extract(make_pair(i, cars_order[i]));
            table[cars_order[i]].pop();
            pair<int, int> new_car = make_pair(table[cars_order[i]].front(), cars_order[i]);
            priority.insert(new_car);
            floor.insert(cars_order[i]);
        }
    }
    cout << actions + floor.size();
}