#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include "iserver.h"

class Server: public Task, public TaskManager 
{
	private:
	 int fRefCount;

	 int a;
	 int b;
	public:
	 Server();
	 ~Server();

	 virtual HRESULT_ __stdcall QueryInterface(const IID_& iid, void** ppv);
	 virtual ULONG_ __stdcall AddRef();
	 virtual ULONG_ __stdcall Release();

	 virtual HRESULT_ __stdcall SetTitle(const char* title);
	 virtual HRESULT_ __stdcall SetDiscription(const char* desc);
	 virtual HRESULT_ __stdcall SetDueDate(const char* date);

	 virtual HRESULT_ __stdcall ShowTasks();
	 virtual HRESULT_ __stdcall AddNewTask();
	 virtual HRESULT_ __stdcall EditTask(Task* task);
	 virtual HRESULT_ __stdcall DeleteTask(Task* task);
};

#endif // SERVER_H_INCLUDED