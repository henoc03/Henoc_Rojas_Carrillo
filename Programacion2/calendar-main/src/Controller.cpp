#include "Controller.h"

Controller::Controller() {
  //        C           A       L         E           #          D         A R
  cout << " _______     ____     __       ______   ___      __   ____       "
          "____     ______"
       << endl;
  cout << "|   ___ |   /    \\   |  |     |   ___| |    \\   |  | |     \\    "
          "/    \\   |   _   \\ "
       << endl;
  cout << "|  |       /  /\\  \\  |  |     |  |__   |     \\  |  | |  |\\  |  "
          "/  /\\  \\  |  | |  |"
       << endl;
  cout << "|  |      |  /__\\  | |  |     |   __|  |  |\\  \\ |  | |  ||  | |  "
          "/__\\  | |  |_/  /"
       << endl;
  cout << "|  |____  |  |  |  | |  |___  |  |___  |  | \\  \\|  | |  |/  | |  "
          "|  |  | |  |\\  \\ "
       << endl;
  cout << "|_______| |__|  |__| |______| |______| |__|  \\____ | |____ /  |__| "
          " |__| |__| \\__\\"
       << endl
       << endl;

  this->managers = nullptr;
  this->MainCalendar = new Calendar();
}

Controller::~Controller() {}

void Controller::SignIn() {

  cout << "                           Options: " << endl
       << "                           1. Log in" << endl
       << "                           2. Sign up" << endl
       << "                           3. Exit " <<endl
       << "                           > ";

  int option;
  cin >> option;
  cin.ignore();

  if (option == 1) {
    cout<< "                                   User name: "<<endl
        <<"                                    > ";
    getline(cin, this->user);
    cout<< "                                   Password: "<<endl
        <<"                                    > ";
    getline(cin, this->password);

    if (authenticateUser(user, password)) {
      loadEmployees();
      this->currentUser = searchEmployee(this->user);
      cout << "Successful start of session.\n";
      loadEvents();
      mainMenu();
    } else {

      char confirmation;
      cout << "                           Your user or password is incorrect"
           << endl
           << "                           Do you wanna try again? [Y/N] ";
      cin >> confirmation;
      cin.ignore();
      if (confirmation == 'Y') {
        system("cls");
        SignIn();
      }
    }

  } else if (option == 2) {
    newEmployee();
    system("cls");
    SignIn();

  } else if (option == 3) {
    saveEvents();

  } else {
    system("cls");
    cout << "\n\n>>>Error, Type a valid option" << endl;
    SignIn();
  }
}


void Controller:: newEmployee(){
    int option;
    cout<< "                                   User name: "<<endl
        <<"                                    > ";
    getline(cin, this->user);
    cout<< "                                   Id: "<<endl
        <<"                                    > ";
    getline(cin, this->id);
    cout<< "                                   Password: "<<endl
        <<"                                    > ";
    getline(cin, this->password);



    cout << "\n                           Options: " << endl
     << "                           1. Manager" << endl
     << "                           2. Individual Contributor" << endl
     << "                           3. Exit " << endl
     <<"                            > ";
    cin >> option;
    if (option == 1) {
      
      newManager(user, id);
      registerUser(user, password);
    } else if (option == 2){
      
      newContributor(user, id);
      registerUser(user, password);
    } else if (option == 3){
      return;
    } else {
    system("cls");
    cout << "\n\n>>>Error, Type a valid option" << endl;
    newEmployee();
  }
}

void Controller::newManager(string user, string id)
{
  ofstream file("Employees.txt", ios::app);
  if (file.is_open()) {
    
    file <<'\n'<< user << '/' << id << "/Manager"<<'\n'<<'*';
    file.close();
  } else {
    cout << "The file could not be opened.\n";
  }
}

