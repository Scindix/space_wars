# Name of the compiled object
OBJECT_NAME	= _AllSpaceships.o

# Compiler Commands
COMPILER	= g++
LINKER		= ld
COMPILER_FLAGS	= -Wall -c -O3 -std=c++11 -fpic -I../inc -o
LINKER_FLAGS	= -r
#LINKER_DEPS	=

# Standard Commands
RMR		= rm -r
RM		= rm -f
CPR		= cp -f
CP		= cp -f
MKDIR		= mkdir -p

# Sources
SOURCES		= ${wildcard *.cpp}
OBJECTS		= ${SOURCES:%.cpp=%.o}
all-local: ${OBJECTS} ${OBJECT_NAME}

${OBJECTS}:
	${COMPILER} ${COMPILER_FLAGS} $@ ${@:%.o=%.cpp}

${OBJECT_NAME}:
	${LINKER} ${LINKER_FLAGS} ${OBJECTS} -o $@

clean-local:
	${RM} ${OBJECTS} ${OBJECT_NAME}
