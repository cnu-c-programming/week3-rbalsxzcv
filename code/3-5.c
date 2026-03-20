#include <stdio.h>
#include <stdarg.h>

int global_var = 0;

void my_sum(char type, int count , ...) {
    va_list ap;
    va_start(ap,count);
    if(type == 'S'){
        for(int i = 0;i<count;i++){
            printf("%s ",va_arg(ap,char*));
        }
        printf("\n");
    }else if (type == 'C'){
        for(int j = 0;j<count;j++){
            printf("%c",va_arg(ap,char*));
        }
        printf("\n");
    }else if(type == 'D'){
        int sum = 0;
        for(int k = 0;k<count;k++){
            sum += va_arg(ap,int);
        }
        printf("%d\n",sum);
    }
    va_end(ap);
}

int main() {
    my_sum('S',2,"Hello","World");
    my_sum('C',3,'C','N','U');
    my_sum('D',4,10,20,30,40);

    return 0;
}
