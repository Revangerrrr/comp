#include "lib/iserver.h"
#include <iostream>
#include <objbase.h>
using namespace std;

int main() {	    		
	cout << "Client::Main::Start" << endl;			

	CoInitialize(NULL);

	IClassFactory* pCF = NULL;
	HRESULT resFactory = CoGetClassObject(CLSID_Server, CLSCTX_INPROC_SERVER, NULL, IID_IClassFactory1, (void**)&pCF);

	if (!(SUCCEEDED(resFactory)))
      {
        throw "No factoty";
      }
    
	Task* task = NULL;
	HRESULT resInstance = pCF->CreateInstance(NULL, IID_Task ,(void**)&task);

	if (!SUCCEEDED(resInstance))
    {
        throw "No instance";
    }

	TaskManager* taskmanager = NULL;
	HRESULT resQuery = task->QueryInterface(IID_TaskManager ,(void**)&taskmanager);

	if (!SUCCEEDED(resQuery))
    {
        throw "No QueryUnterface";
    }

	pCF->Release();

	task->SetTitle();
	task->SetDiscription();
	task->SetDueDate();

	taskmanager->ShowTasks();
	taskmanager->AddNewTask();
	taskmanager->EditTask();
	taskmanager->DeleteTask();

}