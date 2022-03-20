
#include <iostream>
#include <set>
#include <fstream>

using namespace std;

int main(){
    ifstream fin("number.in");
    ofstream fout("number.out");

    auto cmp = [](string a, string b) {
        return a + b > b + a;
    };

    multiset<string, decltype(cmp)> numbers(cmp);

    string line;
    while (true){
        fin >> line;
        if (fin.eof()) {
			break;
		}
        numbers.insert(line);
    }

    std::multiset<string>::iterator it;
    for(it = (numbers).begin(); it != (numbers).end(); it++){
        fout << *it;
    }

	fin.close();
	fout.close();
}