# Nome do executável
EXECUTABLE = portas

# Compiladores
CXX_LINUX = g++
CXX_WINDOWS = x86_64-w64-mingw32-g++
CXX = $(CXX_LINUX)

# Flags de compilação
CFLAGS = -std=c++20 -Wall -pthread
LDFLAGS =

# Diretórios
SOURCE_FOLDER = .
OBJECTS_FOLDER = objects

# Fontes
SOURCES = $(wildcard $(SOURCE_FOLDER)/*.cpp)

# Objetos
OTHER_OBJECTS = $(patsubst $(SOURCE_FOLDER)/%.cpp, $(OBJECTS_FOLDER)/%.o, $(SOURCES))

# Objetos específicos para cada ambiente
OBJECTS_LINUX = $(OTHER_OBJECTS)
OBJECTS_WINDOWS = $(OTHER_OBJECTS)

# Regra de compilação para objetos
$(OBJECTS_FOLDER)/%.o: $(SOURCE_FOLDER)/%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

# Regra de construção do executável
$(EXECUTABLE): $(OBJECTS_LINUX)
	$(CXX) $(CFLAGS) -o $@ $(OBJECTS_LINUX) $(LDFLAGS)

# Regra de compilação para o ambiente Windows
windows: CXX = $(CXX_WINDOWS)
windows: CFLAGS += -static-libgcc -static-libstdc++ # -static
windows: LDFLAGS += -Wl,-Bstatic -lpthread -Wl,-Bdynamic -lstdc++fs -lmingw32
windows: $(EXECUTABLE).exe

# Regra de construção do executável para o ambiente Windows
$(EXECUTABLE).exe: $(OBJECTS_WINDOWS)
	$(CXX) $(CFLAGS) -o $@ $(OBJECTS_WINDOWS) $(LDFLAGS)

# Regra de compilação padrão
all: $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) $(EXECUTABLE).exe $(OBJECTS_LINUX) $(OBJECTS_WINDOWS)

.PHONY: all windows clean
