#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Bestow thy holy moniker, fair stranger\n");
    printf("hello, %s.\n", name);
}
