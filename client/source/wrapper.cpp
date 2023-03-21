#include "wrapper.h"

#include <iostream>
using namespace std;


EServer::EServer(const char* msg)
{
	this->msg = msg;	
}

const char* EServer::GetMessage()
{
	return msg;
}



CServer::CServer()
{
	fIX = NULL;
	HRESULT_ res = CreateServer(CLSID_CServer, IID_IX, (void**)&fIX);
    if (res==E_NOCOMPONENT_)
	{
        throw EServer("Error while creating CServer: Unsupported component CServer");	
	}
    else if (res==E_NOINTERFACE_)
	{	
		throw EServer("Error while creating CServer: Unsupported interface IX");	
	}
	else if (res!=S_OK_)
	{
		throw EServer("Error while creating CServer: Unknown error");	
	}
	    
	fIY = NULL;
    res = fIX->QueryInterface(IID_IY,(void**)&fIY);
	//res = fIX->QueryInterface(56342,(void**)&fIY); Simulating unsupported interface
    if (res!=S_OK_)
    {
      fIX->Release();
	  if (res==E_NOINTERFACE_)
	  {	
		throw EServer("Error while creating CServer: Unsupported interface IY");	
	  }
	  else 
	  {
		throw EServer("Error while creating CServer: Unknown error");	
	  }
	}  
}


CServer::~CServer()
{
   fIX->Release();
   fIY->Release();
}


HRESULT_ __stdcall CServer::Fx1()
{
	return fIX->Fx1();
	
}
HRESULT_ __stdcall CServer::Fx2()
{
	return fIX->Fx2();
}
HRESULT_ __stdcall CServer::Fy1()
{
	return fIY->Fy1();
}
HRESULT_ __stdcall CServer::Fy2()
{
	return fIY->Fy2();
}