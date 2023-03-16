all:main
main: main.o dispatch.o demo.pb.o func_add.o
	g++ --std=c++11 -o $@ $^ -L/usr/local/Cellar/protobuf/21.4/lib/ -lprotobuf

%.o:%.cpp
	g++ --std=c++11 -c $< -o $@

clean:
	rm -rf *.o
