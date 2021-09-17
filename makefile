CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = project4Main.o Queue.o Die.o Character.o Barbarian.o Vampire.o BlueMen.o Medusa.o HarryPotter.o inputValid.o Gameplay.o Menu.o
 
SRCS = project4Main.cpp Die.cpp Character.cpp Barbarian.cpp Vampire.cpp BlueMen.cpp Medusa.cpp HarryPotter.cpp inputValid.cpp Queue.cpp Gameplay.cpp Menu.cpp

HEADERS = Die.hpp Character.hpp Barbarian.hpp Vampire.hpp BlueMen.hpp Medusa.hpp HarryPotter.hpp inputValid.hpp Queue.hpp Gameplay.hpp Menu.hpp 

project4: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o project4

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o project4

