LIBS=-lGL -lGLEW -lglfw
CHOICES=-O3
OUTPUT=01
SRC=gltest.cpp LWindow.cpp ../loadBmp.cpp LShaderLoader.cpp 
$(OUTPUT):$(SRC)
	g++ $(CHOICES) $(SRC) -o $(OUTPUT) $(LIBS)