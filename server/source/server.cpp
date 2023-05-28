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

//IDispatch (Begin)
HRESULT __stdcall Server::GetTypeInfoCount(UINT* pctinfo)
{
    cout << "Server:GetTypeInfoCount" << endl;
    return S_OK;
}

HRESULT __stdcall Server::GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo)
{
    cout << "Server:GetTypeInfo" << endl;
    return S_OK;
}

HRESULT __stdcall Server::GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames,
                                    LCID lcid, DISPID* rgDispId)
{
    cout << "Server:GetIDsOfNames" << endl;
    if (cNames!=1) {return E_NOTIMPL;}

    if (wcscmp(rgszNames[0],L"SetTitle")==0)
    {
      rgDispId[0] = 1;
    }
    else if (wcscmp(rgszNames[0],L"SetDiscription")==0)
    {
      rgDispId[0] = 2;
    }

    else if (wcscmp(rgszNames[0],L"SetDueDate")==0)
    {
      rgDispId[0] = 3;
    }
    
    else if (wcscmp(rgszNames[0],L"ShowTasks")==0)
    {
      rgDispId[0] = 4;
    }

    else if (wcscmp(rgszNames[0],L"AddNewTask")==0)
    {
      rgDispId[0] = 5;
    }

    else if (wcscmp(rgszNames[0],L"EditTask")==0)
    {
      rgDispId[0] = 6;
    }

    else if (wcscmp(rgszNames[0],L"DeleteTask")==0)
    {
      rgDispId[0] = 7;
    }
    else if (wcscmp(rgszNames[0],L"test")==0)
    {
      rgDispId[0] = 8;
    }
    else
    {
       return E_NOTIMPL;
    }
    return S_OK;
}

HRESULT __stdcall Server::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid,WORD wFlags, DISPPARAMS* pDispParams,VARIANT* pVarResult,
                             EXCEPINFO* pExcepInfo, UINT* puArgErr)
{
    cout << "Server:Invoke" << endl;
    if (dispIdMember==1)
    {
       SetTitle();
    }
    else if (dispIdMember==2)
    {
       SetDiscription();
    }
    else if (dispIdMember==3)
    {
       SetDueDate();
    }
    else if (dispIdMember==4)
    {
       ShowTasks();
    }
    else if (dispIdMember==5)
    {
       AddNewTask();
    }
    else if (dispIdMember==6)
    {
       EditTask();
    }
    else if (dispIdMember==7)
    {
       DeleteTask();
    }
    else if (dispIdMember==8)
    {
       {
       if ( (wFlags==DISPATCH_PROPERTYGET) || (wFlags==1) || (wFlags==3) )
       {
          if (pVarResult!=NULL)
          {
            pVarResult->vt = VT_INT;
            pVarResult->intVal = test;
          }
       }
       else if (wFlags==DISPATCH_PROPERTYPUT)
       {
          DISPPARAMS param = *pDispParams;
          VARIANT arg = (param.rgvarg)[0];
          VariantChangeType(&arg,&arg,0,VT_INT);
          test = arg.intVal;
       }
       else
       {
         return E_NOTIMPL;
       }
    };
    }
    else
    {
      return E_NOTIMPL;
    }
    return S_OK;
}
//IDispatch (End)

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
   else if (iid==IID_IDispatch1)
   {
      *ppv = (IDispatch*)this;
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