//Lighting_Editor
//This is a code to receive input from autohotkey

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
#define LFX_BLUE {59, 0, 255, 255};
#define LFX_TEAL {0, 255, 212, 255};
#define LFX_RED {255, 0, 0, 255};
#define LFX_LIGHT_GREEN {0, 255, 24, 255};
#define LFX_WHITE {233, 244, 248, 255};

	const string colourSelection = argv[2];
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
		setLightActionColor = (LFX2SETLIGHTACTIONCOLOR)GetProcAddress(hLibrary, LFX_DLL_SETLIGHTACTIONCOLOR);
		setTiming = (LFX2SETTIMING)GetProcAddress(hLibrary, LFX_DLL_SETTIMING);
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
				for (int i = 1; i <= 15; i++)
				{
					if ((i < 5) || (i >= 9 && i < 13) || i == 15)
					{
						setLightColor(0, i, &purple);
						updateFunction();
						Sleep(100);
					}
					else
					{
						setLightColor(0, i, &blue);
						updateFunction();
						Sleep(100);
					}
				}
				break;
			case 2:
				//green teal
				colour = "green/blue";
				for (int i = 1; i <= 15; i++)
				{
					if ((i < 5) || (i >= 9 && i < 13) || i == 15)
					{
						setLightColor(0, i, &light_green);
						updateFunction();
						Sleep(100);
					}
					else
					{
						setLightColor(0, i, &teal);
						updateFunction();
						Sleep(100);
					}
				}
				break;
			case 3:
				//red purple
				colour = "red/purple";

				for (int i = 1; i <= 15; i++)
				{
					if ((i < 5) || (i >= 9 && i < 13) || i == 15)
					{
						setLightColor(0, i, &purple);
						updateFunction();
						Sleep(100);
					}
					else
					{
						setLightColor(0, i, &red);
						updateFunction();
						Sleep(100);
					}
				}
				break;
			case 4:
				//white
				colour = "white";

				for (int i = 1; i <= 15; i++)
				{
					setLightColor(0, i, &white);
					updateFunction();
					Sleep(100);
				}
				break;
			case 5:
				//rainbow wave
				colour = "Teal/blue";
				for (int i = 1; i <= 15; i++)
				{
					if ((i < 5) || (i >= 9 && i < 13) || i == 15)
					{
						setLightColor(0, i, &teal);
						updateFunction();
						Sleep(100);
					}
					else
					{
						setLightColor(0, i, &blue);
						updateFunction();
						Sleep(100);
					}
				}
				break;
			}
			updateFunction();
			ofstream myfile;
			myfile.open("C:/Users/camer/Desktop/test.txt");
			myfile << "Write colour to file: " + colourSelection + "\n" + colour;
			myfile.close();
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