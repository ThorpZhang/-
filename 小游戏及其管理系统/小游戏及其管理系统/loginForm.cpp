#include "loginForm.h"
#include <Windows.h>  
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
using namespace System::Windows::Forms;
using namespace С��Ϸ�������ϵͳ;
//int main(array<System::String^>^ args)
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew loginForm());
}
