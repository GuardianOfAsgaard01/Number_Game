#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"

int get_num(int n)
{
  if(scanf("%d", &n) == 0) {
    printf("Invalid input!\nProgram is closing..\n");
    exit(0);
  }
  else
    return n;
}

void play(void)
{
  int n;
  printf("Enter the initial number:\n");
  n = get_num(n);
  while(n < 0){
    printf("You cannot enter negative number!\n");
    break;
    n = get_num(n);
  }
  if ((n-1)%4!=0)
    wip(n);
  else {
    printf("You start..\n");
    magic_num(n);
  }
}

void help(void)
{
  printf("-> After entered initial number,\n");
  printf("-> sides decrase the number with 1, 2 or 3 respectively.\n");
  printf("-> The person who says ZERO win.\n");
  printf(" Note: Entering negative number is forbidden!\n");
}

void suggestions(int n)
{
  if(n>2)
    printf("%d %d %d\n", n-1, n-2, n-3);
  else if(n==2)
    printf("%d %d\n", n-1, n-2);
  else
    printf("%d\n", n-1);
}

void wip(int n)
{
  printf("I start..\n");
  int temp = (n-1)%4;
  printf("I say %d.\n", n-temp);
  magic_num(n-temp);
}

void magic_num(int n)
{
  int temp;
  int k = (n-1)/4;
  while(1){
    printf("Possible movements: ");
    suggestions(n);
    temp = get_num(temp);
    if(!(temp==(n-1) || temp==(n-2) || temp==(n-3)) || temp<0){
      printf("Invalid input!\n");
      continue;
    }
    break;
  }
  if (temp==0) {
    printf("\n\nI win :]\n\n");
    exit(0);
  }
  printf("I say %d.\n", (k-1)*4+1);
  magic_num((k-1)*4+1);
}
