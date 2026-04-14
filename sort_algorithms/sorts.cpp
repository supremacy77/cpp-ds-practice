#include<iostream>
using namespace std;

//冒泡排序，每次找出最大的一个数需要找n-1次 比较，外循环需要n-1次，所以时间复杂度为O(n^2)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//选择排序，每次找出最小的一个数需要找n-1次比较，外循环需要n-1次，所以时间复杂度为O(n^2)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

//插入排序，每次将一个数插入到已经排序好的数组中需要比较n-1次，外循环需要n-1次，所以时间复杂度为O(n^2)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        //将key插入到已经排序好的数组中，小于前面的数就交换位置，直到找到合适的位置
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//希尔排序，时间复杂度取决于增量序列的选择，最坏情况下为O(n^2)，平均情况下为O(n log n)
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int key = arr[i];
            int j = i;
            //如果小于后面的数就交换位置，直到找到合适的位置
            while (j >= gap && arr[j - gap] > key) {
                arr[j] = arr[j - gap];  
                j -= gap;
            }
            arr[j] = key;
        }
    }
}

//快速排序，平均时间复杂度为O(n log n)，最坏情况下为O(n^2)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; //选择最后一个元素作为基准
    int i = low - 1; //i是小于基准的元素的索引
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { //如果当前元素小于基准
            i++; //增加小于基准的元素的索引
            swap(arr[i], arr[j]); //交换位置
        }
    }
    swap(arr[i + 1], arr[high]); //将基准放到正确的位置
    return i + 1; //返回基准的索引
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//归并排序，平均时间复杂度为O(n log n)，最坏情况下为O(n log n)
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; //左半部分的长度
    int n2 = right - mid; //右半部分的长度
    int* L = new int[n1]; //创建左半部分的数组
    int* R = new int[n2]; //创建右半部分的数组
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i]; //将左半部分的元素复制到L数组中
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j]; //将右半部分的元素复制到R数组中
    }
    int i = 0, j = 0, k = left; //i是L数组的索引，j是R数组的索引，k是合并后数组的索引
    while (i < n1 && j < n2) { //当L数组和R数组都没有遍历完时
        if (L[i] <= R[j]) { //如果L数组的当前元素小于等于R数组的当前元素
            arr[k] = L[i]; //将L数组的当前元素放到合并后数组中
            i++; //增加L数组的索引
        } else { //如果R数组的当前元素小于L数组的当前元素
            arr[k] = R[j]; //将R数组的当前元素放到合并后数组中
            j++; //增加R数组的索引
        }
        k++; //增加合并后数组的索引
    }
    while (i < n1) { //如果L数组还有剩余元素
        arr[k] = L[i]; //将L数组的剩余元素放到合并后数组中
        i++;
        k++;
    }
    while (j < n2) { //如果R数组还有剩余元素
        arr[k] = R[j]; //将R数组的剩余元素放到合并后数组中
        j++;
        k++;
    }
    delete[] L; //释放L数组的内存
    delete[] R; //释放R数组的内存
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; //计算中间索引
        mergeSort(arr, left, mid); //递归排序左半部分
        mergeSort(arr, mid + 1, right); //递归排序右半部分
        merge(arr, left, mid, right); //合并两个有序的部分
    }
}
