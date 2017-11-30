movie_manage_program.exe : add.o save.o prompt.o welcome.o main.o
	gcc -o movie_manage_program.exe add.o save.o prompt.o welcome.o main.o
add.o : add.c
	gcc -c -o add.o add.c
save.o : save.c
	gcc -c -o save.o save.c
prompt.o : prompt.c
	gcc -c -o prompt.o prompt.c
welcome.o : welcome.c
	gcc -c -o welcome.o welcome.c
main.o : main.c
	gcc -c -o main.o main.c
