# See https://marmelab.com/blog/2016/02/29/auto-documented-makefile.html
help: ## Display help screen
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make \033[36m<target>\033[0m\n"} /^[a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-30s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)
.PHONY: help

app-build: ## Build application
	cmake --no-warn-unused-cli -DTREE_VISIBILITY_BUILD_APP:BOOL=TRUE -DTREE_VISIBILITY_BUILD_TEST:BOOL=FALSE  -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/clang-14 -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/clang++-14 -S . -B build/cmake/build -G "Unix Makefiles"
	cmake --build build/cmake/build --config Debug --target all --parallel --
.PHONY: app-build

app-run: ## Run the application
	./cmd/bin/tree_visibility-app
.PHONY: app-build

app-example: ## Run the example input in example/input
	./cmd/bin/tree_visibility-app < example/input
.PHONY: app-example

all-build: ## Build application & tests
	cmake --no-warn-unused-cli -DTREE_VISIBILITY_BUILD_APP:BOOL=TRUE -DTREE_VISIBILITY_BUILD_TEST:BOOL=TRUE  -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/clang-14 -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/clang++-14 -S . -B build/cmake/build -G "Unix Makefiles"
	cmake --build build/cmake/build --config Debug --target all --parallel --
.PHONY: all-build

test-run: ## Run Unit tests
	 GTEST_OUTPUT=xml:logs/test/result.xml GTEST_COLOR=1 ./cmd/bin/tree_visibility-test
.PHONY: test-run
