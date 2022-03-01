#include <iostream>
#include <string.h>
#include <stack>
#include <unordered_map>

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

void print_map(unordered_map<string, stack<int>> variables){
    unordered_map<string, stack<int>>::iterator it;
    cout << "----map------\n";
    for (it = variables.begin(); it != variables.end(); it++){
        cout << "variables[" << it->first << "]=";
        print_int_stack(it->second);
        cout << "\n";
    }
    cout << "------------\n";
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
    stack<string> vars;
    unordered_map<string, stack<int>> variables;
    const string SEPARATOR_STR = "?";
    size_t possition;

    string line;
    while (getline(cin, line)){
        // cout << "============== " << line << " =========\n";
        if(line[0] == '{'){ 
            vars.push(SEPARATOR_STR);
        }else if (line[0] == '}'){
            while(vars.top()[0] != SEPARATOR_STR[0]){
                variables[vars.top()].pop();
                // if(variables[vars.top()].empty()) variables.erase(vars.top());
                vars.pop();
                // cout << "[";
                // print_str_stack(vars);
                // cout << "]\n";
            }
            vars.pop(); // pop separator from stack
        }else{
            possition = line.find('=');
            string var = line.substr(0, possition);
            string value = line.substr(possition + 1);
            vars.push(var);

            if(variables.find(var) == variables.end()){
                stack<int> var_stack;
                var_stack.push(0);
                variables.insert({var, var_stack});
            }
            // cout << "var=" << var << " value=" << value <<"\n"; 
            if(isdigit(value[0]) || value[0] == '-'){ // <var>=<num>
                variables[var].push(atoi(value.c_str()));
            }else{ //<var>=<var>
                if(variables.find(value) == variables.end()) variables[var].push(0);
                else variables[var].push(variables[value].top());

                cout << variables[var].top() << "\n";
                // cout << "["<< var << "="<< variables[value] << "] = value=" << value;
            }
        }
        // cout << "\n";
        // print_map(variables);
        // cout << "vars=[";
        // print_str_stack(vars);
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