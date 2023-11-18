
#include <iostream>
#include <fstream>
#include <chrono>//για το seconds()
#include <thread>//για το sleep_for()
#include <conio.h> //για την _getch()

using namespace std;


//Βασική κλάση
class Pomodoro 
{
    public:

    void startSession( void);
    void startBreak(void);
    void endSession(int x);
    void getStatistics( void);
    void Time_settings( void);

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

//Μενού
void basemenu (void);
void Statistics_menu (int sessionsCompleted,int totalWorkTime);
void Time_settingsmenu ( int WorkDuration, int BreakDuration);

//choices
void basemenu_choices(Pomodoro& c);

