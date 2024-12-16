#include <stdio.h>
void input(int *arr, int n);//1
void output(int *arr, int size);//2
void tinhTong(int *arr, int n, int *sum);
void max(int *arr, int *arrMax, int n);
int main(){
	int menu;
	int arr[100];
	int n, flag=-1;
	int sum =0;
	do{
		printf("MENU\n");
		printf("1. Nhap vao so phan tu va phan tu trong mang\n");
		printf("2. Hien thi cac phan tu trong mang\n");
		printf("3. Tinh do dai cua mang\n");
		printf("4. Tinh tong cac phan tu trong mang\n");
		printf("5. Hien thi phan tu lon nhat\n");
		printf("6. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &menu);
		switch(menu){
			case 1:
				printf("Moi ban nhap vao kich thuoc mang: ");
				scanf("%d", &n);
				printf("Moi ban nhap vao tung phan tu trong mang: \n");
				input(&arr, n);
				flag=1;
				break;
			case 2:
				if(flag==1){
					printf("Cac phan tu trong mang la\n");
					output(&arr,n);
				}else{
					printf("Ban chua nhap phan tu vao mang");
				}
				break;
			case 3:
				if(flag==1){
					printf("Do dai cua mang la: %d\n", n);
				}else{
					printf("Ban chua nhap phan tu vao mang");
				}
				break;
			case 4:
				if(flag==1){
					tinhTong(&arr, n, &sum);
					printf("Tong cac phan tu trong mang la: %d\n", sum);
				}else{
					printf("Ban chua nhap phan tu vao mang");
				}
				break;
			case 5:
				if(flag==1){
				int arrMax=0;
				max(&arr, &arrMax,n);
				printf("Phan tu lon nhat trong mang la: %d\n", arrMax);
				}else{
					printf("Ban chua nhap phan tu vao mang");
				}
				break;
			case 6:
				
				break;
		default:
		printf("Lua chon khong co trong MENU \n");	
		}
	}while(menu!=6);

	return 0;
}
//1
void input(int *arr, int n){
	for(int i=0;i<n;i++){
		printf("arr[%d]=", i+1);
		scanf("%d", &arr[i]);
		
	}
}
//2
void output(int *arr, int size){
	for(int i=0;i<size;i++){
		printf("arr[%d]=%d\n", i+1, arr[i]);
	}
}
//4
void tinhTong(int *arr, int n, int *sum){
	*sum=0;
	for(int i=0;i<n;i++){
		*sum += *(arr+i);
	}
}
//5
void max(int *arr, int *arrMax, int n){
    for(int i = 0; i < n; i++) {
        if(arr[i] > *arrMax) {
            *arrMax = arr[i]; 
        }
    }
}

