#include "HelloWin.h"
#include <string>
#include "Lib1.h"
//using namespace std;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	FreeDOM::HelloWin form;
	Application::Run(% form);
}