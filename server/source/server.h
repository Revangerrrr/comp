#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include "iserver.h"

class Server: public Task, public TaskManager, public Task_IncludingTest, public IDispatch
{
	private:
	 int fRefCount;

	public:
	 Server();
	 ~Server();
	 Task_IncludingTest* T_IT;

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
	 virtual HRESULT __stdcall IncludingTest();
	 int test = 1;

	 //IDispatch (Begin)
   	virtual HRESULT __stdcall GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId);
	virtual HRESULT __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pDispParams,VARIANT* pVarResult,
                                    EXCEPINFO* pExcepInfo, UINT* puArgErr);

   	virtual HRESULT __stdcall GetTypeInfoCount(UINT* pctinfo);
	virtual HRESULT __stdcall GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo);
   //IDispatch (End)                           
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