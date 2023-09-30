package main

import (
 "fmt"
)

func main() {
 var a, b, d int
 a = 0
 b = 0
 d = 1
 fmt.Scan(&a, &b)
 fmt.Print("    |")
 for i := 1; i <= b; i++ {
  if i/10 < 1 {
  fmt.Print("   ",i)
  } else if i/10 >= 1 {
  fmt.Print("  ",i)
  }   
 }
 fmt.Println("   ")
 fmt.Print("   ")
 fmt.Print("--")
 for i := 0; i < b; i++ {
  fmt.Print("----")
  }
 fmt.Println()
 for i := 1; i <= a; i++ {
     if i/10 < 1 {
         fmt.Print("   ", i, "|")
     } else {
         fmt.Print("  ", i, "|")
     }
  d = i
  for j := 1; j <= b; j++ {
   if j*d/10 < 1 && j*d/100 < 1{
    fmt.Print("   ", j*d)
   } else if j*d/10 >= 1 && j*d/100 < 1{
    fmt.Print("  ", j*d)
   } else if j*d/10 >= 1 && j*d/100 >= 1{
    fmt.Print(" ", j*d)
   }
  }
  fmt.Println()
 }
}
