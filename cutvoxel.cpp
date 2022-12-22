#include "cutvoxel.h"
#include <math.h>

CutVoxel:: CutVoxel(int x,int y,int z){
    
    this -> x = x;
    this -> y = y;
    this -> z = z;
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = a;
         }
   void CutVoxel::draw (Sculptor &s){
     s.setColor(r, g, b, a);//seleciona as cores
             s.cutVoxel(x,y,z);
       }
  
