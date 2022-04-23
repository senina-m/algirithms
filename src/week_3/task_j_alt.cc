#include <iostream>
#include <list>

using namespace std;


void print_list(list<int> list, int center){
    cout << "Center is on i=" << center << " [";
    for (int v : list){
        cout << v << " ";
    }
    cout << "]" << endl;

}

int main(){
    int n;
    cin >> n;

    list<int> queue;
    char request;
    int val;
    int size = 0;
    auto mid = queue.end();
    for (int i = 0; i < n; i++){
        cin >> request;
        cout << "received request: " << request << endl;
        switch(request){
            case '+':
                cin >> val;
                printf("before push back mid = %d\n", *mid);
                queue.push_back(val);
                printf("after push back mid = %d\n", *mid);
                printf("size: %d\n", queue.size());
                // mid--;
                if(queue.size() % 2 != 0){
                    mid++;
                }
                //     printf("found +, and found odd size, incrementing\n");
                //     mid++;
                //     printf("after increment back mid = %d\n", *mid);
                //     mid++;
                //     printf("after increment back mid = %d\n", *mid);
                // }

                break;

            case '*':
                cin >> val;
                mid = queue.insert(mid, val);
                if(queue.size() % 2 != 0){ //odd len
                    mid++;
                }
                break;
            case '-':
                cout << queue.front() << endl;
                queue.pop_front();
                if(queue.size() % 2 != 0){
                    mid++;
                }
                break;
            default:
                cout << "line " << i << " -- error!" << endl;
        }
        print_list(queue, distance(queue.begin(), mid));
    }
}