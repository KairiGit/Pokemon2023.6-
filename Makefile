NAME   = circle
SRCS   = Move.cpp Poke.cpp Trainer.cpp BattleField.cpp main.cpp
OBJS   = $(SRCS:.cpp=.o)
DEPS   = $(SRCS:.cpp=.d)

CXX     = c++
CXXFLAGS = -std=c++14

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.d: %.cpp
	$(CXX) $(CXXFLAGS) -MM $< > $@

-include $(DEPS)

all: $(NAME)

clean:
	rm -f $(OBJS) $(NAME) $(DEPS) unittest unittest.o

buildtest: unittest.cpp
	$(CXX) $(CXXFLAGS) -c unittest.cpp
	$(CXX) unittest.o -o unittest

test: buildtest
	./unittest
