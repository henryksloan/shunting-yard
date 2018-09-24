CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := bin/shunting

SRCTEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCTEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCTEXT)=.o))
CFLAGS :=
LIB := -I lib
INC := -I include

$(TARGET): $(OBJECTS)
	@echo "Linking..."
	@echo "$(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCTEXT)
	@mkdir -p $(BUILDDIR)
	@echo "$(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo "Cleaning..."
	@echo "$(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

test: build/expression_parser.o build/reverse_polish.o test/test.cpp 
	@echo "Building tests..."
	@echo "$(CC) $(CFLAGS) $^ $(INC) $(LIB) -o bin/test"; $(CC) $(CFLAGS) $^ $(INC) $(LIB) -o bin/test

.PHONY: clean test
