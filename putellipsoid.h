#ifndef PUTELLIPSOID
#define PUTELLIPSOID
#include "sculptor.h"
#include "figurageometrica.h"

class PutEllipsoid : public FiguraGeometrica{
  private:
    int x0;
    int y0;
    int z0;
    int rx;
    int ry;
    int rz;

  public:
    PutEllipsoid (int x0, int y0, int z0, int rx, int ry, int rz,float r,float g, float b,float a);
    void draw (Sculptor &s);
  };

  #endif
