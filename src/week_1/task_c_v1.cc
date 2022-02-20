#include <iostream>
#include <string.h>
#include <stack>
#include <map>

using namespace std;

//pases first 44 tests and fails with memory limit (200ms / 122.68Mb)


void print_map(map<string, int> variables){
    map<string, int>::iterator it;
    cout << "----map------\n";
    for (it = variables.begin(); it != variables.end(); it++){
        cout << "variables[" << it->first << "]=" << it->second << "\n";
    }
    cout << "------------\n";
}

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

void print_str_stack(stack<string> &s){
    if(s.empty()){
        return;
    }
    string x= s.top();
    s.pop();
    print_str_stack(s);
    s.push(x);
    cout << x << " ";
}


int main() {
    stack<int> values;
    stack<string> names;
    map<string, int> variables;
    const string SEPARATOR_STR = "?";
    const int SEPARATOR_INT = 0;
    int number_of_block = 0;
    size_t possition;


    string line;
    while (getline(cin, line)){
        // cout << "============== " << line << " =========\n";
        if(line[0] == '{'){ //save values from map to stack
            names.push(SEPARATOR_STR);
            values.push(SEPARATOR_INT);
            // cout << "push separator to names, values\n";
            map<string, int>::iterator it;
            for (it = variables.begin(); it != variables.end(); it++){
                names.push(it->first);
                // cout << "push names: " << it->first << "\n";
                values.push(it->second);
                // cout << "push values: " << it->second << "\n";
            }
        }else if (line[0] == '}'){ //restore values from stack
            variables.clear();
            // cout << "clear variables and restore values from stack\n";
            while(names.top() != SEPARATOR_STR){
                variables.insert({names.top(), values.top()});
                // cout << "variables:[" << names.top() << "]=" << values.top() << "\n";
                names.pop();
                values.pop();
                // cout << "pop name + value from stack \n";
            }
            // cout << "pop separators from stack \n";
            names.pop();
            values.pop();
        }else{
            possition = line.find('=');
            string var = line.substr(0, possition);
            string value = line.substr(possition + 1);

            // cout << "var=" << var << " value=" << value <<"\n"; 

            if(isdigit(value[0]) || value[0] == '-'){ // <var>=<num>
                if(variables.find(var) != variables.end()) variables.erase(var);
                variables.insert({var, atoi(value.c_str())});
                // cout << "["<< var << "="<< value << "]\n";
            }else{ //<var>=<var>
                if(variables.find(value) != variables.end()){
                    if(strcmp(var.c_str(), value.c_str())){ //if var != value
                        // cout << "var != value\n";
                        if(variables.find(var) != variables.end()) variables.erase(var);
                        variables.insert({var, variables[value]});
                    }
                    // cout << "var == value\n";
                } else {
                    if(variables.find(var) != variables.end()) variables.erase(var);
                    variables.insert({var, 0});
                    variables.insert({value, 0});
                }
                cout << variables[value] << "\n";
                // cout << "["<< var << "="<< variables[value] << "] = value=" << value;
            }
        }
        // cout << "\n\n";
        // print_map(variables);
        // cout << "names=[";
        // print_str_stack(names);
        // cout << "]\n";
        // cout << "values=[";
        // print_int_stack(values);
        // cout << "]\n";

    }
    return 0;
}

// a=b -------> 0
// b=123
// var=b -------> 123
// b=-34
// {
// c=b -------> -34
// b=1000000000
// d=b -------> 1000000000
// {
// a=b -------> 1000000000
// e=var  -------> 123
// }
// }
// b=b -------> -34


// a=5
// a=b -------> 0
// b=a -------> 0