void Controller::newContributor(string user, string id) {
    string manager;
    string line;
    ifstream file("Employees.txt");
    ofstream tempFile("TempEmployees.txt");
    if (file.is_open() && tempFile.is_open()) {
        cout << "                           Who is your manager" << endl;
        cin >> manager;
        cin.ignore();
        while (getline(file, line)) {
            if (line != "*") {
                string* data = getData(line);
                tempFile << line << '\n';
                if (data[0] == manager) {
                    tempFile << user << '/' << id << "/Individual Contributor" << '\n';
                }
                delete[] data;
            } else {
                tempFile << line << '\n';
            }
        }
        file.close();
        tempFile.close();
        remove("Employees.txt");
        rename("TempEmployees.txt", "Employees.txt");
    }
}

string* Controller::getData(string line) {

  int count = 0;
  for (size_t i = 0; i < line.length(); i++) {
    if (line[i] == '/') {
      count++;
    }
  }
  count ++;
  string text;
  string* data = new string[count];
  
  int i = 0;
  for (int word = 0; word < count; word++) {
    text = "";
    while (line[i] != '/' && line[i] != '\0') {
      text += line[i];
      i++;
    }
    data[word] = text;
    i++;
  }

  return data;
}

string* Controller::getData2(string line) {

  int count = 0;
  for (size_t i = 0; i < line.length(); i++) {
    if (line[i] == '-') {
      count++;
    }
  }
  count ++;
  string text;
  string* data = new string[count];
  
  int i = 0;
  for (int word = 0; word < count; word++) {
    text = "";
    while (line[i] != '-' && line[i] != '\0') {
      text += line[i];
      i++;
    }
    data[word] = text;
    i++;
  }
  return data;
}

void Controller::loadEmployees() {

  ifstream file;
  file.open("Employees.txt");
  string line;
  string name;
  string id;
  string job;
  Manager *actualManager;

  if (file.is_open()) {

    while (!file.eof()) {

      getline(file, line);
      if (!line.empty()) {

        actualManager = addManager(line);
        getline(file, line);

        while (line != "*") {
          addSubordinate(line, actualManager);
          getline(file, line);
        }
      }
    }

  } else {
    cout << "File Error" << endl;
  }
  file.close();
}

void Controller::mainMenu() {
  int option;
  system("cls");
  cout << "                |\\ /| |'''' |\\  | |  |" << endl
       << "                | v | |---  | \\ | |  |" << endl
       << "                |   | |.... |  \\| \\__/" << endl;

  cout << "                Hello " << user << "!" << endl << endl;

  cout << "                Options:" << endl
       << "                1. Create event" << endl
       << "                2. Change event" << endl
       << "                3. View calendar" << endl
       << "                4. View other users calendars" << endl
       << "                5. View invitations" << endl
       << "                6. Log out" << endl
       <<"                 > ";
  cin >> option;
  cin.ignore();

  switch (option) {
  case 1:
    this->createEvents();
    this->mainMenu();
    break;
  case 2:
    this->changeEvent();
    this->mainMenu();
    break;
  case 3:
    this->currentUser->viewCalendar();
    this->mainMenu();
    break;
  case 4:
    this->viewOtherCalendar();
    this->mainMenu();
    break;
  case 5:
    this->currentUser->viewInvitations();
    this->mainMenu();
    break;
  case 6:
    this->currentUser = nullptr;
    this->SignIn();
    break;
  default:
    cout << "Invalid option... \n Please try again!" << endl;
    cout<< "[Presione enter para continuar]"<<endl;
    cin.ignore();
    this->mainMenu();
    break;
  }
}

string Controller::encrypt(const string &input, int key) {
  string encrypted = input;
  for (char &password : encrypted) {
    password = password + key;
  }
  return encrypted;
}

void Controller::registerUser(const string &username, const string &password) {
  ofstream file("Users.txt", ios::app);
  if (file.is_open()) {
    string encryptedPassword = encrypt(password, 3);
    file << username << ' ' << encryptedPassword << '\n';
    file.close();
    cout << "User registered successfully.\n";
  } else {
    cout << "The file could not be opened.\n";
  }
}

