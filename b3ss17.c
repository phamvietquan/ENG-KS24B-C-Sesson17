#include<stdio.h>
#include<string.h>
#include<ctype.h>
void addStr(char *str);
void reverseStr(char *str,int length);
int countWords(char *str, int length);
void makeArr(char *arr);
void compare(char *arr, char *str);
void capitalLetter(char *str, int length);
void linkStr(char *str, char *arr);
int main(){
    char str[100], arr[100];
    int choose=0, flag=0, length=0;
    do{
	printf("MENU \n 1. Nhap vao chuoi \n 2. In ra chuoi dao nguoc \n 3. Dem so luong tu trong chuoi \n 4. Nhap vao chuoi khac , so sanh chuoi do voi chuoi ban dau (ngan hon hoac dai hon chuoi ban dau) \n 5. In hoa tat ca chu cai trong chuoi \n 6. Nhap vao mot chuoi khac va them va them chuoi do vao chuoi do vao chuoi ban dau \n 7. Thoat \n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choose);
        getchar();
        switch(choose){
            case 1:
                flag=1;
                addStr(str);
                length= (int)strlen(str);
              break;
            case 2:
                if(flag==1){
                    reverseStr(str, length);
                }else{
                    printf("Ban chua khoi tao chuoi ban dau \n");
                }
                break;
            case 3:
                if(flag==1){
                    printf("so luong tu trong chuoi la: %d \n",countWords(str, length)+1);
                }else{
                    printf("Ban chua khoi tao chuoi ban dau \n");
                }

                break;
            case 4:
                if(flag==1){
                    makeArr(arr);
                    compare(arr, str);
                }else{
                    printf("Ban chua khoi tao chuoi ban dau \n");
                }

                break;
            case 5:
                if(flag==1){
                    capitalLetter(str, length);
                    printf("%s", str);
                }else{
                    printf("Ban chua khoi tao chuoi ban dau \n");
                }

                break;
            case 6:
                if(flag==1){
                    makeArr(arr);
                    linkStr(str, arr);
                    printf("%s \n", str);
                }else{
                    printf("Ban chua khoi tao chuoi ban dau \n");
                }

                break;
            case 7:
                printf("Ban da chon thoat \n");
                break;
            default:
                printf("Lua chon cua ban khong co trong chuoi \n");
        }
    }while(choose !=7);
    return 0;
}
void addStr( char *str){
    printf("Moi ban nhap chuoi: ");
    fgets(str, 100, stdin);
}
void reverseStr(char *str,int length){
    char reverseStr[length];
    int index=0;
    for(int i=length-2; i>=0; i--){
        reverseStr[index]=*(str+i);
        index++;
    }
    printf("%s\n", reverseStr);
}
int countWords( char *str, int length){
    int count=0;
    for(int i=0; i<length; i++){
        if(*(str +i)==' ' && i==0){
            
        }
        if(*(str+i)==' ' && i!=0 ){
            if(*(str +i) != *(str +1+i)){
                count++;
            }
        }
    }
    return count;
}
void makeArr(char *arr){
    printf("Moi ban nhap chuoi: ");
    fgets(arr, 100, stdin);
}
void compare(char *arr, char *str){
    int temp=strcmp(arr, str);
    if(temp==0){
        printf("Bang chuoi ban dau \n");
    }else if(temp<0){
        printf("ngan hon chuoi ban dau \n");
    }else{
        printf("dai hon chuoi ban dau \n");
    }
}
void capitalLetter(char *str, int length){
    for(int i=0; i<length; i++){
        *(str +i)= toupper(*(str+i));
    }
}
void linkStr(char *str, char *arr){
    strcat(str,arr);
    int length= (int)strlen(str);
    for(int i=0; i<length; i++){ // xoa ky tu xuong dong 
        if(*(str+i)=='\n'){
            *(str+i)=' ';
        }
    }
}
