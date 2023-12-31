using namespace std;

Any::Any(int* data) {
    this->data = data;
    this->type = Type::INT;
}
Any::Any(double* data) {
    this->data = data;
    this->type = Type::DOUBLE;
}
Any::Any(string* data) {
    this->data = data;
    this->type = Type::STRING;
}
Any::Any(vector<Any*>* data) {
    this->data = data;
    this->type = Type::VECTOR_ANY_PTR;
}
Any::~Any() {
    if (type == Type::VECTOR_ANY_PTR) {
        auto realPtr = static_cast<vector<Any*>*>(data);
        for (auto &it : *realPtr) {
            delete it;
        }
        delete realPtr;
    } else if (type == Type::INT) {
        int* realPtr = static_cast<int*>(data);
        delete realPtr;
    } else if (type == Type::DOUBLE) {
        double* realPtr = static_cast<double*>(data);
        delete realPtr;
    } else if (type == Type::STRING) {
        string* realPtr = static_cast<string*>(data);
        delete realPtr;
    }
}
Any::operator int() {
    if (type != Type::INT) {
        throw "";
    }
    return *static_cast<int*>(data);
}
Any::operator double() {
    if (type != Type::DOUBLE) {
        throw "";
    }
    return *static_cast<double*>(data);
}
Any::operator string() {
    if (type != Type::STRING) {
        throw "";
    }
    return *static_cast<string*>(data);
}
Any::operator vector<Any*>*() {
    if (type != Type::VECTOR_ANY_PTR) {
        throw "";
    }
    return static_cast<vector<Any*>*>(data);
}
ostream& operator<<(ostream& out, const Any& val) {
    if (val.type == Any::Type::VECTOR_ANY_PTR) {
        auto realPtr = static_cast<vector<Any*>*>(val.data);
        for (auto &it : *realPtr) {
            out << *it << " ";
        }
    } else if (val.type == Any::Type::INT) {
        int* realPtr = static_cast<int*>(val.data);
        out << *realPtr;
    } else if (val.type == Any::Type::DOUBLE) {
        double* realPtr = static_cast<double*>(val.data);
        out << *realPtr;
    } else if (val.type == Any::Type::STRING) {
        string* realPtr = static_cast<string*>(val.data);
        out << *realPtr;
    }
    return out;
}
