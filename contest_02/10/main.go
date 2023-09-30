func shift(data []int, steps int) {
    n := len(data)
    shift := steps % n
    if shift < 0 {
        shift += n
    }
    temp := make([]int, n)
    copy(temp, data[n-shift:])
    copy(temp[shift:], data[:n-shift])
    copy(data, temp)
}
