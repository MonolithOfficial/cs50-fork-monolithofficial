#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // retrieving our dear user's input.
    string name = get_string("Bestow thy holy moniker, fair stranger\n");
    
    // replying to our dear holy user, so that he doesn't feel desolated.
    printf("hello, %s.\n", name);
}
