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

## Module 05

From the repository root, run `make -C cpp_05/ex00` to build the first Bureaucrat exercise without changing directories.

## Repository layout

The `cpp_05` through `cpp_09` directories group exercises by module. Exercise directories use names such as `ex00`, `ex01`, and `ex02`; build each exercise separately with its own Makefile.

## Module 06

Build the scalar conversion exercise with `make -C cpp_06/ex00`. The generated executable is `cpp_06/ex00/ex00`.

After building `cpp_05/ex00`, run its demonstration with `./cpp_05/ex00/ex00` from the repository root.

## Intern exercise

Run `make -C cpp_05/ex03` to build the Intern exercise. Its executable is `cpp_05/ex03/ex03`.

## Serialization exercise

Build with `make -C cpp_06/ex01`, then run `./cpp_06/ex01/ex01` from the repository root.
