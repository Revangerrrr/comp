#ifndef ISERVER_H_INCLUDED
#define ISERVER_H_INCLUDED

using IID_ = int;
using CLSID_ = int;
using HRESULT_ = int;
using ULONG_ = int;


const int IID_IUnknown_ = 0;
const int IID_IX = 1;
const int IID_IY = 2;

const int CLSID_CServer = 1;

const int S_OK_ = 0;
const int E_NOINTERFACE_ = 1;
const int E_NOCOMPONENT_ = 2;

class IUnknown_
{
    public:	
     virtual HRESULT_ __stdcall QueryInterface(const IID_& iid, void** ppv)=0;
	 virtual ULONG_ __stdcall AddRef()=0;
	 virtual ULONG_ __stdcall Release()=0;
}; 

class IX: public IUnknown_
{
	public:
	 virtual HRESULT_ __stdcall Fx1()=0;
	 virtual HRESULT_ __stdcall Fx2()=0;
};

class IY: public IUnknown_
{
	public:
	 virtual HRESULT_ __stdcall Fy1()=0;
	 virtual HRESULT_ __stdcall Fy2()=0;
};




 IUnknown_* __stdcall CreateServer_();

 HRESULT_ __stdcall CreateServer(const CLSID_& clsid, const IID_& iid, void** ppv);


#endif // ISERVER_H_INCLUDED