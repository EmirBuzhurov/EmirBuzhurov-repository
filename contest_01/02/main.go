package main
import (
"fmt"
"math"
)

func main() {
    var a, b, c float64
    a = 0.5*365
    b = math.Ceil(a/20)
    c = math.Ceil(a/32)
    fmt.Println(a, c, b)
}
