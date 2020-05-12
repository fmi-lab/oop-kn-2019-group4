SRC_DIR = ./
OBJ_DIR = ./build
#Wildcard means that matches to the pattern are all outputed and made space separated
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
#patsubst matches the pattern on the left and replaces with the one in the middle in the TEXT at the right. 
#% matches any number of given characters. 
#The characters are the same for $(SRC_DIR)/%.cpp and $(OBJ_DIR)/%.o. The idea is to take the space separated .cpp file names and make them
#space separated .o files with the same names
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
CPPFLAGS = -g -Wall #-Wall displays g++ warnings. -g makes it so I can debug with gdb

#$@ matches main.exe and $^ matches all object files or everything after the :
main.exe: $(OBJ_FILES)
	g++ -o $@ $^

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp 
	g++ $(CPPFLAGS) -c -o $@ $<
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/Functions.h
	g++ $(CPPFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/%.h
	g++ $(CPPFLAGS) -c -o $@ $<


	
#Explanation for the last 2 lines: 
#The line matches cpp and header files in the SRC_DIR. $< feeds only the first argument after the colon to g++ which is the cpp file as it should 
#$@ is the same as for main.exe. It is replaced with the text before the colon(:)
#(OBJ_DIR)/%.o means that. % is replaced with what it matches on the right So it becomes ./build/Student.o: ./Student.cpp ./Student.h. 
#This means that ./build/Student.o depends on theese files and if they are changed the command at the bottom should be executed
