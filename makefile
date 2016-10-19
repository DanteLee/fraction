TARGET = src/fraction.cc
OBJECT = fraction.o

o:$(TARGET)
	g++ -c $(TARGET)
	ar -rv libfraction.a $(OBJECT)
	mv libfraction.a out
	rm fraction.o

clean:
	rm ./out/*.o

run-test:
	g++ -o out/fraction_test.o -I src/ -I $(GTEST_INCLUDE) -c test/fraction_test.cc
	g++ -o out/main.test -pthread out/fraction_test.o out/libfraction.a out/libgtest.a
	out/main.test
