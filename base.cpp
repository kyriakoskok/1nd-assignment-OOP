#include "base.hpp"

// κατασκευαστές
Pomodoro::Pomodoro(std::string name):name(name),WorkDuration(1500),BreakDuration(300),sessionsCompleted(0),totalWorkTime(0)//για την δημιουργία νέου χρήστη
    {
        ofstream file;
        file.open("DATA.txt",ios::app);//άνοιγμα file
        file <<endl << name << endl;//εισαγωγή ονόματος
        file << WorkDuration << " " << BreakDuration << " " << sessionsCompleted << " " << totalWorkTime<< "                    ";//εισαγωγή informasion (αφήνω το καινό στο τέλος διότι αν χρειαστει να επεξεργαστεί τα δεδομένα ο χρήστεις να μήν γράψει πάνω στα επόμενα άν είναι μεγαλύτερα από την αρχική κατάσταση)
        file.flush();
        file.close();
    };

Pomodoro::Pomodoro(int x)//για το άνοιγμα κάποιου ήδη υπάρχον χρήστη
{
    ifstream file("DATA.txt");

    std::string name ;
    int WorkDuration ;
    int BreakDuration ;
    int sessionsCompleted ;
    int totalWorkTime ;

    for(int i=1;i<=x;i++)//αναζήτηση του χρήστη
    {
        file >> name;
        file >> WorkDuration;
        file >> BreakDuration;
        file >> sessionsCompleted;
        file >> totalWorkTime;
    }
    //μεταφορά informasion στην κλάση
    this->name=name;
    this->WorkDuration=WorkDuration;
    this->BreakDuration=BreakDuration;
    this->sessionsCompleted=sessionsCompleted;
    this->totalWorkTime=totalWorkTime;
    file.close();
}

//functions
void Pomodoro::startSession(void)
{
    char x = '0';
    while ((x!= ' ')&&( x != 'q'))
    {
        cout << "press space to start the pomodoro or press q to exit" << endl;
        x = _getch(); 
    }
    if (x==' ')
    {
//------------------------------------------------------- μετριτής χρόνου με λειτουργία stop και exit        
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

        if (_kbhit()) {//αν πατηθει κάποιο κουμπί 
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
        if (remainingTime==0)//αποθήκευση στατηστικών
        {
            add_sessionsCompleted();
            add_totalWorkTime(get_WorkDuration());
        }
        else
        {
            cout <<"ok :)"<< endl;
            add_totalWorkTime(get_WorkDuration()-remainingTime);
        }
        
        cout <<"Do you want a break? Press space..."<<endl;
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
        cout << "press space to start the break time or press q to exit" << endl;
        x = _getch();
    }
    if (x==' ')
    {
//-------------------------------------------------------        μετριτής χρόνου με λειτουργία stop και exit
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
       
        cout <<"Do you want one more Pomodoro? Press space..."<<endl;
        x = _getch();
        if (x==' ') this->startSession();
        else cout << "ok :)"<<endl;
    }
    else if (x=='q')
    {
        cout << "ok :)"<<endl;
    }
}

void Pomodoro::endSession(int x)//αποθήκευση στατηστικών
{
    this->sessionsCompleted ++;
    this->totalWorkTime += x;
}

void Pomodoro::getStatistics( void )//εξαγωγή informasion
{
    Statistics_menu(this->sessionsCompleted, this->totalWorkTime, this->name);
}

void Pomodoro::Time_settings( void)//ρυθμίσεις χρόνου
{
    int i;
    char  x=0;
    while (x!='4')
    {
        system("cls"); // Clear the console screen
        Time_settingsmenu(this->WorkDuration, this->BreakDuration);
        x = _getch();
        switch (x)//ανακατεύθινση ανάλογα με την επιλογή του χρήστη
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
            this->set_WorkDuration(i);
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
            this->set_BreakDuration(i);
            cout << "ok" << endl;
        }
        break;
       case '3'://επαναφορά ρυθμίσεων
        this->set_WorkDuration(1500);
        this->set_BreakDuration(300);
        cout << "The settings have reset" << endl;
        break;
       case '4':
       cout << "ok :)" << endl;
        break;
       default:
        cout << "Wrong answer" << endl ;
        break;
       }
    };
}

