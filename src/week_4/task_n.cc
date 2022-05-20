#include <iostream>

using namespace std;

void clear_bool_arr(bool* arr, int n){
    for (int k = 0; k < n; k++){
        arr[k] = false;
    }
}

int DFS(int* pigs, bool* visited, bool* local, int index) {

    local[index] = true;
    // cout << "locally visited: " << index + 1<< endl;

    // если вершину уже встречали в предыдущей компоненте
    // эту компоненту не учитываем
    if(visited[pigs[index]]){
        visited[index] = true;
        // cout << "0 visited: " << index + 1 << endl;
        return 0;
    }

    if (!local[pigs[index]]){
        if (!DFS(pigs, visited, local, pigs[index])){
            visited[index] = true;
            // cout << "0 visited: " << index + 1 << endl;
            return 0;
        }
    } 
    visited[index] = true;
    // cout << "1 visited: " << index + 1<< endl;
    return 1;
}

int main(){
    int n;
	cin >> n;

	int pigs[n];
	bool visited[n] = {true};
	bool local[n] = {true};
    int v_count = 0;
	for (int i = 0; i < n; i++) {
		cin >> pigs[i];
        pigs[i]--;
        visited[pigs[i]] = false;
        v_count++;
        // cout << "unvisited: " << i + 1 << endl;
	}

    int components = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            clear_bool_arr(local, n);
            components += DFS(pigs, visited, local, i);
            // cout << "_________" << endl;
        }
    }

    // cout << "-------";
    cout << components;
}