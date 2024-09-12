#include <iostream>
#include <functional>
#include <cstring>


/*Comb sort*/
void comb_sort(int* arr, int size) {
    int step = size - 1;
    float factor = 1.25;

    while (step >= 1) {
        for (int i = 0; i + step < size; ++i) 
            if (arr[i+ step] < arr[i]) 
                std::swap(arr[i+step], arr[i]);
        
        step /= factor;
    }
}

void insertion_sort(int* arr, int size) {

    int curr;
    int j;
    for (int i = 0; i < size; ++i) {
        curr = arr[i];
        j = i - 1;
        while (j > -1 && curr < arr[j]) {
            arr[j + 1] = arr[j];
            --j; 
        } 
        arr[j+1] = curr;
    }
}

/*Util*/
int* min_ptr(int* arr, int size) {
    int mn = 0x7fffffff;
    int* mn_ptr = nullptr;
    for (int i = 0; i < size; ++i) {
        if (arr[i] < mn) {
            mn = arr[i];
            mn_ptr = arr + i;
        }
    }
    return mn_ptr;
}

void selection_sort(int* arr, int size) {

    for (int i = 0; i < size; ++i) {
        std::swap(arr[i], *(min_ptr(arr + i, size - i)));
    }
}

void shell_sort(int* arr, int size) {
    int step = size / 2;
    int curr;
    int k;
    while (step != 0) {
        for (int i = 0; i < step; ++i) {
            for (int j = i + step; j < size; j += step) {
                curr = arr[j];
                k = j - step;
                while (k > -1 && curr < arr[k]) {
                    arr[k + step] = arr[k];
                    k -= step;
                }
                arr[k + step] = curr;
            }
        }
        step /= 2;
    }
}

void radix_sort(int* arr, int size) {
    // positeive negative segregation


}

void heap_sort(int* arr, int size) {

}

void merge_sort(int* arr, int size) {

}

void quick_sort(int* arr, int size) {

}
/* Gets data from input.txt */
void external_polyphase_sort(int* arr, int size) {

}

int main(int argc, char** argv) {
    std::function<void(int*, int)> sort_alg;
    
    if (!strcmp(argv[1], "--help")) {
        std::cout << "Usage: " << argv[0] << " [OPTION]\nOPTIONS:\n\tcomb\n\tinsertion\n\tselection\n\tshell\n";
        return 0;
    }
    else if (!strcmp(argv[1], "comb")) {
        sort_alg = comb_sort;
    }
    else if (!strcmp(argv[1], "insertion")) {
        sort_alg = insertion_sort;
    }
    else if (!strcmp(argv[1], "selection")) {
        sort_alg = selection_sort;
    }
    else if (!strcmp(argv[1], "shell")) {
        sort_alg = shell_sort;
    }
    else if (!strcmp(argv[1], "radix")) {
        sort_alg = radix_sort;
    }
    else if (!strcmp(argv[1], "heap")) {
        sort_alg = heap_sort;
    }
    else if (!strcmp(argv[1], "merge")) {
        sort_alg = merge_sort;
    }
    else if (!strcmp(argv[1], "quick")) {
        sort_alg = quick_sort;
    }
    else if (!strcmp(argv[1], "external_polyphase")) {
        sort_alg = external_polyphase_sort;
    }
    else {
        std::cout << "Invalid option, type " << argv[0] << " --help for more information.";
        return 0;
    }

    int arr[100];
    int size;
    

    std::cout << "Введите длину массива чисел и сам массив: ";
    std::cin >> size;

    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    sort_alg(arr, size);

    std::cout << "Отсортированный массив:\n";
    for (int i = 0 ; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    
    
}