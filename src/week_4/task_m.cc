#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct dot{
    int x;
    int y;
} dot;

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

void clear_arrays(dot** arr1, int** arr2, int N){
    for(int i = 0; i < N; i++){
            delete [] arr1[i];
            delete [] arr2[i];
        }
    delete [] arr1;
    delete [] arr2;
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

char add_new_parent(dot** path, dot v){
    int x = v.x;
    int y = v.y;
    dot parent = path[y][x];
    int parent_x = parent.x;
    int parent_y = parent.y;
    

    if(x + 1 == parent_x  && y == parent_y){
        return 'W';
    }

    if(x - 1 == parent_x  && y == parent_y){
        return 'E';
    }

    if(x == parent_x  && y + 1 == parent_y){
        return 'N';
    }

    if(x == parent_x  && y - 1 == parent_y){
        return 'S';
    }

    return '!';

}

vector<char> bfs(int** map, dot start, dot end, int N, int M, int* time) {

    //массив с минимальным расстоянием до вершины
    int** dist = new int*[N];

    //массив с родителем (откуда мы пришли в эту вершину)
    dot** path = new dot*[N];

    //инициализация этих массивов
    for(int i = 0; i < N; i++){
        dist[i] = new int[M];
        path[i] = new dot[M];
        for(int j = 0; j < M; j++){
            dist[i][j] = INT_MAX;
            path[i][j] = (dot) {.x=-1, .y=-1}; //{-1, -1}
        }
    }

    //делаем стартовую вершину первой
    dist[start.y][start.x] = 0;
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
        q.pop();

        // print_vector(get_neighbors(v, map, N, M));

        for (dot u : get_neighbors(v, map, N, M)) {
            if (dist[u.y][u.x] > dist[v.y][v.x] + map[u.y][u.x] && map[u.y][u.x] != -1) { //TODO: mb remove -1 check
                path[u.y][u.x] = v;
                dist[u.y][u.x] = dist[v.y][v.x] + map[u.y][u.x];
                q.push(u);
            }
        }
    }

    // print_map(dist, N, M, "dist");

    // если пути не существует, возвращаем пустой vector
    if (dist[end.y][end.x] == INT_MAX) {
        *time=-1;
        // clear_arrays(path, dist, N);
        return {};
    }
    *time = dist[end.y][end.x];

    // cout << "main end = {" << end.x << ", " << end.y << "}; " << endl;
    vector<char> min_path;
    // cout << path[end.y][end.x].x << "; ; ; " <<  path[end.y][end.x].y<<endl;
    while (path[end.y][end.x].x != -1 || path[end.y][end.x].y != -1) {
        char ch = add_new_parent(path, end);
        // cout << "end = {" << end.x << ", " << end.y << "}; letter = " << ch << endl;
        min_path.push_back(ch);
        end = path[end.y][end.x];
    }

    // clear_arrays(path, dist, N);

    // путь был рассмотрен в обратном порядке, поэтому его нужно перевернуть
    reverse(min_path.begin(), min_path.end());
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
    vector<char> path = bfs(map, start, stop, N, M, &time);
    
    cout << time << endl;
    if(time != -1){
        for (char i: path){
            cout << i;
        }
        cout << endl;
    }

    for(int i = 0; i < N; i++){
        delete [] map[i];
    }
    delete[] map;
}
