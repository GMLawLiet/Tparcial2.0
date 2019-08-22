#include "MyForm.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

void main(cli::array<String^>^ arg) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Application::Run(gcnew TParcial20::MyForm);
	
}