CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall
BUILD_DIR = build

define find_cpp
$(shell find . -type f -name "$(1)_*.cpp" | head -n 1)
endef

define find_py
$(shell find . -type f -name "$(1)_*.py" | head -n 1)
endef


# Make a new solution file with a template
# Default settings
path ?= .
ext ?= cpp

define template_cpp
#include <iostream>\n#include <vector>\nusing namespace std;\n\nint main() {\n\n	return 0;\n}
endef

define template_py
import collections\nimport math\n\ndef main():\n    # Code\n    pass\n\nif __name__ == "__main__":\n    main()
endef

# TODO: Add Rust template
define template_rs

endef

define template_md
$(shell date +%Y/%m/%d)\n\n### Notes\n- \n}
endef

# TODO: Refactor to be less complicated and more robust (e.g. handle edge cases, support more languages, etc.)
new:
	@if [ -z "$(name)" ] || [ -z "$(title)" ]; then \
		echo "Usage: make new name=1385 title=Problem_Name path=Binary_Search [ext=cpp|py|md]"; \
		exit 1; \
	fi; \
	target_dir="$(path)"; \
	mkdir -p "$$target_dir"; \
	base_name="$(name)_$(title)"; \
	if [ "$(ext)" = "md" ]; then \
		file_path="$$target_dir/$$base_name.note.md"; \
	else \
		file_path="$$target_dir/$$base_name.$(ext)"; \
	fi; \
	if [ -f "$$file_path" ]; then \
		echo "Error: $$file_path already exists."; \
		exit 1; \
	fi; \
	if [ "$(ext)" = "cpp" ]; then \
		printf "$(template_cpp)" > "$$file_path"; \
	elif [ "$(ext)" = "py" ]; then \
		printf "$(template_py)" > "$$file_path"; \
	elif [ "$(ext)" = "md" ]; then \
		printf "$(template_md)" > "$$file_path"; \
	else \
		touch "$$file_path"; \
	fi; \
	echo ">>> Created: $$file_path" \
	# zed "$$file_path"


# Compile and run the solution file
run:
	@if [ -z "$(name)" ]; then \
		echo "Usage: make run name=003"; \
		exit 1; \
	fi; \
	cpp_file="$(call find_cpp,$(name))"; \
	py_file="$(call find_py,$(name))"; \
	if [ -n "$$cpp_file" ]; then \
		echo ">>> C++ detected: $$cpp_file"; \
		mkdir -p $(BUILD_DIR); \
		out="$(BUILD_DIR)/$(name)"; \
		$(CXX) "$$cpp_file" $(CXXFLAGS) -o "$$out" && "$$out"; \
	elif [ -n "$$py_file" ]; then \
		echo ">>> Python detected: $$py_file"; \
		python3 "$$py_file"; \
	else \
		echo "No matching file found."; \
	fi


# Clean the build directory
clean:
	@echo "Cleaning build directory..."
	@mkdir -p $(BUILD_DIR)
	@rm -rf $(BUILD_DIR)/*
