#include "MatrizPlantilla.h"
#include "VectorPlantilla.h"
#include "Users.h"


#include <iostream>
using namespace std;


class Romance
{
private:
  int counter;
  MatrizPlantilla<Users> matrizRelacion;
  VectorPlantilla<Users> usuarios; 
  string name;
  string username;
  string password;
public:
  Romance();
  void pushBack();
  void seeRelations(int user);
  void createRelations(int user);
  ~Romance();
  void menu();
  void menu2(int user);
  void ImprimirUsuarios(int user);
  void popAl(int user);
  void setRelations(int user);
};