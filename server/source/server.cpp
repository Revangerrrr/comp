#include "server.h"

#include <iostream>
using namespace std;


ServerFactory::ServerFactory()
{
  cout << "ServerFactory::Constructor" << endl;
  fRefCount = 0;
}

ServerFactory::~ServerFactory()  
{
  cout << "ServerFactory::Destructor" << endl;  
}

HRESULT __stdcall ServerFactory::QueryInterface(const IID& iid, void** ppv)
{
   cout << "ServerFactory::QueryInterface" << endl;

   if (iid==IID_IUnknown1)
   {
     *ppv = (IUnknown*)(IClassFactory*)this; 
   }
   else if (iid==IID_IClassFactory1)
   {
     *ppv = static_cast<IClassFactory*>(this);    
   }  
   else if (iid==IID_TaskFactory)
   {
     *ppv = static_cast<TaskFactory*>(this);    
   } 
   else
   {
     *ppv = NULL;
     return E_NOINTERFACE;
   }
   this->AddRef();
   return S_OK;
}

ULONG __stdcall ServerFactory::AddRef()
{
   cout << "ServerFactory::AddRef" << endl;
   fRefCount++;
   cout << "Current references: " << fRefCount << endl;
   return fRefCount;
}


ULONG __stdcall ServerFactory::Release()
{
   cout << "ServerFactory::Relese" << endl;
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
	

HRESULT __stdcall ServerFactory::CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv)
{	 	    		
  cout << "ServerFactory::CreateInstance" << endl;
  Server* s = new Server(); 
  s->AddRef();
  HRESULT res =  s->QueryInterface(iid,ppv);
  s->Release();  
  return res;  
}

HRESULT __stdcall ServerFactory::CreateTaskInstance(const IID& iid, void** ppv)
{	 	    		
  cout << "ServerFactory::CreateTaskInstance" << endl;
  Server* s = new Server(); 
  s->AddRef();
  HRESULT res =  s->QueryInterface(iid,ppv);
  s->Release();  
  return res;  
}


//*********************************************************************************


Server::Server() 
{
  cout << "Server::Constructor" << endl;
  fRefCount = 0;
}

Server::~Server()  
{
  cout << "Server::Destructor" << endl;  
}

HRESULT __stdcall Server::QueryInterface(const IID& iid, void** ppv)
{
   cout << "Server::QueryInterface" << endl;

   if (iid==IID_IUnknown1)
   {
     *ppv = (IUnknown*)(Task*)this;
   }
   else if (iid==IID_Task)
   {
     *ppv = static_cast<Task*>(this);
   }
   else if (iid==IID_TaskManager)
   {
     *ppv = static_cast<TaskManager*>(this);
   }
   else
   {
     *ppv = NULL;
     return E_NOINTERFACE;
   }
   this->AddRef();
   return S_OK;
}

ULONG __stdcall Server::AddRef()
{
   cout << "Server::AddRef" << endl;
   fRefCount++;
   cout << "Current references: " << fRefCount << endl;
   return fRefCount;
}


ULONG __stdcall Server::Release()
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
	

HRESULT __stdcall Server::SetTitle() 
{	 	    		
  cout << "Server::SetTitle" << endl;
  return S_OK;
}

HRESULT __stdcall Server::SetDiscription() 
{	 	    		
  cout << "Server::SetDiscription" << endl;
  return S_OK;
}

HRESULT __stdcall Server::SetDueDate()
{	 	    		
  cout << "Server::SetDueDate" << endl;
  return S_OK;
}

HRESULT __stdcall Server::ShowTasks()
{	 	    		
  cout << "Server::ShowTasks" << endl;
  return S_OK;
}

HRESULT __stdcall Server::AddNewTask()
{	 	    		
  cout << "Server::AddNewTask" << endl;
  return S_OK;
}

HRESULT __stdcall Server::EditTask()
{	 	    		
  cout << "Server::EditTask" << endl;
  return S_OK;
}

HRESULT __stdcall Server::DeleteTask()
{	 	    		
  cout << "Server::DeleteTask" << endl;
  return S_OK;
}

HRESULT __stdcall ServerFactory::LockServer(BOOL bLock)
{
  return S_OK;
}