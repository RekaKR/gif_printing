#ifndef HARMADIK_RESZ_H
#define HARMADIK_RESZ_H

// Készítsd el a gif struktúra típust
struct Gif {
  struct Image Images[10];
};

void print_gif(void);

#endif