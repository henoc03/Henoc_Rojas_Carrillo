#ifndef CALENDAR_H
#define CALENDAR_H

#include "Meeting.h"
#include "Appointment.h"
#include "Cubicle.h"
#include "Activity.h"
#include "DailyEvent.h"
#include <fstream>

using namespace std;

class Calendar{
    private:
        Meeting* meetings;
        Appointment* appointments;
        Cubicle* cubicles;
        Activity* activities;
        DailyEvent* dailyEvents;
    
    public:
        Calendar();
        ~Calendar();
        Cubicle* getCubicleHead();
        Meeting* getMeetingsHead();
        DailyEvent* getDailyEventHead();
        Appointment* getAppointmentHead();
        Activity* getActivitiesHead();
        void addCubicle(Cubicle*);
        void addMeeting(Meeting*);
        void addAppointment(Appointment*);
        void addActivity(Activity*);
        void addDailyEvent(DailyEvent*);
        

};
#endif
