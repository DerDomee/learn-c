#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DDPROMPT_INPUT_BUFFERSIZE 256

void strtolower(char* string)
{
  int i;
  for (i = 0; i < DDPROMPT_INPUT_BUFFERSIZE; i++)
  {
    string[i] = tolower(string[i]) ;
  }
}
int prompt_yes_no(int* result, char* question, int preval)
{
  char const *prompt;
  switch (preval)
  {
    case 0:
      prompt = "[y/n]";
      break;
    case 1:
      prompt = "[Y/n]";
      break;
    case 2:
      prompt = "[y/N]";
      break;
    default:
      return 2;
  }

  while(1)
  {
    printf("%s %s ", question, prompt);
    char input[DDPROMPT_INPUT_BUFFERSIZE];
    fgets(input, sizeof(input), stdin);
    strtolower(input);
    if (
      !strcmp(input, "y\n") ||
      !strcmp(input, "ye\n") ||
      !strcmp(input, "yes\n") ||
      (
        !strcmp(input, "\n") &&
        preval == 1
      )
    )
    {
      *result = 1;
      break;
    }
    else if (
      !strcmp(input, "n\n") ||
      !strcmp(input, "no\n") ||
      !strcmp(input, "nope\n") ||
      (
        !strcmp(input, "\n") &&
        preval == 2
      )
    )
    {
      *result = 0;
      break;
    }
  }
  return 0;
}
