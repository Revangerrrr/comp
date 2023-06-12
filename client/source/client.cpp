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
    
	cout << "---------11-----" << endl;

	Task* task = NULL;
	HRESULT resInstance = pCF->CreateInstance(NULL, IID_Task ,(void**)&task);

	if (!SUCCEEDED(resInstance))
    {
        throw "No instance";
    }

	cout << "---------111-----" << endl;
	TaskManager* taskmanager = NULL;
	HRESULT resQuery = task->QueryInterface(IID_TaskManager ,(void**)&taskmanager);

	if (!SUCCEEDED(resQuery))
    {
        throw "No QueryUnterface";
    }

	Task_IncludingTest* T_IT = NULL;
	HRESULT resQuery2 = task->QueryInterface(IID_Task_IncludingTest ,(void**)&T_IT);

	if (!SUCCEEDED(resQuery2))
    {
        throw "No QueryUnterface";
    }

	pCF->Release();
	cout << "---------2-----" << endl;
	T_IT->IncludingTest();
	T_IT->Release();
	cout << "---------2-----" << endl;
	task->SetTitle();
	task->SetDiscription();
	task->SetDueDate();
	task->Release();

	taskmanager->ShowTasks();
	taskmanager->AddNewTask();
	taskmanager->EditTask();
	taskmanager->DeleteTask();
	taskmanager->Release();
	

}