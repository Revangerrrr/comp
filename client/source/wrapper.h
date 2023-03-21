#ifndef WRAPPER_H_INCLUDED
#define WRAPPER_H_INCLUDED

#include "lib/iserver.h"

class EServer
{
	private:	 
	 const char* msg;
	public:
	 EServer(const char* msg);     
	 const char* GetMessage();	  
};

class CServer
{
	private:
      IX* fIX;
	  IY* fIY;  
	  CServer(const CServer&) {};
	  CServer& operator=(const CServer&) {return *this;};
	public:
	 CServer();
	 ~CServer();
	 HRESULT_ __stdcall Fx1();
	 HRESULT_ __stdcall Fx2();
	 HRESULT_ __stdcall Fy1();
	 HRESULT_ __stdcall Fy2();
};

#endif // WRAPPER_H_INCLUDED