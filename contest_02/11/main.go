func isValidSudoku(board [rows][cols]int) bool {

    for row := 0; row < rows; row++ {
        nums := make([]bool, 10) 
        for col := 0; col < cols; col++ {
            num := board[row][col]
            if num != 0 {
                if nums[num] { 
                    return false
                }
                nums[num] = true 
            }
        }
    }

    for col := 0; col < cols; col++ {
        nums := make([]bool, 10)
        for row := 0; row < rows; row++ {
            num := board[row][col]
            if num != 0 {
                if nums[num] {
                    return false
                }
                nums[num] = true
            }
        }
    }

    for startRow := 0; startRow < rows; startRow += 3 {
        for startCol := 0; startCol < cols; startCol += 3 {
            nums := make([]bool, 10)
            for row := startRow; row < startRow+3; row++ {
                for col := startCol; col < startCol+3; col++ {
                    num := board[row][col]
                    if num != 0 {
                        if nums[num] {
                            return false
                        }
                        nums[num] = true
                    }
                }
            }
        }
    }
    
    return true
}
