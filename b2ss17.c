#include<stdio.h>
#include<string.h>
#include<ctype.h>
void addStr(char *str);
void showStr(char *str);
int countLetters(char *str, int length);
int countNumbers(char *str, int length);
int countCharacters(char *str, int length);
int main(void){
    int choose=0;
    char str[1000];
    int flag=0, length=0;
    do{ 
	    printf("MENU \n 1. Nhap vao chuoi \n 2. In ra chuoi \n 3. Dem so luong chu cai trong chuoi va in ra \n 4. Dem so luong chu so trong chuoi va in ra \n 5. Dem so luong ky tu dac biet trong chuoi va in ra \n 6. Thoat \n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                flag=1;
                addStr(str);
                length= (int)strlen(str);
                break;
            case 2:
                if(flag==1){
                    showStr(str);
                }else{
                    printf("Ban chua khoi tao chuoi \n");
                }
                break;
            case 3:
                if(flag==1){
                    printf("So luon chu cai trong chuoi la: %d \n",countLetters(str, length));
                }else{
                    printf("Ban chua khoi tao chuoi \n");
                }
                break;
            case 4:
                if(flag==1){
                    printf("So luong chu so trong chuoi la: %d \n",countNumbers( str, length));
                }else{
                    printf("Ban chua khoi tao chuoi \n");
                }
                break;
            case 5:
                if(flag==1){
                    printf("So luong ky tu dac biet trong chuoi la: %d \n",countCharacters( str, length));
                }else{
                    printf("Ban chua khoi tao chuoi \n");
                }
                break;
            case 6:
                printf("Ban da chon thoat \n");
                break;
            default:
                printf("Lua chon cua ban khong co trong MENU \n");
        }
    }while(choose!=6);
    return 0;
}
void addStr(char *str){
    printf("Moi ban nhap vao chuoi: ");
    getchar();
    fgets( str, 1000, stdin);
}
void showStr(char *str){
    printf("%s", str);
}
int countLetters(char *str,int length){
    int count=0;
    for(int i=0; i<length; i++ ){
        if(isalpha(*(str+i))){
            count++;
        }
    }
    return count;
}
int countNumbers(char *str,int length){
    int count=0;
    for(int i=0; i<length; i++ ){
        if(isdigit(*(str+i))){
            count++;
        }
    }
    return count;
}
int countCharacters(char *str, int length){
    int temp=0;
    for(int i=0; i<length; i++ ){
        if(isdigit(*(str+i)) || isalpha(*(str+i))){
            temp++;
        }
    }
    int count = length - temp -1;
    return count;
}
