my_Preprocessor: main.o comment.o macro.o head.o
	cc main.o comment.o macro.o head.o -o my_Preprocessor

main.o: main.c header.h
	cc -c main.c

comment.o: comment.c header.h
	cc -c comment.c

macro.o: macro.c header.h
	cc -c macro.c

head.o: head.c header.h
	cc -c head.c

clean:
	rm -r *.o my_Preprocessor 
