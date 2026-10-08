#include <gtest/gtest.h>
#include "array_ops.h"

bool array_equal(const int* arr, const int* expected, std::size_t count){
    if (arr == nullptr && count == 0){
        return true;
    }
    if (arr == nullptr || expected == nullptr){
        return false;
    }
    if (arr[0] != count){
        return false;
    }
    for(std::size_t i = 0; i < count; ++i){
        if (arr[i + 1] != expected[i]){
            return false;
        }
    }
    return true;
}

int* build_array(const int* values, std::size_t count){
    std::size_t capacity;
    if (count == 0){
        capacity = 1;
    }
    else{
        capacity = count * 2;
    }

    int* arr = array_create(capacity);
    std::size_t size = capacity;

    for(std::size_t i = 0; i < count; ++i){
        arr = array_insert(arr, size, arr[0], values[i]);
    }
    return arr;
}

TEST(ArrayOpsTest, createDelete){
    int* arr = array_create(5);

    ASSERT_NE(arr, nullptr);
    EXPECT_EQ(arr[0], 0);

    array_delete(arr);
    EXPECT_EQ(arr, nullptr);
}

TEST(ArrayOpsTest, insertAtBeginning){
    int* arr = array_create(4);
    std::size_t size = 4;
    int expected[] = {10, 20};

    arr = array_insert(arr, size, 0, 10);
    arr = array_insert(arr, size, 1, 20);

    EXPECT_EQ(arr[0], 2);
    EXPECT_TRUE(array_equal(arr, expected, 2));

    array_delete(arr);
}

TEST(ArrayOpsTest, insertInMiddle){
    int* arr = array_create(4);
    std::size_t size = 4;
    int expected[] = {10, 15, 20};

    arr = array_insert(arr, size, 0, 10);
    arr = array_insert(arr, size, 1, 20);
    arr = array_insert(arr, size, 1, 15);

    EXPECT_EQ(arr[0], 3);
    EXPECT_TRUE(array_equal(arr, expected, 3));

    array_delete(arr);
}

TEST(ArrayOpsTest, insertAtEnd){
    int* arr = array_create(4);
    std::size_t size = 4;
    int expected[] = {10, 20, 30};

    arr = array_insert(arr, size, 0, 10);
    arr = array_insert(arr, size, 1, 20);
    arr = array_insert(arr, size, 2, 30);

    EXPECT_EQ(arr[0], 3);
    EXPECT_TRUE(array_equal(arr, expected, 3));

    array_delete(arr);
}

TEST(ArrayOpsTest, resize){
    int values[] = {10, 20, 30};
    int* arr = build_array(values, 3);
    std::size_t size = 6;

    int* resized = array_resize(arr, size, 10);

    ASSERT_NE(resized, nullptr);
    EXPECT_EQ(resized[0], 3);
    EXPECT_TRUE(array_equal(resized, values, 3));

    array_delete(resized);
}

TEST(ArrayOpsTest, removeFirstElement){
    int values[] = {10, 20, 30};
    int* arr = build_array(values, 3);
    std::size_t size = 8;
    int expected[] = {20, 30};

    arr = array_remove(arr, size, 0);

    EXPECT_EQ(arr[0], 2);
    EXPECT_TRUE(array_equal(arr, expected, 2));

    array_delete(arr);
}

TEST(ArrayOpsTest, removeLastElement){
    int values[] = {10, 20, 30};
    int* arr = build_array(values, 3);
    std::size_t size = 8;
    int expected[] = {10, 20};

    arr = array_remove(arr, size, 2);

    EXPECT_EQ(arr[0], 2);
    EXPECT_TRUE(array_equal(arr, expected, 2));

    array_delete(arr);
}

TEST(ArrayOpsTest, removeMiddleElement){
    int values[] = {10, 20, 30, 40};
    int* arr = build_array(values, 4);
    std::size_t size = 8;
    int expected[] = {10, 30, 40};

    arr = array_remove(arr, size, 1);

    EXPECT_EQ(arr[0], 3);
    EXPECT_TRUE(array_equal(arr, expected, 3));

    array_delete(arr);
}

TEST(ArrayOpsTest, bubbleSort){
    int values[] = {9, 1, 7, 3, 5};
    int* arr = build_array(values, 5);
    int expected[] = {1, 3, 5, 7, 9};

    int* sorted = bubble_sort(arr, arr[0]);

    ASSERT_EQ(sorted, arr);
    EXPECT_TRUE(array_equal(sorted, expected, 5));

    array_delete(sorted);
}

TEST(ArrayOpsTest, binarySearchFound){
    int values[] = {5, 1, 9, 3, 7};
    int* arr = build_array(values, 5);
    std::size_t out_index = 0;

    EXPECT_TRUE(array_binary_search(arr, arr[0], 7, out_index));
    EXPECT_EQ(out_index, 3);

    array_delete(arr);
}

TEST(ArrayOpsTest, binarySearchMissing){
    int values[] = {5, 1, 9, 3, 7};
    int* arr = build_array(values, 5);
    std::size_t out_index = 0;

    EXPECT_FALSE(array_binary_search(arr, arr[0], 42, out_index));

    array_delete(arr);
}

TEST(ArrayOpsTest, removeDuplicates){
    int values[] = {4, 2, 2, 1, 3, 3};
    int* arr = build_array(values, 6);
    std::size_t size = 12;
    int expected[] = {1, 2, 3, 4};

    arr = array_unique(arr, size);

    EXPECT_EQ(arr[0], 4);
    EXPECT_TRUE(array_equal(arr, expected, 4));

    array_delete(arr);
}
