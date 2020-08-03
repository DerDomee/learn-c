#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
  printf("Testing full-valid call\n");
  char* first = malloc(sizeof(char) * FILENAME_MAX);
  getcwd(first, FILENAME_MAX);
  printf("%s\n", first);
  free(first);
  printf("\n\n");

  printf("Testing EINVAL trigger by size=0 argument\n");
  char* second = malloc(sizeof(char));
  getcwd(second, 0);
  if (errno == EINVAL)
  {
    errno = 0;
    printf("Error EINVAL triggered.\n\n");
  }
  free(second);

  printf("Testing ERANGE trigger by smaller buffer than cwd-name.\n");
  char* fourth = malloc(sizeof(char) * 2);
  getcwd(fourth, FILENAME_MAX);
  if (errno == ERANGE)
  {
    errno = 0;
    printf("Error ERANGE triggered.\n\n");
  }
  return 0;
}
