#include "stdafx.h"

int main(void)
{
	Application *myApp = new Application();

	myApp->Init();
	myApp->ChangeScene(new ExamScene());
	myApp->Update();
	return 0;
}
