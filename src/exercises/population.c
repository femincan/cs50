#include <stdio.h>
#include <cs50.h>

int main(void)
{
  int start_size;
  do
  {
    start_size = get_int("Start size: ");
  } while (start_size < 8);

  int end_size;
  do
  {
    end_size = get_int("End size: ");
  } while (end_size < start_size);

  int size = start_size;
  int years = 0;
  while (size < end_size)
  {
    int growth = size / 3;
    int decline = size / 4;
    size += growth - decline;
    years++;
  }

  printf("Years: %i\n", years);

  return 0;
}