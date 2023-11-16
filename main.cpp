#include "base.hpp"
//λαγκαρει όταν το βάζω χαρακτήρες







int main (void)
{
char  x;



Pomodoro c1;



while (x!='5')
{
    system("cls"); // Clear the console screen
    basemenu ();
    x = _getch();
    switch (x)
    {
    case '1':
        c1.startSession(c1);
        break;
    case '2':
        c1.startBreak(c1);
        break;
    case '3':
        c1.getStatistics(c1);
        break;    
    case '4':
        c1.Time_settings(c1);
        break;
    case '5':
        cout << "Goodbye :)" ;
        break; 
    default:
        cout << "Wrong answer" << endl ;
        break;
    }
    

}



    return 0;
}

