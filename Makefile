# Student Marks Management System Makefile
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
DEBUG_FLAGS = -g -DDEBUG

# Target executable
TARGET = marks_program

# Source files
SOURCES = main.c student_data.c generate_html.c

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Header files
HEADERS = student_data.h

# Output directory
OUTPUT_DIR = student_marks

# Default target
all: $(TARGET)

# Build the main executable
$(TARGET): $(OBJECTS)
	@echo "🔨 Linking $(TARGET)..."
	$(CC) $(CFLAGS) -o $@ $^
	@echo "✅ Build complete! Run with: ./$(TARGET)"

# Compile source files to object files
%.o: %.c $(HEADERS)
	@echo "📝 Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Debug build
debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean $(TARGET)
	@echo "🐛 Debug build complete"

# Clean build artifacts
clean:
	@echo "🧹 Cleaning build artifacts..."
	rm -f $(OBJECTS) $(TARGET)
	@echo "✨ Clean complete"

# Create output directory if it doesn't exist
ensure-output-dir:
	@mkdir -p $(OUTPUT_DIR)

# Run the program
run: $(TARGET) ensure-output-dir
	@echo "🚀 Running $(TARGET)..."
	./$(TARGET)
	@echo "📄 Check $(OUTPUT_DIR)/index.html for the report"

# Install dependencies for web server
web-setup:
	@echo "📦 Installing Node.js dependencies..."
	cd backend && npm install
	@echo "✅ Web dependencies installed"

# Start web server
web-start:
	@echo "🌐 Starting web server..."
	cd backend && npm start

# Development mode with nodemon
web-dev:
	@echo "🔄 Starting development server..."
	cd backend && npm run dev

# Show help
help:
	@echo "🎓 Student Marks Management System"
	@echo "Available targets:"
	@echo "  all       - Build the C program (default)"
	@echo "  debug     - Build with debug symbols"
	@echo "  clean     - Remove build artifacts"
	@echo "  run       - Build and run the C program"
	@echo "  web-setup - Install Node.js dependencies"
	@echo "  web-start - Start the web server"
	@echo "  web-dev   - Start development server with auto-reload"
	@echo "  help      - Show this help message"

# Phony targets
.PHONY: all debug clean run web-setup web-start web-dev help ensure-output-dir

# Dependencies
main.o: main.c student_data.h
student_data.o: student_data.c student_data.h
generate_html.o: generate_html.c student_data.h

