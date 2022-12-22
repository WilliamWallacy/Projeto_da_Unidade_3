#include "cutsphere.h"
#include <math.h>

CutSphere :: CutSphere(int x0, int y0, int z0, int rr){
    
    this -> x0 = x0;
    this -> y0 = y0;
    this -> z0 = z0;
    this -> rr  = rr;
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = a;
         }
  
   void CutSphere::draw (Sculptor &s){
     int i, j, k;

     s.setColor(r, g, b, a);//seleciona as cores

     for(i = ((x0 - rr)); i < (x0 + rr); i++){
       for(j = (y0 - rr); j < (y0 + rr); j++){
         for(k = (z0 - rr); k < (z0 + rr); k++){
           if ((pow(i-x0,2)) + (pow(j-y0,2)) + (pow(k-z0,2)) <= (pow(rr,2))){

             s.cutVoxel(i,j,k);
           }   
         }
       }
     }
  }  
