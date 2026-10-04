#include <iostream>
#include "array_ops.cpp"


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
        std::cout << "8. Удаление дубликатов"<< std::endl;
        std::cout << "0. Выход"<< std::endl;

        std::cout << "\nВыберите действие: ";
        std::cin >> input;
        std::cout << "\n";

        switch (input){
            case 1:
            {
                if (arr_ptr != nullptr){
                    array_delete(arr_ptr);
                    size = 0;
                }
                std::cout << "Введите размер массива: ";
                std::cin >> size;

                if (size == 0){
                    std::cout << "Размер массива должен быть больше 0"<< std::endl;
                    arr_ptr = nullptr;
                    size = 0;
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
                std::cin >> value;

                std::cout << "Введите позицию, на которую необходимо вставить элемент: ";
                std::cin >> pos;
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
                std::cin >> pos;

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
                std::cin >> new_size;
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
                break;
            }
            case 8:
            {

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

    if (arr_ptr != nullptr)
    {
        array_delete(arr_ptr);
    }

    return 0;
}