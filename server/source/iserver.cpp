#include "server.h"

#include <iostream>
using namespace std;


HRESULT_ __stdcall CreateServer(const CLSID_& clsid, const IID_& iid, void** ppv)
{
  cout << "Function::CreateServer" << endl;
  IUnknown_* s = NULL;
  if (clsid==CLSID_CServer) 
  {
    s = (IUnknown_*)(IX*)new Server();
  }  
  else
  {
     *ppv = NULL;
     return E_NOCOMPONENT_;  
  }  
  
  s->AddRef();
  HRESULT_ res =  s->QueryInterface(iid,ppv);
  s->Release();  
  return res;
}