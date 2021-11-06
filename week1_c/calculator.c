#include <cs50.h>
#include <stdio.h>

int main(void) 
{
	// Prompt user for x
    long x = get_long("x: ");
    
    // Prompt user for y
    long y = get_long("y: ");
    
    // Add x and y, then save it to z
    long z = x + y;
    
    // print z as a result
    printf("result: %li\n", z);
}