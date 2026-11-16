CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

makeup: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o makeup
