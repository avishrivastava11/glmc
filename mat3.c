//
// Created by avi on 29/9/18.
//
#include "glmc.h"
#include <math.h>
#include <stdio.h>

void glmc_mat3f_print(mat3f src_b)
{
    for(int x=0; x<3; x++)
    {
        for(int y=0; y<3; y++)
        {
            printf("%-6.2f ", src_b[x][y]);
        }
        printf("\n");
    }
}

int glmc_mat3f_isequal(mat3f src_a, mat3f src_b)
{
    for(int x=0; x<3; x++)
    {
        for(int y=0; y<3; y++)
        {
            if(src_a[x][y] != src_b[x][y])
            {
                return 0;
            }
        }
    }
    return 1;
}

void glmc_mat3f_copy(mat3f dest, mat3f src_b)
{
    for(int x=0; x<3; x++)
    {
        for(int y=0; y<3; y++)
        {
            dest[x][y]=src_b[x][y];
        }
    }
}

void glmc_mat3f_transp(mat3f dest, mat3f src_b)
{
    for(int x=0; x<3; x++)
    {
        for(int y=0; y<3; y++)
        {
            dest[y][x]=src_b[x][y];
        }
    }
}

float glmc_mat3f_abs(mat3f src_b)
{
    float dest=0;
    for(int x=0; x<3; x++)
    {
        for(int y=0; y<3; y++)
        {
            dest+=src_b[x][y];
        }
    }
    return dest;
}

void glmc_mat3f_add(mat3f dest, mat3f src_a, mat3f src_b)
{
    int x=0;
    for(x=0; x<3; x++)
    {
        glmc_vec3f_add(dest[x], src_a[x], src_b[x]);
    }
}

void glmc_mat3f_sub(mat3f dest, mat3f src_a, mat3f src_b)
{
    int x=0;
    for(x=0; x<3; x++)
    {
        glmc_vec3f_sub(dest[x], src_a[x], src_b[x]);
    }
}

void glmc_mat3f_mul(mat3f dest, mat3f src_a, mat3f src_b)
{
    for(int x=0; x<3; x++)
    {
        for(int y=0; y<3; y++)
        {
            for(int z=0; z<3; z++)
            {
                dest[x][y]=src_a[x][z]*src_b[z][y];
            }
        }
    }
}

void glmc_mat3f_muladd(mat3f dest, mat3f src_a, mat3f src_b)
{
    mat3f temp;
    glmc_mat3f_mul(temp, src_a, src_b);
    glmc_mat3f_add(dest, dest, temp);
}

void glmc_mat3f_mulsub(mat3f dest, mat3f src_a, mat3f src_b)
{
    mat3f temp;
    glmc_mat3f_mul(temp, src_a, src_b);
    glmc_mat3f_sub(dest, dest, temp);
}

void glmc_mat3f_mul_s(mat3f dest, mat3f src_a, float src_b)
{
    glmc_vec3f_mul_s(dest[0], src_a[0], src_b);
    glmc_vec3f_mul_s(dest[1], src_a[1], src_b);
    glmc_vec3f_mul_s(dest[2], src_a[2], src_b);
}

void glmc_mat3f_div_s(mat3f dest, mat3f src_a, float src_b)
{
    glmc_vec3f_div_s(dest[0], src_a[0], src_b);
    glmc_vec3f_div_s(dest[1], src_a[1], src_b);
    glmc_vec3f_div_s(dest[2], src_a[2], src_b);
}

void glmc_mat3f_inv(mat3f dest, mat3f src_a)// Inverse of a matrix by Gauss-Jordan elimination
{
    mat3f temp_mat;
    glmc_mat3f_copy(temp_mat,src_a);
    mat3f identity = {{1,0,0}, {0,1,0}, {0,0,1}};
    glmc_mat3f_copy(dest,identity);
    glmc_vec3f_div_s(dest[0], dest[0], src_a[0][0]);
    glmc_vec3f_div_s(src_a[0], src_a[0], src_a[0][0]);
    float pivot1[]={src_a[1][0],src_a[2][0]};
    for(int x=1; x<3; x++)
    {
        for(int y=0; y<3; y++)
        {
            src_a[x][y]=src_a[x][y]-(pivot1[x-1]*src_a[0][y]);
            dest[x][y]=dest[x][y]-(pivot1[x-1]*dest[0][y]);
        }
    }
    glmc_vec3f_div_s(dest[1], dest[1], src_a[1][1]);
    glmc_vec3f_div_s(src_a[1], src_a[1], src_a[1][1]);
    float pivot2=src_a[2][1];
    for(int y=0; y<3; y++)
    {
        src_a[2][y]=src_a[2][y]-pivot2*src_a[1][y];
        dest[2][y]=dest[2][y]-pivot2*dest[1][y];
    }
    glmc_vec3f_div_s(dest[2], dest[2], src_a[2][2]);
    glmc_vec3f_div_s(src_a[2], src_a[2], src_a[2][2]);
    float temp=src_a[0][1];
    for(int y=0; y<3; y++)
    {
        src_a[0][y]-=temp*src_a[1][y];
        dest[0][y]-=temp*dest[1][y];
    }
    for(int y=0; y<3; y++)
    {
        dest[0][y]-=src_a[0][2]*dest[2][y];
        dest[1][y]-=src_a[1][2]*dest[2][y];
    }
    src_a[0][2]=0;
    src_a[1][2]=0;
    if(glmc_mat3f_isequal(src_a, identity) == 0)
    {
        printf("Error:Matrix is not inversible");
    }
    glmc_mat3f_copy(src_a,temp_mat);
}

void glmc_mat3f_rotation(mat3f dest, vec3f dir, float angle)
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
    glmc_mat3f_add(dest, u, identity);
    glmc_mat3f_add(dest, dest, uxu);

}

void glmc_mat3f_normalize(mat3f dest)
{
    float det = glmc_mat3f_abs(dest);
    glmc_vec3f_div_s(dest[0], dest[0] ,det);
    glmc_vec3f_div_s(dest[1], dest[1] ,det);
    glmc_vec3f_div_s(dest[2], dest[2] ,det);
}

void glmc_mat3f_vecmul(vec3f dest, mat3f src_a, vec3f src_b)
{
    dest[0]=glmc_vec3f_dot(src_a[0], src_b);
    dest[1]=glmc_vec3f_dot(src_a[1], src_b);
    dest[2]=glmc_vec3f_dot(src_a[2], src_b);
}

void glmc_mat3f_trans2D(mat3f dest, float X, float Y)
{
    mat3f temp={{1, 0, X}, {0, 1, Y}, {0, 0, 1}};
    glmc_mat3f_copy(dest, temp);
}

void glmc_mat3f_scale2D(mat3f dest, float X, float Y)
{
    mat3f temp = {{X, 0, 0}, {Y, 0, 0}, {0, 0, 1}};
    glmc_mat3f_copy(dest, temp);
}
