#include "lib/iserver.h"
#include "wrapper.h"

#include <iostream>
using namespace std;

int main() {
 try
 {		    		
	cout << "Client::Main::Start" << endl;			
	
	
	cout << "Client::Main::CreateServer CServer&IX" << endl;			
	IX* pIX = NULL;
	HRESULT_ res = CreateServer(CLSID_CServer, IID_IX, (void**)&pIX);
	
    if (res==S_OK_)
	{
		cout << "Client::Main::Success IX: " << endl;			
		pIX->Fx1();
		pIX->Fx2();
	}	
	else
    {
	   cout << "Client::Main::Error CServer or IX: " << res << endl;	
	   return 0;		
	}

    cout << "Client::Main::QueryInterface IX->IY" << endl;			
	IY* pIY = NULL;
    res = pIX->QueryInterface(IID_IY,(void**)&pIY);
	cout << "Client::Main::IX->Release" << endl;			
	pIX->Release();
    if (res==S_OK_)
	{
		cout << "Client::Main::Success IY: " << endl;			
		pIY->Fy1();
		pIY->Fy2();
	}	
	else
    {
	   cout << "Client::Main::Error IY: " << res << endl;			
	}
	
	cout << "Client::Main::IY->Release" << endl;			
	pIY->Release();
	
    cout << "Client::Main::Finish" << endl;			






    cout << " " << endl;			






    cout << "Client::Main::Wrapper:Strart" << endl;	
	try		
	{
      CServer s;	  
	  s.Fx1();
	  s.Fx2();
      s.Fy1();
      s.Fy2();    
	}
	catch (EServer& e)
	{
	   cout << "Client::Main::Wrapper:Error while working with CServer: " << e.GetMessage() << endl;
	   return 0;
	}

	cout << "Client::Main::Wrapper:Finish" << endl;			
	return 0;
 }
 catch (...) 
 {
	cout << "Client::Main::Unknown error while application running"  << endl;			
	return 0;
 }
}