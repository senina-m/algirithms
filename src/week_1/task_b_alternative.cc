#include <iostream>
#include <cctype> //for tolower and isupper
#include <stack>
#include <map>
 
using namespace std;

//Task B in case when all animals are truly different and there is no the same

void print_arr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i];
    }
}

int main() {

    bool status = true;

    string data;
    cin >> data;

    const int n = data.size() / 2;
    // cout << "n:"<< n << "\n";
    if(data.size() % 2 != 0) status = false;
    
    stack<char> animals;

    map<char, int> animal_set;
    int places[n];
    int animal_counter = 1;
    int trap_counter = 0;
    int index;
    int trap_number;
    int animal_number;

    for(char letter: data){
        // cout << "\nCurrent letter: " << letter << " --------------\n";
        if(animal_set.find(tolower(letter)) == animal_set.end()){

            if(isupper(letter)) index = trap_counter++;
            else index = animal_counter++;
            animal_set.insert({tolower(letter), index});
            // cout << "\""<< letter<< "\"= " << index <<"\n";

            animals.push(letter);
        }else if(tolower(letter) == tolower(animals.top()) && ((isupper(letter) && islower(animals.top())) || (islower(letter) && isupper(animals.top())))){
            animals.pop();
            
            if(isupper(letter)) {
                trap_number = trap_counter++; 
                animal_number = animal_set.at(tolower(letter));
            }else {
                trap_number = animal_set.at(letter); 
                animal_number = animal_counter++;
            }
            
            
            // cout << "places["<< trap_number << "] = " << animal_number <<"\n";
            places[trap_number] = animal_number; // places[#trap] = #animal; (animals starts from 1)

            animal_set.erase(tolower(letter));
        }else{
            // cout << "fail\n";
            status = false;
            break;
        }
        // cout << "animal_counter=" << animal_counter << " trap_counter=" << trap_counter << "\n";
    }

    if(status){
        cout << "Possible\n";
        for (int i = 0; i < n; i++){
            cout << places[i] << " ";
        }
    } else cout << "Impossible";

    return 0;
}
