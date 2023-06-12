#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include "iserver.h"

class Server2: public Task_IncludingTest
{
	private:
	 int fRefCount;

	public:
	 Server2();
	 ~Server2();

	 virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
	 virtual ULONG __stdcall AddRef();
	 virtual ULONG __stdcall Release();

	 virtual HRESULT __stdcall IncludingTest();                        
};

class Server2Factory: public IClassFactory, public Task_IncludingTest_Factory
{
	private:
	 int fRefCount;
	 
	public:
	 Server2Factory();
	 ~Server2Factory();

	 virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
	 virtual ULONG __stdcall AddRef();
	 virtual ULONG __stdcall Release();

	 virtual HRESULT __stdcall CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv);

	 virtual HRESULT __stdcall LockServer(BOOL bLock);
};

#endif // SERVER_H_INCLUDED