import "strconv"
func isLucky(n string) bool {
 if len(n) != 6 {
  return false
 }
 sum1 := 0
 sum2 := 0
 for i := 0; i < len(n)/2; i++ {
  n, err := strconv.Atoi(string(n[i]))
  if err != nil {
   return false
  }
  sum1 += n
 }
 for i := len(n) / 2; i < len(n); i++ {
  n, err := strconv.Atoi(string(n[i]))
  if err != nil {
   return false
  }
  sum2 += n
 }
 if sum1 == sum2 {
  return true
 }
 return false
}
