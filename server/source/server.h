#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include "iserver.h"

class Server: public Task, public TaskManager 
{
	private:
	 int fRefCount;

	public:
	 Server();
	 ~Server();

	 virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
	 virtual ULONG __stdcall AddRef();
	 virtual ULONG __stdcall Release();

	 virtual HRESULT __stdcall SetTitle();
	 virtual HRESULT __stdcall SetDiscription();
	 virtual HRESULT __stdcall SetDueDate();

	 virtual HRESULT __stdcall ShowTasks();
	 virtual HRESULT __stdcall AddNewTask();
	 virtual HRESULT __stdcall EditTask();
	 virtual HRESULT __stdcall DeleteTask();
};

class ServerFactory: public IClassFactory, public TaskFactory
{
	private:
	 int fRefCount;
	 
	public:
	 ServerFactory();
	 ~ServerFactory();

	 virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
	 virtual ULONG __stdcall AddRef();
	 virtual ULONG __stdcall Release();

	 virtual HRESULT __stdcall CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv);
	 virtual HRESULT __stdcall CreateTaskInstance(const IID& iid, void** ppv);

	 virtual HRESULT __stdcall LockServer(BOOL bLock);
};

#endif // SERVER_H_INCLUDED