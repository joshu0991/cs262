CFLAGS=-Wall -g

Stego: Stego.o Lab11_jlilly3_204.o image.o
	gcc Stego.o Lab11_jlilly3_204.o image.o -o Stego $(CFLAGS)

StegoExtract: StegoExtract.o Lab11_jlilly3_204.o image.o
	gcc StegoExtract.o Lab11_jlilly3_204.o image.o -o StegoExtract $(CFLAGS)

StegoExtract.o:
	gcc $(CFLAGS) -c StegoExtract.c

Stego.o:
	gcc $(CFLAGS) -c Stego.c

Lab11_jlilly3_204.o: Lab11_jlilly3_204.c Lab11_jlilly3_204.h
	gcc $(CFLAGS) -c Lab11_jlilly3_204.c Lab11_jlilly3_204.h

image.o: image.c image.h
	gcc $(CFLAG) -c image.c image.h
clean:
	rm -rf Stego StegoExtract *.o
