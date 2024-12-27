#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "masodik_resz.h"
#include "harmadik_resz.h"

#define TERMINAL_CLEAR "\033[2J"
#define TERMINAL_HOME "\033[2H"

// Készítsd el a print_gif függvényt
void print_gif(void) {
  struct Image image;

  // file name from user
  printf("Please, add a file name (fe: input.bg): ");
  char inputName[50];
  scanf("%s", inputName);

  for (int i = 0; i < 10; i++) {
    // I want to freez the last img
    printf("%s %s", TERMINAL_CLEAR, TERMINAL_HOME);

    char fileName[strlen(inputName) + 1];
    strcpy(fileName, inputName);
    char fileNum[2];
    
    // convert from int to str
    sprintf(fileNum, "%d", i);
    strcat(fileName, fileNum);

    read_file(&image, fileName);

    image_print(image);
    
    Sleep(1000);

    // malloc felszabaditása
    for (int i = 0; i < image.height; i++) {
      free(image.color[i]);
    }

    free(image.color);
  }
}