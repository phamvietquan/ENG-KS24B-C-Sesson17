#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void input(int **arr, int n);
void output(int *arr, int size);
bool isPrime(int num);
void printEven(int *arr, int size);
void reverseArray(int *arr, int size);
void sortArray(int *arr, int size, bool ascending);
int searchElement(int *arr, int size, int key, int index);

int main() {
    int menu;
    int *arr = NULL; 
    int n;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu trong mang\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("6. Nhap vao mot phan tu va tim kiem trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &menu);

        switch(menu) {
            case 1:
                printf("Moi ban nhap vao kich thuoc mang: ");
                scanf("%d", &n);
                arr = (int *)malloc(n * sizeof(int));
                if (arr == NULL) {
                    printf("Khong the cap phat bo nho!\n");
                    return 1;
                }
                input(&arr, n);
                break;
            case 2:
                if (arr != NULL) {
                    printf("Cac phan tu la so chan:\n");
                    printEven(arr, n);
                } else {
                    printf("Ban chua nhap phan tu vao mang\n");
                }
                break;
            case 3:
                if (arr != NULL) {
                    printf("Cac phan tu la so nguyen to:\n");
                    for (int i = 0; i < n; i++) {
                        if (isPrime(arr[i])) {
                            printf("%d ", arr[i]);
                        }
                    }
                    printf("\n");
                } else {
                    printf("Ban chua nhap phan tu vao mang\n");
                }
                break;
            case 4:
                if (arr != NULL) {
                    reverseArray(arr, n);
                    printf("Mang sau khi dao nguoc:\n");
                    output(arr, n);
                } else {
                    printf("Ban chua nhap phan tu vao mang\n");
                }
                break;
            case 5:
                if (arr != NULL) {
                    int subMenu;
                    printf("1. Tang dan\n");
                    printf("2. Giam dan\n");
                    printf("Lua chon cua ban: ");
                    scanf("%d", &subMenu);
                    if (subMenu == 1) {
                        sortArray(arr, n, true);
                        printf("Mang sau khi sap xep tang dan:\n");
                    } else if (subMenu == 2) {
                        sortArray(arr, n, false);
                        printf("Mang sau khi sap xep giam dan:\n");
                    } else {
                        printf("Lua chon khong hop le.\n");
                    }
                    output(arr, n);
                } else {
                    printf("Ban chua nhap phan tu vao mang\n");
                }
                break;
            case 6:
                if (arr != NULL) {
                    int key;
                    printf("Nhap vao phan tu can tim: ");
                    scanf("%d", &key);
                    int index = searchElement(arr, n, key, index);
                } else {
                    printf("Ban chua nhap phan tu vao mang\n");
                }
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                free(arr); 
                break;
            default:
                printf("Lua chon khong co trong MENU \n");
        }
    } while (menu != 7);

    return 0;
}

void input(int **arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d]=", i + 1);
        scanf("%d", &(*arr)[i]);
    }
}

void output(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("arr[%d]=%d\n", i + 1, arr[i]);
    }
}

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void printEven(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void reverseArray(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void sortArray(int *arr, int size, bool ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int searchElement(int *arr, int size, int key, int index) {
    for (int i = 0; i < size; i++) {
        if (*(arr+i) == key) {
        	printf("Phan tu %d tim thay tai vi tri %d\n", key, index);  
        	
        }else{
        	printf("Phan tu %d khong ton tai trong mang\n", key);
        	
		}
    }
}
