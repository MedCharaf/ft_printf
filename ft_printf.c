#include <stdarg.h>
#include "ft_printf.h"
static size_t ft_convert(char c, va_list ap)  // refer to va_arg
{
    size_t count;
    count = 0; 
     
    if(c == 'c')
       count += ft_putchar(va_arg(ap, int));
   
    else if (c == 's')
        count +=ft_putstring(va_arg(ap,char*));
    if (c == '%')
       count += write(1, &c, 1);

    return count;
}




int ft_printf(const char *str, ...)
{
    va_list ptr;
    int counter;
    int i;
    i =0;
    counter =0;
    va_start(ptr, str);
    while(str[i])
    {
        if(str[i]== '%')
        {
            i++;
       
            counter +=  ft_convert(str[i], ptr);
        }
        else
           counter += write(1, &str[i], 1);
        i++;
    }
    va_end(ptr);
    return  counter;
}
#include <stdio.h>
int main()
{
    int i ;

    i = ft_printf("mol : %s\n", "charaf");

    printf("%d",i);
}