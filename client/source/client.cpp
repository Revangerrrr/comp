#include "lib/iserver.h"
#include <iostream>
using namespace std;

int main() {	    		
	cout << "Client::Main::Start" << endl;			

	/*const char* task1 = ("task1");
	const char* desc1 = ("desc1");
	const char* date1 = ("date1");
	Task* task = NULL;
	HRESULT_ res = CreateServer(CLSID_CServer, IID_Task, (void**)&task);
	
    if (res==S_OK_)
	{
		cout << "Client::Main::Success task: " << endl;			
		task->SetTitle(task1);
		task->SetDiscription(desc1);
		task->SetDueDate(task1);
	}	
	else
    {
	   cout << "Client::Main::Error CServer or Task: " << res << endl;	
	   return 0;		
	}

    cout << "Client::Main::QueryInterface Task->TaskManager" << endl;			
	TaskManager* taskManager = NULL;
    res = task->QueryInterface(IID_TaskManager,(void**)&taskManager);
	cout << "Client::Main::task->Release" << endl;			
	task->Release();
    if (res==S_OK_)
	{
		cout << "Client::Main::Success taskManager: " << endl;			
		taskManager->ShowTasks();
	 	taskManager->AddNewTask();
	 	taskManager->EditTask(task);
	 	taskManager->DeleteTask(task);
	}	
	else
    {
	   cout << "Client::Main::Error taskManager: " << res << endl;			
	}
	
	cout << "Client::Main::taskManager->Release" << endl;			
	taskManager->Release();*/
	
	cout << "Client::Main::GetClassObject Task&IClassFactory_" << endl;


    cout << "Client::Main::Finish" << endl;			

    cout << " " << endl;			
}