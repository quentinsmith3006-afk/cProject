
#!/bin/bash

gcc src/game.c -pthread -o bin/game.out

./bin/game.out

rm -r *.c~
rm -r *.h~
