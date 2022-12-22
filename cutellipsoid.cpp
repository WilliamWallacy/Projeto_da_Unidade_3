#include "cutellipsoid.h"
#include "sculptor.h"
#include <math.h>

CutEllipsoid::CutEllipsoid(int x0, int y0, int z0, int rx, int ry,int rz){
    
    this -> x0 = x0 ;
    this -> y0 = y0;
    this -> z0 = z0;
    this -> rx  = rx;
    this -> ry  = ry;
    this -> rz  = rz;
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = a;  
   }
   void CutEllipsoid::draw (Sculptor &s){
     s.setColor(r, g, b, a);
    float aux_x, aux_y, aux_z;
    int i, j, k;
    

    for (i = x0 - rx; i < x0+rx; i++){
      for ( j = y0-ry; j < y0+ry; j++){
          for ( k = z0-rz; k < z0 + rz; k++) {
            aux_x = ((float)(i-x0)*(float)(i-x0))/(rx * rx);
            aux_y = ((float)(j-y0)*(float)(j-y0))/(ry * ry);
            aux_z = ((float)(k-z0)*(float)(k-z0))/(rz * rz);

            if ((aux_x + aux_y + aux_z) < 1){
                s.cutVoxel(i,j,k);
            }
          }
      }
    }
  }
