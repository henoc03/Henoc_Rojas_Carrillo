#include "Employee.h"

Employee::Reservation::Reservation(Event* event_n){

    this->event = event_n;
    this->next = nullptr;

}

Employee::Reservation::~Reservation(){

}

Event* Employee::Reservation::getEvent(){

    return this->event;

}

Employee::Reservation* Employee::Reservation::getNext(){

    return this->next;

}

void Employee::Reservation::setNext(Event* event_n){
    
    this->next = new Reservation(event_n);

}

void Employee::Reservation::setEvent(Event* event_n)
{
    this->event = event_n;
}

Employee::Employee(string nameE, string idE, string jobE){

    this->name = nameE;
    this->id = idE;
    this->job = jobE;
    this->invitations = nullptr;
    this->events = nullptr;
    
}

Employee::~Employee(){

}

string Employee::getName(){

    return this->name;

}

string Employee::getId(){

    return this->id;

}

string Employee::getJob(){

    return this->job;

}

void Employee::viewCalendar(){
    
    system("cls");
    this->sortEvents();
    if(this->events){
        Reservation* actual = this->events;
        while(actual){
            cout << endl;
            actual->getEvent()->print();
            actual = actual->getNext();
        }
    }
    cout <<" [Press enter to continue]"<<endl;
    cin.ignore();
}

void Employee::viewDisponibility(){

    system("cls");
    this->sortEvents();
    cout << "           <<<< Ocupied Dates >>>>" << endl;
    if(this->events){
        Reservation* actual = this->events;
        while(actual){
            cout << endl;
            cout << "           >> " << actual->getEvent()->getDate() << endl;
            cout << "           >> " << actual->getEvent()->getStart() << " - " << actual->getEvent()->getEnd() << endl;
            actual = actual->getNext();
        }
    }
    cout << endl << "Continue..." << endl;
    string a;
    cin >> a;
    
}

void Employee::viewInvitations(){

    system("cls");
    if(this->invitations){
        Reservation* actual = this->invitations;
        while(actual){
            actual->getEvent()->print();
            string answer;

            do{
                cout << "\nWanna join the event? [Y/N]" << "\n -> ";
                cin >> answer;
                cin.ignore();
                if(answer == "Y")
                {
                    if(compareEventsTimes(actual->getEvent()->getStart(), actual->getEvent()->getEnd(), actual->getEvent()->getDate())){
                        createEvent(actual->getEvent());
                        this->invitations = this->invitations->getNext();
                    }
                    else{
                        cout << "<< Invitation declined due to conflict with another event! >>";
                        cout << endl << "Press any key to continue..." << endl;
                        string a;
                        cin >> a;
                        this->invitations = this->invitations->getNext();
                    }
                }
                else if(answer == "N"){
                    cout << "<< Invitation declined! >>";
                    this->invitations = this->invitations->getNext();
                }
                else{
                    cout << "Invalid option! Please try again" << endl;
                }
            } while(answer != "Y" && answer != "N");

            actual = actual->getNext();
        }
    }
    else{
        cout << "                   <<<< NO INVITATIONS ON LIST" << " >>>>" << endl;
        cout << endl << "Press any key to continue..." << endl;
        string a;
        cin >> a;
    }

}

void Employee::addInvitation(Event* event){

    if(this->invitations){
        Reservation* actual = this->invitations;
        while(actual->getNext()){
            actual = actual->getNext();
        }
        actual->setNext(event);
    }
    else{
        this->invitations = new Reservation(event);
    }

}

void Employee::createEvent(Event* event_n)
{
  if(this->events){
        Reservation* actual = this->events;
        while(actual->getNext()){
            actual = actual->getNext();
        }
        actual->setNext(event_n);
    }
    else{
        this->events = new Reservation(event_n);
    }
}


void Employee::viewEvents()
{
    Reservation* current = this->events;

    while(current){
        current->getEvent()->printMainData();
        current = current->getNext();
    }
}

Event* Employee::modifyEventReturn(string name_n)
{
    Reservation* current = this->events;

    while(current){
        if(current->getEvent()->getName() == name_n)
        {
            return current->getEvent();
            break;
        }else{
            current = current->getNext();
        }
        
    }
    return nullptr;
}

