/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main () {
  int randomNum;

  /* initialize random seed: */
  srand (time(NULL));

  /* generate secret number between 1 and 10: */
  randomNum = rand() % 40 + 10;
  printf("%d", randomNum);
}