bool Controller::authenticateUser(const string &username,
                                  const string &password) {
  ifstream file("Users.txt");
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      string storedUsername, storedPassword;
      istringstream iss(line);
      if (iss >> storedUsername >> storedPassword) {
        string decryptedPassword = encrypt(storedPassword, -3);
        if (username == storedUsername && password == decryptedPassword) {
          file.close();
          return true;
        }
      }
    }
    file.close();
  }
  return false;
}


Manager *Controller::addManager(string line) {

  string *data = getData(line);
  Manager *manager = new Manager(data[0], data[1], data[2]);

  if (this->managers) {
    Manager *aux = this->managers;
    while (aux->getNextManager()) {
      aux = aux->getNextManager();
    }
    aux->setNextManager(manager);
  } else {
    this->managers = manager;
  }

  return manager;
}

void Controller::addSubordinate(string line, Manager *manager) {

  string *data = getData(line);
  Contributor *contributor = new Contributor(data[0], data[1], data[2]);
  manager->addSubordinate(contributor);
}



Employee *Controller::searchEmployee(string nameC) {

  if (this->managers) {

    Manager *manager = this->managers;
    while (manager) {

      if (manager->getName() == nameC) {
        return manager;
      } else {
        Contributor *subordinate = manager->searchSubordinate(nameC);
        if (subordinate != nullptr) {
          return subordinate;
        }
      }

      manager = manager->getNextManager();
    }
  }


  
  return nullptr;
}

void Controller::createEvents() {
  try{
    
    int option = 0;
    cout << "                Type of events:" << endl
       << "                1. Meeting"        << endl
       << "                2. Cubicle"        << endl
       << "                3. Daily event"    << endl
       << "                4. Appointment"    << endl
       << "                5. Activity"       <<endl
       << "                >";
    cin >> option;
    cin.ignore();
    if(cin.fail())
    {
      throw runtime_error("Invalid input");
    }
      
    switch(option)
    {
      case 1:
        this->createMeeting();
        break;
      case 2:
        this->createCubicle();
        break;
      case 3:
        this->createDailyEvent();
        break;
      case 4: 
        this->createAppointment();
        break;
      case 5:
        this->createActivity();
        break;
      
      default:
        cout<<"La opcion ingresada es incorrecta"<<endl
            <<"[Presione enter para continuar]"<<endl;
        cin.ignore();
        break;
        
      
    }
    
  }catch(exception& e){
    cerr <<"Exception: "<<e.what();
  }
      
    
}

void Controller::createMeeting() 
{
  string inputTemp;
  string* meetName;
  string* startTime;
  string* endTime;
  string* guests;
  string* date;
  string* place;
  string* organizer = new string (currentUser->getName());
  cout<< "           Nombre de la reunion > ";
  getline(cin, inputTemp);
  meetName = new string(inputTemp);
  cout<< "           Hora de inicio [HH:MM] > ";
  getline(cin, inputTemp);
  startTime = new string(inputTemp);
  cout<< "           Hora de finalizacion [HH:MM] > ";
  getline(cin, inputTemp); 
  endTime = new string(inputTemp);
  cout<< "           Fecha [DD/MM/AAAA] > ";
  getline(cin, inputTemp);
  date = new string(inputTemp);
  cout<< "           Invitados [nombre 1/nombre 2/...]"<<endl
      << "           > ";
  getline(cin, inputTemp);
  guests = this->getData(inputTemp);
  cout<< "           Lugar >";
  getline(cin, inputTemp);
  place = new string(inputTemp);

  if(this->currentUser->compareEventsTimes(*startTime, *endTime, *date)){

    Meeting* newMeet = new Meeting(meetName, date, startTime, endTime, place, guests, organizer);
    this->currentUser->createEvent(newMeet);
    this->MainCalendar->addMeeting(newMeet);

    
    int count = 0;
    while(guests+count != nullptr)
    {
      Employee* currentEmploye = this->searchEmployee(*(guests+count));
      if (currentEmploye)
      {
        currentEmploye->addInvitation(newMeet);
      }
      count++;
    }
  }
  else{
    cout << endl << "Event not created due to a conflict with another event!" << endl;
    cout << endl << "Press any key to continue..." << endl;
    string a;
    cin >> a;
  }
  
}

