NAME   = circle
SRCS   = Move.cpp Poke.cpp Trainer.cpp main.cpp 
OBJS   = $(SRCS:.cpp=.o)
DEPS   = $(SRCS:.cpp=.d)

CXX     = c++
CXXFLAGS = -std=c++14

$(NAME):$(OBJS)
	$(CXX) -o $@ $^

.cpp.o:%.d
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.d:%.cpp
	$(CXX) $(CXXFLAGS) -MM $< > $@

-include  $(DEPS)

all: $(NAME)

clean:
	rm -f $(OBJS) $(NAME) $(DEPS) unittest unittest.o

buildtest: unittest.cpp Circle.o
	$(CXX) $(CXXFLAGS) -c unittest.cpp 
	$(CXX) Circle.o unittest.o -o unittest

test: buildtest
	./unittest