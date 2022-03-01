#include <iostream>
#include <cctype> //for tolower and isupper
#include <stack>
 
using namespace std;

void print_int_stack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int x= s.top();
    s.pop();
    print_int_stack(s);
    s.push(x);
    cout << x << " ";
}

void print_str_stack(stack<char> &s){
    if(s.empty()){
        return;
    }
    char x= s.top();
    s.pop();
    print_str_stack(s);
    s.push(x);
    cout << x << " ";
}

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
        // cout << "==========" << letter << "========\n";
        if(isupper(letter)) traps.push(traps_count++);
        else animals.push(animals_count++);

        if(!chars.empty()){
            if(tolower(chars.top()) == tolower(letter) && (
            (isupper(letter) && islower(chars.top())) ||
            (islower(letter) && isupper(chars.top())))){
                places[traps.top()] = animals.top(); // places[#trap] = #animal; (animals starts from 1)
                animals.pop();
                traps.pop();
                chars.pop();
            } else chars.push(letter);
        } else chars.push(letter);

        // cout << "\n";
        // cout << "chars=[";
        // print_str_stack(chars);
        // cout << "]\n";

        // cout << "traps=[";
        // print_int_stack(traps);
        // cout << "]\n";

        // cout << "animals=[";
        // print_int_stack(animals);
        // cout << "]\n";
    }

    // cout << chars.empty();
    if(chars.empty()){
        cout << "Possible\n";
        for (int i = 0; i < n; i++){
            cout << places[i] << " ";
        }
    } else cout << "Impossible";

    return 0;
}
