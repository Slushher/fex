.PHONY: cmake compile run clean

cmake:
	cmake -B cmake

compile:
	cmake --build cmake

run:
	./bin/fex

clean:
	rm cmake -rf