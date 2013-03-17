/*

Copyright © 2013 Sergey Shambir <sergey.shambir.auto@gmail.com>

This work is free. You can redistribute it and/or modify it under the
terms of the Do What The Fuck You Want To Public License, Version 2,
as published by Sam Hocevar. See the COPYING file for more details.

 */

#ifndef OPENGL_TYPECHECKS_H
#define OPENGL_TYPECHECKS_H

#include <GL/gl.h>

#if defined(__has_attribute)
#if __has_attribute(pointer_with_type_tag) && __has_attribute(type_tag_for_datatype)

////////////////////////////////////////////////////////////////////////////////
// Add pointer_with_type_tag to OpenGL functions

extern void GLAPIENTRY glReadPixels (GLint x, GLint y, GLsizei width,
                                     GLsizei height, GLenum format,
                                     GLenum type, GLvoid *pixels)
        __attribute__((pointer_with_type_tag(opengl, 7, 6)));

extern void GLAPIENTRY glNormalPointer (GLenum type, GLsizei stride,
                                        const GLvoid *pointer)
        __attribute__((pointer_with_type_tag(opengl, 3, 1)));

extern void GLAPIENTRY glVertexPointer (GLint size, GLenum type,
                                        GLsizei stride, const GLvoid *pointer)
        __attribute__((pointer_with_type_tag(opengl, 4, 2)));

extern void GLAPIENTRY glNormalPointer( GLenum type, GLsizei stride,
                                       const GLvoid *ptr )
        __attribute__((pointer_with_type_tag(opengl, 3, 1)));

extern void GLAPIENTRY glColorPointer( GLint size, GLenum type,
                                      GLsizei stride, const GLvoid *ptr )
    __attribute__((pointer_with_type_tag(opengl, 4, 2)));

extern void GLAPIENTRY glIndexPointer( GLenum type, GLsizei stride,
                                      const GLvoid *ptr )
        __attribute__((pointer_with_type_tag(opengl, 3, 1)));

extern void GLAPIENTRY glTexCoordPointer( GLint size, GLenum type,
                                         GLsizei stride, const GLvoid *ptr )
        __attribute__((pointer_with_type_tag(opengl, 4, 2)));

////////////////////////////////////////////////////////////////////////////////
// Add type tags

GLenum opengl_predefined_t_double
__attribute__(( type_tag_for_datatype(opengl,const double) )) = GL_DOUBLE;
GLenum opengl_predefined_t_float
__attribute__(( type_tag_for_datatype(opengl,const float) )) = GL_FLOAT;
GLenum opengl_predefined_t_unsigned_byte
__attribute__(( type_tag_for_datatype(opengl,const unsigned char) )) = GL_UNSIGNED_BYTE;
GLenum opengl_predefined_t_unsigned_int
__attribute__(( type_tag_for_datatype(opengl,const unsigned int) )) = GL_UNSIGNED_INT;

////////////////////////////////////////////////////////////////////////////////
// Redefine macros

#undef GL_DOUBLE
#undef GL_FLOAT
#undef GL_UNSIGNED_BYTE
#undef GL_UNSIGNED_INT
#define GL_DOUBLE opengl_predefined_t_double
#define GL_FLOAT opengl_predefined_t_float
#define GL_UNSIGNED_BYTE opengl_predefined_t_unsigned_byte
#define GL_UNSIGNED_INT opengl_predefined_t_unsigned_int

#endif
#endif

#endif // OPENGL_TYPECHECKS_H
