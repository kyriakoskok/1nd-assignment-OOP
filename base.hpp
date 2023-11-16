#include <iostream>
#include <fstream>
#include <chrono>//για το seconds()
#include <thread>//για το sleep_for()
#include <conio.h> //για την _getch()

using namespace std;


class Pomodoro 
{
    public:

    void startSession( void);
    void startBreak(void);
    void endSession(int x);
    void getStatistics( void);
    void Time_settings( Pomodoro& c);

    void set_WorkDuration(int x);
    void set_BreakDuration(int x);
    void add_sessionsCompleted(void);
    void add_totalWorkTime(int x);

    int get_WorkDuration(void);
    int get_BreakDuration(void);
    int get_sessionsCompleted(void);
    int get_totalWorkTime(void);




    
    private:

    int WorkDuration = 1500;
    int BreakDuration = 300;
    int sessionsCompleted = 0;
    int totalWorkTime = 0;

    

};
//Βασική κλάση
void basemenu (void);
//Βασικό Μενού

void Statistics_menu (int sessionsCompleted,int totalWorkTime);

//Εμφάνηση στατηστικών
void Time_settingsmenu ( int WorkDuration, int BreakDuration);

void basemenu_choices(Pomodoro& c);
