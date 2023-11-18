
#include <iostream>
#include <fstream>
#include <chrono>//για το seconds()
#include <thread>//για το sleep_for()
#include <conio.h> //για την _getch()
#include <string>//για το name
#include <queue>//για την στοίβα
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

    void set_name (std::string name);
    void set_WorkDuration(int x);
    void set_BreakDuration(int x);
    void add_sessionsCompleted(void);
    void add_totalWorkTime(int x);

    std::string get_name (void);
    int get_WorkDuration(void);
    int get_BreakDuration(void);
    int get_sessionsCompleted(void);
    int get_totalWorkTime(void);


    Pomodoro():name("Guest"),WorkDuration(1500),BreakDuration(300),sessionsCompleted(0),totalWorkTime(0){};
    Pomodoro(std::string name):name(name),WorkDuration(1500),BreakDuration(300),sessionsCompleted(0),totalWorkTime(0){};

    
    private:

    std::string name ;
    int WorkDuration ;
    int BreakDuration ;
    int sessionsCompleted ;
    int totalWorkTime ;

    

};

//Μενού
void users_menu (queue<std::string> names);
void basemenu (void);
void Statistics_menu (int sessionsCompleted,int totalWorkTime,std::string name);
void Time_settingsmenu ( int WorkDuration, int BreakDuration);

//choices
void basemenu_choices(Pomodoro& c);
void users_menu_choices(void);


std::string get_name(void);


