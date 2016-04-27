#ifndef __SURFACE_H__
#define __SURFACE_H__

#include <new>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <colors.h>

typedef struct
{
    int x;
    int y;
    int width;
    int height;
} rect_t;


class Surface
{
public:
    Surface();
    Surface(rect_t);
    void create_surface();

    rect_t get_rect();
    RGBColor_t *get_surface();

    void write_pixel(int, int, RGBColor_t);
    void read_pixel(int, int, RGBColor_t *);
    void fill(RGBColor_t);
    size_t ctop(int, int);

    // virtual generate for derived classes that override.
    virtual void generate();

    ~Surface();
private:
    RGBColor_t *surface;
    rect_t rect;
};

#endif