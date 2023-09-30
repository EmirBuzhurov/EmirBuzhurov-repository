package main
import "fmt"

func main() {
    var a, b, c, d, e, f, g int
    fmt.Scanf("%d\n",&f);
    g = f
    if f>=5000{
        a = f / 5000
        g = f%5000
    }
    if g>=1000{
        b = g / 1000
        g = g%1000
    }
    if g>=500{
        c = g / 500
        g = g%500
    }
    if g>=200{
        d = g / 200
        g = g%200
    }
    if g>=100{
        e = g / 100
        g = g%100
    }
   fmt.Println(a,b,c,d,e)
}
