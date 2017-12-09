//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#include "client.h"
#include "base.h"
#include <fstream>
#include <string>

int CreateSettings(char * filename)
{
    std::ofstream ConfigFile;
    ConfigFile.open(filename);
    if (ConfigFile.is_open())
    {
        ConfigFile << "127.0.0.1" << "\n"; //server ip (local host)
        ConfigFile << "4200" << "\n"; // server port (chidraqul6 port)
        ConfigFile << "NULL" << "\n"; //username
        ConfigFile << "placeholder" << "\n"; //placeholder
        printf("[client] sucessfully added default settings.\n");
        ConfigFile.close();
        return 0;
    }
    
    printf("[client] creating settings file failed.\n");
    return -1; //error
}

int LoadSettings(char * filename)
{
    std::ifstream file(filename);
    std::string data;
    
    if (std::getline(file, data))
        printf("[client] server=%s\n", data.c_str());
    else
        return -1;
    if (std::getline(file, data))
        printf("[client] port=%s\n", data.c_str());
    else
        return -1;
    if (std::getline(file, data))
        printf("[client] username=%s\n", data.c_str());
    else
        return -1;
    if (std::getline(file, data))
        printf("[client] placeholder=%s\n", data.c_str());
    else
        return -1;

    return 0;
}

int InitClient()
{
    char aSettingsFile[128] = "config.cfg";
    
    ChillClearScreen();
    printf("[client] Init...\n");
    if (GotoChidraqulFolder())
    {
        printf("[client] error loading chidraqul6 dir\n");
        printf("[client] skipping settings load\n");
    }
    else
    {
        printf("[client] loading settings...\n");
        if (LoadSettings(aSettingsFile))
        {
            printf("[client] could't load settings path '%s'\n", aSettingsFile);
            system("pwd");
            printf("[client] creating new fresh settings...\n");
            CreateSettings(aSettingsFile);
        }
    }

    
    printf("[client] done.\n");
    return 0;
}
