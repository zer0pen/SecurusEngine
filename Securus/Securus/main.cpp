#include "Application.h"
int main(void)
{
	Application *myApp = new Application();

	myApp->Init();
	myApp->Update();
	return 0;
}