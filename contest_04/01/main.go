package main
import (
  "encoding/json"
  "fmt"
  "io"
  "os"
)
type Project struct {
  ProjectID int `json:"project_id"`
  Tasks []Task `json:"tasks"`
}

type Task struct {
  UserID int    `json:"user_id"`
  ID int    `json:"id"`
  Title string `json:"title"`
  Completed bool `json:"completed"`
}

func main() {
  var userID int
  fmt.Scan(&userID)
  file, _ := os.Open("data.json")
  defer file.Close()
  data, _ := io.ReadAll(file)
  var projects []Project
  err := json.Unmarshal(data, &projects)
  if err != nil {
    fmt.Println(err)
    return
  }
  completedTasks := 0
  for _, project := range projects {
    for _, task := range project.Tasks {
      if task.UserID == userID && task.Completed {
        completedTasks++
      }
    }
  }
  fmt.Println(completedTasks)
}
