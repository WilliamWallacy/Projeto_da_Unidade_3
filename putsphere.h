#ifndef PUTSPHERE
#define PUTSHPERE
#include "sculptor.h"
#include "figurageometrica.h"

class PutSphere : public FiguraGeometrica{
  private:
    int x0;
    int y0;
    int z0;
    int rr;

  public:
    PutSphere(int x0r, int y0, int z0, int rr, float r, float g, float b, float a);
  
    void draw(Sculptor &s);
    };
  #endif
