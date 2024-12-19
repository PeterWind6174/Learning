#include <stdio.h>

// 定义数组大小常量
#define SIZE 10

// 函数声明
void inputArray(int array[], int size);
void printArray(int array[], int size);
double calculateAverage(int array[], int size);
int findMax(int array[], int size);
int findMin(int array[], int size);
int searchElement(int array[], int size, int key);
void sortArray(int array[], int size);

int main() {
    int array[SIZE];
    int key, index;
    double average;
    int max, min;

    // 输入数组元素
    printf("请输入 %d 个整数元素:\n", SIZE);
    inputArray(array, SIZE);

    // 输出数组元素
    printf("数组元素为: ");
    printArray(array, SIZE);

    // 计算并输出平均值
    average = calculateAverage(array, SIZE);
    printf("数组元素的平均值为: %.2f\n", average);

    // 查找并输出最大值
    max = findMax(array, SIZE);
    printf("数组元素的最大值为: %d\n", max);

    // 查找并输出最小值
    min = findMin(array, SIZE);
    printf("数组元素的最小值为: %d\n", min);

    // 查找某数值元素是否存在
    printf("请输入要查找的整数值: ");
    scanf("%d", &key);
    index = searchElement(array, SIZE, key);
    if (index != -1) {
        printf("元素 %d 存在于数组中，索引为: %d\n", key, index);
    } else {
        printf("元素 %d 不存在于数组中。\n", key);
    }

    // 对数组进行排序
    sortArray(array, SIZE);
    printf("排序后的数组元素为: ");
    printArray(array, SIZE);

    return 0;
}

/**
 * 函数: inputArray
 * 功能: 输入数组元素
 */
void inputArray(int array[], int size) {
    for(int i = 0; i < size; i++) {
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
    }
}

/**
 * 函数: printArray
 * 功能: 输出数组元素
 */
void printArray(int array[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/**
 * 函数: calculateAverage
 * 功能: 计算数组元素的平均值
 */
double calculateAverage(int array[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += array[i];
    }
    return (double)sum / size;
}

/**
 * 函数: findMax
 * 功能: 查找数组元素的最大值
 */
int findMax(int array[], int size) {
    int max = array[0];
    for(int i = 1; i < size; i++) {
        if(array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

/**
 * 函数: findMin
 * 功能: 查找数组元素的最小值
 */
int findMin(int array[], int size) {
    int min = array[0];
    for(int i = 1; i < size; i++) {
        if(array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

/**
 * 函数: searchElement
 * 功能: 查找某数值元素是否存在，存在则返回其索引，否则返回 -1
 */
int searchElement(int array[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(array[i] == key) {
            return i; // 返回第一个匹配的索引
        }
    }
    return -1; // 未找到
}

/**
 * 函数: sortArray
 * 功能: 对数组元素进行升序排序（使用冒泡排序算法）
 */
void sortArray(int array[], int size) {
    int temp;
    int swapped;
    for(int i = 0; i < size-1; i++) {
        swapped = 0;
        for(int j = 0; j < size-1-i; j++) {
            if(array[j] > array[j+1]) {
                // 交换元素
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swapped = 1;
            }
        }
        // 如果没有交换，数组已经有序
        if(!swapped) {
            break;
        }
    }
}