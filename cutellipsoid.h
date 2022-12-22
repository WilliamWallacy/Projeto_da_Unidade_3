#ifndef CUTELLPISOID
#define CUTELLIPSOID
#include "sculptor.h"
#include "figurageometrica.h"

class CutEllipsoid : public FiguraGeometrica{
  private:
    int x0;
    int y0;
    int z0;
    int rx;
    int ry;
    int rz;
  public:
    CutEllipsoid (int x0, int y0, int z0, int rx, int ry, int rz);
    void draw (Sculptor &s);
  };

  #endif
