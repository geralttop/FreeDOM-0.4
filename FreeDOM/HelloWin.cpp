#include "HelloWin.h"
#include <string>
//using namespace std;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array <String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	FreeDOM::HelloWin form;
	Application::Run(% form);
}