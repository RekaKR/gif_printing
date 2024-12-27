#ifndef MASODIK_RESZ_H
#define MASODIK_RESZ_H

// Hozd létre az image struktúra típust
struct Image {
  int** color;
  int width, height;
};

int read_file(struct Image* image, char* inputFile);
void image_print(struct Image image);

#endif