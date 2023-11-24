
#include <iostream>
#include <fstream>
#include <chrono>//για το seconds()
#include <thread>//για το sleep_for()
#include <conio.h> //για την _getch()
#include <string>//για τα strings
#include <queue>//για την ουρά
using namespace std;


//Βασική κλάση
class Pomodoro 
{
    public:

    //δήλωση κατασκεβασών 
    Pomodoro():name("Guest"),WorkDuration(1500),BreakDuration(300),sessionsCompleted(0),totalWorkTime(0){};
    Pomodoro(std::string name);
    Pomodoro(int x);


    //βασικές συναρτήσεις
    void startSession( void);
    void startBreak(void);
    void endSession(int x);
    void getStatistics( void);
    void Time_settings( void);
    //επεξεργασία δεδομένων
    void set_name (std::string name);
    void set_WorkDuration(int x);
    void set_BreakDuration(int x);
    void add_sessionsCompleted(void);
    void add_totalWorkTime(int x);
    //εξαγωγή δεδομένων
    std::string get_name (void);
    int get_WorkDuration(void);
    int get_BreakDuration(void);
    int get_sessionsCompleted(void);
    int get_totalWorkTime(void);


    
    private:
    //δεδομένα
    std::string name ;
    int WorkDuration ;
    int BreakDuration ;
    int sessionsCompleted ;
    int totalWorkTime ;

    

};

//Μενού
void users_menu (queue<std::string> names);
void basemenu (void);
void users_basemenu (void);
void Statistics_menu (int sessionsCompleted,int totalWorkTime,std::string name);
void Time_settingsmenu ( int WorkDuration, int BreakDuration);

//choices
void basemenu_choices(Pomodoro& c);
void users_menu_choices(void);
void Guest_basemenu_choices(Pomodoro& c);



//ελένχοι κα.
std::string get_name(void);
bool check_name(std::string name);
int check_number_of_users(void);


//επεξεργασία  files
queue<std::string> get_names(void);
void set_information_on_file(std::string name,int WorkDuration,int BreakDuration,int sessionsCompleted, int totalWorkTime);
void delete_user(std::string name);
