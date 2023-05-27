g++ -c ./server/source/server.cpp -o ./server/build/server.o
g++ -c ./server/source/iserver.cpp -o ./server/build/iserver.o

g++ -shared .\server\build\server.o .\server\build\iserver.o -o C:\asd\server.dll -Wl,--kill-at -lole32 -loleaut32 -luser32

xcopy .\server\source\iserver.h .\client\source\lib -o

g++ -c ./client/source/client.cpp  -o ./client/build/client.o

g++ ./client/build/client.o -o ./client/build/client.exe -lole32 -loleaut32 -luser32

.\client\build\client.exe

pause