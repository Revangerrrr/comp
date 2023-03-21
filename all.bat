g++ -c ./server/source/server.cpp -o ./server/build/server.o
g++ -c ./server/source/iserver.cpp -o ./server/build/iserver.o

xcopy .\server\build\server.o .\client\build\lib /Y
xcopy .\server\build\iserver.o .\client\build\lib /Y
xcopy .\server\source\iserver.h .\client\source\lib /Y

g++ -c ./client/source/client.cpp  -o ./client/build/client.o

g++ ./client/build/client.o ./client/build/lib/iserver.o ./client/build/lib/server.o    -o ./client/build/client.exe

"client/build/client.exe"

pause