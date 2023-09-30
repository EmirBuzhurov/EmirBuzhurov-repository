package main
import "fmt"

func main() {
    var n int;
    var b float64
    fmt.Scanf("%d", &n)
    s1 := make([]float64, n)
    s2 := make([]float64, n)
    for i:=0;i<n;i++ {
        fmt.Scanf("%f", &b)
        s1[i]=b
    }
    s2[0]=s1[0]
    for i:=1;i<n-1;i++ {
        s2[i]=(s1[i-1]+s1[i]+s1[i+1])/3
    }
    s2[n-1]=s1[n-1]
    for i:=0;i<n;i++ {
        b = s2[i]
        fmt.Print(b);
        fmt.Printf(" ");
    }
}
