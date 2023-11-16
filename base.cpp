#include "base.hpp"


//Επιλογές 

void basemenu_choices(Pomodoro& c)
{
    char  x;
    while (x!='5')
    {
        system("cls"); // Clear the console screen
        basemenu ();
        x = _getch();
        switch (x)
        {
        case '1':
            c.startSession();
            break;
        case '2':
            c.startBreak();
            break;
        case '3':
            c.getStatistics();
            break;    
        case '4':
            c.Time_settings(c);
            break;
        case '5':
            cout << "Goodbye :)" ;
            break; 
        default:
            cout << "Wrong answer" << endl ;
            break;
        }
        

    }
}



//functions

void Pomodoro::startSession(void)
{
    char x = '0';
    while ((x!= ' ')&&( x != 'q'))
    {
        cout << "press spase to start the pomodoro or press q to exit" << endl;
        x = _getch();
        
    }
    if (x==' ')
    {

//-------------------------------------------------------        
        

    char userInput;
    bool timerRunning = true;
    int remainingTime = this->WorkDuration; 

    while (remainingTime > 0) {
        if (timerRunning) {
            int minutes = remainingTime / 60;
            int seconds = remainingTime % 60;

            system("cls"); // Clear the console screen

            cout << "Timer: " << minutes << " minutes " << seconds << " seconds" << endl;

            // Sleep for 1 second
            this_thread::sleep_for(chrono::seconds(1));

            remainingTime--;
        }

        if (_kbhit()) {
            userInput = _getch();
            if (userInput == 'p') {
                timerRunning = !timerRunning;
            } else if (userInput == 'q') {
                break;
            } 
        }
    }

    if (remainingTime == 0) {
        cout << "Timer has finished!" << endl;
    } else {
        cout << "Timer stopped." << endl;
    }
        








//------------------------------------------------------------------------
        
        if (remainingTime==0)
        {
            add_sessionsCompleted();
            add_totalWorkTime(get_WorkDuration());
        }
        else
        {
            cout <<"ok :)"<< endl;
            add_totalWorkTime(get_WorkDuration()-remainingTime);
        }
        
        
        cout <<"Do you want a break? Press spase..."<<endl;
        x = _getch();
        if (x==' ') this->startBreak();
        else cout << "ok :)"<<endl;
    }
    else if (x=='q')
    {
        cout << "ok :)"<<endl;
    }
}

void Pomodoro::startBreak()
{
    char x = '0';
    while ((x!= ' ')&&( x != 'q'))
    {
        cout << "press spase to start the break time or press q to exit" << endl;
        x = _getch();
    }
    if (x==' ')
    {
        


//-------------------------------------------------------        
    char userInput;
    bool timerRunning = true;
    int remainingTime = this->BreakDuration; 

    while (remainingTime > 0) {
        if (timerRunning) {
            int minutes = remainingTime / 60;
            int seconds = remainingTime % 60;

            system("cls"); // Clear the console screen

            cout << "Timer: " << minutes << " minutes " << seconds << " seconds" << endl;

            // Sleep for 1 second
            this_thread::sleep_for(chrono::seconds(1));

            remainingTime--;
        }

        if (_kbhit()) {
            userInput = _getch();
            if (userInput == 'p') {
                timerRunning = !timerRunning;
            } else if (userInput == 'q') {
                break;
            } 
        }
    }

    if (remainingTime == 0) {
        cout << "Timer has finished!" << endl;
    } else {
        cout << "Timer stopped." << endl;
    }


//------------------------------------------------------------------
        if (remainingTime!=0)
        {
            cout << "ok :)"<<endl;
        }
       
        cout <<"Do you want one more Pomodoro? Press spase..."<<endl;
        x = _getch();
        if (x==' ') this->startSession();
        else cout << "ok :)"<<endl;
    }
    else if (x=='q')
    {
        cout << "ok :)"<<endl;
    }

}

void Pomodoro::endSession(int x)
{
    this->sessionsCompleted ++;
    this->totalWorkTime += x;
}

void Pomodoro::getStatistics( void )
{
    Statistics_menu(this->sessionsCompleted, this->totalWorkTime);
}

void Pomodoro::Time_settings( Pomodoro& c)
{

    int i;
    char  x=0;
    while (x!='4')
    {
        system("cls"); // Clear the console screen
        Time_settingsmenu(this->WorkDuration, this->BreakDuration);
        x = _getch();
        switch (x)
        {
        case '1':
        cout << "WorkDuration:";
        
        cin >> i;
        if (i<0)
        {
            cout << "Wrong answer! The number mast be biger then 0" << endl;
        }
        else
        {
            this->WorkDuration = i;
            cout << "ok" << endl;
        }
        
        break;
       case '2':
        cout << "BreakDuration:";
        
        cin >> i;
        if (i<0)
        {
            cout << "Wrong answer! The number mast be biger then 0" << endl;
        }
        else
        {
            this->BreakDuration = i;
            cout << "ok" << endl;
        }
        break;
       case '3':
        this->WorkDuration = 1500;
        this->BreakDuration = 300;
        cout << "The settings have reset" << endl;
        break;
       case '4':
       cout << "ok :)" << endl;
        break;
       default:
        cout << "Wrong answer" << endl ;
        break;
       }
    }
    

    
}

//set-add

void Pomodoro::set_WorkDuration(int x)
{
    if (x>0)WorkDuration=x;
}

void Pomodoro::set_BreakDuration(int x)
{
    if (x>0)BreakDuration=x;
}

void Pomodoro::add_sessionsCompleted(void)
{
    sessionsCompleted++;
}

void Pomodoro::add_totalWorkTime(int x)
{
    if (x>0)totalWorkTime += x;
}

//get

int Pomodoro::get_WorkDuration(void)
{
    return WorkDuration;
}

int Pomodoro::get_BreakDuration(void)
{
    return BreakDuration;
}

int Pomodoro::get_sessionsCompleted(void)
{
    return sessionsCompleted;
}

int Pomodoro::get_totalWorkTime(void)
{
    return totalWorkTime;
}



//menus

void basemenu (void)
{
    

    cout << "+----------------+" << endl;
    cout << "|      MENU      |" << endl;
    cout << "+----------------+" << endl;
    cout << "| 1.WorkDuration |" << endl;
    cout << "| 2.BreakDuration|" << endl;
    cout << "| 3.Statistics   |" << endl;
    cout << "| 4.Time settings|" << endl;
    cout << "| 5.Exit         |" << endl;
    cout << "+----------------+" << endl;


}

void Time_settingsmenu ( int WorkDuration, int BreakDuration)
{
    

    cout << "+----------------------------+" << endl;
    cout << "|     Time settings menu     |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "|  WorkDuration:"<<WorkDuration <<"\t  sec|" << endl;
    cout << "|  BreakDuration:"<<BreakDuration<<"\t  sec|"  << endl;
    cout << "|                            |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "| 1.Change WorkDuration time |" << endl;
    cout << "| 2.Change BreakDuration time|" << endl;
    cout << "| 3.restore settings         |" << endl;
    cout << "| 4.back                     |" << endl;
    cout << "+----------------------------+" << endl;


}

void Statistics_menu (int sessionsCompleted,int totalWorkTime)
{
    system("cls"); // Clear the console screen
    cout << "+----------------------------+" << endl;
    cout << "|     Statistics menu        |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "|  sessionsCompleted:"<<sessionsCompleted <<"\t     |" << endl;
    cout << "|  totalWorkTime:"<<totalWorkTime<<"\t  sec|"  << endl;
    cout << "+----------------------------+" << endl;
    cout << "press something to go back...";
    _getch();
}


