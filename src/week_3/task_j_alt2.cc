#include <iostream>
#include <list>

using namespace std;

typedef struct Node {
    Node *prev;
    Node *next;
    int val;
    Node(int v){
        val = v;
        prev = NULL;
        next = NULL;
    }
} Node;

void print_list(Node* start_node){
    cout << "[";
    Node* tmp = start_node;
    while (tmp->next){
        cout << tmp->val << " ";
    }
    cout << "]" << endl;

}

Node *insert_after(Node *m, int val){
    Node *tmp = new Node(val);
    tmp->prev = m;
    tmp->next = m->next;
    m->next = tmp;
    if(tmp->next) tmp->next->prev = tmp;
    return tmp;
}

Node *push_back(Node *last, int val){
    Node *tmp = new Node(val);
    last->next = tmp;
    tmp->prev = last;
    return tmp;
}

void pop_front(Node *head){
    Node *pop = head->next;
    Node *n = pop->next;
    if(n) n->prev = head;
    head->next = n;
    printf("%d\n", pop->val);
    delete pop;
}

int main(){

    Node *begin;
    Node *end;
    Node *mid;
    char request;
    int val;
    int n;
    int length = 0;
    cin >> n;

    begin = new Node(-1);
    cin >> request;
    cin >> val;
    Node *tmp = insert_after(begin, val);

    for(int i=0; i<n; i++){
        cin >> request;
        switch (request){
            case '+':
                cin >> val;
                end = push_back(end, val);
                length++;
                if(length & 1) mid = mid->next;
                break;
            case '*':
                cin >> val;
                mid = insert_after(mid, val);
                length++;
                if(!length&1) mid = mid->prev;
                break;
            case '-':
                pop_front(begin);
                length--;
                if(length&1) mid = mid->next;
                break;
            default:
                cout << "strange erroooooor\n";
                break;
        }
        print_list(begin);
    }
}


// 1                                ->   2          end
// 1 2                              ->   2          it
// 1 2 3          (len/2) % 2 != 0 ->   3          it + 1
// 1 2 3 4                         ->   3          it
// 1 2 3 4 5       (len/2) % 2 != 0 ->   4          it + 1
// 1 2 3 4 5 6     -                ->   4          it