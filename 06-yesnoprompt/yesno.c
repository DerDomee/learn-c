#include <stdlib.h>
#include <stdio.h>
#include "libprompt.h"

int main()
{
  int* prompt_result = malloc(sizeof(int));
  int returnval = prompt_yes_no(prompt_result, "Do it or don't do it?", 1);
  printf("Returned prompt value: %d\n", *prompt_result);
  printf("Return code: %d\n", returnval);
  return returnval;
}
