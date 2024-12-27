#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
  int cents = get_cents();
  int quantity = 0;

  int quarters = calculate_quarters(cents);
  cents -= quarters * 25;

  int dimes = calculate_dimes(cents);
  cents -= dimes * 10;

  int nickels = calculate_nickels(cents);
  cents -= nickels * 5;

  int pennies = calculate_pennies(cents);
  cents -= pennies * 1;

  quantity = quarters + dimes + nickels + pennies;

  printf("%i\n", quantity);

  return 0;
}

int get_cents(void)
{
  int cents;
  do
  {
    cents = get_int("Cents: ");
  } while (cents < 0);

  return cents;
}

int calculate_quarters(int cents)
{
  return cents / 25;
}

int calculate_dimes(int cents)
{
  return cents / 10;
}

int calculate_nickels(int cents)
{
  return cents / 5;
}

int calculate_pennies(int cents)
{
  return cents / 1;
}