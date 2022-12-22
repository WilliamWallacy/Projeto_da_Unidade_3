#include <fstream>
#include <sstream>
#include <iostream>
#include "interpretador.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

Interpretador::Interpretador(){
  
}

std::vector<FiguraGeometrica*> Interpretador::analise(std::string filename){

  std::vector<FiguraGeometrica*> figs;
  std::ifstream fin;
  std::stringstream ss;
  std::string s;
  std::string token;
  
  fin.open(filename.c_str());
  if(!fin.is_open()){
    std::cout << "Arquivo nao foi aberto!";
    exit(0);
  }

  while(fin.good()){
    getline(fin,s);

    if(fin.good()){
      ss.clear();
      ss.str(s);
      ss >> token;

      if(ss.good()){
        if(token.compare("Dim")==0){
          ss >> dimx >> dimy >> dimz;
        }
        else if(token.compare("putvoxel")==0){
          int x,y,z;
          ss >> x >> y >> z >> r >> g >> b >> a;
          figs.push_back(new PutVoxel(x, y, z, r, g, b, a));
        }
        else if(token.compare("cutvoxel")==0){
          int x,y,z;
          ss >> x >> y >> z;
          figs.push_back(new CutVoxel(x, y, z));
        }
        else if(token.compare("putbox")==0){
          int x0, x1, y0, y1, z0, z1;
          ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
          figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        }
        else if(token.compare("cutbox")==0){
          int x0, x1, y0, y1, z0, z1;
          ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
          figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
        }
        else if(token.compare("putsphere")==0){
          int x0, y0, z0, rr;
          ss >> x0 >> y0 >> z0 >> rr >> r >> g >> b >> a;
          figs.push_back(new PutSphere(x0, y0, z0, rr, r, g, b, a));
        }
        else if(token.compare("cutsphere")==0){
          int x0, y0, z0, rr;
          ss >> x0 >> y0 >> z0 >> rr;
          figs.push_back(new CutSphere(x0, y0, z0, rr));
        }
        else if(token.compare("putellipsoid")==0){
          int x0, y0, z0, rx, ry, rz;
          ss >> x0 >> y0 >> z0 >> rx >> ry >> rz >> r >> g >> b >> a;
          figs.push_back(new PutEllipsoid(x0, y0, z0, rx, ry, rz, r, g, b, a));
        }
        else if(token.compare("cutellipsoid")==0){
          int x0, y0, z0, rx, ry, rz;
          ss >> x0 >> y0 >> z0 >> rx >> ry >> rz;
          figs.push_back(new CutEllipsoid(x0, y0, z0, rx, ry, rz));
        }
      }   
    }
  }
  return (figs);
}


int Interpretador::getDimx(){
  return dimx;
}

int Interpretador::getDimy(){
  return dimy;
}

int Interpretador::getDimz(){
  return dimz;
}
