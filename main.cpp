#include <iostream>
#include "array_ops.h"

int main(){
    int fl = 0;
    std::size_t size = 0;
    std::size_t input;
    std::size_t new_size;
    std::size_t pos;
    int value;
    int* arr_ptr = nullptr;

    while (fl != 1){
        std::cout << "\n";
        std::cout << "1. Создать массив"<< std::endl;
        std::cout << "2. Удалить массив"<< std::endl;
        std::cout << "3. Вставить элемент"<< std::endl;
        std::cout << "4. Удалить элемент"<< std::endl;
        std::cout << "5. Изменить размер"<< std::endl;
        std::cout << "6. Напечатать массив"<< std::endl;
        std::cout << "7. Сортировка массива + Поиск элемента"<< std::endl;
        std::cout << "8. Удаление дубликатов + Сортировка"<< std::endl;
        std::cout << "0. Выход"<< std::endl;

        std::cout << "\nВыберите действие: ";
        while (!(std::cin >> input)){
            std::cout << "Введите число от 0 до 8"<< std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "\nВыберите действие: ";
        }
        std::cout << "\n";

        switch (input){
            case 1:
            {
                if (arr_ptr != nullptr){
                    array_delete(arr_ptr);
                    size = 0;
                }
                std::cout << "Введите размер массива: ";
                long long temp_size;
                while (true){
                    if (!(std::cin >> temp_size)){
                        std::cout << "Введите корректный размер массива"<< std::endl;
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Введите размер массива: ";
                        continue;
                    }
                    if (temp_size <= 0){
                        std::cout << "Размер массива должен быть больше 0"<< std::endl;
                        std::cin.ignore(1000, '\n');
                        std::cout << "Введите размер массива: ";
                        continue;
                    }
                    size = static_cast<std::size_t>(temp_size);
                    break;
                }
                arr_ptr = array_create(size);

                if (arr_ptr != nullptr){
                    std::cout << "Массив создан"<< std::endl;
                }
                else{
                    std::cout << "Ошибка при создании массива"<< std::endl;
                }
                break;
            }

            case 2:
            {
                if (arr_ptr == nullptr){
                    std::cout << "Массив не создан"<< std::endl;
                    break;
                }
                array_delete(arr_ptr);
                size = 0;
                std::cout << "Массив удалён"<< std::endl;
                break;
            }

            case 3:
            {
                if (arr_ptr == nullptr){
                    std::cout << "Массив не создан"<< std::endl;
                    break;
                }

                std::cout << "Введите элемент для вставки: ";
                while (!(std::cin >> value)){
                    std::cout << "Введите корректное целое число"<< std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Введите элемент для вставки: ";
                }

                std::cout << "Введите позицию, на которую необходимо вставить элемент: ";
                long long temp_pos;
                while (true){
                    if (!(std::cin >> temp_pos)){
                        std::cout << "Введите корректную позицию"<< std::endl;
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Введите позицию, на которую необходимо вставить элемент: ";
                        continue;
                    }
                    if (temp_pos < 0){
                        std::cout << "Позиция не может быть отрицательной"<< std::endl;
                        std::cin.ignore(1000, '\n');
                        std::cout << "Введите позицию, на которую необходимо вставить элемент: ";
                        continue;
                    }
                    pos = static_cast<std::size_t>(temp_pos);
                    break;
                }
                if (pos > arr_ptr[0]){
                    std::cout << "Неправильная позиция"<< std::endl;
                    break;
                }
                arr_ptr = array_insert(arr_ptr, size, pos, value);
                break;
            }

            case 4:
            {
                if (arr_ptr == nullptr){
                    std::cout << "Массив не создан"<< std::endl;
                    break;
                }

                if (arr_ptr[0] == 0){
                    std::cout << "Массив пуст"<< std::endl;
                    break;
                }

                std::cout << "Введите индекс элемента, который необходимо удалить: ";
                long long temp_remove_pos;
                while (true){
                    if (!(std::cin >> temp_remove_pos)){
                        std::cout << "Введите корректный индекс"<< std::endl;
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Введите индекс элемента, который необходимо удалить: ";
                        continue;
                    }
                    if (temp_remove_pos < 0){
                        std::cout << "Индекс не может быть отрицательным"<< std::endl;
                        std::cin.ignore(1000, '\n');
                        std::cout << "Введите индекс элемента, который необходимо удалить: ";
                        continue;
                    }
                    pos = static_cast<std::size_t>(temp_remove_pos);
                    break;
                }
                if (pos >= arr_ptr[0]){
                    std::cout << "Неправильная позиция"<< std::endl;
                    break;
                }

                arr_ptr = array_remove(arr_ptr, size, pos);
                break;
            }

            case 5:
            {
                if (arr_ptr == nullptr){
                    std::cout << "Массив не создан"<< std::endl;
                    break;
                }

                std::cout << "Введите новый размер массива: ";
                long long temp_new_size;
                while (true){
                    if (!(std::cin >> temp_new_size)){
                        std::cout << "Введите корректный размер"<< std::endl;
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Введите новый размер массива: ";
                        continue;
                    }
                    if (temp_new_size <= 0){
                        std::cout << "Размер массива должен быть больше 0"<< std::endl;
                        std::cin.ignore(1000, '\n');
                        std::cout << "Введите новый размер массива: ";
                        continue;
                    }
                    new_size = static_cast<std::size_t>(temp_new_size);
                    break;
                }
                if (new_size < arr_ptr[0]){
                    std::cout << "Новый размер массива не может быть меньше количества элементов"<< std::endl;
                    break;
                }
                arr_ptr = array_resize(arr_ptr, size, new_size);
                size = new_size;
                break;
            }
            case 6:
            {
                array_print(arr_ptr, size);
                break;
            }
            case 7:
            {
                int target;
                std::cout << "Введите элемент для поиска: ";
                while (!(std::cin >> target)){
                    std::cout << "Введите корректное целое число"<< std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Введите элемент для поиска: ";
                }
                std::size_t index;
                if (array_binary_search(arr_ptr, size, target, index)){
                    std::cout << "Элемент найден на позиции: "<< index << std::endl;
                }
                else{
                    std::cout << "Элемент не найден"<< std::endl;
                }
                break;
            }
            case 8:
            {
                arr_ptr = array_unique(arr_ptr, size);
                break;
            }

            case 0:
            {
                fl = 1;
                break;
            }


            default:
            {
                std::cout
                    << "Введите число от 0 до 8."
                    << std::endl;

                break;
            }
        }
    }

    if (arr_ptr != nullptr){
        array_delete(arr_ptr);
    }

    return 0;
}