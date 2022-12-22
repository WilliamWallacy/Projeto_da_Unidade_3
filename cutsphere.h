#ifndef CUTSPHERE
#define CUTSHPERE
#include "sculptor.h"
#include "figurageometrica.h"

class CutSphere : public FiguraGeometrica{
  private:
    int x0;
    int y0;
    int z0;
    int rr;
  public:
    CutSphere(int x0, int y0, int z0, int rr);

    void draw (Sculptor &s);
    };

    #endif
