#include "base.hpp"









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

void Time_settingsmenu ( Pomodoro& c)
{
    

    cout << "+----------------------------+" << endl;
    cout << "|     Time settings menu     |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "|  WorkDuration:"<<c.get_WorkDuration() <<"\t  sec|" << endl;
    cout << "|  BreakDuration:"<<c.get_BreakDuration()<<"\t  sec|"  << endl;
    cout << "|                            |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "| 1.Change WorkDuration time |" << endl;
    cout << "| 2.Change BreakDuration time|" << endl;
    cout << "| 3.restore settings         |" << endl;
    cout << "| 4.back                     |" << endl;
    cout << "+----------------------------+" << endl;


}

void Statistics_menu (Pomodoro& c)
{
    system("cls"); // Clear the console screen
    cout << "+----------------------------+" << endl;
    cout << "|     Statistics menu        |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "|  sessionsCompleted:"<<c.get_sessionsCompleted() <<"\t  sec|" << endl;
    cout << "|  totalWorkTime:"<<c.get_totalWorkTime()<<"\t     |"  << endl;
    cout << "+----------------------------+" << endl;
    cout << "press something to go back...";
    _getch();
}

/*void Time_settingsmenu (void)
{
    

    cout << "+----------------------------+" << endl;
    cout << "|     Time settings menu     |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "| 1.current time settings    |" << endl;
    cout << "| 2.Change WorkDuration time |" << endl;
    cout << "| 3.Change BreakDuration time|" << endl;
    cout << "| 4.restore settings         |" << endl;
    cout << "| 5.back                     |" << endl;
    cout << "+----------------------------+" << endl;


}
*/ 
/*void Time_settings(void)
{

int x=0;
while (x!=5)
{
    Time_settingsmenu();
    cin >> x;
    switch (x)
    {
    case 1:
        {
            ifstream inputFile("DATA.txt");


                if (inputFile.is_open()) 
                {

                    string workDuration ,breakDuration , sessionsCompleted ,totalWorkTime ;

                    getline(inputFile, workDuration);
                    getline(inputFile, breakDuration);
                    getline(inputFile, sessionsCompleted);
                    getline(inputFile, totalWorkTime);
                
                    cout << "workDuration is:" << workDuration << " sec" << endl;//Να το κάνω μετατροπή σε λεπτά
                    cout << "breakDuration is:" << breakDuration << " sec" << endl;//Να το κάνω μετατροπή σε λεπτά


                    inputFile.close(); 
                } else 
                {
                    cout << "Unable to find the data file." << endl;
                }

        }
        
        break;
    case 2:
        {
            string workDuration ,breakDuration , sessionsCompleted ,totalWorkTime ;
            fstream file("DATA.txt", ios::in | ios::out);
            if (file.is_open())
            {
                

                getline(file, workDuration);
                getline(file, breakDuration);
                getline(file, sessionsCompleted);
                getline(file, totalWorkTime);

                file.close();
            }
            else 
            {
                cout << "Unable to find the data file." << endl;
            }

            cin >> workDuration;

            ofstream outputFile("DATA.txt", ios::trunc);
            outputFile << workDuration << endl << breakDuration << endl << sessionsCompleted << endl << totalWorkTime;

            outputFile.close();
        }
        break;
    case 3:
        {
            string workDuration ,breakDuration , sessionsCompleted ,totalWorkTime ;
            fstream file("DATA.txt", ios::in | ios::out);
            if (file.is_open())
            {
                

                getline(file, workDuration);
                getline(file, breakDuration);
                getline(file, sessionsCompleted);
                getline(file, totalWorkTime);

                file.close();
            }
            else 
            {
                cout << "Unable to find the data file." << endl;
            }

            cin >> breakDuration;

            ofstream outputFile("DATA.txt", ios::trunc);
            outputFile << workDuration << endl << breakDuration << endl << sessionsCompleted << endl << totalWorkTime;

            outputFile.close();
        }
        break;    
    case 4:
        {
            ofstream outputFile("DATA.txt", ios::trunc);
            
            outputFile  << 1500 << endl << 300 << endl << 0 << endl << 0;

            outputFile.close();
        }
        break;
    case 5:
        cout << "ok"<< endl ;
        break;    
    default:
        cout << "Wrong answer" << endl ;
        break;
    }

}
}



*/
/*void getStatistics(void)
{
    
    ifstream inputFile("DATA.txt");


    if (inputFile.is_open()) {

        string workDuration ,breakDuration , sessionsCompleted ,totalWorkTime ;

        getline(inputFile, workDuration);
        getline(inputFile, breakDuration);
        getline(inputFile, sessionsCompleted);
        getline(inputFile, totalWorkTime);
    
        cout << "sessionsCompleted is:" << sessionsCompleted << endl;
        cout << "totalWorkTime is:" << totalWorkTime << endl;


        inputFile.close(); 
    } else {
        cout << "Unable to find the data file." << endl;
    }




}
*/
