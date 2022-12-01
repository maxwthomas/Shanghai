CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic
GTESTFLAGS := -lgtest -lgtest_main


docker-build:
	docker build -t shanghai -f Dockerfile .

docker-run:
	docker run --rm -it -v $(PWD):/home -w /home shanghai

TestCard.o: TestCard.cpp Card.hpp .PHONY
	$(CXX) $(CXXFLAGS) $(GTESTFLAGS) TestCard.cpp -o TestCard.o

test: TestCard.o
	./TestCard.o

clean:
	rm -f *.o

.PHONY: clean
