#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>
#include "figurageometrica.h"
#include "interpretador.h"
#include "putbox.h"
#include "cutbox.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"


 int main(){
  // Sculptor *Teste;
  Sculptor *Cereja;
  Interpretador Analisador;

  std::vector<FiguraGeometrica*> figs;

  figs = Analisador.analise("cereja.txt");

  Cereja = new Sculptor(Analisador.getDimx(), Analisador.getDimy(), Analisador.getDimz());

  for(size_t i = 0; i < figs.size(); i++){
    std::cout << "draw\n";

    figs[i]->draw(*Cereja);
  }

  Cereja->writeOFF((char *)"cereja.off");

  for(size_t i = 0; i < figs.size(); i++){
    delete figs[i];
  }
  delete Cereja; 
  return 0;
}
