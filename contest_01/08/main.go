package main
import "fmt"

func main() {
    var a, b, c int
    fmt.Scanf("%d %d %d", &a, &b, &c);
    if a > b {
        if a > c {
            fmt.Println(a);
        }
        if a < c {
            fmt.Println(c);
        }
    }
    if a < b {
        if b > c {
           fmt.Println(b); 
        }
        if b < c {
            fmt.Println(c);
        }
    }
}
