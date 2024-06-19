#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Manager.h"
#include "Calendar.h"
#include "Event.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Controller{
  private:
      Manager* managers;
      Calendar* MainCalendar;
      string user;
      string password;
      string id;
      Employee* currentUser;
  
  public:
      Controller();
      ~Controller();
      void SignIn();
      void registerUser(const string& username, const string& password);
      bool authenticateUser(const string& username, const string& password);
      void mainMenu();
      string encrypt(const string& input, int key);
    
      void loadEmployees();
      string* getData(string);
      string* getData2(string);
      Manager* addManager(string);
      void addSubordinate(string, Manager*);
      Employee* searchEmployee(string);
      void saveEmployeeFile();

      void changeEvent();
      void createEvents();
      void createMeeting();
      void createCubicle();
      void createAppointment();
      void createActivity();
      void createDailyEvent();
      void newEmployee();
      void newManager(string, string);
      void newContributor(string, string);

      void saveMeeting(string*, string*, string*, string*, string*, string*, string*);
      void saveCubicle(string*, string*, string*, string*, int* );
      void saveAppointment(string*, string*, string*, string*);
      void saveActivity(string*, string*, string*, string*, string*, string*);
      void saveDailyEvent(string*, string*);
      void loadEvents();

      void viewOtherCalendar();
      void saveEvents();

};
#endif
 