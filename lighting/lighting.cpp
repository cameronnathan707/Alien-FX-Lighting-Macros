//Lighting_Editor
//This is a code to recive input from autohotkey

#include <fstream>
#include <iostream>
#include <string>
#include "C:\Program Files\Alienware\Alienware Command Center\AlienFX SDK\includes\LFX2.h"

#include <ctime>
#include <iomanip>
#include <Windows.h>
#include <tchar.h>

using namespace std;
string colour;

int main(int argc, char *argv[])
{
#define LFX_PURPLE 0x00ff00ff
#define LFX_LIGHT_GREEN 0x004BFF00
#define LFX_WHITE 0x00CAF1FF
#define LFX_ALL_LIGHTBAR 0x07FC0000
#define LFX_ALL_KEYBOARD 0x000001FF

	string colourSelection = argv[2];
	LFX2INITIALIZE initFunction;
	LFX2RELEASE releaseFunction;

	LFX2GETNUMDEVICES getNumDevicesFunction;
	LFX2GETDEVDESC getDeviceDescriptionFunction;
	LFX2GETNUMLIGHTS getNumLightsFunction;
	LFX2GETLIGHTDESC getLightDescriptionFunction;

	LFX2RESET resetFunction;
	LFX2UPDATE updateFunction;
	LFX2LIGHT lightFunction;
	LFX2GETVERSION versionFunction;

	HINSTANCE hLibrary = LoadLibrary(_T(LFX_DLL_NAME));
	if (hLibrary)
	{
		initFunction = (LFX2INITIALIZE)GetProcAddress(hLibrary, LFX_DLL_INITIALIZE);
		releaseFunction = (LFX2RELEASE)GetProcAddress(hLibrary, LFX_DLL_RELEASE);

		getNumDevicesFunction = (LFX2GETNUMDEVICES)GetProcAddress(hLibrary, LFX_DLL_GETNUMDEVICES);
		getDeviceDescriptionFunction = (LFX2GETDEVDESC)GetProcAddress(hLibrary, LFX_DLL_GETDEVDESC);
		getNumLightsFunction = (LFX2GETNUMLIGHTS)GetProcAddress(hLibrary, LFX_DLL_GETNUMLIGHTS);
		getLightDescriptionFunction = (LFX2GETLIGHTDESC)GetProcAddress(hLibrary, LFX_DLL_GETLIGHTDESC);

		resetFunction = (LFX2RESET)GetProcAddress(hLibrary, LFX_DLL_RESET);
		updateFunction = (LFX2UPDATE)GetProcAddress(hLibrary, LFX_DLL_UPDATE);
		lightFunction = (LFX2LIGHT)GetProcAddress(hLibrary, LFX_DLL_LIGHT);
		versionFunction = (LFX2GETVERSION)GetProcAddress(hLibrary, LFX_DLL_GETVERSION);

		LFX_RESULT result = initFunction();
		if (result == LFX_SUCCESS)
		{
			if (versionFunction == NULL)
				std::cout << "SDK version not found ..." << std::endl;

			resetFunction();

			int color = LFX_GREEN;
			lightFunction(LFX_ALL, LFX_OFF | LFX_FULL_BRIGHTNESS);
			updateFunction();
			system("cls");
			std::cout << "Color: " << std::hex << std::setw(6) << std::setfill('0') << color << std::endl;
			Sleep(100);

			std::cout << "Done.\r\n\r\nPress any key to finish ..." << std::endl;
			//_getch();
			switch (stoi(colourSelection))
			{
			case 1:
				//purple blue
				colour = "purple/blue";
					lightFunction(LFX_ALL_KEYBOARD, LFX_PURPLE | LFX_FULL_BRIGHTNESS);
					updateFunction();
					Sleep(100);
							
				
				
				system("cls");
				std::cout << "Color: " << std::hex << std::setw(6) << std::setfill('0') << color << std::endl;
				break;
			case 2:
				//green blue
				colour = "green/blue";
				lightFunction(LFX_ALL, LFX_LIGHT_GREEN | LFX_FULL_BRIGHTNESS);
				updateFunction();
				system("cls");
				std::cout << "Color: " << std::hex << std::setw(6) << std::setfill('0') << color << std::endl;
				break;
			case 3:
				//red purple
				colour = "red/purple";
				lightFunction(LFX_ALL, LFX_PURPLE | LFX_FULL_BRIGHTNESS);
				updateFunction();
				system("cls");
				std::cout << "Color: " << std::hex << std::setw(6) << std::setfill('0') << color << std::endl;
				break;
			case 4:
				//white
				colour = "white";
				lightFunction(LFX_ALL, LFX_WHITE | LFX_FULL_BRIGHTNESS);
				updateFunction();
				system("cls");
				std::cout << "Color: " << std::hex << std::setw(6) << std::setfill('0') << color << std::endl;
				break;
			case 5:
				//rainbow wave
				colour = "rainbow wave";
				lightFunction(LFX_ALL, LFX_PURPLE | LFX_FULL_BRIGHTNESS);
				updateFunction();
				system("cls");
				std::cout << "Color: " << std::hex << std::setw(6) << std::setfill('0') << color << std::endl;
				break;
			}
			ofstream myfile;
			myfile.open("C:/Users/camer/Desktop/test.txt");
			myfile << "Write colour to file: " + colourSelection + "\n" + colour;
			myfile.close();
			cout << colour;

			result = releaseFunction();
		}
		else
		{
			switch (result)
			{
			case LFX_ERROR_NODEVS:
				std::cout << "There is not AlienFX device available." << std::endl;
				break;
			default:
				std::cout << "There was an error initializing the AlienFX device." << std::endl;
				break;
			}
		}
		FreeLibrary(hLibrary);
	}
	else
		std::cout << "Failed to load LightFX.dll." << std::endl;
	return 0;
}
