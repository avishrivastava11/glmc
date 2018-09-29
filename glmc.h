/* 
 * Copyright 2018 Anish Bhobe, glmc Contributors
 * 
 * Permission is hereby granted, free of charge, 
 * to any person obtaining a copy of this software 
 * and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, 
 * merge, publish, distribute, sublicense, and/or sell 
 * copies of the Software, and to permit persons to whom 
 * the Software is furnished to do so, subject to the 
 * ollowing conditions:
 * 
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef _GLMC_H
#define _GLMC_H

#include <stdint.h>

// types

typedef float vec4f[4];
typedef float vec3f[3];
typedef float vec2f[2];

typedef vec4f mat4f[4];
typedef vec3f mat3f[3];
typedef vec2f mat2f[2];

// vec3f

void glmc_vec3f_from_2f(vec3f dest, vec2f src_a, float src_b);
void glmc_vec3f_from_4f(vec3f dest, vec4f src);

void glmc_vec3f_copy(vec3f dest, vec3f src);

float glmc_vec3f_sqrlength(vec3f vec);
float glmc_vec3f_length(vec3f vec);

int  glmc_vec3f_is_normalized(vec3f src);
void glmc_vec3f_normalize(vec3f dest, vec3f src);

void glmc_vec3f_add(vec3f dest, vec3f src_a, vec3f src_b); // dest = src_a + src_b;
void glmc_vec3f_add_dest(vec3f src_dest, vec3f src_b); // dest += src_a;

void glmc_vec3f_sub(vec3f dest, vec3f src_a, vec3f src_b); // dest = src_a - src_b;
void glmc_vec3f_sub_dest(vec3f src_dest, vec3f src_b); // dest -= src_a;

void glmc_vec3f_mul(vec3f dest, vec3f src_a, vec3f src_b); // dest = src_a * src_b;
void glmc_vec3f_mul_dest(vec3f src_dest, vec3f src_b); // dest *= src_a;
void glmc_vec3f_mul_s(vec3f dest, vec3f src_a, float src_b); // dest = src_a * scalar

void glmc_vec3f_div(vec3f dest, vec3f src_a, vec3f src_b); // dest = src_a / src_b;
void glmc_vec3f_div_dest(vec3f src_dest, vec3f src_b); // dest /= src_a;
void glmc_vec3f_div_s(vec3f dest, vec3f src_a, float src_b); // dest = src_a / scalar

void glmc_vec3f_addadd(vec3f dest, vec3f src_a, vec3f src_b); // dest += src_a + src_b;
void glmc_vec3f_subadd(vec3f dest, vec3f src_a, vec3f src_b); // dest += src_a - src_b;

void glmc_vec3f_madd(vec3f dest, vec3f src_a, vec3f src_b); // dest += src_a * src_b;
void glmc_vec3f_msub(vec3f dest, vec3f src_a, vec3f src_b); // dest -= src_a * src_b;

float glmc_vec3f_dot(vec3f src_a, vec3f src_b);
void  glmc_vec3f_cross(vec3f dest, vec3f src_a, vec3f src_b);

// vec4f

void glmc_vec4f_from_2f(vec4f dest, vec2f src_a, float src_b, float src_c);
void glmc_vec4f_from_3f(vec4f dest, vec3f src_a, float src_b);

void glmc_vec4f_copy(vec4f dest, vec4f src);

float glmc_vec4f_sqrlength(vec4f vec);
float glmc_vec4f_length(vec4f vec);

int  glmc_vec4f_is_normalized(vec4f src);
void glmc_vec4f_normlize(vec4f dest, vec4f src);

void glmc_vec4f_add(vec4f dest, vec4f src_a, vec4f src_b); // dest = src_a + src_b;
void glmc_vec4f_add_dest(vec4f src_dest, vec4f src_b); // dest += src_a;

void glmc_vec4f_sub(vec4f dest, vec4f src_a, vec4f src_b); // dest = src_a - src_b;
void glmc_vec4f_sub_dest(vec4f src_dest, vec4f src_b); // dest -= src_a;

void glmc_vec4f_mul(vec4f dest, vec4f src_a, vec4f src_b); // dest = src_a * src_b;
void glmc_vec4f_mul_dest(vec4f src_dest, vec4f src_b); // dest *= src_a;
void glmc_vec4f_mul_s(vec4f dest, vec4f src_a, float src_b); // dest = src_a * scalar

void glmc_vec4f_div(vec4f dest, vec4f src_a, vec4f src_b); // dest = src_a / src_b;
void glmc_vec4f_div_dest(vec4f src_dest, vec4f src_b); // dest /= src_a;
void glmc_vec4f_div_s(vec4f dest, vec4f src_a, float src_b); // dest = src_a / scalar

void glmc_vec4f_addadd(vec4f dest, vec4f src_a, vec4f src_b); // dest += src_a + src_b;
void glmc_vec4f_subadd(vec4f dest, vec4f src_a, vec4f src_b); // dest += src_a - src_b;

void glmc_vec4f_madd(vec4f dest, vec4f src_a, vec4f src_b); // dest += src_a * src_b;
void glmc_vec4f_msub(vec4f dest, vec4f src_a, vec4f src_b); // dest -= src_a * src_b;

float glmc_vec4f_dot(vec4f src_a, vec4f src_b);

// vec2f

void glmc_vec2f_from_3f(vec2f dest, vec3f src);
void glmc_vec2f_from_4f(vec2f dest, vec2f src);

void glmc_vec2f_copy(vec2f dest, vec2f src);

float glmc_vec2f_sqrlength(vec2f vec);
float glmc_vec2f_length(vec2f vec);

int  glmc_vec2f_is_normalized(vec2f src);
void glmc_vec2f_normlize(vec2f dest, vec2f src);

void glmc_vec2f_add(vec2f dest, vec2f src_a, vec2f src_b); // dest = src_a + src_b;
void glmc_vec2f_add_dest(vec2f src_dest, vec2f src_b); // dest += src_a;

void glmc_vec2f_sub(vec2f dest, vec2f src_a, vec2f src_b); // dest = src_a - src_b;
void glmc_vec2f_sub_dest(vec2f src_dest, vec2f src_b); // dest -= src_a;

void glmc_vec2f_mul(vec2f dest, vec2f src_a, vec2f src_b); // dest = src_a * src_b;
void glmc_vec2f_mul_dest(vec2f src_dest, vec2f src_b); // dest *= src_a;
void glmc_vec2f_mul_s(vec2f dest, vec2f src_a, float src_b); // dest = src_a * scalar

void glmc_vec2f_div(vec2f dest, vec2f src_a, vec2f src_b); // dest = src_a / src_b;
void glmc_vec2f_div_dest(vec2f src_dest, vec2f src_b); // dest /= src_a;
void glmc_vec2f_div_s(vec2f dest, vec2f src_a, float src_b); // dest = src_a / scalar

void glmc_vec2f_addadd(vec2f dest, vec2f src_a, vec2f src_b); // dest += src_a + src_b;
void glmc_vec2f_subadd(vec2f dest, vec2f src_a, vec2f src_b); // dest += src_a - src_b;

void glmc_vec2f_madd(vec2f dest, vec2f src_a, vec2f src_b); // dest += src_a * src_b;
void glmc_vec2f_msub(vec2f dest, vec2f src_a, vec2f src_b); // dest -= src_a * src_b;

float glmc_vec2f_dot(vec2f src_a, vec2f src_b);

//mat2f

void glmc_mat2f_print(mat2f src_b);
int glmc_mat2f_isequal(mat2f src_a, mat2f src_b);
void glmc_mat2f_copy(mat2f dest, mat2f src_b);
void glmc_mat2f_transp(mat2f dest, mat2f src_b);
float glmc_mat2f_abs(mat2f src_b);

void glmc_mat2f_add(mat2f dest, mat2f src_a, mat2f src_b);

void glmc_mat2f_sub(mat2f dest, mat2f src_a, mat2f src_b);

void glmc_mat2f_mul(mat2f dest, mat2f src_a, mat2f src_b);
void glmc_mat2f_muladd(mat2f dest, mat2f src_a, mat2f src_b);
void glmc_mat2f_mulsub(mat2f dest, mat2f src_a, mat2f src_b);
void glmc_mat2f_mul_s(mat2f dest, mat2f src_a, float src_b);

void glmc_mat2f_div_s(mat2f dest, mat2f src_a, float src_b);

void glmc_mat2f_inv(mat2f dest, mat2f src_a);

void glmc_mat2f_normalize(mat2f dest);
void glmc_mat2f_vecmul(vec2f dest, mat2f src_a, vec2f src_b);

//mat3f

void glmc_mat3f_print(mat3f src_b);
int glmc_mat3f_isequal(mat3f src_a, mat3f src_b);
void glmc_mat3f_copy(mat3f dest, mat3f src_b);
void glmc_mat3f_transp(mat3f dest, mat3f src_b);
float glmc_mat3f_abs(mat3f src_b);


void glmc_mat3f_add(mat3f dest, mat3f src_a, mat3f src_b);
void glmc_mat3f_sub(mat3f dest, mat3f src_a, mat3f src_b);

void glmc_mat3f_mul(mat3f dest, mat3f src_a, mat3f src_b);
void glmc_mat3f_muladd(mat3f dest, mat3f src_a, mat3f src_b);
void glmc_mat3f_mulsub(mat3f dest, mat3f src_a, mat3f src_b);
void glmc_mat3f_mul_s(mat3f dest, mat3f src_a, float src_b);

void glmc_mat3f_div_s(mat3f dest, mat3f src_a, float src_b);

void glmc_mat3f_inv(mat3f dest, mat3f src_a);

void glmc_mat3f_rotation(mat3f dest, vec3f dir, float angle);

void glmc_mat3f_normalize(mat3f dest);
void glmc_mat3f_vecmul(vec3f dest, mat3f src_a, vec3f src_b);

void glmc_mat3f_trans2D(mat3f dest, float X, float Y);
void glmc_mat3f_scale2D(mat3f dest, float X, float Y);

//mat4f

void glmc_mat4f_print(mat4f src_b);
int glmc_mat4f_isequal(mat4f src_a, mat4f src_b);
void glmc_mat4f_copy(mat4f dest, mat4f src_b);
void glmc_mat4f_transp(mat4f dest, mat4f src_b);
float glmc_mat4f_abs(mat4f src_b);

void glmc_mat4f_add(mat4f dest, mat4f src_a, mat4f src_b);

void glmc_mat4f_sub(mat4f dest, mat4f src_a, mat4f src_b);

void glmc_mat4f_mul(mat4f dest, mat4f src_a, mat4f src_b);
void glmc_mat4f_muladd(mat4f dest, mat4f src_a, mat4f src_b);
void glmc_mat4f_mulsub(mat4f dest, mat4f src_a, mat4f src_b);
void glmc_mat4f_mul_s(mat4f dest, mat4f src_a, float src_b);

void glmc_mat4f_div_s(mat4f dest, mat4f src_a, float src_b);

void glmc_mat4f_inv(mat4f dest, mat4f src_a);

void glmc_mat4f_rotation(mat4f dest, vec4f dir, float angle);

void glmc_mat4f_normalize(mat4f dest);
void glmc_mat4f_vecmul(vec4f dest, mat4f src_a, vec4f src_b);

void glmc_mat4f_trans3D(mat4f dest, float X, float Y, float Z);
void glmc_mat4f_scale3D(mat4f dest, float X, float Y, float Z);

#endif /* _GLMC_H */