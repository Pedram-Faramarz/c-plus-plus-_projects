#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

void logClipboard(const char* fileName){
    if(OpenClipboard(nullptr)){
        HANDLE hData = GetClipboardData(CF_TEXT);
        if(hData != nullptr){
            char* pszText = static_cast<char*>(GlobalLock(hData));
            if(pszText !=nullptr){
                std::ofstream logFile;
                logFile.open(fileName, std::ios::app);
                logFile << "[CLIPBOARD]: "<< pszText << "\n";
                logFile.close();
                GlobalUnlock(hData);
            }
        }
        CloseClipboard();
    }
}

int main(){
    const char* clipboardFile = "New.txt";
    static DWORD lastClipBoardCheck = 0;

    while(true){
        Sleep(10);
        if(GetTickCount() - lastClipBoardCheck > 5000){
            logClipboard(clipboardFile);
            lastClipBoardCheck = GetTickCount();
        }
    }
    return 0;
}