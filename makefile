movie_manage_program.exe : add.o save.o prompt.o welcome.o main.o sort.o read_log.o update.o delete.o print.o delete_log.o cntrl_signal.o link.o
	gcc -o movie_manage_program.exe add.o save.o prompt.o welcome.o main.o sort.o read_log.o update.o delete.o print.o delete_log.o cntrl_signal.o link.o
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
sort.o : sort.c
	gcc -c -o sort.o sort.c
read_log.o : read_log.c
	gcc -c -o read_log.o read_log.c
update.o : update.c
	gcc -c -o update.o update.c
delete.o : delete.c
	gcc -c -o delete.o delete.c
print.o : print.c
	gcc -c -o print.o print.c
delete_log.o : delete_log.c
	gcc -c -o delete_log.o delete_log.c
cntrl_signal.o : cntrl_signal.c
	gcc -c -o cntrl_signal.o cntrl_signal.c
link.o : link.c
	gcc -c -o link.o link.c
