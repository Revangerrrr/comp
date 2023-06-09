#ifndef ISERVER_H_INCLUDED
#define ISERVER_H_INCLUDED
#include "windows.h"

// Guids
const IID IID_IUnknown1 = {0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
const IID IID_IClassFactory1 = {0x00000001,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
const IID IID_TaskFactory = {0x00000002,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};

const IID IID_Task = {0x00000001,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}};
const IID IID_TaskManager = {0x00000002,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}};
const IID IID_Task_IncludingTest = {0x00000005,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}};

const IID IID_IDispatch1 = {0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};

//{5D3A941C-0D2E-4929-936E-7D8BF1F6D05F}
const CLSID CLSID_Server = {0x5D3A941C,0x0D2E,0x4929,{0x93,0x6E,0x7D,0x8B,0xF1,0xF6,0xD0,0x5F}};
const CLSID CLSID_Server2 = {0x0A878E98,0x7253,0x4916,{0x9B,0x14,0x2E,0x5F,0xBF,0x1C,0xEB,0x83}};

class Task: public IUnknown
{
	public:
	 virtual HRESULT __stdcall SetTitle()=0;
	 virtual HRESULT __stdcall SetDiscription()=0;
	 virtual HRESULT __stdcall SetDueDate()=0;
};

class TaskManager: public IUnknown
{
	public:
	 virtual HRESULT __stdcall ShowTasks()=0;
	 virtual HRESULT __stdcall AddNewTask()=0;
	 virtual HRESULT __stdcall EditTask()=0;
	 virtual HRESULT __stdcall DeleteTask()=0;
};

class Task_IncludingTest: public IUnknown
{
	public:
	 virtual HRESULT __stdcall IncludingTest() = 0;
};

class TaskFactory: public IUnknown
{
    public:	
     virtual HRESULT __stdcall CreateTaskInstance(const IID& iid, void** ppv)=0;	 
};

extern "C" HRESULT __stdcall __declspec(dllexport) DllGetClassObject(const CLSID& clsid, const IID& iid, void** ppv);
#endif // ISERVER_H_INCLUDED