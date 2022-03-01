#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int vertex[8];
char vertex_names[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
int diagonals[4][2] = {{0, 6}, {1, 7}, {2, 4}, {3, 5}};
char diagonal_neighbors[4][2] = {{'B','C'}, {'A', 'E'}, {'B','A'}, {'H','E'}};
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
stringstream strm;

int delete_neighbors(){
    // cout << "delete_neighbors" << endl;
    int some_deletions = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(graph[i][j] && vertex[i] && vertex[j]){
                // cout << "delete_dioganales at i=" << i << " j=" << j << endl;
                int diff = vertex[i] > vertex[j] ? vertex[j]: vertex[i];
                for (int k = 0; k < diff; k++){
                    strm << vertex_names[i] << vertex_names[j] << "-" << endl;
                }
                vertex[i] -= diff;
                vertex[j] -= diff;
                some_deletions = 1;
            }
        }
    }
    return some_deletions;
}

int delete_dioganales(){
    // cout << "delete_dioganales" << endl;
    int some_deletions = 0;
    int i_index = 0;
    int j_index = 0;
    for(int i = 0; i < 4; i++){
        i_index = diagonals[i][0];
        j_index = diagonals[i][1];

        if(vertex[i_index] && vertex[j_index]){
            // cout << "delete_dioganales at i=" << i_index << " j=" <<j_index <<endl;
            int diff = vertex[i_index] > vertex[j_index] ? vertex[j_index]: vertex[i_index];
            for(int k = 0; k < diff; k++){
                strm << diagonal_neighbors[i][0] << diagonal_neighbors[i][1] << "+" << endl;
                strm << diagonal_neighbors[i][0] << vertex_names[i_index] << "-" << endl;
                strm << diagonal_neighbors[i][1] << vertex_names[j_index] << "-" << endl;
            }
            vertex[i_index] -= diff;
            vertex[j_index] -= diff;
            some_deletions = 1;
        }
    }
    return some_deletions;
}

void print_vertexes(){
    for (int i = 0; i < 8; i++){
        cout << vertex[i] << " ";
    }
    cout << endl;
}

int main(){
    for (int i = 0; i < 8; i++){
        cin >> vertex[i];
    }
    int something_deleted = 1;
    

    while(something_deleted){
        something_deleted = 0;
        // print_vertexes();
        something_deleted += delete_neighbors();
        something_deleted += delete_dioganales();
    }

    for (int i = 0; i < 8; i++){
        if(vertex[i] != 0){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    string s;
    s = strm.str();
    cout << s;
    return 0;
}