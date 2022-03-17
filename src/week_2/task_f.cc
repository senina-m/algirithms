
#include <iostream>
#include <set>
#include <fstream>

using namespace std;

int main(){
    ifstream fin("/home/senina/Desktop/itmo/algorithms/build/week_2/number.in");
	ofstream fout("/home/senina/Desktop/itmo/algorithms/build/week_2/number.out");
	// ifstream fin("number.in");
	// ofstream fout("number.out");


    //a >= b
    auto cmp = [](string a, string b) {
        for (int i = 0; i < min(a.size(), b.size()); i++){
            // cout << "------ a=" << a << " a.size=" << a.size() << " b.size=" << b.size() << " b=" << b << "-----" << endl;
            if((char)a[i] > (char)b[i]) return 1; // cout << "at i=" << i << " a[i] > b[i]" << endl;
            if((char)a[i] < (char)b[i]) return 0; // cout << "at i=" << i << " a[i] < b[i]" << endl;
        } 
        // if( (a.size() > b.size()) && ( (int) a[b.size()] > 48) ) return 1; //48 is zero at ascii table
        // else if ( (a.size() < b.size()) && ( (int) b[a.size()] > 48) ) return 0;
        // else return (int)(a.size() <= b.size());

        if(a.size() == b.size()) return 1;
        else if(a.size() > b.size()){
            if((int) a[b.size()] > 48) return 1;
            else return 0;
        }else {
            if((int) b[a.size()] > 48) return 0;
            else return 1;
        }
    };

    set<string, decltype(cmp)> numbers(cmp);

    string line;
    while (!fin.eof()){
        fin >> line;
        // cout << "new line:" << line << endl;
        numbers.insert(line);
    
        // std::set<string>::iterator it;
        // for(it = (numbers).begin(); it != (numbers).end(); it++){
        //     cout << *it << " ";
        // }
        // cout << endl;
    }

    std::set<string>::iterator it;
    for(it = (numbers).begin(); it != (numbers).end(); it++){
        fout << *it;
        // cout << *it;
    }

	fin.close();
	fout.close();
}