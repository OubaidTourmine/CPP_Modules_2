# C++ Modules 05–09

Each exercise has its own Makefile. Build from its directory, for example:

```sh
cd cpp_05/ex00
make
```

The exercise builds use C++98 with `-Wall -Wextra -Werror`.

## Clean builds

Run `make clean` inside an exercise directory to remove object files. Use `make fclean` to also remove its executable, or `make re` to rebuild from scratch.

## RPN exercise

Build the reverse Polish notation exercise with `make -C cpp_09/ex01`. Its executable is `cpp_09/ex01/RPN`.