bool Employee::compareEventsTimes(string compareStartTime, string compareEndTime, string compareDate){

    if(this->events){
        Reservation* current = this->events;
        int* EventStart = divideData(compareStartTime, ':');
        int* EventEnd = divideData(compareEndTime, ':');
        int* ActualStart;
        int* ActualEnd;

        while(current){
            ActualStart = divideData(current->getEvent()->getStart(), ':');
            ActualEnd = divideData(current->getEvent()->getEnd(), ':');
            if(compareDate == current->getEvent()->getDate()){  // SAME DATE
                if(EventStart[0] == ActualStart[0] || EventEnd[0] == ActualEnd[0]){ // Same time events
                    delete[] EventStart;
                    delete[] EventEnd;
                    delete[] ActualStart;
                    delete[] ActualEnd;
                    return false;
                }
                else if((EventStart[0] > ActualStart[0] && EventStart[0] < ActualEnd[0]) || (EventEnd[0] > ActualStart[0] && EventEnd[0] < ActualEnd[0])){   // Starts or Ends in between another event
                    delete[] EventStart;
                    delete[] EventEnd;
                    delete[] ActualStart;
                    delete[] ActualEnd;
                    return false;
                }
                else if(EventStart[0] < ActualStart[0] && EventEnd[0] > ActualEnd[0]){  // New event covers another event
                    delete[] EventStart;
                    delete[] EventEnd;
                    delete[] ActualStart;
                    delete[] ActualEnd;
                    return false;
                }
                else if(EventStart[0] == ActualEnd[0] && EventStart[1] < ActualEnd[1]){     // Event starts before other ends
                    delete[] EventStart;
                    delete[] EventEnd;
                    delete[] ActualStart;
                    delete[] ActualEnd;
                    return false;
                }
                else if(EventEnd[0] == ActualStart[0] && EventEnd[1] > ActualStart[1]){     // Event ends after other starts
                    delete[] EventStart;
                    delete[] EventEnd;
                    delete[] ActualStart;
                    delete[] ActualEnd;
                    return false;
                }
            }
            current = current->getNext();
        }
    }
    return true;

}

int* Employee::divideData(string line, char division) {

  int count = 0;
  for (size_t i = 0; i < line.length(); i++) {
    if (line[i] == division) {
      count++;
    }
  }
  count ++;
  string text;
  int* data = new int[count];
  
  int i = 0;
  for (int word = 0; word < count; word++) {
    text = "";
    while (line[i] != division && line[i] != '\0') {
      text += line[i];
      i++;
    }
    data[word] = stoi(text);
    i++;
  }
  return data;

}

void Employee::sortEvents() {
    // Obtener el tamaño de la lista "events"
    int eventsCount = 0;
    Reservation* currentEvent = events;
    while (currentEvent != nullptr) {
        eventsCount++;
        currentEvent = currentEvent->getNext();
    }

    // Crear un array temporal de punteros a eventos con el tamaño de "eventsCount"
    Event** eventsArray = new Event*[eventsCount];

    // Copiar los eventos de la lista "events" al array temporal
    currentEvent = events;
    for (int i = 0; i < eventsCount; i++) {
        eventsArray[i] = currentEvent->getEvent();
        currentEvent = currentEvent->getNext();
    }

    // Ordenar el array de eventos utilizando el método auxiliar "isEventRecent" como comparador
    for (int i = 0; i < eventsCount - 1; i++) {
        for (int j = 0; j < eventsCount - i - 1; j++) {
            if (isEventRecent(eventsArray[j], eventsArray[j + 1])) {
                // Intercambiar los eventos si están en el orden incorrecto
                Event* temp = eventsArray[j];
                eventsArray[j] = eventsArray[j + 1];
                eventsArray[j + 1] = temp;
            }
        }
    }

    // Actualizar la lista "sorted" con los eventos ordenados
    // Actualizar la lista "events" con los eventos ordenados
    currentEvent = events;
    for (int i = 0; i < eventsCount; i++) {
        currentEvent->setEvent(eventsArray[i]);
        currentEvent = currentEvent->getNext();
    }

    // Liberar la memoria ocupada por el array temporal
    delete[] eventsArray;



}



bool Employee::isEventRecent(Event* event1, Event* event2)
{
    // Comparar las fechas en formato "dd/mm/aaaa"
    int day1 = stoi(event1->getDate().substr(0, 2));
    int month1 = stoi(event1->getDate().substr(3, 2));
    int year1 = stoi(event1->getDate().substr(6, 4));

    int day2 = stoi(event2->getDate().substr(0, 2));
    int month2 = stoi(event2->getDate().substr(3, 2));
    int year2 = stoi(event2->getDate().substr(6, 4));

    if (year1 < year2)
        return true;
    else if (year1 > year2)
        return false;

    if (month1 < month2)
        return true;
    else if (month1 > month2)
        return false;

    if (day1 < day2)
        return true;
    else if (day1 > day2)
        return false;

    // Comparar las horas en formato "HH:MM"
    int hour1 = stoi(event1->getStart().substr(0, 2));
    int minute1 = stoi(event1->getStart().substr(3, 2));

    int hour2 = stoi(event2->getStart().substr(0, 2));
    int minute2 = stoi(event2->getStart().substr(3, 2));

    if (hour1 < hour2)
        return true;
    else if (hour1 > hour2)
        return false;

    if (minute1 < minute2)
        return true;
    else if (minute1 > minute2)
        return false;

    // Las fechas y horas son iguales
    return false;
}