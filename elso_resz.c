#include <stdio.h>
#include "elso_resz.h"

#define RESET "\033[0m"
#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"

// Készítsd el a color_print függvényt
void color_print(enum Color color) {
  switch(color) {
    case BLACK:
      printf("%s %s", BG_BLACK, RESET);
      break;
    case RED:
      printf("%s %s", BG_RED, RESET);
      break;
    case GREEN:
      printf("%s %s", BG_GREEN, RESET);
      break;
    case YELLOW:
      printf("%s %s", BG_YELLOW, RESET);
      break;
    case BLUE:
      printf("%s %s", BG_BLUE, RESET);
      break;
    case MAGENTA:
      printf("%s %s", BG_MAGENTA, RESET);
      break;
    case CYAN:
      printf("%s %s", BG_CYAN, RESET);
      break;
    case WHITE:
      printf("%s %s", BG_WHITE, RESET);
      break;
  }
}