//
// Created by avi on 29/9/18.
//

#include "glmc.h"
#include <stdio.h>
#include <math.h>

void glmc_vec2f_from_3f(vec2f dest, vec3f src)
{
    int e3;
    int e2 = 0;
    for(int e3=0; e3<2; e3++)
    {
        if(src[e3]!=0 && e2<2)
        {
            dest[e2++] = src[e3];
        }
        else if(e2>1 && src[e3]!=0)
        {
            printf("Warning: Third value got dumped");
        }
    }
}
void glmc_vec2f_from_4f(vec2f dest, vec2f src)
{
    int e3;
    int e2 = 0;
    for(int e4=0; e4<4; e4++)
    {
        if(src[e3]!=0 && e2<2)
        {
            dest[e2++] = src[e3];
        }
        else if(e2>1 && src[e3]!=0)
        {
            printf("Warning: One value got dumped");
        }
    }
}
void glmc_vec2f_copy(vec2f dest, vec2f src)
{
    int e2;
    for(e2=0; e2<2; e2++)
    {
        dest[e2] = src[e2];
    }
}

float glmc_vec2f_sqrlength(vec2f vec)
{
    int e2 = 0;
    float sum=0.0;
    for(e2=0; e2<2; e2++)
    {
        sum+=vec[e2]*vec[e2];
    }
    return sum;

}

float glmc_vec2f_length(vec2f vec)
{
    return (powf(glmc_vec2f_sqrlength(vec),0.5));
}

int  glmc_vec2f_is_normalized(vec2f src)
{
    if(glmc_vec2f_length(src) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void glmc_vec2f_normlize(vec2f dest, vec2f src)
{
    int e2 = 0;
    float sum=0.0;
    for(e2=0; e2<2; e2++)
    {
        dest[e2] = src[e2] / (glmc_vec2f_length(src));
    }
}

void glmc_vec2f_add(vec2f dest, vec2f src_a, vec2f src_b)
{
    int e2;
    for(e2=0; e2<2; e2++)
    {
        dest[e2] = src_a[e2] + src_b[e2];
    }
}

void glmc_vec2f_add_dest(vec2f src_dest, vec2f src_b)
{
    int e2;
    for(e2=0; e2<2; e2++)
    {
        src_dest[e2] += src_b[e2];
    }
}

void glmc_vec2f_sub(vec2f dest, vec2f src_a, vec2f src_b)
{
    int e2;
    for(e2=0; e2<2; e2++)
    {
        dest[e2] = src_a[e2] - src_b[e2];
    }
}

void glmc_vec2f_sub_dest(vec2f src_dest, vec2f src_b)
{
    int e2;
    for(e2=0; e2<2; e2++)
    {
        src_dest[e2] -= src_b[e2];
    }
}

void glmc_vec2f_mul(vec2f dest, vec2f src_a, vec2f src_b)
{
    int e2;
    for(e2=0; e2<2; e2++)
    {
        dest[e2] = src_a[e2] * src_b[e2];
    }
}

void glmc_vec2f_mul_dest(vec2f src_dest, vec2f src_b)
{
    int e2;
    for(e2=0; e2<2; e2++)
    {
        src_dest[e2] *= src_b[e2];
    }
}

void glmc_vec2f_mul_s(vec2f dest, vec2f src_a, float src_b)
{
    int e2;
    for(e2=0; e2<2; e2++)
    {
        dest[e2] = src_a[e2] * src_b;
    }
}

void glmc_vec2f_div(vec2f dest, vec2f src_a, vec2f src_b)
{
    int e2;
    for(e2=0; e2<2; e2++)
    {
        dest[e2] = src_a[e2] / src_b[e2];
    }
}
void glmc_vec2f_div_dest(vec2f src_dest, vec2f src_b)
{
    int e2;
    for(e2=0; e2<2; e2++)
    {
        src_dest[e2] /= src_b[e2];
    }
}

void glmc_vec2f_div_s(vec2f dest, vec2f src_a, float src_b)
{
    int e2;
    for(e2=0; e2<2; e2++)
    {
        dest[e2] = src_a[e2] / src_b;
    }
}
void glmc_vec2f_addadd(vec2f dest, vec2f src_a, vec2f src_b)
{
    int e2;
    for(e2=0; e2<2; e2++)
    {
        dest[e2] += src_a[e2] + src_b[e2];
    }
}

void glmc_vec2f_subadd(vec2f dest, vec2f src_a, vec2f src_b)
{
    int e2;
    for(e2=0; e2<2; e2++)
    {
        dest[e2] += src_a[e2] - src_b[e2];
    }
}

void glmc_vec2f_madd(vec2f dest, vec2f src_a, vec2f src_b)
{
    int e2;
    for(e2=0; e2<2; e2++)
    {
        dest[e2] += src_a[e2] * src_b[e2];
    }
}
void glmc_vec2f_msub(vec2f dest, vec2f src_a, vec2f src_b)
{
    int e2;
    for(e2=0; e2<2; e2++)
    {
        dest[e2] -= src_a[e2] * src_b[e2];
    }
}
float glmc_vec2f_dot(vec2f src_a, vec2f src_b)
{
    int e2;
    float dot_product = 0;
    for(e2=0; e2<2; e2++)
    {
        dot_product += src_a[e2] * src_b[e2];
    }
    return dot_product;
}

