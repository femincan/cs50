#include <cs50.h>
#include <stdio.h>

int main(void)
{
  long card_number = get_long("Number: ");

  int type;
  int length = 0, odd_position_sum = 0, even_position_sum = 0;
  while (card_number > 0)
  {
    // If only two digits left, this is the card type
    if (card_number > 9 && card_number < 100)
    {
      type = card_number;
    }

    int last_digit = card_number % 10;

    if (length % 2 == 0)
    {
      even_position_sum += last_digit;
    }
    else
    {
      int doubled_digit = last_digit * 2;

      // If doubled_digit consists of two digits, add them separately
      if (doubled_digit > 9)
      {
        odd_position_sum += doubled_digit % 10;
        odd_position_sum += doubled_digit / 10;
      }
      else
      {
        odd_position_sum += doubled_digit;
      }
    }

    // Remove last digit
    card_number /= 10;
    length += 1;
  }

  int sum = even_position_sum + odd_position_sum;

  if (sum % 10 == 0)
  {
    if (length == 15 && (type == 34 || type == 37))
    {
      printf("AMEX\n");
    }
    else if (length == 16 && (type >= 51 && type <= 55))
    {
      printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && type / 10 == 4)
    {
      printf("VISA\n");
    }
    else
    {
      printf("INVALID\n");
    }

    return 0;
  }

  printf("INVALID\n");
  return 0;
}