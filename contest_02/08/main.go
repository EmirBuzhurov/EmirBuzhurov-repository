import (
 "strings"
 "unicode"
)
func isPalindrome(s string) bool {
 normalized := strings.ToLower(s)
 normalized = strings.Map(func(r rune) rune {
  if unicode.IsLetter(r) || unicode.IsDigit(r) {
   return r
  }
  return -1
 }, normalized)
 normalized = strings.Replace(normalized, " ", "", -1)

 left := 0
 right := len(normalized) - 1

 for left <= right {
  if normalized[left] != normalized[right] {
   return false
  }
  left++
  right--
 }

 return true
}
