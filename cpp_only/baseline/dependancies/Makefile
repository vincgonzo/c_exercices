

all:
	g++ mylib.cpp -fPIC -shared -o libmylib.so && g++ -o test main.cpp -L. -lmylib
