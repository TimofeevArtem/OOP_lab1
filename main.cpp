#include <iostream>
#include "array_ops.cpp"


int main(){
    while(1){
        int size = 0;
        int input;
        int new_size;
        int element;
        std::cout<<"1. Создать массив"<< std::endl;
        std::cout<<"2. Напечатать массив"<< std::endl;
        std::cout<<"3. Вставить элемент"<< std::endl;
        std::cout<<"4. Удалить элемент"<< std::endl;
        std::cout<<"5. Изменить размер"<< std::endl;
        std::cout<<"6. Сортировка"<< std::endl;
        std::cout<<"7. Поиск элемента"<< std::endl;
        std::cout<<"8. Удаление дубликатов"<< std::endl;
        std::cout<<"0. Выход\n"<< std::endl;

        std::cin >> input;
        std::cout<<"\n";
        switch (input)
        {
        case 1:
            std::cout<<"Введите размер массива: ";
            std::cin >> new_size;
            createArrey(new_size);
            break;

        case 2:
            printArrey();
            break;

        case 3:
            std::cout<<"Введите элемент для вставки: ";
            std::cin >> element;
            InsertElement(element);
            break;

        case 4:
            std::cout<<"Введите элемент для удаления: ";
            std::cin >> element;
            RemoveElement(element);
            break;

        case 5:
            std::cout<<"Введите новый размер массива: ";
            std::cin >> new_size;
            arrayResize(new_size);
            break;

        case 6:
            sortArrey();
            break;

        case 7:
            std::cout<<"Введите элемент для поиска: ";
            std::cin >> element;
            searchElement(element);
            break;

        case 8:
            deleteDuplicates();
            break;

        case 0:
            break;
        default:
            std::cout<< "Введите число 1-8 или 0\n"<< std::endl;
            break;
        }
    }
}