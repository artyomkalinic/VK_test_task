#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

void bfs(std::vector<std::vector<int>>& graph, int start) {
    std::queue<int> q;
    std::vector<int> ans(graph.size(), -1);
    ans[start] = 0;

    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int vert : graph[cur]) {
            if (ans[vert] == -1) {
                q.push(vert);
                ans[vert] = ans[cur] + 1;
            }
        } 
    }
    for (int i = 0; i < graph.size(); ++i) {
        std::cout << ans[i] << std::endl;
    }
};

int main() {
    std::ifstream in("graph.txt");
    int n, m, start;
    if (in.is_open()) {
        in >> n >> m;
        std::vector<std::vector<int>> graph(n);
        for (int i = 0; i < m; ++i) {
            int from, to;
            in >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        in >> start;
        bfs(graph, start);
    }
    in.close();
return 0;
}