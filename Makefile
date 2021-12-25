make:
	g++ *.cpp -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf -lSDL2_mixer && ./a.out
clean:
	rm a.out
