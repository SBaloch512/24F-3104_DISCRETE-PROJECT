// DynamicArray.h
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
using namespace std;

template <typename T>
class DynamicArray {
private:
    T* data;
    int capacity;
    int size;
    
    void resize();
    
public:
    DynamicArray();
    ~DynamicArray();
    
    void push_back(T value);
    T& operator[](int index);
    const T& operator[](int index) const;
    int getSize() const;
    bool contains(T value) const;
    void remove(T value);
    void pop_back();
    void clear();
    void print() const;
    T* getData();
};

// Template implementation must be in header
template <typename T>
DynamicArray<T>::DynamicArray() : capacity(10), size(0) {
    data = new T[capacity];
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template <typename T>
void DynamicArray<T>::resize() {
    capacity *= 2;
    T* newData = new T[capacity];
    for(int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

template <typename T>
void DynamicArray<T>::push_back(T value) {
    if(size >= capacity) resize();
    data[size++] = value;
}

template <typename T>
T& DynamicArray<T>::operator[](int index) {
    return data[index];
}

template <typename T>
const T& DynamicArray<T>::operator[](int index) const {
    return data[index];
}

template <typename T>
int DynamicArray<T>::getSize() const {
    return size;
}

template <typename T>
bool DynamicArray<T>::contains(T value) const {
    for(int i = 0; i < size; i++) {
        if(data[i] == value) return true;
    }
    return false;
}

template <typename T>
void DynamicArray<T>::remove(T value) {
    for(int i = 0; i < size; i++) {
        if(data[i] == value) {
            for(int j = i; j < size - 1; j++) {
                data[j] = data[j + 1];
            }
            size--;
            return;
        }
    }
}
template <typename T>
void DynamicArray<T>::pop_back() {
    if (size > 0) {
        size--;
    }
}
template <typename T>
void DynamicArray<T>::clear() {
    size = 0;
}

template <typename T>
void DynamicArray<T>::print() const {
    cout << "{ ";
    for(int i = 0; i < size; i++) {
        cout << data[i];
        if(i < size - 1) cout << ", ";
    }
    cout << " }";
}

template <typename T>
T* DynamicArray<T>::getData() {
    return data;
}

#endif