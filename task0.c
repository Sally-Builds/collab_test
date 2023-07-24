#include <stdio.h>
#include <stdarg.h>

int _printf(char *format, ...);
int main()
{
    // printf("Hello World");
    
    char c = 'K';
    char *s = "Hello";
    int res = _printf("hello%c %s\n", c, s);
    printf("result from custom printf fn: %d\n", res);
    int res1 = printf("hello%c %s\n", c, s);
    printf("result from main printf fn: %d\n", res1);
    return 0;
}

int _printf(char *format, ...)
{
    va_list args;
    va_start(args, format);
    int i = 0;
    int sum = 0;
    
    while(format[i])
    {
        if(format[i] == '%'){
            i++;
            if(format[i] == 'c'){
                int x = va_arg(args, int);
                printf("%c", x);
                sum++;
            }else if(format[i] == 's'){
                char *x = va_arg(args, char*);
                int sum1 = printf("%s", x);
                sum += sum1;
            }
        }else{
            printf("%c", format[i]);
            sum++;
        }
        i++;
    }
    return sum;
}
