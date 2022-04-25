#include <iostream>

using namespace std;

typedef struct Node{
    Node *prev;
    Node *next;
    int val;
    Node(int v){
        this->val = v;
    }
} Node;

void print_list(Node *start){
    while(start){
        cout << start->val << " ";
        start = start->next;
    }
}


int main(int argc, char const *argv[]){
    int N, val, length=0;
    bool nado = false;
    Node *begin = NULL, *mid = NULL, *end = NULL;
    cin >> N;
    for(int i=0; i<N; i++){
        cout << "nado " << (nado?"yes":"no") << endl;
        char r;
        cin >> r;
        switch (r) {
            case '+':
                cin >> val;
                if(!length){
                    begin = new Node(val);
                    end = begin;
                    mid = begin;
                    begin->prev = NULL;
                    end->next =  NULL;
                    nado = false;
                } else {
                    end->next = new Node(val);
                    end->next->prev = end;
                    end = end->next;
        
                    if(nado) mid = mid->next;
                    nado = !nado;
                }
                length++;
                break;
            case '*':
                cin >> val;
                if(!length){
                    begin = new Node(val);
                    end = begin;
                    mid = begin;
                    begin->prev = NULL;
                    end->next =  NULL;
                    nado = false;
                } else {
                    Node *tmp = mid->next;
                    mid->next = new Node(val);
                    mid->next->prev = mid;
                    mid->next->next = tmp;
                    if(nado) mid = mid->next;
                    nado = !nado;
                }
    
                length++;
                while(end->next){
                    end = end->next;
                }
                break;

            case '-':
            
                cout << begin->val << endl;
                begin = begin->next;
    
                if(nado) mid = mid->next;
                nado = !nado;
    
                length--;
                break;
        }
    }
    return 0;
}
