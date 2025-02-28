# Nombre del ejecutable y directorios
TARGET = bin/scrabble
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude/ -MMD
SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

# Buscar todos los archivos .cpp en la raíz y subcarpetas de src/
SRCS = $(wildcard *.cpp) $(wildcard $(SRC_DIR)/**/*.cpp)

# Generar los nombres de los archivos objeto en bin/
OBJS = $(patsubst %.cpp, $(BIN_DIR)/%.o, $(SRCS))

# Generar los nombres de los archivos de dependencias
DEPFILES = $(OBJS:.o=.d)

# Asegurar que bin/ exista antes de compilar
$(TARGET): $(OBJS)
$(TARGET): $(OBJS)
	md bin 2> nul || exit 0
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compilar archivos .cpp a .o dentro de bin/
$(BIN_DIR)/%.o: %.cpp
	md $(dir $@) 2> nul || exit 0
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar los archivos compilados
clean:
	if exist bin ( rmdir /s /q bin )

# Regla para recompilar desde cero
all: clean $(TARGET)

# Incluir archivos de dependencias
-include $(DEPFILES)