#include "files.hpp"

queue<std::string> get_names(void)
{
    queue<std::string> names;
    ifstream file("DATA.txt");
    if(!file)
    {
        return names;
    }

    std::string name;
    while (!file.eof())
    {
        getline(file,name);
        names.push(name);
        getline(file,name);
    }
    file.close();
    return names;
}