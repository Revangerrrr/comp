#include "server.h"

#include <iostream>
using namespace std;


Server::Server() 
{
  cout << "Server::Constructor" << endl;
  fRefCount = 0;
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
     *ppv = (IUnknown_*)(Task*)this;
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
	

HRESULT_ __stdcall Server::SetTitle(const char* title) 
{	 	    		
  cout << "Server::SetTitle" << endl;
  return S_OK_;
}

HRESULT_ __stdcall Server::SetDiscription(const char* desc) 
{	 	    		
  cout << "Server::SetDiscription" << endl;
  return S_OK_;
}

HRESULT_ __stdcall Server::SetDueDate(const char* date)
{	 	    		
  cout << "Server::SetDueDate" << endl;
  return S_OK_;
}

HRESULT_ __stdcall Server::ShowTasks()
{	 	    		
  cout << "Server::ShowTasks" << endl;
  return S_OK_;
}

HRESULT_ __stdcall Server::AddNewTask()
{	 	    		
  cout << "Server::AddNewTask" << endl;
  return S_OK_;
}

HRESULT_ __stdcall Server::EditTask(Task* task)
{	 	    		
  cout << "Server::EditTask" << endl;
  return S_OK_;
}

HRESULT_ __stdcall Server::DeleteTask(Task* task)
{	 	    		
  cout << "Server::DeleteTask" << endl;
  return S_OK_;
}