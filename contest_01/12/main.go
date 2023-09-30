package main
import "fmt"

func main() {
    var x, g int
    fmt.Scanf("%d", &x)
    for i:=0; i!=1;i++{
        if x == 1 {break}
        if x % 2 != 0 {x = x*3 + 1
        }else if x % 2 == 0 {x = x / 2}
        g++
        i=x
    }
    fmt.Println(g)
}
