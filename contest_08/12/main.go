type SimpleStack struct {
 data []rune
}

func NewSimpleStack() *SimpleStack {
 return &SimpleStack{data: []rune{}}
}

func (s *SimpleStack) empty() bool {
 return len(s.data) == 0
}

func (s *SimpleStack) push(r rune) {
 s.data = append(s.data, r)
}

func (s *SimpleStack) top() rune {
 if len(s.data) == 0 {
  return 0
 }
 return s.data[len(s.data)-1]
}

func (s *SimpleStack) pop() rune {
 if len(s.data) == 0 {
  return 0
 }
 r := s.data[len(s.data)-1]
 s.data = s.data[:len(s.data)-1]
 return r
}
