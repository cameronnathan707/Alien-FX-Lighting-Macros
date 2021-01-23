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

// SDKSample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <ctime>
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	LFX2INITIALIZE initFunction;
	LFX2RELEASE releaseFunction;
	
	LFX2GETNUMDEVICES getNumDevicesFunction;
	LFX2GETDEVDESC getDeviceDescriptionFunction;
	LFX2GETNUMLIGHTS getNumLightsFunction;
	LFX2GETLIGHTDESC getLightDescriptionFunction;
	LFX2GETLIGHTLOC getLightLocationFunction;

	LFX2SETLIGHTCOL setLightColor;

	LFX2RESET resetFunction;
	LFX2UPDATE updateFunction;
	LFX2LIGHT lightFunction;
	LFX2GETVERSION versionFunction;
	LFX_COLOR lights[] = {{181,7,213,100}, {250,2,2,100}, {2,2,250,100}, {2,250,2,100},{181,7,213,100}, {250,2,2,100}, {2,2,250,100}, {2,250,2,100} ,{181,7,213,100}, {250,2,2,100}, {2,2,250,100}, {2,250,2,100} ,{181,7,213,100}, {250,2,2,100}, {2,2,250,100}, {2,250,2,100} ,{181,7,213,100}, {250,2,2,100}, {2,2,250,100}, {2,250,2,100}  };
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
		resetFunction = (LFX2RESET)GetProcAddress(hLibrary, LFX_DLL_RESET);
		updateFunction = (LFX2UPDATE)GetProcAddress(hLibrary, LFX_DLL_UPDATE);
		lightFunction = (LFX2LIGHT)GetProcAddress(hLibrary, LFX_DLL_LIGHT);
		versionFunction = (LFX2GETVERSION)GetProcAddress(hLibrary, LFX_DLL_GETVERSION);

		LFX_RESULT result = initFunction();
		if (result == LFX_SUCCESS)
		{
			if (versionFunction == NULL)
				std::cout << "SDK version not found ..." << std::endl;
			else
			{
				unsigned int versionSize = 255;
				char* version = new char[versionSize];
				result = versionFunction(version, versionSize);
				std::cout << "SDK version: " << version << std::endl;
				delete[]version;
			}

			unsigned int numDevices = 0;
			result = getNumDevicesFunction(&numDevices);
			std::cout << "Devices: " << numDevices << std::endl;

			for (unsigned int devIndex = 0; devIndex < numDevices; devIndex++)
			{
				unsigned int numLights = 0;
				unsigned char devType = 0;
				unsigned char* devTypePtr = &devType;

				unsigned int descSize = 255;
				char* description = new char[descSize];
				result = getDeviceDescriptionFunction(devIndex, description, descSize, &devType);
				std::cout << "Description: " << description << std::endl;
				delete[]description;

				description = new char[descSize];
				result = getNumLightsFunction(devIndex, &numLights);
				for (unsigned int lightIndex = 0; lightIndex < numLights; lightIndex++)
				{
					result = getLightDescriptionFunction(devIndex, lightIndex, description, descSize);
					if (result != LFX_SUCCESS)
						continue;
					// LFX_POSITION* pos = new LFX_POSITION;
					// LFX_POSITION* pos1 = new LFX_POSITION;

					// LFX_RESULT result = getLightLocationFunction(0, 1, pos);
					// LFX_RESULT result2 = getLightLocationFunction(0, 2, pos1);
					LFX_COLOR col = lights[lightIndex];
					LFX_RESULT result3 = setLightColor(devIndex, lightIndex, &col);
					updateFunction();
					Sleep(100);
					std::cout << "\tLight: " << lightIndex << "\tDescription: " << description << std::endl;
					// printf("Value:  %d\n", *pos );	
					// printf("Value:  %d\n", *pos1 );	
					// delete pos;
				}

				delete[]description;
			}

			Sleep(1000);
			//resetFunction();
			/*
			for (int i = 0; i <= 0; i++)
			{
				int color = ((0xFF - i) << 16) | i;
				lightFunction(LFX_ALL, color | LFX_FULL_BRIGHTNESS);
				updateFunction();
				system("cls");
				std::cout << "Color: " << std::hex << std::setw(6) << std::setfill('0') << color << std::endl;
				Sleep(100);
			}
			*/
			std::cout << "Done.\r\n\r\nPress any key to finish ..." << std::endl;
			//_gettch();
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
