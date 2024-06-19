#include "MatrizPlantilla.h"
#include "VectorPlantilla.h"

#include "Employee.h"

#include <iostream>
using namespace std;


class Workers
{
private:
  int counter; 

  VectorPlantilla<Employee> workers;
  MatrizPlantilla<Employee> matrizRelacion;
  
public:
  Workers();
  void pushBack();
  void seeRelations();
  void createRelations();
  void setRelations();
  ~Workers();
  void menu();
  void imprimirTrabajadores();
  void popAl();
  
};