#include <stdio.h>

int main()
{
  char userInput;
  printf("Enter a character: ");
  scanf("%c", &userInput);
  printf("You said: '%c'!\n", userInput);
  return 0;
}
