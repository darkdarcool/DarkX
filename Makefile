build:
	g++ src/DarkX/main.cpp src/DarkX/lexer/*.hpp src/DarkX/runner/*.hpp -o main
test-write:
	g++ src/tests/write/write.cpp -o write
sample:
	make test-write && ./write && make build && ./main tests/test.dark