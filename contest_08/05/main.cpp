class IntSharedPointer {
private:
    int* ref;
    int* p;
    void decreaseRef() {
        (*ref)--;
        if (*ref == 0) {
            delete p;
            delete ref;
        }
    }
    void copyRef(const IntSharedPointer& b) {
        p = b.p;
        ref = b.ref;
        (*ref)++;
    }
public:
    IntSharedPointer(int* pointer) {
        ref = new int{1};
        p = pointer;
    }
    IntSharedPointer(IntSharedPointer& b) {
        copyRef(b);
    }
    ~IntSharedPointer() {
        decreaseRef();
    }
    int& operator*() {
        return *p;
    }
    IntSharedPointer& operator=(const IntSharedPointer& b) {
        if (this == &b) {
            return *this;
        }
        decreaseRef();
        copyRef(b);
        return *this;
    }
};
