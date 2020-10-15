# Bettermake
## A snappy build system using YAML and written in C
### Get started
#### Dependencies
- libcyaml (<https://github.com/tlsa/libcyaml>)
- By extension, libyaml

#### Installation
#### Via `hubcap` (<https://github.com/munchkinhalfling/hubcap>)
Run:
```sh
$ sudo hubcap install munchkinhalfling/bettermake
```
Caveat (or feature, depending on your view): the `mk-` commands will be available in /usr/bin.
#### Via `app` (<https://github.com/munchkinhalfling/app>) (Linux only)
Run:
```sh
$ app install munchkinhalfling/bettermake
```
This has the same caveat as installation via `hubcap`. The advantage of this is that it installs only for your account.
#### From source
`git clone` the repository and run `./configure && make && sudo make install`, or, on Linux, you can run 'sudo ./bettermake build install' to take a look at the built-in build system.

#### Create a build file
##### Using make (deprecated, no longer updated)
Just use make as usual, with `include /opt/bettermake/path.mk` at the top, and using the commands described below.
##### Using the built-in build system (recommended)
Run `bettermake init` to create an example `buildconf.yml` file for you. \
See the `buildconf.yml` file in this repository for a fully-documented example.

### Building
Run `bettermake build` to run the default task.
See the `bettermake` subcommand reference below for more details.

### `bettermake` subcommand reference
#### `bettermake build [target...]`
With no arguments, builds the default target. \
With one or more arguments, builds the targets specified by the arguments, in order.

#### `bettermake init`
Initializes `buildconf.yml` with the following content:
```yaml
default: helloworld
env: ""
tasks:
  - name: helloworld
    depends: []
    description: Print hello world
    commands:
      - echo hello
```

#### `bettermake list`
Lists the targets in `buildconf.yml`. \
Sample output (from this project):
```
Default task: build
build: Compile
configure: Autoconf
install: Install (needs sudo)
hello: Print hello
world: Print world
fail: Fail it
testenv: Test Environment
```

#### `bettermake install`
Installs the latest Linux makefile utilities to /opt/bettermake.

### Why I chose to switch over to a custom build system
The main reason is, this one is faster than Make, single-threaded. \
Also, I was noticing that using the Makefile utilities, with all their `mk-` prefixes, was making my output nice, but my Makefile downright ugly. I prefer YAML for this sort of thing. \
Finally, I was hoping to do some things with Bettermake that I couldn't do when all the parts were separated into separate, non-communicating executables (for example, putting out 'completed successfully' at the end of a target, instead of after each command). \
Also, who doesn't want another YAML-based build system? ;)


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
