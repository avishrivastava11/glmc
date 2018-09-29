//
// Created by avi on 29/9/18.
//

#include "glmc.h"
#include <math.h>
#include <stdio.h>

void glmc_mat2f_print(mat2f src_b)
{
    for(int x=0; x<2; x++)
    {
        for(int y=0; y<2; y++)
        {
            printf("%-6.2f ", src_b[x][y]);
        }
        printf("\n");
    }
}

int glmc_mat2f_isequal(mat2f src_a, mat2f src_b)
{
    for(int x=0; x<2; x++)
    {
        for(int y=0; y<2; y++)
        {
            if(src_a[x][y] != src_b[x][y])
            {
                return 0;
            }
        }
    }
    return 1;
}

void glmc_mat2f_copy(mat2f dest, mat2f src_b)
{
    for(int x=0; x<2; x++)
    {
        for(int y=0; y<2; y++)
        {
            dest[x][y]=src_b[x][y];
        }
    }
}

void glmc_mat2f_transp(mat2f dest, mat2f src_b)
{
    for(int x=0; x<2; x++)
    {
        for(int y=0; y<2; y++)
        {
            dest[y][x]=src_b[x][y];
        }
    }
}

float glmc_mat2f_abs(mat2f src_b)
{
    float dest=0;
    for(int x=0; x<2; x++)
    {
        for(int y=0; y<2; y++)
        {
            dest+=src_b[x][y];
        }
    }
    return dest;
}

void glmc_mat2f_add(mat2f dest, mat2f src_a, mat2f src_b)
{
    int x=0;
    for(x=0; x<2; x++)
    {
        glmc_vec2f_add(dest[x], src_a[x], src_b[x]);
    }
}

void glmc_mat2f_sub(mat2f dest, mat2f src_a, mat2f src_b)
{
    int x=0;
    for(x=0; x<2; x++)
    {
        glmc_vec2f_sub(dest[x], src_a[x], src_b[x]);
    }
}

void glmc_mat2f_mul(mat2f dest, mat2f src_a, mat2f src_b)
{
    for(int x=0; x<2; x++)
    {
        for(int y=0; y<2; y++)
        {
            for(int z=0; z<2; z++)
            {
                dest[x][y]=src_a[x][z]*src_b[z][y];
            }
        }
    }
}

void glmc_mat2f_muladd(mat2f dest, mat2f src_a, mat2f src_b)
{
    mat2f temp;
    glmc_mat2f_mul(temp, src_a, src_b);
    glmc_mat2f_add(dest, dest, temp);
}

void glmc_mat2f_mulsub(mat2f dest, mat2f src_a, mat2f src_b)
{
    mat2f temp;
    glmc_mat2f_mul(temp, src_a, src_b);
    glmc_mat2f_sub(dest, dest, temp);
}

void glmc_mat2f_mul_s(mat2f dest, mat2f src_a, float src_b)
{
    glmc_vec2f_mul_s(dest[0], src_a[0], src_b);
    glmc_vec2f_mul_s(dest[1], src_a[1], src_b);
}

void glmc_mat2f_div_s(mat2f dest, mat2f src_a, float src_b)
{
    glmc_vec2f_div_s(dest[0], src_a[0], src_b);
    glmc_vec2f_div_s(dest[1], src_a[1], src_b);
}

void glmc_mat2f_inv(mat2f dest, mat2f src_a)
{
    float disc = glmc_mat2f_abs(src_a);
    mat2f temp = {{src_a[2][2], src_a[2][1]}, {src_a[1][2], src_a[1][1]}};
    glmc_mat2f_div_s (dest, temp, disc);
}

void glmc_mat2f_normalize(mat2f dest)
{
    float det = glmc_mat2f_abs(dest);
    glmc_vec2f_div_s(dest[0], dest[0] ,det);
    glmc_vec2f_div_s(dest[1], dest[1] ,det);
}

void glmc_mat2f_vecmul(vec2f dest, mat2f src_a, vec2f src_b)
{
    dest[0]=glmc_vec2f_dot(src_a[0], src_b);
    dest[1]=glmc_vec2f_dot(src_a[1], src_b);
}