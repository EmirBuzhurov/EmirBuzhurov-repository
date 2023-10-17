package main
import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    var result int
    for i := 0; i < n; i++ {
        var num int
        fmt.Scan(&num)
        result ^= num
    }
    fmt.Println(result)
}
