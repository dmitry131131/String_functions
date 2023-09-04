CXX = g++
CXXFLAGS =  -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code \
		    -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall \
		    -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 \
			-Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith \
			-Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla \
			-D_DEBUG -D_EJUDGE_CLIENT_SIDE
TARGET = main
SourceFolder = Source
BuildFolder = build

Sources = StringFunctions.cpp MatrixFunctions.cpp
Main = main.cpp

.PHONY : all clean folder

all : folder $(TARGET)

Source = $(addprefix $(SourceFolder)/, $(Sources))
ObjNames = $(Sources:.cpp=.o) $(Main:.cpp=.o)
MainObject = $(addprefix $(BuildFolder)/, $(Main:.cpp=.o))

objects = $(addprefix $(BuildFolder)/, $(ObjNames))

$(addprefix $(BuildFolder)/, $(ObjNames)): $(BuildFolder)/%.o: $(SourceFolder)/%.cpp
	@echo [CXX] -c $< -o $@
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET) : $(objects) $(MainObject)
	@echo [CC] $^ -o $@
	@$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	rm $(TARGET).exe *.o

folder :
	mkdir -p $(BuildFolder)