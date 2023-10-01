Student make_student(const std::string& line) {
    size_t delim_pos = line.find(';');
    std::string name = line.substr(0, delim_pos);
    std::string group = line.substr(delim_pos + 1);
    return {name, group};
}
bool is_upper(const Student& s1, const Student& s2) {
    if (s1.group < s2.group) {
        return true;
    } else if (s1.group > s2.group) {
        return false;
    } else {
        return s1.name < s2.name;
    }
}
void print(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "Empty list!\n";
        return;
    }
    std::string current_group = students[0].group;
    std::cout << current_group << "\n";
    for (const Student& student : students) {
        if (student.group != current_group) {
            current_group = student.group;
            std::cout << current_group << "\n";
        }
        std::cout << "- " << student.name << "\n";
    }
}
