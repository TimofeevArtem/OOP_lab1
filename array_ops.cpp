#include <iostream>
#include <cstddef>

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
        std::cout << "Новый размер массива не может быть меньше количества элементов"<< std::endl;
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
        std::cout << "Неправильная позиция"<< std::endl;
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
        std::cout << "Массив пустой"<< std::endl;
        return arr;
    }

    if (pos >= count){
        std::cout << "Неправильная позиция"<< std::endl;
        return arr;
    }

    for(std::size_t i = pos; i < count - 1; ++i){
        arr[i + 1] = arr[i + 2];
    }
    arr[0]--;

    return arr;
}