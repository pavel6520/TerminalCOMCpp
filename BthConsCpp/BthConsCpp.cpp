// BthConsCpp.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "GetPortNames.h"
#include "S_WS_Convert.h"
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "russian");
	size_t i = 0;
	GetPortNames::CPortsArray ports;
	GetPortNames::CNamesArray names;
#ifndef NO_CENUMERATESERIAL_USING_SETUPAPI1
	_tprintf(_T("Device Manager (SetupAPI - GUID_DEVINTERFACE_COMPORT) reports\n"));
	if (GetPortNames::UsingSetupAPI1(ports, names))
	{
#ifndef CENUMERATESERIAL_MFC_EXTENSIONS
		for (i = 0; i < ports.size(); i++) {
			std::string str = S_WS_Convert::WideStringToAnsi(names[i]);
			std::cout << "COM" << ports[i] << " " << str << std::endl;
		}
#else
		for (i = 0; i < ports.GetSize(); i++) {
			string str = names[i];
			std::cout << "COM" << ports[i] << " " << str << std::endl;
		}
#endif //#ifndef CENUMERATESERIAL_MFC_EXTENSIONS
	}
	else
		_tprintf(_T("CEnumerateSerial::UsingSetupAPI1 failed, Error:%u\n"), GetLastError());
#endif //#ifndef NO_CENUMERATESERIAL_USING_SETUPAPI1

#ifndef NO_CENUMERATESERIAL_USING_SETUPAPI2
	_tprintf(_T("Device Manager (SetupAPI - Ports Device information set) reports\n"));
	if (GetPortNames::UsingSetupAPI2(ports, names))
	{
#ifndef CENUMERATESERIAL_MFC_EXTENSIONS
		for (i = 0; i < ports.size(); i++) {
			std::string str = S_WS_Convert::WideStringToAnsi(names[i]);
			std::cout << "COM" << ports[i] << " " << str << std::endl;
		}
#else
		for (i = 0; i < ports.GetSize(); i++) {
			string str = names[i];
			std::cout << "COM" << ports[i] << " " << str << std::endl;
		}
#endif //#ifndef CENUMERATESERIAL_MFC_EXTENSIONS
	}
	else
		_tprintf(_T("CEnumerateSerial::UsingSetupAPI2 failed, Error:%u\n"), GetLastError());
#endif //#ifndef NO_CENUMERATESERIAL_USING_SETUPAPI2
	system("pause");
}