#include <queue>
bool is_can_exit_from_maze(const std::vector<std::string>& maze, int row, int col) {
    int a = maze.size();
    int b = maze[0].size();
    std::vector<std::vector<bool>> visited(a, std::vector<bool>(b, false));
    std::queue<std::pair<int, int>> q;
    q.push({ row, col });
    visited[row][col] = true;
    std::vector<int> dx = { 0, 0, -1, 1 };
    std::vector<int> dy = { -1, 1, 0, 0 };
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if (maze[r][c] == 'E') {
            return true;
        }
        for (int k = 0; k < 4; k++) {
            int nr = r + dx[k];
            int nc = c + dy[k];
            if (nr >= 0 && nr < a && nc >= 0 && nc < b && maze[nr][nc] != '#' && !visited[nr][nc]) {
                q.push({ nr, nc });
                visited[nr][nc] = true;
            }
        }
    }
    return false;
}
