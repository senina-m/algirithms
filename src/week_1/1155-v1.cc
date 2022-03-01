#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int vertex[8];
int graph[8][8] = {
    {0, 1, 0, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 0, 1, 0},
    {1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 1},
    {0, 1, 0, 0, 1, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 0, 1},
    {0, 0, 0, 1, 1, 0, 1, 0}
};

int sum = 0;

stringstream strm;

int delete_neighbours(int i){
    int retval = 0;
    for(int j=0; j<8; j++){
        while(graph[i][j] && vertex[j] && vertex[i]){
            strm << (char)('A'+i) << (char)('A'+j) << "-" << endl;
            vertex[i]--;
            vertex[j]--;
            sum-=2;
            retval = 1;
        }
    }
    return retval;
}

int delete_diagonal(int i, int j){
    int retval = 0;
    while(vertex[i] && vertex[j]){
        strm << (char)('A'+((i+1)&0b11)) << (char)('A'+((j+3)&0b11)+4) << "+" << endl;
        strm << (char)('A'+i) << (char)('A'+((i+1)&0b11)) << "-" << endl;
        strm << (char)('A'+((j+3)&0b11)+4) << (char)('A'+j) << "-" << endl;
        vertex[i]--;
        vertex[j]--;
        retval = 1;
    }
    return retval;
}

int main(int argc, char const *argv[]) {
    for(int i=0; i<8; i++){
        cin >> vertex[i];
        sum += vertex[i];
    }

    if(sum & 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int flag = 1;
    while(flag){
        flag = 0;
        for(int i=0; i<8; i++){
            flag += delete_neighbours(i);
            flag += delete_diagonal(i, ((i+6)&0b11) + 4);
        }
    }

    for(int i: vertex){
        if(i) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    string s;
    s = strm.str();
    cout << s;
    return 0;
}