void Controller::createCubicle() 
{
  
  string inputTemp;
  string* cubName;
  string* startTime;
  string* endTime;
  string* date;
  int* cubicle;
  cout<< "           Nombre del cubiculo > ";
  getline(cin, inputTemp);
  cubName = new string(inputTemp);
  cout<< "           Hora de inicio [HH:MM] > ";
  getline(cin, inputTemp);
  startTime = new string(inputTemp);
  cout<< "           Hora de finalizacion [HH:MM] > ";
  getline(cin, inputTemp); 
  endTime = new string(inputTemp);
  cout<< "           Fecha [DD/MM/AAAA] > ";
  getline(cin, inputTemp);
  date = new string(inputTemp);
  cout<< "           Numero de cubiculo >";
  int temp;
  cin>>temp;
  cin.ignore();
  cubicle = new int(temp);

    Cubicle* newCubicle = new Cubicle(cubName, date, startTime, endTime, cubicle);
    this->currentUser->createEvent(newCubicle);
    this->MainCalendar->addCubicle(newCubicle);
}

void Controller::createDailyEvent() 
{
  string inputTemp;
  string* dailyEventName;
  string* date;
  cout<< "           Nombre del evento diario > ";
  getline(cin, inputTemp);
  dailyEventName = new string(inputTemp);
  cout<< "           Fecha [DD/MM/AAAA] > ";
  getline(cin, inputTemp);
  date = new string(inputTemp);

  if(this->currentUser->compareEventsTimes("00:00", "23:59", *date)){

    DailyEvent* newDailyEvent = new DailyEvent(dailyEventName, date);
    this->currentUser->createEvent(newDailyEvent);
    this->MainCalendar->addDailyEvent(newDailyEvent);
  }
  else{
    cout << endl << "Event not created due to a conflict with another event!" << endl;
    cout << endl << "Press any key to continue..." << endl;
    string a;
    cin >> a;
  }
}
  
void Controller::createAppointment()
{
  string inputTemp;
  string* appoName;
  string* startTime;
  string* endTime;
  string* date;
  cout<< "           Nombre de la cita > ";
  getline(cin, inputTemp);
  appoName = new string(inputTemp);
  cout<< "           Hora de inicio [HH:MM] > ";
  getline(cin, inputTemp);
  startTime = new string(inputTemp);
  cout<< "           Hora de finalizacion [HH:MM] > ";
  getline(cin, inputTemp); 
  endTime = new string(inputTemp);
  cout<< "           Fecha [DD/MM/AAAA] > ";
  getline(cin, inputTemp);
  date = new string(inputTemp);

  if(this->currentUser->compareEventsTimes(*startTime, *endTime, *date)){

    Appointment* newAppointment = new Appointment(appoName, date, startTime, endTime);
    this->currentUser->createEvent(newAppointment);
    this->MainCalendar->addAppointment(newAppointment);
  }
  else{
    cout << endl << "Event not created due to a conflict with another event!" << endl;
    cout << endl << "Press any key to continue..." << endl;
    string a;
    cin >> a;
  }
}

void Controller::createActivity()
{
  string inputTemp;
  string* activityName;
  string* startTime;
  string* endTime;
  string* guests;
  string* date;
  string* place;
  cout<< "           Nombre de la actividad > ";
  getline(cin, inputTemp);
  activityName = new string(inputTemp);
  cout<< "           Hora de inicio [HH:MM] > ";
  getline(cin, inputTemp);
  startTime = new string(inputTemp);
  cout<< "           Hora de finalizacion [HH:MM] > ";
  getline(cin, inputTemp); 
  endTime = new string(inputTemp);
  cout<< "           Fecha [DD/MM/AAAA] > ";
  getline(cin, inputTemp);
  date = new string(inputTemp);
  cout<< "           Invitados [nombre 1/nombre 2/...]"<<endl
      << "           > ";
  getline(cin, inputTemp);
  guests = this->getData(inputTemp);
  cout<< "           Lugar >";
  getline(cin, inputTemp);
  place = new string(inputTemp);

  if(this->currentUser->compareEventsTimes(*startTime, *endTime, *date)){

    Activity* newActivity = new Activity(activityName, date, startTime, endTime, place, guests);
    this->currentUser->createEvent(newActivity);
    this->MainCalendar->addActivity(newActivity);

    
    int count = 0;
    while(guests+count != nullptr)
    {
      Employee* currentEmploye = this->searchEmployee(*(guests+count));
      if (currentEmploye)
      {
        currentEmploye->createEvent(newActivity);
      }
      count++;
    }
  }
  else{
    cout << endl << "Event not created due to a conflict with another event!" << endl;
    cout << endl << "Press any key to continue..." << endl;
    string a;
    cin >> a;
  }
}

