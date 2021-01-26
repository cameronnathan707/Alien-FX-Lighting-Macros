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
	#define LFX_PURPLE {255, 0, 255, 255};
	#define LFX_BLUE {59,0,255,255};
	#define LFX_TEAL {0,255,212,255};
	#define LFX_RED {255,0,0,255}
	#define LFX_LIGHT_GREEN {0,255,24,255};
	#define LFX_WHITE {233,244,248,255};

	string colourSelection = argv[2];
	LFX2INITIALIZE initFunction;
	LFX2RELEASE releaseFunction;

	LFX2GETNUMDEVICES getNumDevicesFunction;
	LFX2GETDEVDESC getDeviceDescriptionFunction;
	LFX2GETNUMLIGHTS getNumLightsFunction;
	LFX2GETLIGHTDESC getLightDescriptionFunction;

	LFX2SETLIGHTACTIONCOLOR setLightActionColor;
	LFX2GETLIGHTLOC getLightLocationFunction;
	LFX2SETLIGHTCOL setLightColor;
	LFX2SETTIMING setTiming;
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

		getLightLocationFunction = (LFX2GETLIGHTLOC)GetProcAddress(hLibrary, LFX_DLL_GETLIGHTLOC);
		setLightColor = (LFX2SETLIGHTCOL)GetProcAddress(hLibrary, LFX_DLL_SETLIGHTCOL);
		setLightActionColor =(LFX2SETLIGHTACTIONCOLOR)GetProcAddress(hLibrary,LFX_DLL_SETLIGHTACTIONCOLOR);
		setTiming=(LFX2SETTIMING)GetProcAddress(hLibrary,LFX_DLL_SETTIMING);
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

			LFX_COLOR purple = LFX_PURPLE;
			LFX_COLOR blue = LFX_BLUE;
			LFX_COLOR teal = LFX_TEAL;
			LFX_COLOR red = LFX_RED;
			LFX_COLOR light_green = LFX_LIGHT_GREEN;
			LFX_COLOR white = LFX_WHITE;
			
			switch (stoi(colourSelection))
			{
			case 1:
				//purple blue
				colour = "purple/blue";
				setLightColor(0, 1, &purple);
				Sleep(100);
				updateFunction();
				setLightColor(0, 2, &purple);
				Sleep(100);
				updateFunction();
				setLightColor(0, 3, &purple);
				Sleep(100);
				updateFunction();
				setLightColor(0, 4, &purple);
				Sleep(100);
				updateFunction();
				setLightColor(0, 5, &blue);
				Sleep(100);
				updateFunction();
				setLightColor(0, 6, &blue);
				Sleep(100);
				updateFunction();
				setLightColor(0, 7, &blue);
				Sleep(100);
				updateFunction();
				setLightColor(0, 8, &blue);
				Sleep(100);
				updateFunction();
				setLightColor(0, 9, &purple);
				Sleep(100);
				updateFunction();
				setLightColor(0, 10, &purple);
				Sleep(100);
				updateFunction();
				setLightColor(0, 11, &purple);
				Sleep(100);
				updateFunction();
				setLightColor(0, 12, &purple);
				Sleep(100);
				updateFunction();
				setLightColor(0, 13, &blue);
				Sleep(100);
				updateFunction();
				setLightColor(0, 14, &blue);
				Sleep(100);
				updateFunction();
				
				setLightColor(0, 15,&purple);
				Sleep(100);
				updateFunction();
				

				system("cls");
				std::cout << "Color: " << std::hex << std::setw(6) << std::setfill('0') << color << std::endl;
				break;
			case 2:
				//green teal
				colour = "green/blue";

				setLightColor(0, 1, &light_green);
				updateFunction();
				Sleep(100);
				setLightColor(0, 2, &light_green);
				updateFunction();
				Sleep(100);
				setLightColor(0, 3, &light_green);
				updateFunction();
				Sleep(100);
				setLightColor(0, 4, &light_green);
				updateFunction();
				Sleep(100);
				setLightColor(0, 5, &teal);
				updateFunction();
				Sleep(100);
				setLightColor(0, 6, &teal);
				updateFunction();
				Sleep(100);
				setLightColor(0, 7, &teal);
				updateFunction();
				Sleep(100);
				setLightColor(0, 8, &teal);
				updateFunction();
				Sleep(100);
				setLightColor(0, 9, &light_green);
				updateFunction();
				Sleep(100);
				setLightColor(0, 10, &light_green);
				updateFunction();
				Sleep(100);
				setLightColor(0, 11, &light_green);
				updateFunction();
				Sleep(100);
				setLightColor(0, 12, &light_green);
				updateFunction();
				Sleep(100);
				setLightColor(0, 13, &teal);
				updateFunction();
				Sleep(100);
				setLightColor(0, 14, &teal);	
				updateFunction();
				Sleep(100);	
				setLightColor(0, 15, &light_green);
				updateFunction();
				Sleep(100);
				system("cls");
				std::cout << "Color: " << std::hex << std::setw(6) << std::setfill('0') << color << std::endl;
				break;
			case 3:
				//red purple
				colour = "red/purple";

				setLightColor(0, 1, &purple);
				updateFunction();
				Sleep(100);
				setLightColor(0, 2, &purple);
				updateFunction();
				Sleep(100);
				setLightColor(0, 3, &purple);
				updateFunction();
				Sleep(100);
				setLightColor(0, 4, &purple);
				updateFunction();
				Sleep(100);
				setLightColor(0, 5, &red);
				updateFunction();
				Sleep(100);
				setLightColor(0, 6, &red);
				updateFunction();
				Sleep(100);
				setLightColor(0, 7, &red);
				updateFunction();
				Sleep(100);
				setLightColor(0, 8, &red);
				updateFunction();
				Sleep(100);
				setLightColor(0, 9, &purple);
				updateFunction();
				Sleep(100);
				setLightColor(0, 10, &purple);
				updateFunction();
				Sleep(100);
				setLightColor(0, 11, &purple);
				updateFunction();
				Sleep(100);
				setLightColor(0, 12, &purple);
				updateFunction();
				Sleep(100);
				setLightColor(0, 13, &red);
				updateFunction();
				Sleep(100);
				setLightColor(0, 14, &red);	
				updateFunction();
				Sleep(100);	
				setLightColor(0, 15, &purple);
				updateFunction();
				Sleep(100);
				system("cls");
				std::cout << "Color: " << std::hex << std::setw(6) << std::setfill('0') << color << std::endl;
				break;
			case 4:
				//white
				colour = "white";
				
				setLightColor(0, 1, &white);
				updateFunction();
				Sleep(100);
				setLightColor(0, 2, &white);
				updateFunction();
				Sleep(100);
				setLightColor(0, 3, &white);
				updateFunction();
				Sleep(100);
				setLightColor(0, 4, &white);
				updateFunction();
				Sleep(100);
				setLightColor(0, 5, &white);
				updateFunction();
				Sleep(100);
				setLightColor(0, 6, &white);
				updateFunction();
				Sleep(100);
				setLightColor(0, 7, &white);
				updateFunction();
				Sleep(100);
				setLightColor(0, 8, &white);
				updateFunction();
				Sleep(100);
				setLightColor(0, 9, &white);
				updateFunction();
				Sleep(100);
				setLightColor(0, 10, &white);
				updateFunction();
				Sleep(100);
				setLightColor(0, 11, &white);
				updateFunction();
				Sleep(100);
				setLightColor(0, 12, &white);
				updateFunction();
				Sleep(100);
				setLightColor(0, 13, &white);
				updateFunction();
				Sleep(100);
				setLightColor(0, 14, &white);	
				updateFunction();
				Sleep(100);	
				setLightColor(0, 15, &white);	
				updateFunction();
				Sleep(100);			
				updateFunction();
				system("cls");
				std::cout << "Color: " << std::hex << std::setw(6) << std::setfill('0') << color << std::endl;
				break;
			case 5:
				//rainbow wave
				colour = "rainbow wave";
				setLightColor(0, 1, &red);
				updateFunction();
				Sleep(100);
				setLightColor(0, 2, &light_green);
				updateFunction();
				Sleep(100);
				setLightColor(0, 3, &blue);
				updateFunction();
				Sleep(100);
				setLightColor(0, 4, &purple);
				updateFunction();
				Sleep(100);
				setLightColor(0, 5, &purple);
				updateFunction();
				Sleep(100);
				setLightColor(0, 6, &blue);
				updateFunction();
				Sleep(100);
				setLightColor(0, 7, &light_green);
				updateFunction();
				Sleep(100);
				setLightColor(0, 8, &red);
				updateFunction();
				Sleep(100);
				setLightColor(0, 9, &light_green);
				updateFunction();
				Sleep(100);
				setLightColor(0, 10, &blue);
				updateFunction();
				Sleep(100);
				setLightColor(0, 11, &purple);
				updateFunction();
				Sleep(100);
				setLightColor(0, 12, &red);
				updateFunction();
				Sleep(100);
				setLightColor(0, 13, &light_green);
				updateFunction();
				Sleep(100);
				setLightColor(0, 14, &blue);		
				updateFunction();
				Sleep(100);
				setLightColor(0, 15, &purple);	
				Sleep(100);
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
