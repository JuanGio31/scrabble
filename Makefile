# Nombre del ejecutable y directorios
TARGET = bin/scrabble
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude/ -MMD
SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

# Detectar sistema operativo
ifeq ($(OS),Windows_NT)
    MKDIR = mkdir
    RM = del /Q /F
    MKDIR_P = mkdir
    SEP = \\
else
    MKDIR = mkdir -p
    RM = rm -f
    MKDIR_P = mkdir -p
    SEP = /
endif

# Buscar todos los archivos .cpp en la raíz y subcarpetas de src/
SRCS = $(wildcard *.cpp) $(wildcard $(SRC_DIR)/**/*.cpp)

# Generar los nombres de los archivos objeto en bin/
OBJS = $(patsubst %.cpp, $(BIN_DIR)/%.o, $(SRCS))

# Generar los nombres de los archivos de dependencias
DEPFILES = $(OBJS:.o=.d)

# Regla principal
$(TARGET): $(OBJS)
	@$(MKDIR_P) $(dir $@)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compilar archivos .cpp a .o dentro de bin/
$(BIN_DIR)/%.o: %.cpp
	@$(MKDIR_P) $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar los archivos compilados
clean:
	$(RM) $(subst /,$(SEP),$(TARGET))
	$(RM) $(subst /,$(SEP),$(OBJS))
	$(RM) $(subst /,$(SEP),$(DEPFILES))

# Regla para recompilar desde cero
.PHONY: all clean
all: clean $(TARGET)

# Incluir archivos de dependencias
-include $(DEPFILES)