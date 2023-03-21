#include "server.h"

#include <iostream>
using namespace std;


Server::Server() 
{
  cout << "Server::Constructor" << endl;
 
  fRefCount = 0;

  a = 10;
  b = 20;
}

Server::~Server()  
{
  cout << "Server::Destructor" << endl;  
}

HRESULT_ __stdcall Server::QueryInterface(const IID_& iid, void** ppv)
{
   cout << "Server::QueryInterface" << endl;

   if (iid==IID_IUnknown_)
   {
     *ppv = (IUnknown_*)(IX*)this;
   }
   else if (iid==IID_IX)
   {
     *ppv = static_cast<IX*>(this);
   }
   else if (iid==IID_IY)
   {
     *ppv = (IY*)this;
   }
   else
   {
     *ppv = NULL;
     return E_NOINTERFACE_;
   }
   this->AddRef();
   return S_OK_;
}

ULONG_ __stdcall Server::AddRef()
{
   cout << "Server::AddRef" << endl;
   fRefCount++;
   cout << "Current references: " << fRefCount << endl;
   return fRefCount;
}


ULONG_ __stdcall Server::Release()
{
   cout << "Server::Relese" << endl;
   fRefCount--;
   cout << "Current references: " << fRefCount << endl;
   if (fRefCount==0)
   {
     cout << "Self-destructing..." << endl;
     delete this;
     cout << "Self-destructing...OK" << endl;
   }
   return fRefCount;
}
	

HRESULT_ __stdcall Server::Fx1() 
{	 	    		
  cout << "Server::Fx1" << endl;
  a = a + 1;
  cout << "a=" << a << endl;
  return S_OK_;
}

HRESULT_ __stdcall Server::Fx2() 
{	 	    		
  cout << "Server::Fx2" << endl;
  a = a + 2;
  cout << "a=" << a << endl;
  return S_OK_;
}

HRESULT_ __stdcall Server::Fy1() 
{	 	    		
  cout << "Server::Fy1" << endl;
  b = b + 1;
  cout << "b=" << b << endl;
  return S_OK_;
}

HRESULT_ __stdcall Server::Fy2()
{	 	    		
  cout << "Server::Fy2" << endl;
  b = b + 2;
  cout << "b=" << b << endl;
  return S_OK_;
}