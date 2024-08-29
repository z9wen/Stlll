#ifndef VECC_H
#define VECC_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
public:
    // Constructors
    Vector() : size_(0), capacity_(1), data_(new T[1]) {}
    explicit Vector(size_t size) : size_(size), capacity_(size), data_(new T[size]) {}

    // Destructor
    ~Vector() { delete[] data_; }

    // Copy Constructor
    Vector(const Vector& other) : size_(other.size_), capacity_(other.capacity_), data_(new T[other.capacity_]) {
        std::copy(other.data_, other.data_ + size_, data_);
    }

    // Move Constructor
    Vector(Vector&& other) noexcept : size_(other.size_), capacity_(other.capacity_), data_(other.data_) {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    // Copy Assignment Operator
    Vector& operator=(const Vector& other) {
        if (this == &other) return *this;

        delete[] data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new T[capacity_];
        std::copy(other.data_, other.data_ + size_, data_);
        return *this;
    }

    // Move Assignment Operator
    Vector& operator=(Vector&& other) noexcept {
        if (this == &other) return *this;

        delete[] data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = other.data_;
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
        return *this;
    }

    // Element Access
    T& operator[](size_t index) {
        if (index >= size_) throw std::out_of_range("Index out of range");
        return data_[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size_) throw std::out_of_range("Index out of range");
        return data_[index];
    }

    // Size and Capacity
    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }

    // Modifiers
    void push_back(const T& value) {
        if (size_ == capacity_) {
            reserve(capacity_ * 2);
        }
        data_[size_++] = value;
    }

    void pop_back() {
        if (size_ > 0) {
            --size_;
        }
    }

    void reserve(size_t new_capacity) {
        if (new_capacity <= capacity_) return;

        T* new_data = new T[new_capacity];
        std::copy(data_, data_ + size_, new_data);
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

    void clear() { size_ = 0; }

private:
    size_t size_;
    size_t capacity_;
    T* data_;
};

#endif // VECC_H