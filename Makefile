pa12: Vector.o pa12.o
	$(CXX) $(CXXFLAGS) Vector.o pa12.o

pa12.o: pa12.cpp Vector.h
	$(CXX) $(CXXFLAGS)

Vector.o: Vector.cpp Vector.h
	$(CXX) $(CXXFLAGS) -c Vector.cpp

clean:
	rm -f *.o ch12

judge:
	judge -p pa12 -i pa12-input0.txt -o pa12-output0.txt - v

judge1:
	judge -p pa12 -i pa12-input1.txt -o pa12-output1.txt - v

judge2:
	judge -p pa12 -i pa12-input2.txt -o pa12-output2.txt - v

comp:
	g++ $(CXXFLAGS) Vector.cpp pa12.cpp -o pa12

val:
	valgrind ./pa12 < pa12-input0.txt

val1:
	valgrind ./pa12 < pa12-input1.txt

val2:
	valgrind ./pa12 < pa12-input2.txt
