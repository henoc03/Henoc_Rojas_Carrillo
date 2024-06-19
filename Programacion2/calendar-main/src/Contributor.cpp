#include "Contributor.h"

Contributor::Contributor(string nameE, string idE, string jobE):Employee(nameE, idE, jobE){
    
    this->nextContributor = nullptr;
    
}

Contributor::~Contributor(){

}

void Contributor::viewOtherCalendar(Employee* employee){

    employee->viewDisponibility();

}

void Contributor::setNextContributor(Contributor* contributor){

    this->nextContributor = contributor;

}

Contributor* Contributor::getNextContributor(){

    return this->nextContributor;

} 