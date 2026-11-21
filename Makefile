BUILD_DIR ?= build
CMAKE ?= cmake

.PHONY: symsala clean
.DEFAULT_GOAL := symsala

symsala:
	$(CMAKE) -S . -B $(BUILD_DIR)
	$(CMAKE) --build $(BUILD_DIR) --target symsala

clean:
	$(CMAKE) -E rm -rf $(BUILD_DIR)
