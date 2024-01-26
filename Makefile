.PHONY: clean example

example:
	$(CC) example.c -o example -std=c99

clean:
	rm -rf example