//set-add
void Pomodoro::set_name (std::string name)
{
    if (name.length()>0&&name.length()<20)
    this->name=name;
    else if (name.length()>20)
    cout<<"The name must be less than 20 characters" <<endl;
}

void Pomodoro::set_WorkDuration(int x)
{
    if (x>0)
    {
        WorkDuration=x;
        if(name!="Guest")
        set_information_on_file( name, WorkDuration, BreakDuration, sessionsCompleted, totalWorkTime);
    }
}

void Pomodoro::set_BreakDuration(int x)
{
    if (x>0)
    {
        BreakDuration=x;
        if(name!="Guest")
        set_information_on_file( name, WorkDuration, BreakDuration, sessionsCompleted, totalWorkTime);
    }
}

void Pomodoro::add_sessionsCompleted(void)
{
    sessionsCompleted++;
    if(name!="Guest")
    set_information_on_file( name, WorkDuration, BreakDuration, sessionsCompleted, totalWorkTime);
}

void Pomodoro::add_totalWorkTime(int x)
{
    if (x>0)
    {
        totalWorkTime += x;
        if(name!="Guest")
        set_information_on_file( name, WorkDuration, BreakDuration, sessionsCompleted, totalWorkTime);
    }
}

//get
std::string Pomodoro::get_name (void)
{
    return name;
}

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
void users_menu (queue<std::string> names)
{
    int j=3;
    //int i=name.length();
    cout << "+-------------------------------+" << endl;
    cout << "|        Users menu             |" << endl;
    cout << "+-------------------------------+" << endl;
    cout << "| 1.Guest                       |" << endl;
    cout << "| 2.New User                    |" << endl;
    while(!names.empty())//εμφάνηση ονομάτων από την ουρά του αρχείου 
    {
    cout << "| " << j << "." << names.front() << endl;
    names.pop();
    j++;
    }
    cout << "| q.exit                        |" << endl;
    cout << "+-------------------------------+" << endl;
}

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

void users_basemenu (void)
{
    cout << "+----------------+" << endl;
    cout << "|      MENU      |" << endl;
    cout << "+----------------+" << endl;
    cout << "| 1.WorkDuration |" << endl;
    cout << "| 2.BreakDuration|" << endl;
    cout << "| 3.Statistics   |" << endl;
    cout << "| 4.Time settings|" << endl;
    cout << "| 5.Exit         |" << endl;
    cout << "| 6.Delete user  |" << endl;
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

void Statistics_menu (int sessionsCompleted,int totalWorkTime,std::string name)
{
    int i=name.length();

    system("cls"); // Clear the console screen
    cout << "+-------------------------------+" << endl;
    cout << "|     Statistics menu\t\t|" << endl;
    cout << "+-------------------------------+" << endl;
    cout << "|  user:"<<name;
    if(i<8){cout<<"\t\t\t|"<< endl;}//ρυθμίζει τα tabs ανάλογα με το μέγεθος του ονόματος 
    else if(i<16){cout<<"\t\t|"<< endl;}
    else if(i<20){cout<<"\t|"<< endl;}
    else {cout<<endl;}
    cout << "|  sessionsCompleted:"<<sessionsCompleted <<"\t\t|" << endl;
    cout << "|  totalWorkTime:"<<totalWorkTime<<"\t    sec\t|"  << endl;
    cout << "+-------------------------------+" << endl;
    cout << "press something to go back...";
    _getch();
}

//Επιλογές 
void users_menu_choices(void)//ανακατεύθνση του προγράματος ανάλογα με την επιλογή του χρήστη
{
    std::string  x;
    int X;
    queue<std::string> names ;
    while (x!="q"&&x!="Q")
    {
        system("cls"); // Clear the console screen
        names= get_names();
        users_menu(names);
        cin >> x;

        try 
        {
            X=std::stoi(x);
        }
        catch (const std::invalid_argument& a)
        {
            X=0;//Λαθος απάντηση.
        }
        catch (const std::out_of_range& a)
        {
            X=0;//Πολύ μεγάλος αριθμός.
        }
        if(X==1)
        {
            Pomodoro c;
            Guest_basemenu_choices(c); 
        }
        else if(X==2)
        {
            std::string name;
            name =get_name();
            Pomodoro c(name);
            basemenu_choices(c);
        }
        else if((X>2)&&(X<=check_number_of_users()+2))
        {
            Pomodoro c(X-2); 
            basemenu_choices(c);
        }
        else if (x!="q"&&x!="Q")
        {
            cout << "Wrong answer" << endl ;
        }
    }
}

void basemenu_choices(Pomodoro& c)//ανακατεύθνση του προγράματος ανάλογα με την επιλογή του χρήστη
{
    char  x;
    while (x!='5'&&x!='6')
    {
        system("cls"); // Clear the console screen
        
        users_basemenu ();
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
            c.Time_settings();
            break;
        case '5':
            cout << "Goodbye :)" ;
            break; 
        case '6':
            delete_user(c.get_name());
            break;
        default:
            cout << "Wrong answer" << endl ;
            break;
        }
    }
}

