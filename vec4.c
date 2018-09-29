//
// Created by avi on 29/9/18.
//

#include "glmc.h"
#include <stdio.h>
#include <math.h>

void glmc_vec4f_from_2f(vec4f dest, vec2f src_a, float src_b, float src_c)
{
    int e4;
    for(e4=0; e4<2; e4++)
    {
        dest[e4] = src_a[e4];
    }
    dest[e4++] = src_b;
    dest[e4++] = src_c;
}

void glmc_vec4f_from_3f(vec4f dest, vec3f src_a, float src_b)
{
    int e4;
    for(e4=0; e4<3; e4++)
    {
        dest[e4] = src_a[e4];
    }
    dest[e4++] = src_b;
}

void glmc_vec4f_copy(vec4f dest, vec4f src)
{
    int e4;
    for(e4=0; e4<4; e4++)
    {
        dest[e4] = src[e4];
    }
}

float glmc_vec4f_sqrlength(vec4f vec)
{
    int e4 = 0;
    float sum=0.0;
    for(e4=0; e4<4; e4++)
    {
        sum+=vec[e4]*vec[e4];
    }
    return sum;

}

float glmc_vec4f_length(vec4f vec)
{
    return (powf(glmc_vec4f_sqrlength(vec),0.5));
}

int  glmc_vec4f_is_normalized(vec4f src)
{
    if(glmc_vec4f_length(src) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void glmc_vec4f_normlize(vec4f dest, vec4f src)
{
    int e4 = 0;
    float sum=0.0;
    for(e4=0; e4<4; e4++)
    {
        dest[e4] = src[e4] / (glmc_vec4f_length(src));
    }
}

void glmc_vec4f_add(vec4f dest, vec4f src_a, vec4f src_b)
{
    int e4;
    for(e4=0; e4<4; e4++)
    {
        dest[e4] = src_a[e4] + src_b[e4];
    }
}

void glmc_vec4f_add_dest(vec4f src_dest, vec4f src_b)
{
    int e4;
    for(e4=0; e4<4; e4++)
    {
        src_dest[e4] += src_b[e4];
    }
}

void glmc_vec4f_sub(vec4f dest, vec4f src_a, vec4f src_b)
{
    int e4;
    for(e4=0; e4<4; e4++)
    {
        dest[e4] = src_a[e4] - src_b[e4];
    }
}

void glmc_vec4f_sub_dest(vec4f src_dest, vec4f src_b)
{
    int e4;
    for(e4=0; e4<4; e4++)
    {
        src_dest[e4] -= src_b[e4];
    }
}

void glmc_vec4f_mul(vec4f dest, vec4f src_a, vec4f src_b)
{
    int e4;
    for(e4=0; e4<4; e4++)
    {
        dest[e4] = src_a[e4] * src_b[e4];
    }
}

void glmc_vec4f_mul_dest(vec4f src_dest, vec4f src_b)
{
    int e4;
    for(e4=0; e4<4; e4++)
    {
        src_dest[e4] *= src_b[e4];
    }
}

void glmc_vec4f_mul_s(vec4f dest, vec4f src_a, float src_b)
{
    int e4;
    for(e4=0; e4<4; e4++)
    {
        dest[e4] = src_a[e4] * src_b;
    }
}

void glmc_vec4f_div(vec4f dest, vec4f src_a, vec4f src_b)
{
    int e4;
    for(e4=0; e4<4; e4++)
    {
        dest[e4] = src_a[e4] / src_b[e4];
    }
}
void glmc_vec4f_div_dest(vec4f src_dest, vec4f src_b)
{
    int e4;
    for(e4=0; e4<4; e4++)
    {
        src_dest[e4] /= src_b[e4];
    }
}

void glmc_vec4f_div_s(vec4f dest, vec4f src_a, float src_b)
{
    int e4;
    for(e4=0; e4<4; e4++)
    {
        dest[e4] = src_a[e4] / src_b;
    }
}

void glmc_vec4f_addadd(vec4f dest, vec4f src_a, vec4f src_b)
{
    int e4;
    for(e4=0; e4<4; e4++)
    {
        dest[e4] += src_a[e4] + src_b[e4];
    }
}

void glmc_vec4f_subadd(vec4f dest, vec4f src_a, vec4f src_b)
{
    int e4;
    for(e4=0; e4<4; e4++)
    {
        dest[e4] += src_a[e4] - src_b[e4];
    }
}

void glmc_vec4f_madd(vec4f dest, vec4f src_a, vec4f src_b)
{
    int e4;
    for(e4=0; e4<4; e4++)
    {
        dest[e4] += src_a[e4] * src_b[e4];
    }
}

void glmc_vec4f_msub(vec4f dest, vec4f src_a, vec4f src_b)
{
    int e4;
    for(e4=0; e4<4; e4++)
    {
        dest[e4] -= src_a[e4] * src_b[e4];
    }
}

float glmc_vec4f_dot(vec4f src_a, vec4f src_b)
{
    int e4;
    float dot_product = 0;
    for(e4=0; e4<4; e4++)
    {
        dot_product += src_a[e4] * src_b[e4];
    }
    return dot_product;
}