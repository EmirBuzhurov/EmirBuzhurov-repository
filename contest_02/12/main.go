func fill(maze [][]int) {
    rows := len(maze)
    cols := len(maze[0])

    for i := 0; i < rows; i++ {
        for j := 0; j < cols; j++ {
            if maze[i][j] != -1 {
                count := 0
                for row := i - 1; row <= i+1; row++ {
                    for col := j - 1; col <= j+1; col++ {
                        if row >= 0 && row < rows && col >= 0 && col < cols && maze[row][col] == -1 {
                            count++
                        }
                    }
                }
                maze[i][j] = count
            }
        }
    }
}
