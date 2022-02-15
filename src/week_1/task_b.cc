#include <iostream>
#include <cctype> //for tolower and isupper
#include <stack>
 
using namespace std;

int main() {

    bool status = true;

    string data;
    cin >> data;

    const int n = data.size() / 2;
    if(data.size() % 2 != 0) status = false;

    int places[n];

    stack<int> traps;
    int traps_count = 0;
    stack<int> animals;
    int animals_count = 1;
    stack<char> chars;

    for(char letter: data){
        if(isupper(letter)) traps.push(traps_count++);
        else animals.push(animals_count++);
        if(!chars.empty()){
            if(tolower(chars.top()) == tolower(letter) && 
            (isupper(letter) && islower(chars.top())) ||
            (islower(letter) && isupper(chars.top()))){
                places[traps.top()] = animals.top(); // places[#trap] = #animal; (animals starts from 1)
                animals.pop();
                traps.pop();
                chars.pop();
            }

        } else chars.push(letter);
    }


    if(status || chars.empty()){
        cout << "Possible\n";
        for (int i = 0; i < n; i++){
            cout << places[i] << " ";
        }
    } else cout << "Impossible";

    return 0;
}
