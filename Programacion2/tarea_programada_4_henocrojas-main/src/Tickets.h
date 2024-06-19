#include "MatrizPlantilla.h"
#include "VectorPlantilla.h"

#include "Stations.h"

#include <iostream>
using namespace std;


class Tickets
{
private:
  int counter;
  MatrizPlantilla<Stations> matrizRelacion;
  VectorPlantilla<Stations> estaciones;
public:
  Tickets();
  void pushBack();
  void seeRelations();
  void createRelations();
  ~Tickets();
  void menu();
  void imprimirEstaciones();
  void popAl();
};