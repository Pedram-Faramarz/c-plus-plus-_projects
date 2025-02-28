#include <windows.h>
#include <gdiplus.h>
#include <iostream>
#include <string>

#pragma comment (lib, "Gdiplus.lib")

using namespace Gdiplus;
using namespace std;

// Function to get the CLSID for the image encoder (e.g., PNG, JPEG)
int GetEncoderClsid(const WCHAR* format, CLSID* pClsid) {
    UINT num = 0;   // Number of image encoders
    UINT size = 0;  // Size of the image encoder array

    // Get the number of image encoders and the size of the array
    GetImageEncodersSize(&num, &size);
    if (size == 0) return -1;  // Failure

    // Allocate memory for the image encoder array
    ImageCodecInfo* pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
    if (pImageCodecInfo == nullptr) return -1;  // Failure

    // Get the image encoders
    GetImageEncoders(num, size, pImageCodecInfo);

    // Loop through the encoders to find the one for the requested format
    for (UINT j = 0; j < num; ++j) {
        if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0) {
            *pClsid = pImageCodecInfo[j].Clsid;
            free(pImageCodecInfo);
            return j;  // Success
        }
    }

    free(pImageCodecInfo);
    return -1;  // Failure
}

// Initialize GDI+
void InitGDIPlus(ULONG_PTR& gdiplusToken) {
    GdiplusStartupInput gdiPlusStartupInput;
    GdiplusStartup(&gdiplusToken, &gdiPlusStartupInput, nullptr);
}

// Save the bitmap from the clipboard to a file
bool SaveBitmapToFile(const char* fileName) {
    if (OpenClipboard(nullptr)) {
        HANDLE hBitmap = GetClipboardData(CF_BITMAP);  // Get bitmap from clipboard
        if (hBitmap == NULL) {
            cout << "Clipboard does not contain a bitmap." << endl;
            CloseClipboard();
            return false;
        }
        cout << "Bitmap found in clipboard." << endl;

        // Convert HBITMAP to GDI+ Bitmap
        HBITMAP hbm = (HBITMAP)hBitmap;
        Bitmap bitmap(hbm, nullptr);
        CLSID clsidEncoder;

        // Get the CLSID of the PNG encoder
        if (GetEncoderClsid(L"image/png", &clsidEncoder) >= 0) {
            std::wstring wfileName(fileName, fileName + strlen(fileName));

            // Save the bitmap as a PNG file
            if (bitmap.Save(wfileName.c_str(), &clsidEncoder, nullptr) == Ok) {
                CloseClipboard();
                return true;  // Success
            } else {
                cout << "Failed to save the bitmap as a PNG." << endl;
            }
        } else {
            cout << "Failed to get PNG encoder CLSID." << endl;
        }
        CloseClipboard();
    } else {
        cout << "Failed to open clipboard." << endl;
    }
    return false;  // Failure
}

// Simulate a screenshot using the PrintScreen key
void takeScreenshot() {
    keybd_event(VK_SNAPSHOT, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);  // Press PrtScn key
    Sleep(100);  // Allow time for the screenshot to be taken
}

int main() {
    // Initialize GDI+
    ULONG_PTR gdiplusToken;
    InitGDIPlus(gdiplusToken);

    // Take a screenshot and save it to the clipboard
    takeScreenshot();

    // Save the screenshot from the clipboard to a PNG file
    const char* fileName = "screenshot.png";
    if (SaveBitmapToFile(fileName)) {
        cout << "Screenshot saved successfully to " << fileName << endl;
    } else {
        cout << "Failed to save screenshot." << endl;
    }

    // Shutdown GDI+
    GdiplusShutdown(gdiplusToken);

    return 0;
}
