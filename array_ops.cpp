#include <iostream>
#include <cstddef>

int* array_create(std::size_t size){
    if (size == 0){
        return nullptr;
    }
    int* arr = new int[size];
    return arr;
}

void array_delete(int*& arr){
    delete[] arr;
    arr = nullptr;
}

int* array_resize(int* arr, std::size_t size, std::size_t new_size){
    std::size_t num_elem;
    if (new_size == 0){
        delete[] arr;
        arr = nullptr;
        return arr;
    }
    int* new_arr = new int[new_size];
    if (new_size > size){
        num_elem = size;
    }
    else{
        num_elem = new_size;
    }

    for(std::size_t i = 0; i < num_elem; i++){
        new_arr[i] = arr[i];
    }

    for(std::size_t i = num_elem; i < new_size; i++){
        new_arr[i] = 0;
    }

    delete[] arr;
    arr = nullptr;
    return new_arr; 
}


int* array_insert(int* arr, std::size_t& size, std::size_t pos, int value){
    if (pos > size){
        return arr;
    }
    int* new_arr = new int[size + 1];
    for(std::size_t i = 0; i < pos; i++){
        new_arr[i] = arr[i];
    }
    new_arr[pos] = value;
    for(std::size_t i = pos; i < size; i++){
        new_arr[i + 1] = arr[i];
    }
    delete[] arr;
    ++size;
    return new_arr;
}

void array_print(const int* arr, std::size_t size) {
    if (arr == nullptr || size == 0) {
        std::cout << "[]"<< std::endl;
        return;
    }
    std::cout << '[';
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i + 1 < size) std::cout << ", ";
    }
    std::cout << "]\n";
}

int* array_remove(int* arr, std::size_t& size, std::size_t pos){
    int* new_arr = new int[size - 1];
    for(std::size_t i = size - 1; i > pos; i--){
        new_arr[i - 1] = arr[i];
    }
    for(std::size_t i = 0; i < pos; i ++){
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = nullptr;
    --size;
    return new_arr;
}