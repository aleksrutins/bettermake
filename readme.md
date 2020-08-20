# Bettermake
## Make your makefiles better
### Get started
#### Installation
`git clone` the repository and run `./configure && make && sudo make install`, or, on Linux, you can run 'sudo ./bettermake build install' to take a look at the built-in build system.

#### Create a build file
##### Using make
Just use make as usual, with `include /opt/bettermake/path.mk` at the top, and using the commands described below.
##### Using the built-in build system.
Run `bettermake init` to create an example `buildconf.yml` file for you. \
See the `buildconf.yml` file in this repository for a fully-documented example.
```
### Building
Simply run `make` as usual.

### Command reference (for Makefiles)
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
