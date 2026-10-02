#include <iostream>
#include "array_ops.cpp"


int main(){
    int fl{0};
    std::size_t size = 0;
    std::size_t input;
    std::size_t new_size;
    int value;
    std::size_t pos;
    int* arr_ptr = nullptr;

    while(fl != 1){
        std::cout<<"1. Создать массив"<< std::endl;
        std::cout<<"2. Удалить массив"<< std::endl;
        std::cout<<"3. Вставить элемент"<< std::endl;
        std::cout<<"4. Удалить элемент"<< std::endl;
        std::cout<<"5. Изменить размер"<< std::endl;
        std::cout<<"6. Напечатать массив"<< std::endl;
        std::cout<<"7. Сортировка массива + Поиск элемента"<< std::endl;
        std::cout<<"8. Удаление дубликатов"<< std::endl;
        std::cout<<"0. Выход\n"<< std::endl;

        if (!(std::cin >> input)){
                std::cin.clear();
                char ch;
                while (std::cin.get(ch) && ch != '\n') { }
                std::cout<<"Неверный ввод\n\n";
                continue;
            }
        std::cout<<"\n";
        switch (input)
        {
        case 1:
            std::cout<<"Введите размер массива: ";
            std::cin >> size;
            arr_ptr = array_create(size);
            break;

        case 2:
            array_delete(arr_ptr);
            break;

        case 3:
            std::cout<<"Введите элемент для вставки: ";
            std::cin >> value;
            std::cout<<"Введите позицию на которую необходимо вставить элемент: ";
            std::cin >> pos;
            arr_ptr = array_insert(arr_ptr, size, pos, value);
            break;

        case 4:
            std::cout<<"Введите индекс элемента который необходимо удалить: ";
            std::cin >> pos;
            arr_ptr = array_remove(arr_ptr, size, pos);
            break;

        case 5:
            std::cout<<"Введите новый размер массива: ";
            std::cin >> new_size;
            arr_ptr = array_resize(arr_ptr, size, new_size);
            size = new_size;
            break;


        case 6:
            array_print(arr_ptr, size);
            break;
        case 0:
            fl = 1;
            break;
        default:
            std::cout<< "Введите число 1-8 или 0\n"<< std::endl;
            break;
        }
    }
}