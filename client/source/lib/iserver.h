#ifndef ISERVER_H_INCLUDED
#define ISERVER_H_INCLUDED

using IID_ = int;
using CLSID_ = int;
using HRESULT_ = int;
using ULONG_ = int;


const int IID_IUnknown_ = 0;
const int IID_Task = 1;
const int IID_TaskManager = 2;

const int CLSID_CServer = 1;
const int CLSID_TaskFactory = 1;

const int S_OK_ = 0;
const int E_NOINTERFACE_ = 1;
const int E_NOCOMPONENT_ = 2;

const int IID_IClassFactory_ = 100;
const int IID_TaskFactory = 101;


class IUnknown_
{
    public:	
     virtual HRESULT_ __stdcall QueryInterface(const IID_& iid, void** ppv)=0;
	 virtual ULONG_ __stdcall AddRef()=0;
	 virtual ULONG_ __stdcall Release()=0;
}; 

class Task: public IUnknown_
{
	public:
	 virtual HRESULT_ __stdcall SetTitle(const char* title)=0;
	 virtual HRESULT_ __stdcall SetDiscription(const char* desc)=0;
	 virtual HRESULT_ __stdcall SetDueDate(const char* date)=0;
};

class TaskManager: public IUnknown_
{
	public:
	 virtual HRESULT_ __stdcall ShowTasks()=0;
	 virtual HRESULT_ __stdcall AddNewTask()=0;
	 virtual HRESULT_ __stdcall EditTask(Task* task)=0;
	 virtual HRESULT_ __stdcall DeleteTask(Task* task)=0;
};

class IClassFactory_: public IUnknown_
{
	public:
	 virtual HRESULT_ __stdcall CreateInstance(const IID_& iid, void** ppv)=0;
};

class TaskFactory: public IUnknown_
{
    public:	
     virtual HRESULT_ __stdcall CreateTaskInstance(const IID_& iid, void** ppv)=0;	 
};



 HRESULT_ __stdcall CreateInstance(const CLSID_& clsid, const IID_& iid, void** ppv);

 HRESULT_ __stdcall GetClassObject(const CLSID_& clsid, const IID_& iid, void** ppv);


#endif // ISERVER_H_INCLUDED