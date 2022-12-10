CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic
GTESTFLAGS := -lgtest


docker-build:
	docker build -t shanghai -f Dockerfile .

docker-run:
	docker run --rm -it -v $(PWD):/home -w /home shanghai

RunTests: TestCard.hpp Card.hpp TestCardHand.hpp CardHand.hpp TestCardStack.hpp CardStack.hpp .PHONY
	$(CXX) $(CXXFLAGS) $(GTESTFLAGS) RunTests.cpp -o RunTests

test: RunTests
	./RunTests

clean:
	rm -f *.o

.PHONY: clean
