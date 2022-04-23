#include <iostream>
#include <map>
#include <list>
#include <iterator>

using namespace std;

typedef struct{
    int size;
    int start;
} block;

list<block> blocks;
map<int, block> free_block;
map<int, block> used_block;

int search_for_block(int size){
    list<block>::iterator it = blocks.upper_bound()
}

int main(){
    int n, m;
    cin >> n, m;


    blocks.push_front((block){.size=n, .start=0});

    int request;
    for (int i = 0; i < m; i++){
        cin >> request;
        if(request >= 0){
            result = search_for_block(request);
        }else{
            
        }
    }

}

// list block []
// map по размеру свободные блоки
// map по номеру запроса занятые блоки