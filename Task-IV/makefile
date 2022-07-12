main: uzduotis.c vartotojoMeniu.c vienpusisSarasas.c ivestisIsvestis.c
	gcc -o main uzduotis.c vartotojoMeniu.c vienpusisSarasas.c ivestisIsvestis.c

.PHONY: program

program: main
	main

test: vienetuTestai.c vartotojoMeniu.c vienpusisSarasas.c ivestisIsvestis.c
	gcc -o test vienetuTestai.c vartotojoMeniu.c vienpusisSarasas.c ivestisIsvestis.c

.PHONY: testavimas

testavimas: test
	test
