#include "loginForm.h"
#include <Windows.h>  
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
using namespace System::Windows::Forms;
using namespace 小游戏及其管理系统;
//int main(array<System::String^>^ args)
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew loginForm());
}
