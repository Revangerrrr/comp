#include "server.h"

#include <iostream>
using namespace std;


HRESULT_ __stdcall CreateInstance(const CLSID_& clsid, const IID_& iid, void** ppv)
{
    cout << "Function::CreateServer" << endl;
    IClassFactory_ *icf = NULL;
    HRESULT_ res = GetClassObject(clsid, IID_IClassFactory_, (void**) icf);

    if (res != S_OK_)
    {
      return res;
    }

    IUnknown_ *s = NULL;

    if (iid == IID_Task) 
    {
      res = icf -> CreateInstance(iid, (void**) &s);
      *ppv = (IUnknown_*)(Task*) s;
    }  
    else if (iid == IID_TaskManager)
    {
      res = icf -> CreateInstance(iid, (void**) &s);
      *ppv = (IUnknown_*)(TaskManager*) s;
      
    }
    
    if (res != S_OK_)
    {
      ppv = NULL;
    }
    
    return res;
}


HRESULT_ __stdcall GetClassObject(const CLSID_& clsid, const IID_& iid, void** ppv)
{
  cout << "Function::GetClassObject" << endl;
  IUnknown_* s = NULL;
  if (clsid==CLSID_TaskFactory) 
  {
    s = (IUnknown_*)(IClassFactory_*) new ServerFactory();
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