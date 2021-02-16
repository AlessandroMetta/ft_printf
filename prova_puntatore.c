#include <stdio.h>
#include <unistd.h>

char hex_digit(int v) {
    if (v >= 0 && v < 10)
        return '0' + v;
    else
        return 'a' + v - 10; // <-- Here
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void print_address_hex(void* p0) {
    int i;
    uintptr_t p = (uintptr_t)p0;

    ft_putchar('0'); 
    ft_putchar('x');
    for(i = (sizeof(p) << 3) - 4; i>=0; i -= 4) 
    {
        ft_putchar(hex_digit((p >> i) & 0xf));
    }
}

int main(void) 
{
    int a = 10;
    int *tab = &a;
    print_address_hex(tab);
    printf("\n%p\n", tab);
    return 0;
}