void Guest_basemenu_choices(Pomodoro& c)//ανακατεύθνση του προγράματος ανάλογα με την επιλογή του χρήστη
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
            c.Time_settings();
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

//string names
std::string get_name(void)//εισαγωγή ονόματος με έλεγχο μήκους και ταύτησης 
{
    std::string name;

    while (true)
    {
        cout << "Name:";
        cin >> name;
        if(name.size()>20){cout << "The name must be a maximum of 20 characters" << endl;}
        else if(check_name(name)==true){cout << "This name already exists" << endl;}
        else break;
    }
    
    return name;
}

bool check_name(std::string name)//έλενχος ταύτησης ονόματος
{
    queue<std::string> names;
    names = get_names();
    while(!names.empty())
    {
        if (name==names.front())return true;
        names.pop();
    }
    return false;
}

int check_number_of_users(void)//έλενχος αριθμού χριστών
{
   queue<std::string> names; 
   names = get_names();
   return names.size();
}

//files
queue<std::string> get_names(void)//εισαγωγή των ονομάτων από το αρχείο σε μία ουρά
{
    queue<std::string> names;
    ifstream file("DATA.txt");
    if(!file)
    {
        return names;
    }

    std::string name;

    while (getline(file,name))
    {
        
        if(name.empty()||name=="/n")getline(file,name);
        names.push(name);
        getline(file,name);
    }
    file.close();
    return names;
}

void set_information_on_file(std::string name,int WorkDuration,int BreakDuration,int sessionsCompleted, int totalWorkTime)//προσθήκη χρήστη στο αρχείο
{
    fstream file("DATA.txt",std::ios::in | std::ios::out);
    std::string str;
    getline(file,str);
    while (str!=name)
    {
        getline(file,str);
    }
    file << WorkDuration << " " << BreakDuration << " " << sessionsCompleted << " " << totalWorkTime << "                         ";
    file.close();
}

void delete_user(std::string name)
{
    ifstream file("DATA.txt");
    queue<std::string> names;
    queue<std::string> info;

    std::string str;
    int i;
    while(getline(file,str))
    {
        if (!str.empty())
        {names.push(str);
        getline(file,str);
        info.push(str);}
    }
    file.close();
    ofstream file2("DATA.txt",ios::trunc|ios::out);

    while (!names.empty())
    {
        if(names.front()!=name)
        {
            file2 <<endl << names.front() << endl << info.front();
        }
        names.pop();
        info.pop();
    }
    file2.close();
}
