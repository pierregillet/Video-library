# How to build #

## Dependencies ##

Dependencies | Version | Reason
------------ | -------:| ------
ncurses      | >= 6.0  | We need it for the CLI
libyaml      | >= 1.1  | We need it for the config file parsing


## Compilation instructions ##

At the root of the project : 

1. Create build directory
  * `$ mkdir build`
  * `$ meson build`

2. Compile
  * `$ cd build`
  * `$ ninja`