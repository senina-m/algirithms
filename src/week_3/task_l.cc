#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
    int N, K;
    cin >> N >> K;
    int a[N], b[N], c[N];

    if(K == 1){
        for (int i = 0; i < N; i++){
            cin >> a[i];
            cout << a[i] << " ";
        }
        cout << endl;
        return 0;
    }
    K--;
    for(int i=0; i<N; i++){
        cin >> a[i];
        b[i] = i % K ? (a[i] < b[i-1] ? a[i] : b[i-1]) : a[i];
    }
    c[N-1] = a[N-1];
    for(int i = N-2; i>=0; i--){
        c[i] = (i+1) % K ? (a[i] < c[i+1] ? a[i] : c[i+1]) : a[i];
    }

    for(int i=0; i<N-K; i++){
        cout << (c[i]<b[i+K]?c[i]:b[i+K]) << " ";
    }
    cout << endl;
    return 0;
}
