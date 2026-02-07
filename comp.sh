
#!/bin/bash

rm -r src/*.c~
rm -r src/resource/*.h~

gcc src/game.c -pthread -o bin/game.out

./bin/game.out

