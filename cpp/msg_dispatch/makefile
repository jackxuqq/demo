all:main
main: demo.pb.o main.o dispatch.o func_add.o
	g++ -g --std=c++11 -o $@ $^ -lprotobuf

demo.pb.cpp:demo.proto
	protoc --cpp_out=. $<
	mv demo.pb.cc demo.pb.cpp

%.o:%.cpp
	g++ -g --std=c++11 -c $< -o $@
clean:
	rm -rf *.o
	rm -f demo.pb.cpp
	rm -f demo.pb.h
	rm -f main
