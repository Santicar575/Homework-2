local:
	g++ -std=c++14 -g -Wall -Wconversion -Wno-sign-conversion -Werror -o main main.cpp entero.cpp real.cpp complejo.cpp
	valgrind -s --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes ./main
	rm main