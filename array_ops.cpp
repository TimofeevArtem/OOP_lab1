#include <iostream>
#include <cstddef>
#include "array_ops.h"

int* array_create(std::size_t size){
    int* arr = new int[size + 1];
    arr[0] = 0;
    return arr;
}

void array_delete(int*& arr){
    delete[] arr;
    arr = nullptr;
}

int* array_resize(int* arr, std::size_t size, std::size_t new_size){
    std::size_t count = arr[0];
    if (new_size < count){
        return arr;
    }
    int* new_arr = new int[new_size + 1];
    new_arr[0] = arr[0];

    for (std::size_t i = 1; i <= count; ++i){
        new_arr[i] = arr[i];
    }
    delete[] arr;
    return new_arr;
}

int* array_insert(int* arr, std::size_t& size, std::size_t pos, int value){
    std::size_t count = arr[0];
    if (pos > count){
        return arr;
    }

    if (count >= size){
        std::size_t new_size;
        if (size == 0){
            new_size = 1;
        }
        else{
            new_size = size * 2;
        }
        arr = array_resize(arr, size, new_size);
        size = new_size;
    }

    for(std::size_t i = count; i > pos; --i){
        arr[i + 1] = arr[i];
    }
    arr[pos + 1] = value;
    arr[0]++;
    return arr;
}

void array_print(const int* arr, std::size_t size){
    if (arr == nullptr){
        std::cout << "Массив не найден"<< std::endl;
        return;
    }

    if (arr[0] == 0){
        std::cout << "[]"<< std::endl;
        return;
    }
    std::cout<< '[';
    for(std::size_t i = 1; i <= arr[0]; ++i){
        std::cout << arr[i];
        if (i < arr[0]){
            std::cout << ", ";
        }
    }
    std::cout << ']'<< std::endl;
}

int* array_remove(int* arr, std::size_t& size, std::size_t pos){
    if (arr == nullptr){
        return nullptr;
    }
    std::size_t count = arr[0];
    if (count == 0){
        return arr;
    }

    if (pos >= count){
        return arr;
    }

    for(std::size_t i = pos; i < count - 1; ++i){
        arr[i + 1] = arr[i + 2];
    }
    arr[0]--;

    return arr;
}

int* bubble_sort(int* arr, std::size_t size){
    if (arr == nullptr){
        return nullptr;
    }
    std::size_t count = arr[0];
    if (count <= 1){
        return arr;
    }
    for(std::size_t i = 1; i < count; ++i){
        for(std::size_t j = 1; j <= count - i; ++j){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

bool array_binary_search(const int* arr, std::size_t size, int target, std::size_t& out_index){
    if (arr == nullptr){
        return false;
    }
    std::size_t count = arr[0];
    out_index = 0;
    if (count == 0){
        return false;
    }

    std::size_t left = 1;
    std::size_t right = count;

    int* mutable_arr = const_cast<int*>(arr);
    mutable_arr = bubble_sort(mutable_arr, size);
    std::cout << "Отсортированный массив: ";
    array_print(mutable_arr, size);
    while (left <= right){
        std::size_t mid = left + (right - left) / 2;

        if (mutable_arr[mid] == target){
            out_index = mid - 1;
            return true;
        }
        else if (mutable_arr[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return false;
}

int* array_unique(int* arr, std::size_t& size){
    if (arr == nullptr){
        return nullptr;
    }
    std::size_t count = arr[0];
    if (count == 0){
        return arr;
    }
    arr = bubble_sort(arr, size);
    std::size_t new_count = 1;
    for(std::size_t i = 2; i <= count; ++i){
        if (arr[i] != arr[new_count]){
            new_count++;
            arr[new_count] = arr[i];
        }
    }
    arr[0] = new_count;

    return arr;
}