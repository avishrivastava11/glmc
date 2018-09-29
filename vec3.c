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

/*
 * Created by avi on 29/9/18.
 */

#include "glmc.h"
#include <stdio.h>
#include <math.h>

void glmc_vec3f_from_2f(vec3f dest, vec2f src_a, float src_b)
{
    int e3;
    for(e3=0; e3<2; e3++)
    {
        dest[e3] = src_a[0];
        printf("%f\n", dest[e3]);
    }
    dest[e3] = src_b;
}

void glmc_vec3f_from_4f(vec3f dest, vec4f src)
{
    int e4;
    int e3 = 0;
    for(int e4=0; e4<4; e4++)
    {
        if(src[e4]!=0 && e3<3)
        {
            dest[e3++] = src[e4];
        }
        else if(e3>2 && src[e4]!=0)
        {
            printf("Warning: Fourth value got dumped");
        }
    }
}

void glmc_vec3f_copy(vec3f dest, vec3f src)
{
    int e3 = 0;
    for(e3=0; e3<3; e3++)
    {
        dest[e3] = src[e3];
    }
}

float glmc_vec3f_sqrlength(vec3f vec)
{
    int e3 = 0;
    float sum=0.0;
    for(e3=0; e3<3; e3++)
    {
        sum+=vec[e3]*vec[e3];
    }
    return sum;

}

float glmc_vec3f_length(vec3f vec)
{
    return (powf(glmc_vec3f_sqrlength(vec),0.5));
}

int  glmc_vec3f_is_normalized(vec3f src)
{
    if(glmc_vec3f_length(src)==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void glmc_vec3f_normlize(vec3f dest, vec3f src)
{
    int e3;
    int length=glmc_vec3f_length(src);
    for(e3=0; e3<3; e3++)
    {
        dest[e3] = src[e3]/length;
    }
}

void glmc_vec3f_add(vec3f dest, vec3f src_a, vec3f src_b)
{
    int e3;
    for(e3=0; e3<3; e3++)
    {
        dest[e3] = src_a[e3] + src_b[e3];
    }
}

void glmc_vec3f_add_dest(vec3f src_dest, vec3f src_b)
{
    int e3;
    for(e3=0; e3<3; e3++)
    {
        src_dest[e3] += src_b[e3];
    }
}

void glmc_vec3f_sub(vec3f dest, vec3f src_a, vec3f src_b)
{
    int e3;
    for(e3=0; e3<3; e3++)
    {
        dest[e3] = src_a[e3] - src_b[e3];
    }
}

void glmc_vec3f_sub_dest(vec3f src_dest, vec3f src_b)
{
    int e3;
    for(e3=0; e3<3; e3++)
    {
        src_dest[e3] -= src_b[e3];
    }
}

void glmc_vec3f_mul(vec3f dest, vec3f src_a, vec3f src_b)
{
    int e3;
    for(e3=0; e3<3; e3++)
    {
        dest[e3] = src_a[e3] * src_b[e3];
    }
}

void glmc_vec3f_mul_dest(vec3f src_dest, vec3f src_b)
{
    int e3;
    for(e3=0; e3<3; e3++)
    {
        src_dest[e3] *= src_b[e3];
    }
}
void glmc_vec3f_mul_s(vec3f dest, vec3f src_a, float src_b)
{
    int e3;
    for(e3=0; e3<3; e3++)
    {
        dest[e3] = src_a[e3] * src_b;
    }
}

void glmc_vec3f_div(vec3f dest, vec3f src_a, vec3f src_b)
{
    int e3;
    for(e3=0; e3<3; e3++)
    {
        dest[e3] = src_a[e3] / src_b[e3];
    }
}
void glmc_vec3f_div_dest(vec3f src_dest, vec3f src_b)
{
    int e3;
    for(e3=0; e3<3; e3++)
    {
        src_dest[e3] /= src_b[e3];
    }
}
void glmc_vec3f_div_s(vec3f dest, vec3f src_a, float src_b)
{
    int e3;
    for(e3=0; e3<3; e3++)
    {
        dest[e3] = src_a[e3] / src_b;
    }
}

void glmc_vec3f_addadd(vec3f dest, vec3f src_a, vec3f src_b)
{
    int e3;
    for(e3=0; e3<3; e3++)
    {
        dest[e3] += src_a[e3] + src_b[e3];
    }
}

void glmc_vec3f_subadd(vec3f dest, vec3f src_a, vec3f src_b)
{
    int e3;
    for(e3=0; e3<3; e3++)
    {
        dest[e3] += src_a[e3] - src_b[e3];
    }
}


void glmc_vec3f_madd(vec3f dest, vec3f src_a, vec3f src_b)
{
    int e3;
    for(e3=0; e3<3; e3++)
    {
        dest[e3] += src_a[e3] * src_b[e3];
    }
}

void glmc_vec3f_msub(vec3f dest, vec3f src_a, vec3f src_b)
{
    int e3;
    for(e3=0; e3<3; e3++)
    {
        dest[e3] -= src_a[e3] * src_b[e3];
    }
}

float glmc_vec3f_dot(vec3f src_a, vec3f src_b)
{
    int e3;
    float dot_product = 0;
    for(e3=0; e3<3; e3++)
    {
        dot_product += src_a[e3] * src_b[e3];
    }
    return dot_product;
}

void  glmc_vec3f_cross(vec3f dest, vec3f src_a, vec3f src_b)
{
    dest[0] = (src_a[1]*src_b[2]-src_a[2]*src_b[1]);
    dest[1] =-1*(src_a[0]*src_b[2]-src_a[2]*src_b[0]);
    dest[2] = (src_a[0]*src_b[1]-src_a[1]*src_b[0]);
}

