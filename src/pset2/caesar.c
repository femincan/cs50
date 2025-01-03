#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rotate(char ch, int key);
bool only_digits(string key);

int main(int argc, string argv[])
{
  if (argc != 2 || !only_digits(argv[1]))
  {
    printf("Usage: ./caesar key\n");
    return 1;
  }

  int key = atoi(argv[1]);

  string plaintext = get_string("plaintext: ");

  printf("ciphertext: ");
  for (int i = 0, l = strlen(plaintext); i < l; i++)
  {
    printf("%c", rotate(plaintext[i], key));
  }
  printf("\n");
}

char rotate(char ch, int key)
{
  if (ch >= 'A' && ch <= 'Z')
  {
    return (((ch - 'A') + key) % 26) + 'A';
  }

  if (ch >= 'a' && ch <= 'z')
  {
    return (((ch - 'a') + key) % 26) + 'a';
  }

  return ch;
}

bool only_digits(string key)
{
  for (int i = 0, l = strlen(key); i < l; i++)
  {
    if (!isdigit(key[i]))
    {
      return false;
    }
  }

  return true;
}