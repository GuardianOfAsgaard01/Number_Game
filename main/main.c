#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"

int main(void)
{
  char choice;
  printf("Enter 'p' to start.\n");
  printf("Enter 'h' for getting help.\n");
  printf("Enter 'e' for exit.\n");
  while(1) {
    //scanf("%c", &choice);
    choice = getchar();
    choice = tolower(choice);
    while(!(choice == 'p' || choice == 'h' || choice =='e' || choice == '\n')){
      printf("Invalid input!\n");
      choice = getchar();
    }

    switch(choice)
    {
      case 'p' : play(); break;
      case 'h' : help(); break;
      case 'e' : exit(0); break;
    }
  }
  return 0;
}
