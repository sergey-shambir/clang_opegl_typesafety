clang_opegl_typesafety
======================

Header injection aimed to add type checks for glVertexPointer-like OpenGL functions.

Such type safety is clang extension, available since clang 3.2.

Just insert header anywhere between GL/gl.h or GL/glew.h and your code. You can add attributes directly to gl.h and glew.h, like MPICH2 library developers did, moreover, I will be glad if anyone will make patches for Mesa and GLEW projects (and WTFPL license allows this).