void Controller::changeEvent()
{
    try{

        this->currentUser->viewEvents();

        string nameEvent;
        cout <<"   Ingrese el nombre del evento a modificar> ";
        getline(cin, nameEvent);
        Event* currentEvent = this->currentUser->modifyEventReturn(nameEvent);
        if (currentEvent)
        {
            string name = currentEvent->getName();
            string date = currentEvent->getDate();
            string startT = currentEvent->getStart();
            string endT= currentEvent->getEnd();
            int option;
            cout<< "                     [Opciones]"<<endl
                << "             1. Editar nombre"<<endl
                << "             2. Cambiar hora de inicio"<<endl
                << "             3. Cambiar hora de inicio"<<endl
                << "             4. Cambiar fecha"<<endl
                << "             >";
            cin >> option;
            if (cin.fail())
            {
                throw runtime_error("Invalid input");
            }
            cin.ignore();

            switch (option)
            {
            case 1:
                cout<< "    Nuevo nombre > ";
                getline(cin, name);
                break;
            case 2:
                cout<< "    Nueva hora de inicio > ";
                getline(cin, startT);
                break;
            case 3:
                cout<< "    Nueva hora de final > ";
                getline(cin, endT);
                break;
            case 4:
                cout<< "    Nueva fecha > ";
                getline(cin, date);
                break;
            default:
                break;
            }
            name = name + " [Editado]";

            currentEvent->editEvent(name, date, startT, endT);


        }else{
            cout <<"          No hay eventos con este nombre"<<endl;
        }

    }catch(exception& e)
    {
        cerr <<"Exception "<< e.what();
    }

}

void Controller::saveMeeting(string* newName, string* newDate, string* newStart, string* newEnd, string* place, string* guests, string* organizer){

    string line;
    ifstream file("Events.txt");
    ofstream tempFile("TempEvents.txt");
    if (file.is_open() && tempFile.is_open()) {
        while (getline(file, line)) {
            if (line == "*") {
                tempFile << "*" <<'\n';
                getline(file, line);
                tempFile << line << '\n';
                if (line == "Meeting") {
                    tempFile << *newName <<"-"<<  *newDate<<"-"<<  *newStart <<"-"<<  *newEnd<< "-"<< *place <<"-"<<  *guests << "-"<< *organizer<< '\n';
                }
            } else {
                tempFile << line << '\n';
            }
        }
        file.close();
        tempFile.close();
        remove("Events.txt");
        rename("TempEvents.txt", "Events.txt");
    }
}

void Controller::saveCubicle(string* newName, string* newDate, string* newStart, string* newEnd, int* cubicleNumber_n){

    string line;
    ifstream file("Events.txt");
    ofstream tempFile("TempEvents.txt");
    if (file.is_open() && tempFile.is_open()) {
        while (getline(file, line)) {
            if (line == "*") {
                tempFile << "*" <<'\n';
                getline(file, line);
                tempFile << line << '\n';
                if (line == "Cubicle") {
                    tempFile << *newName <<"-"<<  *newDate<<"-"<<  *newStart <<"-"<<  *newEnd<< "-"<< *cubicleNumber_n << '\n';
                }
            } else {
                tempFile << line << '\n';
            }
        }
        file.close();
        tempFile.close();
        remove("Events.txt");
        rename("TempEvents.txt", "Events.txt");
    }
}

