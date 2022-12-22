#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <string>
#include <vector>
#include "figurageometrica.h"

class Interpretador {
private:
  int dimx, dimy, dimz;
  float r, g, b, a;

public:
  Interpretador();
  std::vector<FiguraGeometrica*> analise(std::string filename);
  int getDimx();
  int getDimy();
  int getDimz();
};
#endif
