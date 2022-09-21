#include <stdio.h>
#include <stdlib.h>
#include "c_img.c"

int main() {
    struct rgb_img*im = (struct rgb_img*)malloc(sizeof(struct rgb_img));
    read_in_img(&im,"president.bin");

    printf("Height: %lu, Width: %lu\n", im->height, im->width);
    int height = im->height;
    int width = im->width;
    //im->raster = get_pixel(im, 532, 353, 1);//y:height, x:width
    // printf("%d\n", im->raster);
    int i = 1;//y
    int j = 1;//x
    double a = 1.4;//multiply
    for(i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int r = get_pixel(im, i, j, 0);
            int g = get_pixel(im, i, j, 1);
            int b = get_pixel(im, i, j, 2);
            r = r*a;
            g = g*a;
            b = b*a;
            if(r>255){
                r = 255;
            }if(g>255){
                g = 255;
            }if(b>255){
                b = 255;
            }
            set_pixel(im, i, j, r, g, b);
        }
    }
    write_img(im, "president.bin");
    return 0;
}
