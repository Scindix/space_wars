#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(spacewars, 1.0, wehrum.cedric@gmail.com)


AM_INIT_AUTOMAKE
AC_CONFIG_FILES([Makefile src/Makefile lib/Makefile])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([memory.h stddef.h stdint.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T

# Checks for library functions.
AC_CHECK_LIB([glfw], [glfwInit], [], [
  AC_MSG_ERROR([spacewars requires glfw])])
AC_CHECK_LIB([GLEW], [glewInit], [], [
  AC_MSG_ERROR([spacewars requires libglew])])
AC_CHECK_LIB([GLU], [gluLookAt], [], [
  AC_MSG_ERROR([spacewars requires libglu])])
AC_CHECK_LIB([GL], [glGenVertexArrays], [], [
  AC_MSG_ERROR([spacewars requires libgl])])
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([floor memmove memset pow sqrt strtol])

AC_OUTPUT