void Controller::saveDailyEvent(string* newName, string* newDate){
    string line;
    ifstream file("Events.txt");
    ofstream tempFile("TempEvents.txt");
    if (file.is_open() && tempFile.is_open()) {
        while (getline(file, line)) {
            if (line == "*") {
                tempFile << "*" <<'\n';
                getline(file, line);
                tempFile << line << '\n';
                if (line == "DailyEvent") {
                    tempFile << *newName <<"-"<<  *newDate << '\n';
                }
            } else {
                tempFile << line << '\n';
            }
        }
        file.close();
        tempFile.close();
        remove("Events.txt");
        rename("TempEvents.txt", "Events.txt");
    }
}

void Controller::saveAppointment(string* newName, string* newDate, string* newStart, string* newEnd){
    string line;
    ifstream file("Events.txt");
    ofstream tempFile("TempEvents.txt");
    if (file.is_open() && tempFile.is_open()) {
        while (getline(file, line)) {
            if (line == "*") {
                tempFile << "*" <<'\n';
                getline(file, line);
                tempFile << line << '\n';
                if (line == "Appointment") {
                    tempFile <<*newName <<"-"<<  *newDate<<"-"<<  *newStart <<"-"<<  *newEnd<<'\n';
                }
            } else {
                tempFile << line << '\n';
            }
        }
        file.close();
        tempFile.close();
        remove("Events.txt");
        rename("TempEvents.txt", "Events.txt");
    }
}

void Controller::saveActivity(string* newName, string* newDate, string* newStart, string* newEnd, string* place, string* guests){

    string line;
    ifstream file("Events.txt");
    ofstream tempFile("TempEvents.txt");
    if (file.is_open() && tempFile.is_open()) {
        while (getline(file, line)) {
            if (line == "*") {
                tempFile << "*" <<'\n';
                getline(file, line);
                tempFile << line << '\n';
                if (line == "Activity") {
                    tempFile << *newName <<"-"<<  *newDate<<"-"<<  *newStart <<"-"<<  *newEnd<< "-"<< *place <<"-"<<  *guests << '\n';
                }
            } else {
                tempFile << line << '\n';
            }
        }
        //tempFile << "*";
        file.close();
        tempFile.close();
        remove("Events.txt");
        rename("TempEvents.txt", "Events.txt");
    }
}

void Controller::viewOtherCalendar(){

  string nameC;
  cout << "     Which calendar you wanna see?  \n     -> ";
  getline(cin, nameC);
  Employee* currentEmploye = this->searchEmployee(nameC);
  if(currentEmploye){
    this->currentUser->viewOtherCalendar(currentEmploye);
  }
  else{
    cout << "\n     <<< EMPLOYEE NOT FOUND >>>" << endl;
  }
}

