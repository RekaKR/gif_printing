#include <stdio.h>
#include <stdlib.h>
#include "elso_resz.h"
#include "masodik_resz.h"

#define MAX_SIZE 30

// read from file
int read_file(struct Image* image, char* inputFile) {
  FILE* file = fopen(inputFile, "r");

  if (file == NULL) {
      perror("Upsis, failed to open file.");
      return 1;
  }

  int width, height;

  // first two rows
  if (fscanf(file, "%d", &width) != 1 || fscanf(file, "%d", &height) != 1) {
      fprintf(stderr, "Upsis, error reading dimensions\n");
      fclose(file);
      return 1;
  }

  // max 30 méret lehet
  if (width > MAX_SIZE || height > MAX_SIZE) {
    fprintf(stderr, "The width or height over 30. Should be under.\n");
    return 1;
  }

  // dinamikus foglalás
  (*image).color = (int**) malloc(height*sizeof(int*));

  for (int i = 0; i < height; i++) {
    (*image).color[i] = (int*) malloc(width*sizeof(int));
  }

  // read mtx
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (fscanf(file, "%d", &(*image).color[i][j]) != 1) {
        fprintf(stderr, "Upsis, error reading matrix data\n");
        fclose(file);
        return 1;
      }
    }
  }

  fclose(file);

  (*image).width = width;
  (*image).height = height;

  return 0;
}

// Készítsd el az image_print függvényt
void image_print(struct Image image) {
  for (int i = 0; i < image.height; i++) {
    for (int j = 0; j < image.width; j++) {
      color_print((enum Color)image.color[i][j]);
    }
    
    printf("\n");
  }
}
