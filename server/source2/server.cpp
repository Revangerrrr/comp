#include "server.h"
#include <iostream>
using namespace std;


Server2::Server2() 
{
    cout << "Server2::Constructor" << endl;
    fRefCount = 0;

    CoInitialize(NULL);

    IClassFactory* pCF = NULL;
    HRESULT resFactory = CoGetClassObject(CLSID_Server2, CLSCTX_INPROC_SERVER, NULL, IID_IClassFactory1, (void**)&pCF);

	if (!(SUCCEEDED(resFactory)))
    {
        throw "No factoty";
    }
    

}

Server2::~Server2()  
{
    cout << "Server2::Destructor" << endl;  
}

HRESULT __stdcall Server2::QueryInterface(const IID& iid, void** ppv)
{
   cout << "Server2::QueryInterface" << endl;

   if (iid==IID_IUnknown1)
   {
     *ppv = (IUnknown*)(IClassFactory*)this; 
   } 
   else if (iid==IID_Task_IncludingTest)
   {
     *ppv = static_cast<Task_IncludingTest*>(this);    
   } 
   else
   {
     *ppv = NULL;
     return E_NOINTERFACE;
   }
   cout << "--------------" << endl;
   this->AddRef();
   return S_OK;
}

ULONG __stdcall Server2::AddRef()
{
   cout << "Server2::AddRef" << endl;
   fRefCount++;
   cout << "Current references: " << fRefCount << endl;
   return fRefCount;
}


ULONG __stdcall Server2::Release()
{
   cout << "Server2::Release" << endl;
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

HRESULT __stdcall Server2::IncludingTest() 
{	 	    		
  cout << "Server2::IncludingTest()" << endl;
  return S_OK;
}

Server2Factory::Server2Factory()
{
  cout << "Server2Factory::Constructor" << endl;
  fRefCount = 0;
}

Server2Factory::~Server2Factory()  
{
  cout << "Server2Factory::Destructor" << endl;  
}

HRESULT __stdcall Server2Factory::QueryInterface(const IID& iid, void** ppv)
{
   cout << "Server2Factory::QueryInterface" << endl;

   if (iid==IID_IUnknown1)
   {
     *ppv = (IUnknown*)(IClassFactory*)this; 
   }
   else if (iid==IID_IClassFactory1)
   {
     *ppv = static_cast<IClassFactory*>(this);    
   }  
   else if (iid==IID_Task_IncludingTest_Factory)
   {
     *ppv = static_cast<Task_IncludingTest_Factory*>(this);    
   } 
   else
   {
     *ppv = NULL;
     return E_NOINTERFACE;
   }
   cout << "--------------" << endl;
   this->AddRef();
   return S_OK;
}

ULONG __stdcall Server2Factory::AddRef()
{
   fRefCount++;
   return fRefCount;
}


ULONG __stdcall Server2Factory::Release()
{
   cout << "Server2Factory::Release" << endl;
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

HRESULT __stdcall Server2Factory::CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv)
{	 	    	
  if (pUnknownOuter!=NULL)
  {
    return E_NOTIMPL;
  };	
  cout << "Server2Factory::CreateInstance" << endl;
  Server2* s = new Server2(); 
  HRESULT res =  s->QueryInterface(iid,ppv);  
  return res;  
}

HRESULT __stdcall Server2Factory::LockServer(BOOL bLock)
{
  return S_OK;
}