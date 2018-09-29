//
// Created by avi on 29/9/18.
//

#include "glmc.h"
#include <math.h>
#include <stdio.h>

void glmc_mat4f_print(mat4f src_b)
{
    for(int x=0; x<4; x++)
    {
        for(int y=0; y<4; y++)
        {
            printf("%-6.2f ", src_b[x][y]);
        }
        printf("\n");
    }
}

int glmc_mat4f_isequal(mat4f src_a, mat4f src_b)
{
    for(int x=0; x<4; x++)
    {
        for(int y=0; y<4; y++)
        {
            if(src_a[x][y] != src_b[x][y])
            {
                return 0;
            }
        }
    }
    return 1;
}

void glmc_mat4f_copy(mat4f dest, mat4f src_b)
{
    for(int x=0; x<4; x++)
    {
        for(int y=0; y<4; y++)
        {
            dest[x][y]=src_b[x][y];
        }
    }
}

void glmc_mat4f_transp(mat4f dest, mat4f src_b)
{
    for(int x=0; x<4; x++)
    {
        for(int y=0; y<4; y++)
        {
            dest[y][x]=src_b[x][y];
        }
    }
}

float glmc_mat4f_abs(mat4f src_b)
{
    float dest=0;
    for(int x=0; x<4; x++)
    {
        for(int y=0; y<4; y++)
        {
            dest+=src_b[x][y];
        }
    }
    return dest;
}

void glmc_mat4f_add(mat4f dest, mat4f src_a, mat4f src_b)
{
    int x=0;
    for(x=0; x<4; x++)
    {
        glmc_vec4f_add(dest[x], src_a[x], src_b[x]);
    }
}

void glmc_mat4f_sub(mat4f dest, mat4f src_a, mat4f src_b)
{
    int x=0;
    for(x=0; x<4; x++)
    {
        glmc_vec4f_sub(dest[x], src_a[x], src_b[x]);
    }
}

void glmc_mat4f_mul(mat4f dest, mat4f src_a, mat4f src_b)
{
    for(int x=0; x<4; x++)
    {
        for(int y=0; y<4; y++)
        {
            for(int z=0; z<4; z++)
            {
                dest[x][y]=src_a[x][z]*src_b[z][y];
            }
        }
    }
}

void glmc_mat4f_muladd(mat4f dest, mat4f src_a, mat4f src_b)
{
    mat4f temp;
    glmc_mat4f_mul(temp, src_a, src_b);
    glmc_mat4f_add(dest, dest, temp);
}

void glmc_mat4f_mulsub(mat4f dest, mat4f src_a, mat4f src_b)
{
    mat4f temp;
    glmc_mat4f_mul(temp, src_a, src_b);
    glmc_mat4f_sub(dest, dest, temp);
}

void glmc_mat4f_mul_s(mat4f dest, mat4f src_a, float src_b)
{
    glmc_vec4f_mul_s(dest[0], src_a[0], src_b);
    glmc_vec4f_mul_s(dest[1], src_a[1], src_b);
    glmc_vec4f_mul_s(dest[2], src_a[2], src_b);
    glmc_vec4f_mul_s(dest[3], src_a[3], src_b);
}

void glmc_mat4f_div_s(mat4f dest, mat4f src_a, float src_b)
{
    glmc_vec4f_div_s(dest[0], src_a[0], src_b);
    glmc_vec4f_div_s(dest[1], src_a[1], src_b);
    glmc_vec4f_div_s(dest[2], src_a[2], src_b);
    glmc_vec4f_div_s(dest[3], src_a[3], src_b);
}

void glmc_mat4f_inv(mat4f dest, mat4f src_a);

void glmc_mat4f_rotation(mat4f dest, vec4f dir, float angle)
{
    mat3f identity = {{0, 0, 1}, {0, 1, 0}, {1, 0, 0}};
    vec3f uv;
    glmc_vec3f_normalize(uv,dir);
    mat3f u = {{0, -1*uv[2], uv[1]},
               {uv[2], 0, -1*uv[0]},
               {-1*uv[1], uv[0], 0}};
    mat3f uxu = {{uv[0]*uv[0], uv[0]*uv[1], uv[0]*uv[2]},
                 {uv[0]*uv[1], uv[1]*uv[1], uv[1]*uv[2]},
                 {uv[0]*uv[2], uv[1]*uv[2], uv[2]*uv[2]}};
    glmc_mat3f_mul_s(identity, identity, cos(angle));
    glmc_mat3f_mul_s(u, u, sin(angle));
    glmc_mat3f_mul_s(uxu, uxu, (1-cos(angle)));
    glmc_mat3f_add(u, u, identity);
    glmc_mat3f_add(uxu, uxu, u);
    for(int x=0; x<4; x++)
    {
        for(int y=0; y<4; y++)
        {
            if(y<3 && x<3)
            {
                dest[x][y]=uxu[x][y];
            }
            else if(y==3 || x==3)
            {
                dest[x][y]==0;
            }
        }
    }
    dest[3][3]=1;
}

void glmc_mat4f_normalize(mat4f dest)
{
    float det = glmc_mat4f_abs(dest);
    glmc_vec4f_div_s(dest[0], dest[0] ,det);
    glmc_vec4f_div_s(dest[1], dest[1] ,det);
    glmc_vec4f_div_s(dest[2], dest[2] ,det);
    glmc_vec4f_div_s(dest[3], dest[3] ,det);
}

void glmc_mat4f_vecmul(vec4f dest, mat4f src_a, vec4f src_b)
{
    dest[0]=glmc_vec4f_dot(src_a[0], src_b);
    dest[1]=glmc_vec4f_dot(src_a[1], src_b);
    dest[2]=glmc_vec4f_dot(src_a[2], src_b);
    dest[3]=glmc_vec4f_dot(src_a[3], src_b);
}

void glmc_mat4f_trans3D(mat4f dest, float X, float Y, float Z)
{
    mat4f temp={{1, 0, 0, X}, {0, 1, 0, Y}, {0, 0, 1, Z}, {0, 0, 0, 1}};
    glmc_mat4f_copy(dest, temp);
}

void glmc_mat4f_scale3D(mat4f dest, float X, float Y, float Z)
{
    mat4f temp = {{X, 0, 0, 0}, {0, Y, 0, 0}, {0, 0, Z, 0}, {0, 0, 0, 1}};
    glmc_mat4f_copy(dest, temp);
}