# Bettermake
## Make your makefiles better
### Get started
#### On MacOS/Unix (Use the way below if on Linux)
`git clone` the repository and run `./configure && make && sudo make install`. Then, download <dist/bettermake.gz> and unzip it to your project directory for Linux users. You will have to build it from source every time you want to update. \
Then, include `/opt/bettermake/path.mk` in your Makefile.
#### On Linux
Download <dist/bettermake.gz> and unzip it in your project directory. Then, run './bettermake install' as the superuser to install bettermake. \
Then, add to the top of your makefile:
```Makefile
include /opt/bettermake/path.mk
```
### Building
Simply run `make` as usual.

### Command reference
#### `mk-header`
Print out a recipe header. \
Usage: `@mk-header <recipe name> "<recipe description>"` \
Example: `@mk-header tribbles "Running tribble extraction routines..."`

#### `mk-detail`
Print out a detail message. \
Usage: `@mk-detail "<message>"` \
Example: `@mk-detail "Deporting tribbles..."`

#### `command`
Run a command. \
Usage: `@mk-command '<command>' [flags]` \
Example: `@mk-command 'find tribbles -delete'` \
The only flag is `quiet`, which stops it from outputting the exit code.
