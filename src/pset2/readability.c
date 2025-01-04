#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  string text = get_string("Text: ");

  int sentence_count = 0;
  int word_count = 0;
  int letter_count = 0;
  for (int i = 0, length = strlen(text); i < length; i++)
  {
    char ch = text[i];

    if (ch == '.' || ch == '!' || ch == '?')
    {
      sentence_count += 1;

      if (i == length - 1)
      {
        word_count += 1;
      }
    }
    else if (ch == ' ')
    {
      word_count += 1;
    }
    else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
      letter_count += 1;
    }
  }

  int index = round(0.0588 * (double)letter_count / (double)word_count * 100.0 - 0.296 * ((double)sentence_count / (double)word_count * 100.0) - 15.8);

  if (index < 1)
  {
    printf("Before Grade 1\n");
  }
  else if (index > 16)
  {
    printf("Grade 16+\n");
  }
  else
  {
    printf("Grade %i\n", index);
  }

  return 0;
}