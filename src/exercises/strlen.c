#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
  string name = get_string("Name: ");
  int length = strlen(name);

  printf("Name length: %i\n", length);

  return 0;
}