void Controller::loadEvents(){
  string line;
  ifstream file("Events.txt");
  if (file.is_open()) {
    getline(file, line);
    string* guests;
    if (line == "*") {
      getline(file, line);
      getline(file, line);
      while (line != "*") {
        string* data = getData2(line);
        string* meetName = new string(data[0]);
        string* startTime = new string(data[2]);
        string* endTime = new string(data[3]);
        guests = getData(data[5]);
        //guests = new string(data[5]);
        string* date = new string(data[1]);
        string* place = new string(data[4]);
        string* organizer = new string(data[6]);
        Meeting* newMeet = new Meeting(meetName, date, startTime, endTime, place, guests, organizer);
        Employee* currentEmployee = this->searchEmployee(*organizer);
        currentEmployee->createEvent(newMeet);
        delete[] data;
        int count = 0;
        // while(guests+count)
        // {
        //   Employee* currentEmploye = this->searchEmployee(*(guests+count));
        //   if (currentEmploye)
        //   {
        //     currentEmploye->addInvitation(newMeet);
        //   }
        //   count++;
        // }
        getline(file, line);
      }

      getline(file, line);
      getline(file, line);
      while (line != "*") {
        string* data = getData2(line);
        string* cubName = new string(data[0]);
        string* startTime = new string(data[2]);
        string* endTime = new string(data[3]);
        string* date = new string(data[1]);

        int* cubicle = new int( stoi(data[4]));
        Cubicle* newCubicle = new Cubicle(cubName, date, startTime, endTime, cubicle);
        currentUser->createEvent(newCubicle);
        delete[] data;
        getline(file, line);
      }
      getline(file, line);
      getline(file, line);
      while (line != "*") {
        string* data = getData2(line);
        string* dailyEventName = new string(data[0]);
        string* date = new string(data[1]);
        DailyEvent* newDailyEvent = new DailyEvent(dailyEventName, date);
        currentUser->createEvent(newDailyEvent);
        delete[] data;
        getline(file, line);
      }
      getline(file, line);
      getline(file, line);
      while (line != "*") {
        string* data = getData2(line);
        string* appoName = new string(data[0]);
        string* date = new string(data[1]);
        string* startTime = new string(data[2]);
        string* endTime = new string(data[3]);
        Appointment* newAppointment = new Appointment(appoName, date, startTime, endTime);
        currentUser->createEvent(newAppointment);
        delete[] data;
        getline(file, line);
      }
      getline(file, line);
      getline(file, line);
      while (line != "*") {
        string* data = getData2(line);
        string* activityName = new string(data[0]);
        string* date = new string(data[1]);
        string* startTime = new string(data[2]);
        string* endTime = new string(data[3]);
        guests = new string(data[5]);
        string* place = new string(data[4]);
        Activity* newActivity = new Activity(activityName, date, startTime, endTime, place, guests);
        currentUser->createEvent(newActivity);
        delete[] data;
        int count = 0;

        // while(guests+count)
        // {
        //   Employee* currentEmploye = this->searchEmployee(*(guests+count));
        //   if (currentEmploye)
        //   {
        //       currentEmploye->createEvent(newActivity);
        //   }
        //   count++;
        // }
        getline(file, line);
      }

      
    }
  }
  file.close();
}



void Controller::saveEvents(){

  if(this->MainCalendar->getMeetingsHead()){
    Meeting* actualM = this->MainCalendar->getMeetingsHead();
    while(actualM){
      saveMeeting(new string (actualM->getName()), new string (actualM->getDate()), new string (actualM->getStart()), new string (actualM->getEnd()), new string (actualM->getPlace()), actualM->getGuests(), new string (actualM->getOrganizer()));
      actualM = actualM->getNext();
    }
    delete actualM;
  }

  if(this->MainCalendar->getCubicleHead()){
    Cubicle* actualC = this->MainCalendar->getCubicleHead();
    while(actualC){
      saveCubicle(new string (actualC->getName()), new string (actualC->getDate()), new string (actualC->getStart()), new string (actualC->getEnd()), new int(actualC->getNumber()));
      actualC = actualC->getNext();
    }
    delete actualC;
  }

  if(this->MainCalendar->getDailyEventHead()){
    DailyEvent* actualD = this->MainCalendar->getDailyEventHead();
    while(actualD){
      saveDailyEvent(new string (actualD->getName()), new string (actualD->getDate()));
      actualD = actualD->getNext();
    }
    delete actualD;
  }

  if(this->MainCalendar->getAppointmentHead()){
    Appointment* actualA = this->MainCalendar->getAppointmentHead();
    while(actualA){
      saveAppointment(new string (actualA->getName()), new string (actualA->getDate()), new string (actualA->getStart()), new string (actualA->getEnd()));
      actualA = actualA->getNext();
    }
    delete actualA;
  }

  if(this->MainCalendar->getActivitiesHead()){
    Activity* actualM = this->MainCalendar->getActivitiesHead();
    while(actualM){
      saveActivity(new string (actualM->getName()), new string (actualM->getDate()), new string (actualM->getStart()), new string (actualM->getEnd()), new string (actualM->getPlace()), actualM->getGuests());
      actualM = actualM->getNext();
    }
    delete actualM;
  }

}