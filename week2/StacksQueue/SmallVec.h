//
// Created by brayden on 2019-08-17.
//

#ifndef STACKSQUEUE_SMALLVEC_H
#define STACKSQUEUE_SMALLVEC_H

#include <memory>
#include <string>

template <typename T>
class SmallVec {
public:
    SmallVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { };
    SmallVec(std::initializer_list<T> il);
    SmallVec &operator=(std::initializer_list<T> il);
    SmallVec(const SmallVec &);
    SmallVec &operator=(const SmallVec &);
    T &operator[](size_t n);
    const T &operator[](size_t n) const;
    SmallVec(SmallVec &&) noexcept ;
    SmallVec &operator=(SmallVec &&) noexcept ;
    ~SmallVec();
    void push_back(const T &);
    void push_back(T &&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    T *begin() const { return elements; }
    T *end() const { return first_free; }
    void reserve(size_t n);
    void resize(size_t n);
    void resize(size_t n, const T &);

private:
    static std::allocator<T> alloc;
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<T *, T *> alloc_n_copy(const T *, const T *);
    void alloc_n_move(size_t new_cap);
    void free();
    void reallocate();
    void check(size_t n, const std::string &msg);
    T *elements;
    T *first_free;
    T *cap;

};

template <typename T>
std::allocator<T> SmallVec<T>::alloc;

template <typename T>
void SmallVec<T>::push_back(const T &elem) {
    chk_n_alloc();
    alloc.construct(first_free++, elem);
}

template <typename T>
void SmallVec<T>::push_back(T &&elem) {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(elem));
}

template <typename T>
void SmallVec<T>::free() {
    if (elements) {
        for (auto p = first_free; p != elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
SmallVec<T>::~SmallVec() {
    free();
}

template <typename T>
std::pair<T *, T *> SmallVec<T>::alloc_n_copy(const T *b, const T *e) {
    auto data = alloc.allocate(e - b );
    return {data, std::uninitialized_copy(b, e, data)};
}

template <typename T>
SmallVec<T>::SmallVec(const SmallVec &rhs) {
    auto new_data = alloc_n_copy(rhs.begin(), rhs.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

template <typename T>
SmallVec<T>& SmallVec<T>::operator=(const SmallVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = elements = data.second;
    return *this;
}

template <typename T>
SmallVec<T>::SmallVec(SmallVec &&rhs) noexcept
    : elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap) {
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

template <typename T>
SmallVec<T>& SmallVec<T>::operator=(SmallVec &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.free();
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

template <typename T>
void SmallVec<T>::alloc_n_move(size_t new_cap) {
    auto new_data = alloc.allocate(new_cap);
    auto dest = new_data;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = new_data;
    first_free = dest;
    cap = elements + new_cap;
}

template <typename T>
void SmallVec<T>::reallocate() {
    size_t newcapacity = size() ? 2 * size() : 1;
    alloc_n_move(newcapacity);
}

template <typename T>
SmallVec<T>::SmallVec(std::initializer_list<T> il) {
    auto data = alloc_n_copy(il.begin(), il.end());
    elements = data.first;
    first_free = cap = data.second;
}

template <typename T>
SmallVec<T>& SmallVec<T>::operator=(std::initializer_list<T> il) {
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template <typename T>
void SmallVec<T>::check(size_t n, const std::string &msg) {
    if (n > size())
        throw std::out_of_range(msg);
}

template <typename T>
T &SmallVec<T>::operator[](size_t n) {
    check(n, "subscript out of range");
    return *(elements + n);
}

template <typename T>
const T &SmallVec<T>::operator[](size_t n) const {
    check(n, "subscript out of range");
    return *(elements + n);
}

template <typename T>
void SmallVec<T>::reserve(size_t n) {
    if (n > capacity())
        alloc_n_move(n);
}

template <typename T>
void SmallVec<T>::resize(size_t n) {
    resize(n, T());
}

template <typename T>
void SmallVec<T>::resize(size_t n, const T &fill) {
    if (n < size()) {
        while (first_free != elements + n)
            alloc.destroy(--first_free);
    } else if (n > size()) {
        if (n > capacity()) reserve(2 * n);
        for (size_t i = size(); i != n; ++i)
            alloc.construct(first_free++, fill);
    }
}

#endif //STACKSQUEUE_SMALLVEC_H
