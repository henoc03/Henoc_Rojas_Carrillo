#include "Manager.h"
#include <iostream>

Manager::Manager(string nameE, string idE, string jobE):Employee(nameE, idE, jobE){
    
    this->subordinates = nullptr;
    this->nextManager = nullptr;

}

Manager::~Manager(){

    delete this->subordinates;

}

void Manager::viewOtherCalendar(Employee* employee){

    if(searchSubordinate(employee->getName())){
        employee->viewCalendar();
    }
    else{
        employee->viewDisponibility();
    }

}

Contributor* Manager::searchSubordinate(string nameC){

    if(this->subordinates){
        Contributor* aux = this->subordinates;
        while(aux){
            if(nameC == aux->getName()){
                return aux;
            }
            aux = aux->getNextContributor();
        }
    }

    return nullptr;
    
}

void Manager::addSubordinate(Contributor* employee){

    if(this->subordinates){
        Contributor* aux = this->subordinates;
        while(aux->getNextContributor()){
            aux = aux->getNextContributor();
        }
        aux->setNextContributor(employee);
    }
    else{
        this->subordinates = employee;
    }

}

void Manager::setNextManager(Manager* manager){

    this->nextManager = manager;

}

Manager* Manager::getNextManager(){

    return this->nextManager;

}

void Manager::viewSubordinates(){

    if(this->subordinates){
        Contributor* subordinate = this->subordinates;
        while(subordinate){
            std::cout << subordinate->getName() << "-" << subordinate->getId() << std::endl;
            
            subordinate = subordinate->getNextContributor();
        }
    }

} 