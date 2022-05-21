#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stack>

using namespace std;

typedef struct dot{
    int x;
    int y;
} dot;

typedef struct child{
    int dist = INT_MAX;
    char path = '!';
} child;

void print_map(int** map, int N, int M, string label){
    cout << "++++" << label <<"+++" << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << "+++++++" << endl;
}

void print_queue(queue<dot> q){
    cout << "[ ";
    while (!q.empty()){
        cout << "("<< q.front().x  << ", " << q.front().y  << ")" << " ";
        q.pop();
    }
    cout << "]" << endl;
}

void print_vector(vector<dot> v){
    cout << "neighbors: ";
    for(auto u: v){
        cout << "{" << u.x << ", " << u.y << "}, ";
    }
    cout <<endl;
}


void print_vertexes(child** arr, int N, int M){
    cout << "======" << "dist" << "======" << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << arr[i][j].dist << " ";
        }
        cout << endl;
    }
    cout << "======" << "path" << "======" << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << arr[i][j].path << " ";
        }
        cout << endl;
    }
    cout << "============" << endl;
}

void clear_arrays(child** arr, int N){
    for(int i = 0; i < N; i++){
        delete [] arr[i];
    }
    delete [] arr;
}

vector<dot> get_neighbors(dot v, int** map, int N, int M){
    int x = v.x;
    int y = v.y;

    vector<dot> neighbors;
    if(x != M - 1){
        neighbors.push_back({x+1, y});
    }
    if(x != 0){
        neighbors.push_back({x-1, y});
    }
    if(y != N - 1){
        neighbors.push_back({x, y+1});
    }
    if(y != 0){
        neighbors.push_back({x, y-1});
    }
    return neighbors;    
}

char get_child_direction(dot v, dot u){
    if(v.x + 1 == u.x  && v.y == u.y){
        return 'E';
    }

    if(v.x - 1 == u.x  && v.y == u.y){
        return 'W';
    }

    if(v.x == u.x  && v.y + 1 == u.y){
        return 'S';
    }

    if(v.x == u.x  && v.y - 1 == u.y){
        return 'N';
    }

    return '!';
}


dot move_to_child(child** vertexes, dot v){
    switch (vertexes[v.y][v.x].path){
    case 'N':
        return (dot) {v.x, v.y + 1};
    case 'S':
        return (dot) {v.x, v.y - 1};
    case 'W':
        return (dot) {v.x + 1, v.y};
    case 'E':
        return (dot) {v.x - 1, v.y};
    
    default:
        cout << "Error! Wrong path!" << endl;
        return (dot) {-1, -1};
    }


}

stack<char> bfs(int** map, dot start, dot end, int N, int M, int* time) {

    //массив с минимальным расстоянием до вершины
    child** vertexes = new child*[N];

    //инициализация этих массивов
    for(int i = 0; i < N; i++){
        vertexes[i] = new child[M];
        for(int j = 0; j < M; j++){
            vertexes[i][j] = {}; //TODO:
        }
    }

    //делаем стартовую вершину первой
    vertexes[start.y][start.x].dist = 0;
    // создаём очередь для bfs
    queue<dot> q;
    // кладём стартовую вершину в очередь 
    q.push(start);

    //для каждой вершины из очереди проверяем можно ли до её соседей
    //дойти быстрее, чем можно было раньше, если можно обновляем путь
    //(через текущую вершину) и расстояние пути
    while (!q.empty()) {
        // print_queue(q);
        dot v = q.front();
        // cout << "popped " << v.x << ", " << v.y << endl;
        q.pop();

        auto neighbors = get_neighbors(v, map, N, M);
        // print_vector(neighbors);
        for (dot u : get_neighbors(v, map, N, M)) {
            if (vertexes[u.y][u.x].dist > vertexes[v.y][v.x].dist + map[u.y][u.x] && map[u.y][u.x] != -1) {
                vertexes[u.y][u.x].path = get_child_direction(v, u);
                vertexes[u.y][u.x].dist = vertexes[v.y][v.x].dist + map[u.y][u.x];
                q.push(u);
                // cout << "added " << u.x << ", " << u.y << endl;
            }
        }
    }

    // print_vertexes(vertexes, N, M);

    // если пути не существует, возвращаем пустой
    if (vertexes[end.y][end.x].dist == INT_MAX) {
        *time=-1;
        clear_arrays(vertexes, N);
        return {};
    }
    *time = vertexes[end.y][end.x].dist;

    stack<char> min_path;
    // cout << "end " << end.x << ", " << end.y << endl;
    while (vertexes[end.y][end.x].path != '!' || vertexes[end.y][end.x].path != '!') {
        min_path.push(vertexes[end.y][end.x].path);
        end = move_to_child(vertexes, end);
        // cout << "end " << end.x << ", " << end.y << endl;
    }

    clear_arrays(vertexes, N);
    return min_path;
}


int** read_map(int N, int M){
    int** map = new int*[N];
    for(int i = 0; i < N; i++){
        map[i] = new int[M];
        for(int j = 0; j < M; j++){
            char dot;
            cin >> dot;
            int val = 0;
            switch (dot){
            case '.': //поле
                val = 1;
                break;
            case 'W': //лес
                val = 2;
                break;
            case '#': //вода
                val = -1;
                break;
            default:
                cout << "Error: invalid input:" << dot << endl;
                break;
            }
            map[i][j] = val;
        }
    }
    return map;
}

int main(){
    int N, M; // N - строки, M - столбцы
    cin >> N >> M;
    // int vertexes = N*M; // количество вершин

    // читаем начало и конец
    dot start, stop;
    cin >> start.y >> start.x >> stop.y >> stop.x;
    //уменьшаем на 1 чтобы это было индексами массива
    start.x--;
    start.y--;
    stop.x--;
    stop.y--;

    // cout << "points: start(" << start.x << ", " << start.y << ") stop("<< stop.x << ", " << stop.y << ")" << endl;

    // считываем карту
    int** map = read_map(N, M);
    // print_map(map, N, M, "map");

    int time = -1; 
    stack<char> path = bfs(map, start, stop, N, M, &time);
    
    cout << time << endl;
    while(!path.empty()){
        cout << path.top();
        path.pop();
    }
    

    for(int i = 0; i < N; i++){
        delete [] map[i];
    }
    delete[] map;
}
